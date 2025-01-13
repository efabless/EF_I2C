/*
	Copyright 2025 Efabless Corp.


	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	    www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.

*/


/*! \file EF_I2C.h
    \brief C header file for I2C APIs which contains the function prototypes 
    
*/

#ifndef EF_I2C_H
#define EF_I2C_H

/******************************************************************************
* Includes
******************************************************************************/
#include "EF_I2C_regs.h"
#include "EF_Driver_Common.h"


/******************************************************************************
* Macros and Constants
******************************************************************************/

/******************************************************************************
* Typedefs and Enums
******************************************************************************/

/******************************************************************************
* Function Prototypes
******************************************************************************/


EF_DRIVER_STATUS EF_I2C_setGclkEnable (EF_I2C_PTR i2c, uint32_t value);
EF_DRIVER_STATUS EF_I2C_writeAddress(EF_I2C_PTR i2c, char addr);
EF_DRIVER_STATUS EF_I2C_startCmd(EF_I2C_PTR i2c);
EF_DRIVER_STATUS EF_I2C_readCmd(EF_I2C_PTR i2c, char addr);
EF_DRIVER_STATUS EF_I2C_writeCmd(EF_I2C_PTR i2c, char addr);
EF_DRIVER_STATUS EF_I2C_writeMultipleCmd(EF_I2C_PTR i2c);
EF_DRIVER_STATUS EF_I2C_stopCmd(EF_I2C_PTR i2c);
EF_DRIVER_STATUS EF_I2C_setCommandReg(EF_I2C_PTR i2c, uint32_t value);
EF_DRIVER_STATUS EF_I2C_getCommandReg(EF_I2C_PTR i2c, uint32_t* command_value);
EF_DRIVER_STATUS EF_I2C_writeData(EF_I2C_PTR i2c, char data);
EF_DRIVER_STATUS EF_I2C_readData(EF_I2C_PTR i2c, char *data);
EF_DRIVER_STATUS EF_I2C_setDataValid(EF_I2C_PTR i2c, bool valid);
EF_DRIVER_STATUS EF_I2C_getDataValid(EF_I2C_PTR i2c, bool *data_valid);
EF_DRIVER_STATUS EF_I2C_setDataLast(EF_I2C_PTR i2c, bool valid);
EF_DRIVER_STATUS EF_I2C_getDataLast(EF_I2C_PTR i2c, bool *data_last);
EF_DRIVER_STATUS EF_I2C_setDataReg(EF_I2C_PTR i2c, uint32_t value);
EF_DRIVER_STATUS EF_I2C_getDataReg(EF_I2C_PTR i2c, uint32_t* data_reg_value);
EF_DRIVER_STATUS EF_I2C_setPrescaler(EF_I2C_PTR i2c, uint32_t value);
EF_DRIVER_STATUS EF_I2C_getPrescaler(EF_I2C_PTR i2c, uint32_t* prescaler_value);
EF_DRIVER_STATUS EF_I2C_getRIS(EF_I2C_PTR i2c, uint32_t* ris_value);
EF_DRIVER_STATUS EF_I2C_getMIS(EF_I2C_PTR i2c, uint32_t* mis_value);
EF_DRIVER_STATUS EF_I2C_setIM(EF_I2C_PTR i2c, uint32_t mask);
EF_DRIVER_STATUS EF_I2C_getIM(EF_I2C_PTR i2c, uint32_t* im_value);

/******************************************************************************
* External Variables
******************************************************************************/



#endif // EF_I2C_H

/******************************************************************************
* End of File
******************************************************************************/
