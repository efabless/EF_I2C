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


class i2c_write_read_seq(i2c_bus_seq_base):
    # use this sequence write or read from register by the bus interface
    # this sequence should be connected to the bus sequencer in the testbench
    # you should create as many sequences as you need not only this one
    def __init__(self, name="i2c_bus_seq"):
        super().__init__(name)

    async def body(self):
        await super().body()
        for i in range(100):
            if random.random() > 0.5:
                op = self.slave0.choose_op()
            else:
                op = self.slave1.choose_op()
            if op[1] == "write":
                data = [random.randint(0, 255) for i in range(op[3])]
                uvm_info(self.tag, f"op: {'slave0' if op[0] == self.slave0.slave_address else 'slave1'}, {op[1]}, address = {hex(op[2])}, number of data = {op[3]} data = {[hex(i) for i in data]}", UVM_LOW)
                await self.write_address(op[0], op[2], data) 
            else:
                data = [op[3]]
                uvm_info(self.tag, f"op: {'slave0' if op[0] == self.slave0.slave_address else 'slave1'}, {op[1]}, address = {hex(op[2])}, number of data = {op[3]}", UVM_LOW)
                await self.read_address(op[0], op[2], op[3])
                for i in range(op[3]):
                    await self.wait_data_rx_not_empty()
                    await self.send_req(is_write=False, reg="Data") # read all so the fifo will not get full                

uvm_object_utils(i2c_bus_seq_base)