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
    
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else if (value > (uint32_t)0x1) {  
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if value is out of range
    }else {
        i2c->GCLK = value;                      // Set the GCLK enable bit to the given value
    }

    return status;
}

EF_DRIVER_STATUS EF_I2C_writeToAddress(EF_I2C_TYPE_PTR i2c, char addr, char data){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else{
        status = EF_I2C_writeData(i2c, data);                                       // Write the data to the I2C data register
        if (status == EF_DRIVER_OK) {status = EF_I2C_writeCmd(i2c, addr);}else{}    // Write the target address to the I2C command register
        if (status == EF_DRIVER_OK) {status = EF_I2C_stopCmd(i2c);}else{}           // Issue a stop condition to end the transaction
        if (status == EF_DRIVER_OK) {status = EF_I2C_waitBusy(i2c);}else{}          // Wait for the I2C hardware to complete the operation
    }
    return status;
}

EF_DRIVER_STATUS EF_I2C_readCommand(EF_I2C_TYPE_PTR i2c, char addr){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else{
        status = EF_I2C_readCmd(i2c, addr);                                        // Send a read command to the specified address
        if (status == EF_DRIVER_OK) {status = EF_I2C_stopCmd(i2c);}else{}          // Issue a stop condition to end the transaction
        if (status == EF_DRIVER_OK) {status = EF_I2C_waitBusy(i2c);}else{}         // Wait for the I2C hardware to complete the read operation
    }
    return status;
}


EF_DRIVER_STATUS EF_I2C_writeAddress(EF_I2C_TYPE_PTR i2c, char addr){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else{
        // Clear the field bits in the register using the defined mask
        uint32_t command =  i2c->COMMAND & ~EF_I2C_COMMAND_REG_CMD_ADDRESS_MASK;

        // Set the bits with the given value at the defined offset
        i2c->COMMAND = command | ((addr << EF_I2C_COMMAND_REG_CMD_ADDRESS_BIT) & EF_I2C_COMMAND_REG_CMD_ADDRESS_MASK);
    }
    return status;
}


EF_DRIVER_STATUS EF_I2C_startCmd(EF_I2C_TYPE_PTR i2c){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else{
        i2c->COMMAND |= ((1 << EF_I2C_COMMAND_REG_CMD_START_BIT) & EF_I2C_COMMAND_REG_CMD_START_MASK);
    }
    return status;
}


EF_DRIVER_STATUS EF_I2C_readCmd(EF_I2C_TYPE_PTR i2c, char addr){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else{
        i2c->COMMAND = ((addr << EF_I2C_COMMAND_REG_CMD_ADDRESS_BIT ) | EF_I2C_COMMAND_REG_CMD_READ_MASK);
    }
    return  status;
}



EF_DRIVER_STATUS EF_I2C_writeCmd(EF_I2C_TYPE_PTR i2c, char addr){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else{
        i2c->COMMAND = ((addr << EF_I2C_COMMAND_REG_CMD_ADDRESS_BIT) | EF_I2C_COMMAND_REG_CMD_WRITE_MASK);
    }
    return status;
}



EF_DRIVER_STATUS EF_I2C_writeMultipleCmd(EF_I2C_TYPE_PTR i2c){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else{
        i2c->COMMAND |= ((1 << EF_I2C_COMMAND_REG_CMD_WRITE_MULTIPLE_BIT) & EF_I2C_COMMAND_REG_CMD_WRITE_MULTIPLE_MASK);
    }
    return status;
}


EF_DRIVER_STATUS EF_I2C_stopCmd(EF_I2C_TYPE_PTR i2c){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else{
        i2c->COMMAND = ((1 << EF_I2C_COMMAND_REG_CMD_STOP_BIT) & EF_I2C_COMMAND_REG_CMD_STOP_MASK);
    }
    return status;
}


#define EF_I2C_COMMAND_REG_CMD_CORRECT_MASK 0xFFFFE080


EF_DRIVER_STATUS EF_I2C_setCommandReg(EF_I2C_TYPE_PTR i2c, uint32_t value){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } if (value & EF_I2C_COMMAND_REG_CMD_CORRECT_MASK) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if value is out of range
    }else{    
        i2c->COMMAND = value;
    }
    return status;
}



EF_DRIVER_STATUS EF_I2C_getCommandReg(EF_I2C_TYPE_PTR i2c, uint32_t* command_value){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else if (command_value == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if command_value is NULL
    } else{
        *command_value = i2c->COMMAND;
    }
    return status;
}



EF_DRIVER_STATUS EF_I2C_writeData(EF_I2C_TYPE_PTR i2c, char data){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else{
        i2c->DATA = ((data << EF_I2C_DATA_REG_DATA_BIT) & EF_I2C_DATA_REG_DATA_MASK);
    }
}



EF_DRIVER_STATUS EF_I2C_readData(EF_I2C_TYPE_PTR i2c, char *data){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else if (data == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if data is NULL
    } else{
        *data = i2c->DATA;
    
        bool valid = (*data & EF_I2C_DATA_REG_DATA_VALID_MASK) >> EF_I2C_DATA_REG_DATA_VALID_BIT;
        if (valid){
            *data = (*data & EF_I2C_DATA_REG_DATA_MASK) >> EF_I2C_DATA_REG_DATA_BIT;
        }else{
            *data = -1;
        }
    }
    return status;
}



EF_DRIVER_STATUS EF_I2C_setDataValid(EF_I2C_TYPE_PTR i2c, bool valid){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else{

        if (valid){
            i2c->DATA |= ((1 << EF_I2C_DATA_REG_DATA_VALID_BIT) & EF_I2C_DATA_REG_DATA_VALID_MASK);
            }
        else{
            i2c->DATA &= ~EF_I2C_DATA_REG_DATA_VALID_MASK;
        }
    }
    return status;
}



EF_DRIVER_STATUS EF_I2C_getDataValid(EF_I2C_TYPE_PTR i2c, bool *data_valid){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else if (data_valid == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if data_valid is NULL
    } else{
        if ((i2c->DATA & EF_I2C_DATA_REG_DATA_VALID_MASK) >> EF_I2C_DATA_REG_DATA_VALID_BIT){
            *data_valid = true;
        }
        else{
            *data_valid = false;
        }
    }
    return status;
}



EF_DRIVER_STATUS EF_I2C_setDataLast(EF_I2C_TYPE_PTR i2c, bool valid){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    }else{
        if (valid){
            i2c->DATA |= ((1 << EF_I2C_DATA_REG_DATA_LAST_BIT) & EF_I2C_DATA_REG_DATA_LAST_MASK);
        }else{
            i2c->DATA &= ~EF_I2C_DATA_REG_DATA_LAST_MASK;
        }    
    }
    return status;
}



EF_DRIVER_STATUS EF_I2C_getDataLast(EF_I2C_TYPE_PTR i2c, bool *data_last){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    }else if (data_last == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if data_last is NULL
    }else{    
        if ((i2c->DATA & EF_I2C_DATA_REG_DATA_LAST_MASK) >> EF_I2C_DATA_REG_DATA_LAST_BIT){
            *data_last = true;
        }else{
            *data_last = false;
        }
    }
    return status;
}


#define EF_I2C_DATA_REG_MAX_VALUE 0x000003FF
EF_DRIVER_STATUS EF_I2C_setDataReg(EF_I2C_TYPE_PTR i2c, uint32_t value){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL   
    } else if (value > EF_I2C_DATA_REG_MAX_VALUE) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if value is out of range
    }else{
        i2c->DATA = value;
    }
    return status;
}



EF_DRIVER_STATUS EF_I2C_getDataReg(EF_I2C_TYPE_PTR i2c, uint32_t* data_reg_value){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL   
    } else if (data_reg_value == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if data_reg_value is NULL
    }else{
        *data_reg_value = i2c->DATA;
    }
    return status;
}


#define EF_I2C_PR_MAX_VALUE 0x0000FFFF
EF_DRIVER_STATUS EF_I2C_setPrescaler(EF_I2C_TYPE_PTR i2c, uint32_t value){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL   
    } else if (value > EF_I2C_PR_MAX_VALUE) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if value is out of range
    }else{
        i2c->PR = value;
    }
    return status;
}


EF_DRIVER_STATUS EF_I2C_getPrescaler(EF_I2C_TYPE_PTR i2c, uint32_t* prescaler_value){
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL   
    } else if (prescaler_value == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if prescaler_value is NULL
    }else{  
        *prescaler_value = i2c->PR;
    }
    return status;
}



EF_DRIVER_STATUS EF_I2C_getRIS(EF_I2C_TYPE_PTR i2c, uint32_t* ris_value){
    
    EF_DRIVER_STATUS status = EF_DRIVER_OK; 

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;                // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else if (ris_value == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;                // Return EF_DRIVER_ERROR_PARAMETER if ris_value is NULL, 
                                                        // i.e. there is no memory location to store the value
    } else {
        *ris_value = i2c->RIS;
        
    }
    return status;
}


EF_DRIVER_STATUS EF_I2C_getMIS(EF_I2C_TYPE_PTR i2c, uint32_t* mis_value){
    
    EF_DRIVER_STATUS status = EF_DRIVER_OK; 

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;                // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else if (mis_value == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;                // Return EF_DRIVER_ERROR_PARAMETER if mis_value is NULL, 
                                                        // i.e. there is no memory location to store the value
    } else {
        *mis_value = i2c->MIS;
        
    }
    return status;
}

#define EF_I2C_IM_REG_MAX_VALUE  0x000001FF
#define EF_I2C_IC_REG_MAX_VALUE  0x000001FF
EF_DRIVER_STATUS EF_I2C_setIM(EF_I2C_TYPE_PTR i2c, uint32_t mask){
    
    EF_DRIVER_STATUS status = EF_DRIVER_OK; 

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;                // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else if (mask > EF_I2C_IM_REG_MAX_VALUE) {
        status = EF_DRIVER_ERROR_PARAMETER;                // Return EF_DRIVER_ERROR_PARAMETER if mask is out of range

    } else {
        i2c->IM = mask;
        
    }
    return status;
}


EF_DRIVER_STATUS EF_I2C_getIM(EF_I2C_TYPE_PTR i2c, uint32_t* im_value){
    
    EF_DRIVER_STATUS status = EF_DRIVER_OK; 

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;                // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else if (im_value == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;                // Return EF_DRIVER_ERROR_PARAMETER if im_value is NULL, 
                                                        // i.e. there is no memory location to store the value
    } else {
        *im_value = i2c->IM;
        
    }
    return status;
}



//EF_DRIVER_STATUS EF_I2C_setICR(EF_I2C_TYPE_PTR i2c, uint32_t mask){
    
//    EF_DRIVER_STATUS status = EF_DRIVER_OK; 

//    if (i2c == NULL) {
//        status = EF_DRIVER_ERROR_PARAMETER;                // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
//    } else if (mask > EF_I2C_IC_REG_MAX_VALUE) {
//        status = EF_DRIVER_ERROR_PARAMETER;                // Return EF_DRIVER_ERROR_PARAMETER if mask is out of range
//    } else {
//        i2c->IC = mask;
        
//    }
//    return status;
//}

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

