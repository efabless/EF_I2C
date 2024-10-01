from uvm.base.uvm_component import UVMComponent
from uvm.macros import uvm_component_utils
from uvm.tlm1.uvm_analysis_port import UVMAnalysisImp
from uvm.base.uvm_object_globals import UVM_HIGH, UVM_LOW, UVM_MEDIUM 
from uvm.macros import uvm_component_utils, uvm_fatal, uvm_info
from uvm.base.uvm_config_db import UVMConfigDb
from uvm.tlm1.uvm_analysis_port import UVMAnalysisExport
import cocotb
from EF_UVM.ref_model.ref_model import ref_model
from EF_UVM.bus_env.bus_item import bus_item
from uvm.macros import uvm_component_utils, uvm_info, uvm_error, uvm_warning
from cocotb.queue import Queue, QueueFull


class i2c_ref_model(ref_model):
    """
    The reference model is a crucial element within the top-level verification environment, designed to validate the functionality and performance of both the IP (Intellectual Property) and the bus system. Its primary role is to act as a representative or mimic of the actual hardware components, including the IP and the bus. Key features and functions of the reference model include:
    1) Input Simulation: The reference model is capable of receiving the same inputs that would be provided to the actual IP and bus via connection with the monitors of the bus and IP.
    2) Functional Emulation: It emulates the behavior and responses of the IP and bus under test. By replicating the operational characteristics of these components, the reference model serves as a benchmark for expected performance and behavior.
    3) Output Generation: Upon receiving inputs, the reference model processes them in a manner akin to the real hardware, subsequently generating expected outputs. These outputs are essential for comparison in the verification process.
    4) Interface with Scoreboard: The outputs from the reference model, representing the expected results, are forwarded to the scoreboard. The scoreboard then compares these expected results with the actual outputs from the IP and bus for verification.
    5)Register Abstraction Layer (RAL) Integration: The reference model includes a RAL model that mirrors the register values of the RTL, ensuring synchronization between expected and actual register states. This model facilitates register-level tests and error detection, offering accessible and up-to-date register values for other verification components. It enhances the automation and coverage of register testing, playing a vital role in ensuring the accuracy and comprehensiveness of the verification process.
    """
    def __init__(self, name="i2c_ref_model", parent=None):
        super().__init__(name, parent)
        self.tag = name
        self.fifo_rx = TX_QUEUE(maxsize=16)
        self.i2c_slave0 = I2cSlave("i2c_slave0", queue = self.fifo_rx) # address 0b1010101
        self.i2c_slave1 = I2cSlave("i2c_slave1", queue = self.fifo_rx) # address 0b1010110
        
    def build_phase(self, phase):
        super().build_phase(phase)
        # Here adding any initialize for user classes for the model

    async def run_phase(self, phase):
        await super().run_phase(phase)
        # Here add the log to run when simulation starts

    def write_bus(self, tr):
        # Called when new transaction is received from the bus monitor
        # TODO: update the following logic to determine what to do with the received transaction
        uvm_info(self.tag, " Ref model recieved from bus monitor: " + tr.convert2string(), UVM_HIGH)
        td = tr.do_clone()
        if td.kind == bus_item.RESET:
            self.bus_bus_export.write(tr)
            uvm_info("Ref model", "reset from ref model", UVM_LOW)
            # TODO: write logic needed when reset is received
            #self.bus_bus_export.write(tr)
            return
        elif td.kind == bus_item.WRITE:
            if td.addr == self.regs.reg_name_to_address["Command"]:
                command = self.decode_command(td.data)
                self.slave = "slave0" if command[0] == 0b1010101 else "slave1" if command[0] == 0b1010110 else "unkown"
                if self.slave == "slave0":
                    self.i2c_slave0.set_new_command(command[1])
                elif self.slave == "slave1":
                    self.i2c_slave1.set_new_command(command[1])
                else:
                    uvm_error(self.tag, f"unkown slave address {command[0]}")
            elif td.addr == self.regs.reg_name_to_address["Data"]:
                if self.slave == "slave0":
                    self.i2c_slave0.set_new_data(td.data)
                elif self.slave == "slave1":
                    self.i2c_slave1.set_new_data(td.data)
                else:
                    uvm_error(self.tag, "unkown slave address")
            self.bus_bus_export.write(tr)
                
        elif td.kind == bus_item.READ:
            if td.addr == self.regs.reg_name_to_address["Data"]:
                td.data = self.fifo_rx.get_nowait() | (0b1 << 8) # add valid data bit
            self.bus_bus_export.write(td)  # this is output to the scoreboard

    def decode_command(self, command):
        slave_address = (command) & 0x7F
        stop = (command >> 12) & 0x1
        access = "write" if (command >> 10) & 0x1 else "read" if (command >> 9) & 0x1 else "unkown"
        write_mul = (command >> 11) & 0x1
        uvm_info(self.tag, f"slave_address = {slave_address}, stop = {stop}, access = {access}, write_mul = {write_mul}", UVM_LOW)
        if stop:
            return (slave_address, "stop")
        elif write_mul:
            return (slave_address, "write_multiple")
        else:
            return (slave_address, access)
        
    def write_ip(self, tr):
        # Called when new transaction is received from the ip monitor
        # TODO: write what to do when new transaction ip transaction is received
        uvm_info(self.tag, "Ref model recieved from ip monitor: " + tr.convert2string(), UVM_HIGH)        
        # Here the ref model should predict the transaction and send it to scoreboard 
        #self.ip_export.write(td) # this is output ro scoreboard

uvm_component_utils(i2c_ref_model)

class I2cSlave:
    def __init__(self, name="i2c_slave", queue = None):
        self.name = name
        self.memory = [0] * 256         # the address is 8 bits (sent once for simplicity) 
        self.current_address = 0
        self.current_data = 0
        self.mem = I2cSlave.MemoryBlock()
        self.state = "idle"
        self.queue = queue

    def set_new_command(self, command):
        self.command = command
        if command == "stop":
            self.state = "idle"
            uvm_info("I2cSlave", "stop command received", UVM_LOW)
        elif command == "write" and self.state == "idle":
            self.state = "address1"
        elif command == "read":
            self.process()
        elif command == "write_multiple":
            pass
    def set_new_data(self, data):
        if self.command == "write":
            self.new_data = data
            self.process()
        elif self.command == "read":
            pass
        elif self.command == "stop":
            pass
        elif self.command == "write_multiple":
            self.new_data = data
            self.process()

    def process(self):
        if self.state == "address1":
            self.addr_counter = 0
            self.address = self.new_data & 0x1F
            self.state = "address0"
        elif self.state == "address0":
            self.addr_counter = 0
            self.address = (self.address << 8) | (self.new_data & 0xFF)
            uvm_info("I2cSlave", f"address = {hex(self.address)}", UVM_LOW)
            self.state = "access"
        elif self.state == "access":
            if self.command == "read":
                data = self.mem.read(self.address + self.addr_counter)
                try:
                    self.queue.put_nowait(data)
                    uvm_info(
                        "I2cSlave",
                        f"value {hex(data)} written to tx fifo size = {self.queue.qsize()}",
                        UVM_MEDIUM,
                    )
                except QueueFull:
                    uvm_warning(
                        "I2cSlave",
                        f"writing to tx while fifo is full so ignore the value {hex(data)}",
                    )
            elif self.command in ["write", "write_multiple"]:
                self.mem.write(self.address + self.addr_counter, self.new_data)
            self.addr_counter += 1

    class MemoryBlock:
        """
        A class to model an EEPROM data memory array with 8192 (0 to 8191) 8-bit memory locations.
        """

        def __init__(self, size=8192, bit_width=8):
            """
            Initialize the memory block.

            :param size: Number of memory locations. Default is 8192.
            :param bit_width: Bit width of each memory location. Default is 8 bits.
            """
            self.size = size
            self.bit_width = bit_width
            self.max_value = (1 << bit_width) - 1  # Maximum value based on bit width
            self.memory = [0] * self.size  # Initialize memory with zeros

        def read(self, address):
            """
            Read the value from a specific memory address.

            :param address: Memory address to read from (0 to size-1).
            :return: Value at the specified memory address.
            :raises ValueError: If the address is out of bounds.
            """
            if 0 <= address < self.size:
                value = self.memory[address]
                uvm_info("MemoryBlock",f"Read from address {hex(address)}: {hex(value)}", UVM_LOW)
                return value
            else:
                raise ValueError(f"Invalid address {address}. Must be between 0 and {self.size - 1}.")

        def write(self, address, value):
            """
            Write a value to a specific memory address.

            :param address: Memory address to write to (0 to size-1).
            :param value:  Value to write (0 to max_value based on bit width).
            :raises ValueError: If the address or value is out of bounds.
            """
            if not (0 <= address < self.size):
                raise ValueError(f"Invalid address {address}. Must be between 0 and {self.size - 1}.")
            if not (0 <= value <= self.max_value):
                raise ValueError(f"Invalid value {value}. Must be between 0 and {self.max_value}.")
            self.memory[address] = value
            uvm_info("MemoryBlock",f"Wrote value {hex(value)} to address {hex(address)}.", UVM_LOW)




class TX_QUEUE(Queue):
    """same queue provided by cocotb but with 2 new functions to get the tx value send it and then pop it from the queue after sending"""

    def __init__(self, maxsize: int = 0):
        super().__init__(maxsize)

    async def get_no_pop(self):
        """same as get but without popping it from the queue"""
        while self.empty():
            event = Event("{} get".format(type(self).__name__))
            self._getters.append((event, cocotb.scheduler._current_task))
            await event.wait()
        return self._queue[0]