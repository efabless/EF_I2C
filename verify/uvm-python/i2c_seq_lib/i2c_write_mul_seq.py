from uvm.seq import UVMSequence
from uvm.macros.uvm_object_defines import uvm_object_utils
from uvm.macros.uvm_message_defines import uvm_fatal
from uvm.base.uvm_config_db import UVMConfigDb
from EF_UVM.bus_env.bus_seq_lib.bus_seq_base import bus_seq_base
from cocotb.triggers import Timer
from uvm.macros.uvm_sequence_defines import uvm_do_with, uvm_do
from i2c_seq_lib.i2c_bus_seq_base import i2c_bus_seq_base
import random 
from uvm.macros import uvm_component_utils, uvm_info, uvm_error, uvm_warning
from uvm.base.uvm_object_globals import UVM_HIGH, UVM_LOW, UVM_MEDIUM 


class i2c_write_mul_seq(i2c_bus_seq_base):
    # use this sequence write or read from register by the bus interface
    # this sequence should be connected to the bus sequencer in the testbench
    # you should create as many sequences as you need not only this one
    def __init__(self, name="i2c_write_mul_seq"):
        super().__init__(name)

    async def body(self):
        await super().body()
        address = random.randint(0, 8191)
        data = [random.randint(0, 255) for i in range(random.randint(1, 10))]
        data = self.check_block_boundry(address, data)
        for i in range(10):
            print(f"seq nume = {i}")
            if random.random() > 0.5:
                slave_address = self.slave0.slave_address
            else:
                slave_address = self.slave1.slave_address
            await self.write_multiple(slave_address, address, data)
            await self.read_address(slave_address, address, len(data))
            # read rx fifo
            for i in range(len(data)):
                await self.wait_data_rx_not_empty()
                await self.send_req(is_write=False, reg="Data") # read all so the fifo will not get full 
            
    def check_block_boundry(self, address, data):
        """Check if data write would be in 2 blocks the block shares address [12:5] in used slave"""
        if address & 0b1111111100000 != (address+ len(data)) & 0b1111111100000:
            return self.check_block_boundry(address, data[:-1])
        return data

uvm_object_utils(i2c_write_mul_seq)