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


/*! \file EF_I2C.c
    \brief C header file for I2C APIs which contains the function implementations 
    
*/

#ifndef EF_I2C_C
#define EF_I2C_C

/******************************************************************************
* Includes
******************************************************************************/
#include "EF_I2C.h"

/******************************************************************************
* File-Specific Macros and Constants
******************************************************************************/



/******************************************************************************
* Static Variables
******************************************************************************/



/******************************************************************************
* Static Function Prototypes
******************************************************************************/



/******************************************************************************
* Function Definitions
******************************************************************************/


EF_DRIVER_STATUS EF_I2C_setGclkEnable (EF_I2C_TYPE_PTR i2c, uint32_t value){
    
    i2c->GCLK = value;
}

EF_DRIVER_STATUS EF_I2C_writeToAddress(EF_I2C_TYPE_PTR i2c, char addr, char data){

    EF_I2C_writeData(i2c, data);
    EF_I2C_writeCmd(i2c, addr);
    EF_I2C_stopCmd(i2c);
    EF_I2C_waitBusy(i2c);
}

EF_DRIVER_STATUS EF_I2C_readCommand(EF_I2C_TYPE_PTR i2c, char addr){

    EF_I2C_readCmd(i2c, addr);
    EF_I2C_stopCmd(i2c);
    EF_I2C_waitBusy(i2c);
}


EF_DRIVER_STATUS EF_I2C_writeAddress(EF_I2C_TYPE_PTR i2c, char addr){

    // Clear the field bits in the register using the defined mask
    uint32_t command =  i2c->COMMAND & ~EF_I2C_COMMAND_REG_CMD_ADDRESS_MASK;

    // Set the bits with the given value at the defined offset
    i2c->COMMAND = command | ((addr << EF_I2C_COMMAND_REG_CMD_ADDRESS_BIT) & EF_I2C_COMMAND_REG_CMD_ADDRESS_MASK);
}


EF_DRIVER_STATUS EF_I2C_startCmd(EF_I2C_TYPE_PTR i2c){
    
    i2c->COMMAND |= ((1 << EF_I2C_COMMAND_REG_CMD_START_BIT) & EF_I2C_COMMAND_REG_CMD_START_MASK);
}


EF_DRIVER_STATUS EF_I2C_readCmd(EF_I2C_TYPE_PTR i2c, char addr){
    
    i2c->COMMAND = ((addr << EF_I2C_COMMAND_REG_CMD_ADDRESS_BIT ) | EF_I2C_COMMAND_REG_CMD_READ_MASK);
}



EF_DRIVER_STATUS EF_I2C_writeCmd(EF_I2C_TYPE_PTR i2c, char addr){
    
    i2c->COMMAND = ((addr << EF_I2C_COMMAND_REG_CMD_ADDRESS_BIT) | EF_I2C_COMMAND_REG_CMD_WRITE_MASK);
}



EF_DRIVER_STATUS EF_I2C_writeMultipleCmd(EF_I2C_TYPE_PTR i2c){

    i2c->COMMAND |= ((1 << EF_I2C_COMMAND_REG_CMD_WRITE_MULTIPLE_BIT) & EF_I2C_COMMAND_REG_CMD_WRITE_MULTIPLE_MASK);
}



EF_DRIVER_STATUS EF_I2C_stopCmd(EF_I2C_TYPE_PTR i2c){
    
    i2c->COMMAND = ((1 << EF_I2C_COMMAND_REG_CMD_STOP_BIT) & EF_I2C_COMMAND_REG_CMD_STOP_MASK);
}




EF_DRIVER_STATUS EF_I2C_setCommandReg(EF_I2C_TYPE_PTR i2c, uint32_t value){

    i2c->COMMAND = value;
}



EF_DRIVER_STATUS EF_I2C_getCommandReg(EF_I2C_TYPE_PTR i2c, uint32_t* command_value){

    *command_value = i2c->COMMAND;
}



EF_DRIVER_STATUS EF_I2C_writeData(EF_I2C_TYPE_PTR i2c, char data){

    // Clear the field bits in the register using the defined mask
    // i2c->DATA &= ~EF_I2C_DATA_REG_DATA_MASK;

    // Set the bits with the given value at the defined offset
    
    i2c->DATA = ((data << EF_I2C_DATA_REG_DATA_BIT) & EF_I2C_DATA_REG_DATA_MASK);
}



EF_DRIVER_STATUS EF_I2C_readData(EF_I2C_TYPE_PTR i2c, char *data){
    
    *data = i2c->DATA;
    bool valid = (*data & EF_I2C_DATA_REG_DATA_VALID_MASK) >> EF_I2C_DATA_REG_DATA_VALID_BIT;
    if (valid){
        *data = (*data & EF_I2C_DATA_REG_DATA_MASK) >> EF_I2C_DATA_REG_DATA_BIT;
    }else{
        *data = -1;
    }
}



EF_DRIVER_STATUS EF_I2C_setDataValid(EF_I2C_TYPE_PTR i2c, bool valid){

    if (valid)
        i2c->DATA |= ((1 << EF_I2C_DATA_REG_DATA_VALID_BIT) & EF_I2C_DATA_REG_DATA_VALID_MASK);
    else
        i2c->DATA &= ~EF_I2C_DATA_REG_DATA_VALID_MASK;
}



EF_DRIVER_STATUS EF_I2C_getDataValid(EF_I2C_TYPE_PTR i2c, bool *data_valid){

    if ((i2c->DATA & EF_I2C_DATA_REG_DATA_VALID_MASK) >> EF_I2C_DATA_REG_DATA_VALID_BIT)
        *data_valid = true;
    else
        *data_valid = false;
}



EF_DRIVER_STATUS EF_I2C_setDataLast(EF_I2C_TYPE_PTR i2c, bool valid){

    if (valid)
        i2c->DATA |= ((1 << EF_I2C_DATA_REG_DATA_LAST_BIT) & EF_I2C_DATA_REG_DATA_LAST_MASK);
    else
        i2c->DATA &= ~EF_I2C_DATA_REG_DATA_LAST_MASK;
}



EF_DRIVER_STATUS EF_I2C_getDataLast(EF_I2C_TYPE_PTR i2c, bool *data_last){

    if ((i2c->DATA & EF_I2C_DATA_REG_DATA_LAST_MASK) >> EF_I2C_DATA_REG_DATA_LAST_BIT)
        *data_last = true;
    else
        *data_last = false;
}



EF_DRIVER_STATUS EF_I2C_setDataReg(EF_I2C_TYPE_PTR i2c, uint32_t value){

    i2c->DATA = value;
}



EF_DRIVER_STATUS EF_I2C_getDataReg(EF_I2C_TYPE_PTR i2c, uint32_t* data_reg_value){

    *data_reg_value = i2c->DATA;
}



EF_DRIVER_STATUS EF_I2C_setPrescaler(EF_I2C_TYPE_PTR i2c, uint32_t value){

    i2c->PR = value;
}


EF_DRIVER_STATUS EF_I2C_getPrescaler(EF_I2C_TYPE_PTR i2c, uint32_t* prescaler_value){

    *prescaler_value = i2c->PR;
}



EF_DRIVER_STATUS EF_I2C_getRIS(EF_I2C_TYPE_PTR i2c, uint32_t* ris_value){
    
    *ris_value = i2c->RIS;
}


EF_DRIVER_STATUS EF_I2C_getMIS(EF_I2C_TYPE_PTR i2c, uint32_t* mis_value){

    *mis_value = i2c->MIS;
}



EF_DRIVER_STATUS EF_I2C_setIM(EF_I2C_TYPE_PTR i2c, uint32_t mask){
   
    i2c->IM = mask;
}



EF_DRIVER_STATUS EF_I2C_getIM(EF_I2C_TYPE_PTR i2c, uint32_t* im_value){

    *im_value = i2c->IM;
}

EF_DRIVER_STATUS EF_I2C_waitBusy(EF_I2C_TYPE_PTR i2c){

    while(i2c->STATUS & 0b1 == 1);
}



/******************************************************************************
* Static Function Definitions
******************************************************************************/



#endif // EF_I2C_C

/******************************************************************************
* End of File
******************************************************************************/

