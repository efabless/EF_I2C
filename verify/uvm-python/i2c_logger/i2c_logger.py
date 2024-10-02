from EF_UVM.ip_env.ip_logger.ip_logger import ip_logger
import cocotb 
from uvm.macros import uvm_component_utils, uvm_fatal
from i2c_item.i2c_item import i2c_item


class i2c_logger(ip_logger):
    def __init__(self, name="i2c_logger", parent=None):
        super().__init__(name, parent)
        self.header = ['Time (ns)', "Slave Address", "Read/Write", "Data"]
        self.col_widths = [10]* len(self.header)

    def logger_formatter(self, transaction):
        sim_time = f"{cocotb.utils.get_sim_time(units='ns')} ns"
        slave_address = f"0x{transaction.slave_address:X}"
        read_or_write = f"{transaction.read_or_write}"
        data = f"{transaction.data}"
        return [sim_time, slave_address, read_or_write, data]

uvm_component_utils(i2c_logger)
