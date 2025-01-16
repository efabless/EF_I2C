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




EF_DRIVER_STATUS EF_I2C_setCommandReg(EF_I2C_TYPE_PTR i2c, uint32_t value){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } if ((value & EF_I2C_COMMAND_REG_CMD_CORRECT_MASK) != (uint32_t)0x0) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if value is out of range
    }else{    
        bool is_command_available = false;
        do{
            status = EF_I2C_isCommandFIFOAvailable(i2c, &is_command_available);
        }while ((status==EF_DRIVER_OK)&&(is_command_available==false));
        i2c->COMMAND = value;
    }
    return status;
}

EF_DRIVER_STATUS EF_I2C_setCommandRegNonBlocking (EF_I2C_TYPE_PTR i2c, uint32_t value, bool *command_sent){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } if ((value & EF_I2C_COMMAND_REG_CMD_CORRECT_MASK) != (uint32_t)0x0) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if value is out of range
    }else{    
        bool is_command_available = false;
        status = EF_I2C_isCommandFIFOAvailable(i2c, &is_command_available);
        if ((status==EF_DRIVER_OK)&&(is_command_available==true)){
            i2c->COMMAND = value;
            *command_sent = true;
        }else{
            *command_sent = false;
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
        if (((i2c->DATA & EF_I2C_DATA_REG_DATA_VALID_MASK) >> EF_I2C_DATA_REG_DATA_VALID_BIT) != (uint32_t)0){
            *data_valid = true;
        }
        else{
            *data_valid = false;
        }
    }
    return status;
}

EF_DRIVER_STATUS EF_I2C_setDataLast(EF_I2C_TYPE_PTR i2c){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    }else{
        i2c->DATA |= (((uint32_t)1 << EF_I2C_DATA_REG_DATA_LAST_BIT) & EF_I2C_DATA_REG_DATA_LAST_MASK);
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
        if (((i2c->DATA & EF_I2C_DATA_REG_DATA_LAST_MASK) >> EF_I2C_DATA_REG_DATA_LAST_BIT) != (uint32_t)0){
            *data_last = true;
        }else{
            *data_last = false;
        }
    }
    return status;
}



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



// The following functions are not verified yet
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/

EF_DRIVER_STATUS EF_I2C_isBusy(EF_I2C_TYPE_PTR i2c, bool *is_busy){
    
    EF_DRIVER_STATUS status = EF_DRIVER_OK; 

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;                // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else if (is_busy == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;                // Return EF_DRIVER_ERROR_PARAMETER if is_busy is NULL, 
                                                        // i.e. there is no memory location to store the value
    } else {
        *is_busy = i2c->STATUS & EF_I2C_STATUS_REG_BUSY_MASK;
        
    }
    return status;
}

EF_DRIVER_STATUS EF_I2C_isCommandFIFOAvailable(EF_I2C_TYPE_PTR i2c, bool *is_available){
    
    EF_DRIVER_STATUS status = EF_DRIVER_OK; 

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;                // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else if (is_available == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;                // Return EF_DRIVER_ERROR_PARAMETER if is_available is NULL, 
                                                        // i.e. there is no memory location to store the value
    } else {
        *is_available = !((i2c->STATUS & EF_I2C_STATUS_REG_CMD_FULL_MASK) >> EF_I2C_STATUS_REG_CMD_FULL_BIT);
        
    }
    return status;
}


EF_DRIVER_STATUS EF_I2C_isWriteFIFOAvailable(EF_I2C_TYPE_PTR i2c, bool *is_available){
    
    EF_DRIVER_STATUS status = EF_DRIVER_OK; 

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;                // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else if (is_available == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;                // Return EF_DRIVER_ERROR_PARAMETER if is_available is NULL, 
                                                        // i.e. there is no memory location to store the value
    } else {
        *is_available = !((i2c->STATUS & EF_I2C_STATUS_REG_WR_FULL_MASK) >> EF_I2C_STATUS_REG_WR_FULL_BIT);
        
    }
    return status;
}

EF_DRIVER_STATUS EF_I2C_isReadFIFOAvailable(EF_I2C_TYPE_PTR i2c, bool *is_available){
    
    EF_DRIVER_STATUS status = EF_DRIVER_OK; 

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;                // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else if (is_available == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;                // Return EF_DRIVER_ERROR_PARAMETER if is_available is NULL, 
                                                        // i.e. there is no memory location to store the value
    } else {
        *is_available = !((i2c->STATUS & EF_I2C_STATUS_REG_RD_FULL_MASK) >> EF_I2C_STATUS_REG_RD_FULL_BIT);
        
    }
    return status;
}


// this is a blocking send write command function
EF_DRIVER_STATUS EF_I2C_sendWriteCommand(EF_I2C_TYPE_PTR i2c, uint8_t addr){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else{
        bool command_FIFO_available = false;
        do{
            status = EF_I2C_isCommandFIFOAvailable(i2c, &command_FIFO_available);
        }while ((status==EF_DRIVER_OK)&&(command_FIFO_available==false));
        
        i2c->COMMAND = ((addr << EF_I2C_COMMAND_REG_CMD_ADDRESS_BIT) | EF_I2C_COMMAND_REG_CMD_WRITE_MASK);
    }
    return status;
}

EF_DRIVER_STATUS EF_I2C_sendWriteCommandNonBlocking(EF_I2C_TYPE_PTR i2c, uint8_t addr, bool *command_sent){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else if (command_sent == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if command_sent is NULL
    } else{
        bool command_FIFO_available = false;
        status = EF_I2C_isCommandFIFOAvailable(i2c, &command_FIFO_available);
        if ((status==EF_DRIVER_OK)&&(command_FIFO_available==true)){
            i2c->COMMAND = ((addr << EF_I2C_COMMAND_REG_CMD_ADDRESS_BIT) | EF_I2C_COMMAND_REG_CMD_WRITE_MASK);
            *command_sent = true;
        }else{
            *command_sent = false;
        }
    }
    return status;
}


EF_DRIVER_STATUS EF_I2C_sendReadCommand(EF_I2C_TYPE_PTR i2c, uint8_t addr){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else{
        bool command_FIFO_available = false;
        do{
            status = EF_I2C_isCommandFIFOAvailable(i2c, &command_FIFO_available);
        }while ((status==EF_DRIVER_OK)&&(command_FIFO_available==false));
        
        i2c->COMMAND = ((addr << EF_I2C_COMMAND_REG_CMD_ADDRESS_BIT) | EF_I2C_COMMAND_REG_CMD_READ_MASK);
    }
    return status;
}


EF_DRIVER_STATUS EF_I2C_sendReadCommandNonBlocking(EF_I2C_TYPE_PTR i2c, uint8_t addr, bool *command_sent){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else if (command_sent == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if command_sent is NULL
    } else{
        bool command_FIFO_available = false;
        status = EF_I2C_isCommandFIFOAvailable(i2c, &command_FIFO_available);
        if ((status==EF_DRIVER_OK)&&(command_FIFO_available==true)){
            i2c->COMMAND = ((addr << EF_I2C_COMMAND_REG_CMD_ADDRESS_BIT) | EF_I2C_COMMAND_REG_CMD_READ_MASK);
            *command_sent = true;
        }else{
            *command_sent = false;
        }
    }
    return status;
}  


EF_DRIVER_STATUS EF_I2C_sendStartCommand(EF_I2C_TYPE_PTR i2c){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else{
        bool command_FIFO_available = false;
        do{
            status = EF_I2C_isCommandFIFOAvailable(i2c, &command_FIFO_available);
        }while ((status==EF_DRIVER_OK)&&(command_FIFO_available==false));
        
        i2c->COMMAND = (((uint32_t)1 << EF_I2C_COMMAND_REG_CMD_START_BIT) & EF_I2C_COMMAND_REG_CMD_START_MASK);
    }
    return status;
}

EF_DRIVER_STATUS EF_I2C_sendStartCommandNonBlocking(EF_I2C_TYPE_PTR i2c, bool *command_sent){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else if (command_sent == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if command_sent is NULL
    } else{
        bool command_FIFO_available = false;
        status = EF_I2C_isCommandFIFOAvailable(i2c, &command_FIFO_available);
        if ((status==EF_DRIVER_OK)&&(command_FIFO_available==true)){
            i2c->COMMAND = (((uint32_t)1 << EF_I2C_COMMAND_REG_CMD_START_BIT) & EF_I2C_COMMAND_REG_CMD_START_MASK);
            *command_sent = true;
        }else{
            *command_sent = false;
        }
    }
    return status;
}

EF_DRIVER_STATUS EF_I2C_sendStopCommand(EF_I2C_TYPE_PTR i2c){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else{
        bool command_FIFO_available = false;
        do{
            status = EF_I2C_isCommandFIFOAvailable(i2c, &command_FIFO_available);
        }while ((status==EF_DRIVER_OK)&&(command_FIFO_available==false));
        
        i2c->COMMAND = (((uint32_t)1 << EF_I2C_COMMAND_REG_CMD_STOP_BIT) & EF_I2C_COMMAND_REG_CMD_STOP_MASK);
    }
    return status;
}


EF_DRIVER_STATUS EF_I2C_sendStopCommandNonBlocking(EF_I2C_TYPE_PTR i2c, bool *command_sent){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else if (command_sent == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if command_sent is NULL
    } else{
        bool command_FIFO_available = false;
        status = EF_I2C_isCommandFIFOAvailable(i2c, &command_FIFO_available);
        if ((status==EF_DRIVER_OK)&&(command_FIFO_available==true)){
            i2c->COMMAND = (((uint32_t)1 << EF_I2C_COMMAND_REG_CMD_STOP_BIT) & EF_I2C_COMMAND_REG_CMD_STOP_MASK);
            *command_sent = true;
        }else{
            *command_sent = false;
        }
    }
    return status;
}

EF_DRIVER_STATUS EF_I2C_sendWriteMultipleCommand(EF_I2C_TYPE_PTR i2c, uint8_t addr){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    bool command_FIFO_available = false;
    do{
        status = EF_I2C_isCommandFIFOAvailable(i2c, &command_FIFO_available);
    }while ((status==EF_DRIVER_OK)&&(command_FIFO_available==false));
    
    i2c->COMMAND = ((addr << EF_I2C_COMMAND_REG_CMD_ADDRESS_BIT) & EF_I2C_COMMAND_REG_CMD_WRITE_MULTIPLE_MASK);
    return status;
}

EF_DRIVER_STATUS EF_I2C_sendWriteMultipleCommandNonBlocking(EF_I2C_TYPE_PTR i2c, uint8_t addr, bool *command_sent){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (command_sent == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if command_sent is NULL
    } else{
        bool command_FIFO_available = false;
        status = EF_I2C_isCommandFIFOAvailable(i2c, &command_FIFO_available);
        if ((status==EF_DRIVER_OK)&&(command_FIFO_available==true)){
            i2c->COMMAND = ((addr << EF_I2C_COMMAND_REG_CMD_ADDRESS_BIT) & EF_I2C_COMMAND_REG_CMD_WRITE_MULTIPLE_MASK);
            *command_sent = true;
        }else{
            *command_sent = false;
        }
    }
    return status;
}

EF_DRIVER_STATUS EF_I2C_writeDataToWriteFIFO(EF_I2C_TYPE_PTR i2c, uint8_t data){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else{
        bool write_FIFO_available = false;
        do{
            status = EF_I2C_isWriteFIFOAvailable(i2c, &write_FIFO_available);
        }while ((status==EF_DRIVER_OK)&&(write_FIFO_available==false));
        
        i2c->DATA = ((data << EF_I2C_DATA_REG_DATA_BIT) & EF_I2C_DATA_REG_DATA_MASK);
    }
    return status;
}


EF_DRIVER_STATUS EF_I2C_writeDataToWriteFIFONonBlocking(EF_I2C_TYPE_PTR i2c, uint8_t data, bool *data_written){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else if (data_written == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if data_written is NULL
    } else{
        bool write_FIFO_available = false;
        status = EF_I2C_isWriteFIFOAvailable(i2c, &write_FIFO_available);
        if ((status==EF_DRIVER_OK)&&(write_FIFO_available==true)){
            i2c->DATA = ((data << EF_I2C_DATA_REG_DATA_BIT) & EF_I2C_DATA_REG_DATA_MASK);
            *data_written = true;
        }else{
            *data_written = false;
        }
    }
    return status;
}


EF_DRIVER_STATUS EF_I2C_readDataFromReadFIFO(EF_I2C_TYPE_PTR i2c, uint8_t *data){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else if (data == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if data is NULL
    } else{
        bool read_FIFO_available = false;
        do{
            status = EF_I2C_isReadFIFOAvailable(i2c, &read_FIFO_available);
        }while ((status==EF_DRIVER_OK)&&(read_FIFO_available==false));
        
        *data = i2c->DATA;

        bool data_valid = ((*data & EF_I2C_DATA_REG_DATA_VALID_MASK) >> EF_I2C_DATA_REG_DATA_VALID_BIT);
        if (!data_valid){
            status = EF_DRIVER_ERROR_I2C_INVALID_DATA;     // Return EF_DRIVER_ERROR_DATA if data is not valid
        }else{}
    }
    return status;
}

EF_DRIVER_STATUS EF_I2C_readDataFromReadFIFONonBlocking(EF_I2C_TYPE_PTR i2c, uint8_t *data, bool *data_read){

    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    } else if (data == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if data is NULL
    } else if (data_read == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if data_read is NULL
    } else{
        bool read_FIFO_available = false;
        status = EF_I2C_isReadFIFOAvailable(i2c, &read_FIFO_available);
        if ((status==EF_DRIVER_OK)&&(read_FIFO_available==true)){
            *data = i2c->DATA;
            bool data_valid = ((*data & EF_I2C_DATA_REG_DATA_VALID_MASK) >> EF_I2C_DATA_REG_DATA_VALID_BIT);
            if (!data_valid){
                status = EF_DRIVER_ERROR_I2C_INVALID_DATA;     // Return EF_DRIVER_ERROR_DATA if data is not valid
            }else{}
            *data_read = true;
        }else{
            *data_read = false;
        }
    }
    return status;
}

EF_DRIVER_STATUS EF_I2C_transmitByte(EF_I2C_TYPE_PTR i2c, uint8_t data, uint8_t addr){
    
    EF_DRIVER_STATUS status = EF_DRIVER_OK;
    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    }else{
        status = EF_I2C_writeDataToWriteFIFO(i2c, data);
        if (status == EF_DRIVER_OK) {status = EF_I2C_sendWriteCommand(i2c, addr);}else{}
        if (status == EF_DRIVER_OK) {status = EF_I2C_sendStopCommand(i2c);}else{}
    }
    return status;
}



EF_DRIVER_STATUS EF_I2C_transmitByteNonBlocking(EF_I2C_TYPE_PTR i2c, uint8_t data, uint8_t addr, bool *transmitted){
    
    EF_DRIVER_STATUS status = EF_DRIVER_OK;
    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    }else if (transmitted == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if transmitted is NULL
    }else{
        bool command_sent = false;
        bool data_written = false;
        bool stop_command_sent = false;
        status = EF_I2C_writeDataToWriteFIFONonBlocking(i2c, data, &data_written);
        if ((status == EF_DRIVER_OK)&&(data_written == true)) {status = EF_I2C_sendWriteCommandNonBlocking(i2c, addr, &command_sent);}else{}
        if ((status == EF_DRIVER_OK)&&(command_sent == true)) {status = EF_I2C_sendStopCommandNonBlocking(i2c, &stop_command_sent);}else{}
        if ((status == EF_DRIVER_OK)&&(stop_command_sent == true)) {*transmitted = true;}else{*transmitted = false;}
    }
    return status;
}


EF_DRIVER_STATUS EF_I2C_receiveByte(EF_I2C_TYPE_PTR i2c, uint8_t *data, uint8_t addr){
    
    EF_DRIVER_STATUS status = EF_DRIVER_OK;
    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    }else{
        status = EF_I2C_sendReadCommand(i2c, addr);
        if (status == EF_DRIVER_OK) {status = EF_I2C_sendStopCommand(i2c);}else{}
        if (status == EF_DRIVER_OK) {status = EF_I2C_readDataFromReadFIFO(i2c, data);}else{}
    }
    return status;
}


EF_DRIVER_STATUS EF_I2C_receiveByteNonBlocking(EF_I2C_TYPE_PTR i2c, uint8_t *data, uint8_t addr, bool *received){
    
    EF_DRIVER_STATUS status = EF_DRIVER_OK;
    if (i2c == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if i2c is NULL
    }else if (received == NULL) {
        status = EF_DRIVER_ERROR_PARAMETER;     // Return EF_DRIVER_ERROR_PARAMETER if received is NULL
    }else{
        bool command_sent = false;
        bool data_read = false;
        bool stop_command_sent = false;
        
        status = EF_I2C_sendReadCommandNonBlocking(i2c, addr, &command_sent);
        if ((status == EF_DRIVER_OK)&&(command_sent == true)) {status = EF_I2C_sendStopCommandNonBlocking(i2c, &stop_command_sent);}else{}
        if ((status == EF_DRIVER_OK)&&(stop_command_sent == true)) {status = EF_I2C_readDataFromReadFIFONonBlocking(i2c, data, &data_read);}else{}
        if ((status == EF_DRIVER_OK)&&(data_read == true)) {*received = true;}else{*received = false;}
    }
    return status;
}


EF_DRIVER_STATUS EF_I2C_transmitCharArr(EF_I2C_TYPE_PTR i2c, uint8_t *data, uint32_t data_length, uint8_t addr) {
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    // Validate input parameters
    if ((i2c == NULL) || (data == NULL)) {
        status = EF_DRIVER_ERROR_PARAMETER;                                 // Set error status if parameters are invalid
    } else {

        status = EF_I2C_writeDataToWriteFIFO(i2c, data[0]);                 // Write the first byte to the FIFO

        if (status == EF_DRIVER_OK) {
            status = EF_I2C_sendWriteMultipleCommand(i2c, addr);                  // Send the write multiple command
        }else{}

        // Transmit the remaining bytes if no error has occurred
        for (uint32_t i = 1; (i < data_length) && (status == EF_DRIVER_OK); i++) {
            
            if (i == (data_length - (uint32_t)1)) {
                status = EF_I2C_setDataLast(i2c);                     // Mark the last byte appropriately
            }

            if (status == EF_DRIVER_OK) {
                status = EF_I2C_writeDataToWriteFIFO(i2c, data[i]);         // Write the current byte to the FIFO
            }
        }
        
        if (status == EF_DRIVER_OK) {
            status = EF_I2C_sendStopCommand(i2c);                           // Send the stop command if all prior steps succeeded
        }
    }
    return status;
}

EF_DRIVER_STATUS EF_I2C_recieveCharArr(EF_I2C_TYPE_PTR i2c, uint8_t *data, uint32_t data_length, uint8_t addr) {
    EF_DRIVER_STATUS status = EF_DRIVER_OK;

    // Validate input parameters
    if ((i2c == NULL) || (data == NULL) || (data_length == (uint32_t)0)) {
        status = EF_DRIVER_ERROR_PARAMETER;                                 // Set error status if parameters are invalid
    } else {
        // Transmit the remaining bytes if no error has occurred
        for (uint32_t i = 0; (i < data_length) && (status == EF_DRIVER_OK); i++) {
            
            status = EF_I2C_sendReadCommand(i2c, addr);                     // Send the read command

            if (status == EF_DRIVER_OK) {
                status = EF_I2C_readData(i2c, data[i]);                     // read the current byte to the FIFO
            }
        }
        
        if (status == EF_DRIVER_OK) {
            status = EF_I2C_sendStopCommand(i2c);                           // Send the stop command if all prior steps succeeded
        }
    }
    return status;
}
    

/******************************************************************************
* Static Function Definitions
******************************************************************************/



#endif // EF_I2C_C

/******************************************************************************
* End of File
******************************************************************************/

