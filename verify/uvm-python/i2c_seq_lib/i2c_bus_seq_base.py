from uvm.seq import UVMSequence
from uvm.macros.uvm_object_defines import uvm_object_utils
from uvm.macros.uvm_message_defines import uvm_fatal
from uvm.base.uvm_config_db import UVMConfigDb
from EF_UVM.bus_env.bus_seq_lib.bus_seq_base import bus_seq_base
from cocotb.triggers import Timer
from uvm.macros.uvm_sequence_defines import uvm_do_with, uvm_do
import random
from uvm.macros import uvm_component_utils, uvm_info, uvm_error, uvm_warning
from uvm.base.uvm_object_globals import UVM_HIGH, UVM_LOW, UVM_MEDIUM

class i2c_bus_seq_base(bus_seq_base):
    # use this sequence write or read from register by the bus interface
    # this sequence should be connected to the bus sequencer in the testbench
    # you should create as many sequences as you need not only this one
    def __init__(self, name="i2c_bus_seq_base"):
        super().__init__(name)
        regs_arr = []
        if not UVMConfigDb.get(self, "", "bus_regs", regs_arr):
            uvm_fatal(self.tag, "No json file wrapper regs")
        else:
            self.regs = regs_arr[0]
        self.slave0 = slave_valid_addr(0b1010101)
        self.slave1 = slave_valid_addr(0b1010110)


    async def body(self):
        await super().body()
        await self.send_req(is_write=True, reg="CLKGATE", data_condition=lambda data: data == 1)
        
    
    async def change_PR(self, val):
        await self.send_req(is_write=True, reg="PR", data_value=val)

    async def write_multiple(self, slave_address, address, data):
        uvm_info(self.tag, f"write_multiple slave address = 0x{slave_address:X}, address = 0x{address:X}, data = {data}", UVM_MEDIUM)
        #        address         write_mul
        commad_write = slave_address | 1 << 10
        command_write_mul = slave_address | 1 << 11
        await self.wait_data_fifo_not_full()
        await self.send_req(is_write=True, reg="Command", data_value=commad_write) # issue write command
        await self.send_req(is_write=True, reg="Data", data_value=(address>>8) & 0xFF) # address high
        await self.wait_data_fifo_not_full()
        await self.send_req(is_write=True, reg="Command", data_value=commad_write) # issue write command
        await self.send_req(is_write=True, reg="Data", data_value=address & 0xFF) # address low        
        # write mul 
        await self.send_req(is_write=True, reg="Command", data_value=command_write_mul) # issue write command
        for i in data[:-1]: # data
            await self.wait_data_fifo_not_full()
            await self.send_req(is_write=True, reg="Data", data_value=i) # data
        # send last data and add data last bit
        await self.wait_data_fifo_not_full()
        await self.send_req(is_write=True, reg="Data", data_value=data[-1] | 1 << 9) # data
        command_stop = slave_address | 1 << 12 # stop
        await self.send_req(is_write=True, reg="Command", data_value=command_stop) # issue write command
        await Timer(100, "us")

    async def write_address(self, slave_address, address, data):
        uvm_info(self.tag, f"write_address slave address = 0x{slave_address:X}, address = 0x{address:X}, data = {data}", UVM_MEDIUM)
        #        address         write 
        commad_write = slave_address | 1 << 10 
        await self.wait_data_fifo_not_full()
        await self.send_req(is_write=True, reg="Command", data_value=commad_write) # issue write command
        await self.send_req(is_write=True, reg="Data", data_value=(address>>8) & 0xFF) # address high
        await self.wait_data_fifo_not_full()
        await self.send_req(is_write=True, reg="Command", data_value=commad_write) # issue write command
        await self.send_req(is_write=True, reg="Data", data_value=address & 0xFF) # address low
        for i in data: # data
            await self.wait_data_fifo_not_full()
            await self.send_req(is_write=True, reg="Command", data_value=commad_write) # issue write command
            await self.send_req(is_write=True, reg="Data", data_value=i) # data
        command_stop = slave_address | 1 << 12 # stop
        await self.send_req(is_write=True, reg="Command", data_value=command_stop) # issue write command
        await Timer(10, "us")

    async def read_address(self, slave_address, address, number_of_reads=1):
        #        address         read
        commad_write = slave_address | 1 << 10
        commad_read = slave_address | 1 << 9
        await self.wait_data_fifo_not_full()
        await self.send_req(is_write=True, reg="Command", data_value=commad_write) # issue read command
        await self.send_req(is_write=True, reg="Data", data_value=(address >> 8) & 0xFF) # address high
        await self.send_req(is_write=True, reg="Command", data_value=commad_write) # issue read command
        await self.send_req(is_write=True, reg="Data", data_value=address & 0xFF) # adrress low
        for i in range(number_of_reads):
            await self.send_req(is_write=True, reg="Command", data_value=commad_read) # issue read command
        command_stop = slave_address | 1 << 12 # stop
        await self.send_req(is_write=True, reg="Command", data_value=command_stop) # issue write command
        await Timer(10, "us")
    
    async def wait_data_fifo_not_full(self):
        # wait until tx is empty and not busy
        self.clear_response_queue()
        while True:
            rsp = []
            await self.send_req(is_write=False, reg="ris")
            await self.get_response(rsp)
            rsp = rsp[0]
            uvm_info("wait_data_fifo_not_full", f"ris = {rsp}", UVM_MEDIUM)
            if (
                rsp.addr == self.regs.reg_name_to_address["ris"]
                and rsp.data & 0b100000 == 0b0
            ):
                break
        # wait until not busy
        cycles_additional = 8 * 4
        for _ in range(cycles_additional):
            await self.send_nop()
    
    async def wait_data_rx_not_empty(self):
        # wait until tx is empty and not busy
        self.clear_response_queue()
        while True:
            rsp = []
            await self.send_req(is_write=False, reg="ris")
            await self.get_response(rsp)
            rsp = rsp[0]
            uvm_info("wait_data_rx_not_empty", f"ris = {rsp}", UVM_MEDIUM)
            if (
                rsp.addr == self.regs.reg_name_to_address["ris"]
                and rsp.data & 0b10000000 == 0b0
            ):
                break
        # wait until not busy
        cycles_additional = 8 * 4
        for _ in range(cycles_additional):
            await self.send_nop()
  
uvm_object_utils(i2c_bus_seq_base)



class slave_valid_addr():
    def __init__(self, address):
        self.slave_address = address
        self.valid_address = []
    
    def write_address(self):
        address = random.randint(0, 8191) & 0x1FE0  # 0x1FE0 ensures the first 5 bits are 0
        number_of_data = random.randint(1, 7)
        for i in range(number_of_data):
            self.valid_address.append(address + i)
        return (self.slave_address, "write",address, number_of_data)

    def read_address(self):
        if len(self.valid_address) == 0:
            return self.write_address()
        address = random.choice(self.valid_address)
        number_of_data = random.randint(1, 7) 
        for i in range(number_of_data):
            if (address + i) not in self.valid_address:
                number_of_data = i
                break
        return (self.slave_address, "read", address, number_of_data)
    
    def choose_op(self):
        if random.random() > 0.75:
            return self.write_address()
        else:
            return self.read_address()