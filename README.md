# EF_I2C

I2C master controller with an APB and wishbone interfaces
## The wrapped IP


 The IP comes with APB and wishbone Wrappers

#### Wrapped IP System Integration
Based on your use case, use one of the provided wrappers or create a wrapper for your system bus type. For an example of how to integrate the wishbone wrapper:

```verilog
EF_I2C_WB INST (
	.clk_i(clk_i),
	.rst_i(rst_i),
	.adr_i(adr_i),
	.dat_i(dat_i),
	.dat_o(dat_o),
	.sel_i(sel_i),
	.cyc_i(cyc_i),
	.stb_i(stb_i),
	.ack_o(ack_o),
	.we_i(we_i), 
	.IRQ(irq),
	.scl_i(scl_i),
	.scl_o(scl_o),
	.scl_oen_o(scl_oen_o),
	.sda_i(sda_i),
	.sda_o(sda_o),
	.sda_oen_o(sda_oen_o)
);
```

#### Wrappers with DFT support
Wrappers in the directory ``/hdl/rtl/bus_wrappers/DFT`` have an extra input port ``sc_testmode`` to disable the clock gate whenever the scan chain testmode is enabled.

## Implementation example  

The following table is the result for implementing the EF_I2C IP with different wrappers using Sky130 PDK and [OpenLane2](https://github.com/efabless/openlane2) flow.
|Module | Number of cells | Max. freq |
|---|---|---|
|EF_I2C|TBD| TBD |
|EF_I2C_APB|TBD|TBD|
## The Programmer's Interface


### Registers

|Name|Offset|Reset Value|Access Mode|Description|
|---|---|---|---|---|
|Command|0004|0x00000000|w|bit 0-6: cmd_address, bit 8: cmd_start, bit 9: cmd_read, bit 10: cmd_write, bit 11: cmd_wr_m, bit 12: cmd_stop. Setting more than one command bit is allowed.  Start or repeated start will be issued first, followed by read or write, followed by stop.  Note that setting read and write at the same time is not allowed, this will result in the command being ignored.|
|Data|0008|0x00000000|w/r|bit 0-7: data, bit 8: data_valid, bit 9: data_last|
|PR|000c|0x00000000|w|prescale = Fclk / (FI2Cclk * 4)|
|IM|ff00|0x00000000|w|Interrupt Mask Register; write 1/0 to enable/disable interrupts; check the interrupt flags table for more details|
|RIS|ff08|0x00000000|w|Raw Interrupt Status; reflects the current interrupts status;check the interrupt flags table for more details|
|MIS|ff04|0x00000000|w|Masked Interrupt Status; On a read, this register gives the current masked status value of the corresponding interrupt. A write has no effect; check the interrupt flags table for more details|
|IC|ff0c|0x00000000|w|Interrupt Clear Register; On a write of 1, the corresponding interrupt (both raw interrupt and masked interrupt, if enabled) is cleared; check the interrupt flags table for more details|
|GCLK|ff10|0x00000000|w|Gated clock enable; 1: enable clock, 0: disable clock|

### Command Register [Offset: 0x4, mode: w]

bit 0-6: cmd_address, bit 8: cmd_start, bit 9: cmd_read, bit 10: cmd_write, bit 11: cmd_wr_m, bit 12: cmd_stop. Setting more than one command bit is allowed.  Start or repeated start will be issued first, followed by read or write, followed by stop.  Note that setting read and write at the same time is not allowed, this will result in the command being ignored.
<img src="https://svg.wavedrom.com/{reg:[{name:'cmd_address', bits:7},{bits: 1},{name:'cmd_start', bits:1},{name:'cmd_read', bits:1},{name:'cmd_write', bits:1},{name:'cmd_write_multiple', bits:1},{name:'cmd_stop', bits:1},{bits: 19}], config: {lanes: 2, hflip: true}} "/>

|bit|field name|width|description|
|---|---|---|---|
|0|cmd_address|7|I2C address for command|
|8|cmd_start|1|set high to issue I2C start, write to push on command FIFO|
|9|cmd_read|1|set high to start read, write to push on command FIFO|
|10|cmd_write|1|set high to start write, write to push on command FIFO|
|11|cmd_write_multiple|1|set high to start block write, write to push on command FIFO|
|12|cmd_stop|1|set high to issue I2C stop, write to push on command FIFO|

### Data Register [Offset: 0x8, mode: w/r]

bit 0-7: data, bit 8: data_valid, bit 9: data_last
<img src="https://svg.wavedrom.com/{reg:[{name:'data', bits:8},{name:'data_valid', bits:1},{name:'data_last', bits:1},{bits: 22}], config: {lanes: 2, hflip: true}} "/>

|bit|field name|width|description|
|---|---|---|---|
|0|data|8| I2C data, write to push on write data FIFO, read to pull from read data FIFO|
|8|data_valid|1|indicates valid read data, must be accessed with atomic 16 bit reads and writes|
|9|data_last|1|indicate last byte of block write (write_multiple), must be accessed with atomic 16 bit reads and writes|

### PR Register [Offset: 0xc, mode: w]

prescale = Fclk / (FI2Cclk * 4)
<img src="https://svg.wavedrom.com/{reg:[{name:'PR', bits:16},{bits: 16}], config: {lanes: 2, hflip: true}} "/>

### GCLK Register [Offset: 0xff10, mode: w]

 Gated clock enable register
<img src="https://svg.wavedrom.com/{reg:[{name:'gclk_enable', bits:1},{bits: 31}], config: {lanes: 2, hflip: true}} "/>

|bit|field name|width|description|
|---|---|---|---|
|0|gclk_enable|1|Gated clock enable; 1: enable clock, 0: disable clock|


### Interrupt Flags

The wrapped IP provides four registers to deal with interrupts: IM, RIS, MIS and IC. These registers exist for all wrapper types.

Each register has a group of bits for the interrupt sources/flags.
- `IM` [offset: 0xff00]: is used to enable/disable interrupt sources.

- `RIS` [offset: 0xff08]: has the current interrupt status (interrupt flags) whether they are enabled or disabled.

- `MIS` [offset: 0xff04]: is the result of masking (ANDing) RIS by IM.

- `IC` [offset: 0xff0c]: is used to clear an interrupt flag.


The following are the bit definitions for the interrupt registers:

|Bit|Flag|Width|Description|
|---|---|---|---|
|0|MISS_ACK|1|Slave ACK is missed|
|1|CMDE|1|Command FIFO is Empty|
|2|CMDF|1|Command FIFO is Full|
|3|CMDOVF|1|Command FIFO overflow; write 1 to clear|
|4|WRE|1|Write FIFO is Empty|
|5|WRF|1|Write FIFO is Full|
|6|WROVF|1|Write FIFO overflow; write 1 to clear|
|7|RDE|1|Read FIFO is Empty|
|8|RDF|1|Read FIFO is Full|
### Clock Gating
The IP has clock gating feature, enabling the selective activation and deactivation of the clock as required through the ``GCLK`` register. This functionality is implemented through the ``ef_util_gating_cell``, which is part of the the common modules library, [ef_util_lib.v](https://github.com/efabless/EF_IP_UTIL/blob/main/hdl/ef_util_lib.v). By default, the cell operates with a behavioral implementation, but when the ``CLKG_SKY130_HD`` macro is enabled, the ``sky130_fd_sc_hd__dlclkp_4`` clock gating cell is used.

**Note:** If you choose the [OpenLane2](https://github.com/efabless/openlane2) flow for implementation and would like to add the clock gating feature, you need to add ``CLKG_SKY130_HD`` macro to the ``VERILOG_DEFINES`` configuration variable. Update the YAML configuration file as follows: 
```
VERILOG_DEFINES:
- CLKG_SKY130_HD
```

### The Interface 

<img src="docs/_static/EF_I2C.svg" width="600"/>

#### Module Parameters 

|Parameter|Description|Default Value|
|---|---|---|
|DEFAULT_PRESCALE|Default value for Prescale; prescale = Fclk / (FI2Cclk * 4)|1|
|FIXED_PRESCALE|Prescale value is fixed or could be dynamically configured|0|
|CMD_FIFO|Command AXI4 FIFO enable|1|
|CMD_FIFO_DEPTH|Command AXI4 FIFO depth|32|
|WRITE_FIFO|Write AXI4 FIFO enable|1|
|WRITE_FIFO_DEPTH|Write AXI4 FIFO depth|32|
|READ_FIFO|Read AXI4 FIFO enable|1|
|READ_FIFO_DEPTH|Read AXI4 FIFO depth|32|

#### Ports 

|Port|Direction|Width|Description|
|---|---|---|---|
|scl_i|input|1|i2c scl (Serial Clock) input|
|scl_o|output|1|i2c scl (Serial Clock) output|
|scl_oen_o|output|1|i2c scl (Serial Clock) output enable|
|sda_i|input|1|i2c scl (Serial Data) input|
|sda_o|output|1|i2c scl (Serial Data) output|
|sda_oen_o|output|1|i2c scl (Serial Data) output enable|
|i2c_irq|output|1|i2c interrupt|
|wbs_adr_i|input|3|wishbone input address|
|wbs_dat_i|input|16|wishbone input data|
|wbs_dat_o|output|16|wishbone data out|
|wbs_we_i|input|1|wishbone write enable|
|wbs_sel_i|input|2|wishbone select|
|wbs_stb_i|input|1|wishbone chip select|
|wbs_ack_o|output|1|wishbone acknowledge|
|wbs_cyc_i|input|1|wishbone bus cycle|
|i2c_scl_i|input|1|i2c scl (Serial Clock) input|
|i2c_scl_o|output|1|i2c scl (Serial Clock) output|
|i2c_scl_t|output|1|i2c scl (Serial Clock) tristate|
|i2c_sda_i|input|1|i2c scl (Serial Data) input|
|i2c_sda_o|output|1|i2c scl (Serial Data) output|
|i2c_sda_t|output|1|i2c scl (Serial Data) tristate|
|flags|output|16|i2c flags|
## Firmware Drivers:
Firmware drivers for EF_I2C can be found in the [fw](https://github.com/efabless/EF_I2C/tree/main/fw) directory. EF_I2C driver documentation  is available [here](https://github.com/efabless/EF_I2C/blob/main/fw/README.md).
You can also find an example C application using the EF_I2C drivers [here]().
## Installation:
You can either clone repo or use [IPM](https://github.com/efabless/IPM) which is an open-source IPs Package Manager
* To clone repo:
```git clone https://https://github.com/efabless/EF_I2C```
> **Note:** If you choose this method, you need to clone [EF_IP_UTIL](https://github.com/efabless/EF_IP_UTIL.git) repository, as it includes required modules from the common modules library, [ef_util_lib.v](https://github.com/efabless/EF_IP_UTIL/blob/main/hdl/ef_util_lib.v)
* To download via IPM , follow installation guides [here](https://github.com/efabless/IPM/blob/main/README.md) then run 
```ipm install EF_I2C```
> **Note:** This method is recommended as it automatically installs [EF_IP_UTIL](https://github.com/efabless/EF_IP_UTIL.git) as a dependency.
