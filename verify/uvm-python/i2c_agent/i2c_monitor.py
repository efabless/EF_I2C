from uvm.macros import uvm_component_utils, uvm_fatal, uvm_info, uvm_error, uvm_warning
from uvm.comps.uvm_monitor import UVMMonitor
from uvm.tlm1.uvm_analysis_port import UVMAnalysisPort
from uvm.base.uvm_config_db import UVMConfigDb
from cocotb.triggers import Timer, ClockCycles, FallingEdge, Event, RisingEdge, Combine, First
from uvm.base.uvm_object_globals import UVM_HIGH, UVM_LOW, UVM_MEDIUM
import cocotb
import math
import copy
from EF_UVM.ip_env.ip_agent.ip_monitor import ip_monitor
from i2c_item.i2c_item import i2c_item


class i2c_monitor(ip_monitor):
    def __init__(self, name="i2c_monitor", parent=None):
        super().__init__(name, parent)
        self.data_byte = 0

    async def run_phase(self, phase):
        uvm_info(self.tag, "run_phase started", UVM_LOW)
        await self.sample_i2c()
        # await cocotb.start(self.sample_i2c())
        # await cocotb.start(self.check_stop_condition())
        # use self.vif.<signal name> for monitoring interface signals
        # self.monitor_port.write(tr) # this is the port to send the transaction after sampling it


    async def sample_i2c(self):
        return
        await RisingEdge (self.vif.RESETn)
        while(True):
            data = []
            address = 0
            tr = i2c_item.type_id.create("tr", self) 
            await FallingEdge(self.vif.sda_pin)             # start condition 
            for i in range (6, -1, -1):                     # 7-bit address
                await RisingEdge(self.vif.scl_pin)
                address |= self.vif.sda_pin.value << i 
            
            uvm_info (self.tag, f"slave address  = 0x{address:X}", UVM_LOW)

            await RisingEdge(self.vif.scl_pin)
            read_or_write = self.vif.sda_pin.value             # R/W bit read (1) or write (0)


            await RisingEdge(self.vif.scl_pin)
            address_nack = self.vif.sda_pin.value              # NACK/ACK bit  ack(0) or nack(1)
            if (address_nack):
                uvm_fatal (self.tag, "Recieved Nack from slave in address frame")


            while (True):
                self.data_byte = 0
                await FallingEdge(self.vif.sda_pin)             # start of a new frame 

                await RisingEdge (self.vif.scl_pin)             # at the rising edge of scl , read the msb of data byte and update self.data_byte
                self.update_data_byte(7)

                scl_risingEdge = RisingEdge(self.vif.scl_pin)   
                sda_risingEdge = RisingEdge(self.vif.sda_pin)
                first_event = await First (scl_risingEdge, sda_risingEdge)      
                uvm_info (self.tag, f"first event {first_event}", UVM_LOW)
                if (first_event == sda_risingEdge and self.vif.scl_pin.value == 1): # if the sda pin had a rising edge first while scl was high , this means a stop condition 
                    tr.slave_address = address
                    tr.data = copy.copy(data)
                    tr.read_or_write = "read" if read_or_write else "write"
                    uvm_info (self.tag, "sampled i2c" + tr.convert2string(), UVM_LOW)
                    self.monitor_port.write(tr)
                    break
                elif (first_event == scl_risingEdge):            # if it is not a stop condition, read the second MSB and update data item
                    self.update_data_byte(6)    

                for i in range (5, -1, -1):                     # get the remaining 6 data bits 
                    await RisingEdge(self.vif.scl_pin)
                    self.update_data_byte(i)

                
                uvm_info (self.tag, f"data item {len(data)}  = 0x{self.data_byte:X}", UVM_LOW)
                
                await RisingEdge(self.vif.scl_pin)
                data_nack = self.vif.sda_pin.value                 # NACK/ACK bit  ack(0) or nack(1)
                if (data_nack):
                    uvm_fatal (self.tag, "Recieved Nack from slave in data frame")

                
                data.append(self.data_byte)


    def update_data_byte (self, i):
        self.data_byte |= self.vif.sda_pin.value << i 

    
            

uvm_component_utils(i2c_monitor)
