import cocotb
from uvm.macros import uvm_component_utils, uvm_fatal, uvm_info
from uvm.base.uvm_config_db import UVMConfigDb
from uvm.base.uvm_object_globals import UVM_LOW
from uvm.base.uvm_globals import run_test
from i2c_interface.i2c_if import i2c_if
from EF_UVM.bus_env.bus_interface.bus_if import bus_apb_if, bus_irq_if, bus_ahb_if, bus_wb_if
from cocotb_coverage.coverage import coverage_db
from cocotb.triggers import Event, First, Timer
from EF_UVM.bus_env.bus_regs import bus_regs
from uvm.base import UVMRoot
from EF_UVM.base_test import base_test

# seqences import
from i2c_seq_lib.i2c_write_read_seq import i2c_write_read_seq
from i2c_seq_lib.i2c_write_mul_seq import i2c_write_mul_seq
from i2c_seq_lib.i2c_ip_seq import i2c_ip_seq

# override classes
from EF_UVM.ip_env.ip_agent.ip_driver import ip_driver
from i2c_agent.i2c_driver import i2c_driver
from EF_UVM.ip_env.ip_agent.ip_monitor import ip_monitor
from i2c_agent.i2c_monitor import i2c_monitor
from EF_UVM.ref_model.ref_model import ref_model
from i2c_ref_model.i2c_ref_model import i2c_ref_model
from EF_UVM.ip_env.ip_coverage.ip_coverage import ip_coverage
from i2c_coverage.i2c_coverage import i2c_coverage
from EF_UVM.ip_env.ip_logger.ip_logger import ip_logger
from i2c_logger.i2c_logger import i2c_logger
from EF_UVM.bus_env.bus_seq_lib.write_read_regs import write_read_regs
from i2c_seq_lib.i2c_bus_seq_base import i2c_bus_seq_base


@cocotb.test()
async def module_top(dut):
    # profiler = cProfile.Profile()
    # profiler.enable()
    BUS_TYPE = cocotb.plusargs['BUS_TYPE']
    pif = i2c_if(dut)
    if BUS_TYPE == "APB":
        w_if = bus_apb_if(dut)
    elif BUS_TYPE == "AHB":
        w_if = bus_ahb_if(dut)
    elif BUS_TYPE == "WISHBONE":
        w_if = bus_wb_if(dut)
    else:
        uvm_fatal("module_top", f"unknown bus type {BUS_TYPE}")
    w_irq_if = bus_irq_if(dut)
    UVMConfigDb.set(None, "*", "ip_if", pif)
    UVMConfigDb.set(None, "*", "bus_if", w_if)
    UVMConfigDb.set(None, "*", "bus_irq_if", w_irq_if)
    yaml_file = []
    UVMRoot().clp.get_arg_values("+YAML_FILE=", yaml_file)
    yaml_file = yaml_file[0]
    regs = bus_regs(yaml_file)
    UVMConfigDb.set(None, "*", "bus_regs", regs)
    UVMConfigDb.set(None, "*", "irq_exist", regs.get_irq_exist())
    UVMConfigDb.set(None, "*", "collect_coverage", True)
    UVMConfigDb.set(None, "*", "disable_logger", False)
    test_path = []
    UVMRoot().clp.get_arg_values("+TEST_PATH=", test_path)
    test_path = test_path[0]
    await run_test()
    coverage_db.export_to_yaml(filename=f"{test_path}/coverage.yaml")
    # profiler.disable()
    # profiler.dump_stats("profile_result.prof")


class i2c_base_test(base_test):
    def __init__(self, name="i2c_first_test", parent=None):
        BUS_TYPE = cocotb.plusargs['BUS_TYPE']
        super().__init__(name, bus_type=BUS_TYPE, parent=parent)
        self.tag = name

    def build_phase(self, phase):
        super().build_phase(phase)
        # override
        self.set_type_override_by_type(ip_driver.get_type(), i2c_driver.get_type())
        self.set_type_override_by_type(ip_monitor.get_type(), i2c_monitor.get_type())
        self.set_type_override_by_type(ref_model.get_type(), i2c_ref_model.get_type())
        self.set_type_override_by_type(ip_coverage.get_type(), i2c_coverage.get_type())
        self.set_type_override_by_type(ip_logger.get_type(), i2c_logger.get_type())


uvm_component_utils(i2c_base_test)


class WriteReadRegsTest(i2c_base_test):
    def __init__(self, name="WriteReadRegsTest", parent=None):
        super().__init__(name, parent)
        self.tag = name

    async def main_phase(self, phase):
        uvm_info(self.tag, f"Starting test {self.__class__.__name__}", UVM_LOW)
        phase.raise_objection(self, f"{self.__class__.__name__} OBJECTED")
        bus_seq = i2c_bus_seq_base("i2c_bus_seq_base") # enable CLKgate
        await bus_seq.start(self.bus_sqr)
        bus_seq = write_read_regs()
        await bus_seq.start(self.bus_sqr)
        phase.drop_objection(self, f"{self.__class__.__name__} drop objection")


uvm_component_utils(WriteReadRegsTest)



class i2c_write_read_test(i2c_base_test):
    def __init__(self, name="i2c__first_test", parent=None):
        super().__init__(name, parent=parent)
        self.tag = name

    async def main_phase(self, phase):
        uvm_info(self.tag, f"Starting test {self.__class__.__name__}", UVM_LOW)
        phase.raise_objection(self, f"{self.__class__.__name__} OBJECTED")
        bus_seq = i2c_write_read_seq("i2c_write_read_seq")
        await bus_seq.start(self.bus_sqr)
        await Timer(10000 , "ns")
        phase.drop_objection(self, f"{self.__class__.__name__} drop objection")


uvm_component_utils(i2c_write_read_test)


class i2c_write_mul_test(i2c_base_test):
    def __init__(self, name="i2c_write_mul_test", parent=None):
        super().__init__(name, parent=parent)
        self.tag = name

    async def main_phase(self, phase):
        uvm_info(self.tag, f"Starting test {self.__class__.__name__}", UVM_LOW)
        phase.raise_objection(self, f"{self.__class__.__name__} OBJECTED")
        bus_seq = i2c_write_mul_seq("i2c_write_mul_seq")
        await bus_seq.start(self.bus_sqr)
        await Timer(10000 , "ns")
        phase.drop_objection(self, f"{self.__class__.__name__} drop objection")


uvm_component_utils(i2c_write_mul_test)
