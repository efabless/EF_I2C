from uvm.macros import uvm_component_utils, uvm_fatal, uvm_info, uvm_warning
from uvm.base.uvm_config_db import UVMConfigDb
from uvm.base.uvm_object_globals import UVM_HIGH, UVM_LOW, UVM_MEDIUM
from cocotb.triggers import Timer, ClockCycles, FallingEdge, Event, RisingEdge, First
from cocotb.binary import BinaryValue
import cocotb
import random
from EF_UVM.ip_env.ip_agent.ip_driver import ip_driver
from i2c_item.i2c_item import i2c_item


class i2c_driver(ip_driver):
    def __init__(self, name="i2c_driver", parent=None):
        super().__init__(name, parent)
        self.tag = name
        self.slave_1 = i2c_slave("slave_1", address = 0x12)
        self.slave_2 = i2c_slave("slave_2", address = 0x34)
        self.slave_3 = i2c_slave("slave_3", address = 0x56)

    async def run_phase(self, phase):
        return
        uvm_info(self.tag, "run_phase started", UVM_LOW)
        while True:
            address = 0
            tr = []
            await self.seq_item_port.get_next_item(tr)
            tr = tr[0]

            for i in range (6, -1, -1):                 # read address to check if it is one of the slave's addresses 
                await RisingEdge(self.vif.scl_pin)
                address |= self.vif.sda_pin.value << i 

            
            await RisingEdge(self.vif.scl_pin)
            read_or_write = self.vif.sda_pin.value             # R/W bit read (1) or write (0)

            
            current_slave = self.get_slave(address)     # send address frame ack if the address sent is valid 
            if (current_slave):     
                await self.send_ack()                   


            if (read_or_write == 0): # a write transaction
                address_byte = True 
                for i in range (0, len(tr.data)):
                    if address_byte:
                        await self.send_ack() 
                        current_slave.set_current_address(tr.data[i])
                        address_byte = False
                    else:
                    # await self.send_two_acks()                # send an ack after each of the two data frames (address then data)
                        await self.send_ack()
                        current_slave.write_to_slave(tr.data[i])
                        address_byte = True

            else:
                for data_byte in tr.data:
                    for i in range (7, -1, -1):             # drive sda from data byte 
                        await FallingEdge(self.vif.scl_pin)
                        self.vif.sda_pin.value = (data_byte >> i ) & 0b1


            self.seq_item_port.item_done()
                

    async def send_ack(self):
        await FallingEdge(self.vif.scl_pin)
        for i in range (4):
            await RisingEdge(self.vif.CLK)
        self.vif.sda_pin.value = 0              # send Ack bit 
        
        await FallingEdge(self.vif.scl_pin)
        for i in range (4):
            await RisingEdge(self.vif.CLK)
        
        self.vif.sda_pin.value = 1              # release ack 

    def get_slave (self, address):
        if(address == self.slave_1.address):
            uvm_info (self.tag, f"Slave address  = 0x{address:X} , Driver will send Ack", UVM_LOW)
            return self.slave_1
        elif(address == self.slave_2.address):
            uvm_info (self.tag, f"Slave address  = 0x{address:X} , Driver will send Ack", UVM_LOW)
            return self.slave_2
        elif(address == self.slave_3.address):
            uvm_info (self.tag, f"Slave address  = 0x{address:X} , Driver will send Ack", UVM_LOW)
            return self.slave_3
        else:
            uvm_warning (self.tag, f"Slave address sent = 0x{address:X} while available slave addresses are 0x{self.slave_1.address:X}, 0x{self.slave_2.address:X}, 0x{self.slave_3.address:X}")
            return False

    async def send_two_acks(self):
        for _ in range (8):             # wait until the data bits are sent  (memory address/index)
            await RisingEdge(self.vif.scl_pin)
        await self.send_ack()           # send data frame ack 

        for _ in range (8):             # wait until the data bits are sent (data)
            await RisingEdge(self.vif.scl_pin)
        await self.send_ack()           # send data frame ack 



uvm_component_utils(i2c_driver)


class i2c_slave ():

    def __init__(self, name="i2c_slave", address=0):
        self.name = name
        self.address = address
        self.memory = [0] * 256         # the address is 8 bits (sent once for simplicity) 
        self.current_address = 0
    
    def set_current_address(self, address):
        self.current_address = address
    
    def write_to_slave (self, data):
        if (self.current_address > 255 or self.current_address < 0):
            uvm_fatal(self.tag, "Memory address is not valid. Please send address between 0 and 255")
        self.memory[self.current_address] = data
        uvm_info (self.name, f"Writing 0x{data:X} in memory address {self.current_address}", UVM_LOW)

    def read_from_slave (self):
        return self.memory[self.current_address]


