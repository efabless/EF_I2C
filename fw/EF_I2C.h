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


void EF_I2C_setGclkEnable (uint32_t i2c_base, int value);
void EF_I2C_writeAddress(uint32_t i2c_base, char addr);
void EF_I2C_startCmd(uint32_t i2c_base);
void EF_I2C_readCmd(uint32_t i2c_base, char addr);
void EF_I2C_writeCmd(uint32_t i2c_base, char addr);
void EF_I2C_writeMultipleCmd(uint32_t i2c_base);
void EF_I2C_stopCmd(uint32_t i2c_base);
void EF_I2C_setCommandReg(uint32_t i2c_base, int value);
int EF_I2C_getCommandReg(uint32_t i2c_base);
void EF_I2C_writeData(uint32_t i2c_base, char data);
char EF_I2C_readData(uint32_t i2c_base);
void EF_I2C_setDataValid(uint32_t i2c_base, bool valid);
bool EF_I2C_getDataValid(uint32_t i2c_base);
void EF_I2C_setDataLast(uint32_t i2c_base, bool valid);
bool EF_I2C_getDataLast(uint32_t i2c_base);
void EF_I2C_setDataReg(uint32_t i2c_base, int value);
int EF_I2C_getDataReg(uint32_t i2c_base);
void EF_I2C_setPrescaler(uint32_t i2c_base, int value);
int EF_I2C_getPrescaler(uint32_t i2c_base);
int EF_I2C_getRIS(uint32_t i2c_base);
int EF_I2C_getMIS(uint32_t i2c_base);
void EF_I2C_setIM(uint32_t i2c_base, int mask);
int EF_I2C_getIM(uint32_t i2c_base);

/******************************************************************************
* External Variables
******************************************************************************/



#endif // EF_I2C_H

/******************************************************************************
* End of File
******************************************************************************/
