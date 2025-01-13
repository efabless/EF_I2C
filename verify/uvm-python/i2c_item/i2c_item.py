from uvm.seq.uvm_sequence_item import UVMSequenceItem
from uvm.macros import uvm_object_utils_begin, uvm_object_utils_end, uvm_field_int, uvm_object_utils, uvm_error, uvm_info
from uvm.base.uvm_object_globals import UVM_ALL_ON, UVM_NOPACK, UVM_HIGH, UVM_MEDIUM
from uvm.base.sv import sv
from EF_UVM.ip_env.ip_item import ip_item

class i2c_item(ip_item):
    def __init__(self, name="i2c_item"):
        super().__init__(name)
        # self.frame_type = "address"
        self.slave_address = 0
        self.read_or_write = "write"
        self.data = []


    def convert2string(self):
        return sv.sformatf(f" I2C slave address = 0x{self.slave_address:X} , {self.read_or_write} , data = {self.data}")
        # if frame_type = "address":
        #     r_w_str = "write to" if self.read_or_write == "write" else "read from"
        #     return sv.sformatf(f" I2C address frame: {r_w_str} slave with address = 0x{self.slave_address:X}")
        # elif frame_type = "data":

    def do_compare(self, tr):
        uvm_info(self.tag, "Comparing " + self.convert2string() + " with " + tr.convert2string(), UVM_MEDIUM)
        return self.slave_address == tr.slave_address and self.data == tr.data and self.read_or_write == tr.read_or_write and self.nack_or_ack == self.nack_or_ack 


uvm_object_utils(i2c_item)
