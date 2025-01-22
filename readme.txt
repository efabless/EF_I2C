/*
	Copyright 2024 Efabless Corp.

	Author: Efabless Corp. (ip_admin@efabless.com)

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	    http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.

*/

IP_name: EF_I2C
Author: Efabless
Directory Structure:

    - fw 
        - **EF_I2C_regs.h**: Header file containing the register definitions for the EF_I2C interface.

    - hdl 
        - rtl 
            - **axis_fifo.v**: Verilog source code for the EF_I2C design.
            - **i2c_init.v**: Verilog source code for the EF_I2C design.
            - **i2c_master_axil.v**: Verilog source code for the EF_I2C design.
            - **i2c_master_wbs_8.v**: Verilog source code for the EF_I2C design.
            - **i2c_master_wbs_16.v**: Verilog source code for the EF_I2C design.
            - **i2c_master.v**: Verilog source code for the EF_I2C design.
            - **i2c_single_reg.v**: Verilog source code for the EF_I2C design.
            - **i2c_slave_axil_master.v**: Verilog source code for the EF_I2C design.
            - **i2c_slave_wbm.v**: Verilog source code for the EF_I2C design.
            - **i2c_slave.v**: Verilog source code for the EF_I2C design.
            - **bus_wrappers**
                - **EF_I2C_APB.v**: Verilog wrapper to interface the EF_I2C with the Advanced Peripheral Bus (APB) protocol.
                - **EF_I2C_WB.v**: Verilog wrapper to interface the EF_I2C with the Wishbone bus protocol.
            - **dft**
                - **EF_I2C_APB_DFT.v**: Verilog wrapper with DFT support specific to the APB interface of the EF_I2C.
                - **EF_I2C_WB_DFT.v**: Verilog wrapper with DFT support specific to the Wishbone interface of the EF_I2C.

    - ip 
        - **dependencies.json**: Used by IPM [Do NOT EDIT OR DELETE].
    
    - **EF_I2C.pdf**: Comprehensive documentation for the EF_I2C, including its features, configuration, and usage.