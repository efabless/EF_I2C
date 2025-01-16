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
#define EF_I2C_COMMAND_REG_CMD_CORRECT_MASK ((uint32_t)0xFFFFE080)
#define EF_I2C_PR_MAX_VALUE                 ((uint32_t)0x0000FFFF)
#define EF_I2C_IM_REG_MAX_VALUE             ((uint32_t)0x000001FF)
#define EF_I2C_IC_REG_MAX_VALUE             ((uint32_t)0x000001FF)
/******************************************************************************
* Typedefs and Enums
******************************************************************************/

/******************************************************************************
* Function Prototypes
******************************************************************************/

//! Sets the GCLK enable bit in the I2C register to a certain value
    /*!
        \param [in] i2c An \ref EF_I2C_TYPE_PTR , which points to the base memory address of I2C registers. \ref EF_I2C_TYPE is a structure that contains the I2C registers.
        \param [in] value The value of the GCLK enable bit
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_I2C_setGclkEnable (EF_I2C_TYPE_PTR i2c, uint32_t value);



//! Sets the command register of the I2C controller.
/*!
    This ia a blocking function that writes a specified value directly to the I2C command register. It allows manual 
    configuration of the I2C controller for advanced or custom operations. 

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.
    \param [in] value The 32-bit value to write to the I2C command register. This value typically 
                      contains specific bit fields to configure the I2C operation.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_setCommandReg(EF_I2C_TYPE_PTR i2c, uint32_t value);


//! Writes a command value to the I2C command register (non-blocking).
/*!
    This function attempts to write a specified command value to the I2C command register in a 
    non-blocking manner. It checks the availability of the command FIFO before writing and 
    updates the provided flag to indicate success.

    \param [in] i2c          Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [in] value        The command value to be written to the command register.
    \param [out] command_sent Pointer to a boolean flag that indicates whether the command was successfully sent:
                              - true: Command was written successfully.
                              - false: Command was not written (FIFO unavailable or error).

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_setCommandRegNonBlocking(EF_I2C_TYPE_PTR i2c, uint32_t value, bool *command_sent);


//! Reads the data valid flag from the I2C data register.
/*!
    This function retrieves the current state of the data valid flag in the I2C data register. 
    The flag indicates whether the data is valid for an I2C transaction.

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.
    \param [out] data_valid A pointer to a boolean variable where the state of the data valid flag 
                            will be stored. The value is set to `true` if the data is valid, or 
                            `false` otherwise.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_getDataValid(EF_I2C_TYPE_PTR i2c, bool *data_valid);


//! Sets the data last flag in the I2C data register.
/*!
    This function modifies the data last flag in the I2C data register. The flag indicates whether 
    the current data is the last in an I2C transaction.

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.
    \param [in] valid A boolean value specifying the state of the data last flag. 
                      Set to `true` to mark the data as the last in the transaction, or `false` to clear the flag.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_setDataLast(EF_I2C_TYPE_PTR i2c);


//! Reads the data last flag from the I2C data register.
/*!
    This function retrieves the current state of the data last flag in the I2C data register. 
    The flag indicates whether the current data is the last in an I2C transaction.

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.
    \param [out] data_last A pointer to a boolean variable where the state of the data last flag 
                            will be stored. The value is set to `true` if the data is the last in the transaction, 
                            or `false` otherwise.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_getDataLast(EF_I2C_TYPE_PTR i2c, bool *data_last);



//! Sets the I2C prescaler value.
/*!
    This function sets the prescaler value for the I2C peripheral. The prescaler is used to 
    configure the speed of the I2C communication by adjusting the clock frequency.

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.
    \param [in] value The prescaler value to set for the I2C clock. This value determines the clock 
                      frequency for I2C communication.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_setPrescaler(EF_I2C_TYPE_PTR i2c, uint32_t value);


//! Gets the I2C prescaler value.
/*!
    This function reads the current prescaler value from the I2C peripheral. The prescaler 
    determines the clock frequency for the I2C communication.

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.
    \param [out] prescaler_value A pointer to a 32-bit variable where the current prescaler value 
                                 will be stored.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_getPrescaler(EF_I2C_TYPE_PTR i2c, uint32_t* prescaler_value);


//! Reads the Raw Interrupt Status (RIS) register.
/*!
    This function reads the raw interrupt status register (RIS) of the I2C peripheral. 
    The RIS register provides raw interrupt status flags indicating various conditions 
    within the I2C communication. These flags include information such as FIFO states 
    and errors.

    **RIS Register Breakdown**:
    - Bit 0: MISS_ACK - Slave ACK is missed
    - Bit 1: CMDE - Command FIFO is Empty
    - Bit 2: CMDF - Command FIFO is Full
    - Bit 3: CMDOVF - Command FIFO overflow; write 1 to clear
    - Bit 4: WRE - Write FIFO is Empty
    - Bit 5: WRF - Write FIFO is Full
    - Bit 6: WROVF - Write FIFO overflow; write 1 to clear
    - Bit 7: RDE - Read FIFO is Empty
    - Bit 8: RDF - Read FIFO is Full
    - Bits [9-31]: Reserved.

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.
    \param [out] ris_value A pointer to a 32-bit variable where the raw interrupt status 
                           will be stored.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_getRIS(EF_I2C_TYPE_PTR i2c, uint32_t* ris_value);


//! Reads the Masked Interrupt Status (MIS) register.
/*!
    This function reads the masked interrupt status register (MIS) of the I2C peripheral. 
    **MIS Register Breakdown**:
    - Bit 0: MISS_ACK - Slave ACK is missed
    - Bit 1: CMDE - Command FIFO is Empty
    - Bit 2: CMDF - Command FIFO is Full
    - Bit 3: CMDOVF - Command FIFO overflow; write 1 to clear
    - Bit 4: WRE - Write FIFO is Empty
    - Bit 5: WRF - Write FIFO is Full
    - Bit 6: WROVF - Write FIFO overflow; write 1 to clear
    - Bit 7: RDE - Read FIFO is Empty
    - Bit 8: RDF - Read FIFO is Full
    - Bits [9-31]: Reserved.

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.
    \param [out] mis_value A pointer to a 32-bit variable where the masked interrupt status 
                           will be stored.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_getMIS(EF_I2C_TYPE_PTR i2c, uint32_t* mis_value);

//! Sets the Interrupt Mask (IM) register.
/*!
    This function writes a mask value to the interrupt mask register (IM) of the I2C peripheral. 
    The IM register enables or disables the interrupt sources. The bits set in this register 
    determine which interrupt sources generate masked interrupts.
    **IM Register Breakdown**:
    - Bit 0: MISS_ACK - Slave ACK is missed
    - Bit 1: CMDE - Command FIFO is Empty
    - Bit 2: CMDF - Command FIFO is Full
    - Bit 3: CMDOVF - Command FIFO overflow; write 1 to clear
    - Bit 4: WRE - Write FIFO is Empty
    - Bit 5: WRF - Write FIFO is Full
    - Bit 6: WROVF - Write FIFO overflow; write 1 to clear
    - Bit 7: RDE - Read FIFO is Empty
    - Bit 8: RDF - Read FIFO is Full
    - Bits [9-31]: Reserved.
    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.
    \param [in] mask A 32-bit mask value to be written to the IM register. Each bit corresponds 
                     to a specific interrupt source, with 1 enabling the interrupt and 0 disabling it.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_setIM(EF_I2C_TYPE_PTR i2c, uint32_t mask);


//! Reads the Interrupt Mask (IM) register.
/*!
    This function reads the interrupt mask register (IM) of the I2C peripheral. The IM register 
    contains a mask value that determines which interrupt sources are enabled. It shows the status 
    of interrupt enablement for various interrupt sources.
    **IM Register Breakdown**:
    - Bit 0: MISS_ACK - Slave ACK is missed
    - Bit 1: CMDE - Command FIFO is Empty
    - Bit 2: CMDF - Command FIFO is Full
    - Bit 3: CMDOVF - Command FIFO overflow; write 1 to clear
    - Bit 4: WRE - Write FIFO is Empty
    - Bit 5: WRF - Write FIFO is Full
    - Bit 6: WROVF - Write FIFO overflow; write 1 to clear
    - Bit 7: RDE - Read FIFO is Empty
    - Bit 8: RDF - Read FIFO is Full
    - Bits [9-31]: Reserved.
    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.
    \param [out] im_value A pointer to a 32-bit variable where the interrupt mask value 
                          will be stored.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_getIM(EF_I2C_TYPE_PTR i2c, uint32_t* im_value);


////! Sets the Interrupt Clear (ICR) register.
///*!
//    This function writes a mask value to the interrupt clear register (ICR) of the I2C peripheral. 
//    The ICR register is used to clear the interrupt status bits. Writing a 1 to a bit in the ICR 
//    register clears the corresponding interrupt status bit in the RIS register.
//    **IM Register Breakdown**:
//    - Bit 0: MISS_ACK - Slave ACK is missed
//    - Bit 1: CMDE - Command FIFO is Empty
//    - Bit 2: CMDF - Command FIFO is Full
//    - Bit 3: CMDOVF - Command FIFO overflow; write 1 to clear
//    - Bit 4: WRE - Write FIFO is Empty
//    - Bit 5: WRF - Write FIFO is Full
//    - Bit 6: WROVF - Write FIFO overflow; write 1 to clear
//    - Bit 7: RDE - Read FIFO is Empty
//    - Bit 8: RDF - Read FIFO is Full
//    - Bits [9-31]: Reserved.
//    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
//                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.    
//    \param [in] mask A 32-bit mask value to be written to the ICR register. Each bit corresponds 
//                     to a specific interrupt source, with 1 clearing the interrupt status and 0 leaving it unchanged.

//    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
//*/
//EF_DRIVER_STATUS EF_I2C_setICR(EF_I2C_TYPE_PTR i2c, uint32_t mask);


// The following functions are not verified yet
/******************************************************************************************************************************************/
/******************************************************************************************************************************************/

//! Checks if the I2C peripheral is busy.
/*!
    This function checks the `STATUS` register of the I2C peripheral to determine if the 
    bus is currently busy. The result is stored in the memory location pointed to by 
    `is_busy`.

    \param [in] i2c       Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [out] is_busy  Pointer to a boolean where the busy status will be stored:
                          - `true`: I2C is busy.
                          - `false`: I2C is idle.

    \return status A value of type \ref EF_DRIVER_STATUS:
                   - EF_DRIVER_OK: The operation completed successfully.
                   - EF_DRIVER_ERROR_PARAMETER: `i2c` or `is_busy` is NULL.
*/
EF_DRIVER_STATUS EF_I2C_isBusy(EF_I2C_TYPE_PTR i2c, bool *is_busy);



//! Checks if the command FIFO is available.
/*!
    This function checks the `STATUS` register of the I2C peripheral to determine if the 
    command FIFO is not full and ready to accept new commands. The result is stored in the 
    memory location pointed to by `is_available`.

    \param [in] i2c           Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [out] is_available Pointer to a boolean where the availability status will be stored:
                              - `true`: Command FIFO is available.
                              - `false`: Command FIFO is full.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_isCommandFIFOAvailable(EF_I2C_TYPE_PTR i2c, bool *is_available);



//! Checks if the write FIFO is available.
/*!
    This function checks the `STATUS` register of the I2C peripheral to determine if the 
    write FIFO is not full and ready to accept new data. The result is stored in the memory 
    location pointed to by `is_available`.

    \param [in] i2c           Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [out] is_available Pointer to a boolean where the availability status will be stored:
                              - `true`: Write FIFO is available.
                              - `false`: Write FIFO is full.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_isWriteFIFOAvailable(EF_I2C_TYPE_PTR i2c, bool *is_available);



//! Checks if the read FIFO is available.
/*!
    This function checks the `STATUS` register of the I2C peripheral to determine if the 
    read FIFO is not empty and has data available to be read. The result is stored in the 
    memory location pointed to by `is_available`.

    \param [in] i2c           Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [out] is_available Pointer to a boolean where the availability status will be stored:
                              - `true`: Read FIFO is available.
                              - `false`: Read FIFO is empty.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_isReadFIFOAvailable(EF_I2C_TYPE_PTR i2c, bool *is_available);




//! Sends a write command to the I2C device (blocking).
/*!
    This function sends a write command to the I2C device at the specified address. 
    It blocks until the command FIFO becomes available.

    \param [in] i2c Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [in] addr The I2C address of the target device.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_sendWriteCommand(EF_I2C_TYPE_PTR i2c, uint8_t addr);



//! Sends a write command to the I2C device (non-blocking).
/*!
    This function attempts to send a write command to the I2C device at the specified 
    address. If the command FIFO is unavailable, the function returns immediately.

    \param [in] i2c          Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [in] addr         The I2C address of the target device.
    \param [out] command_sent Pointer to a boolean where the command status will be stored:
                              - `true`: Command was sent successfully.
                              - `false`: Command FIFO was unavailable.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_sendWriteCommandNonBlocking(EF_I2C_TYPE_PTR i2c, uint8_t addr, bool *command_sent);



//! Sends a read command to the I2C device (blocking).
/*!
    This function sends a read command to the I2C device at the specified address. 
    It blocks until the command FIFO becomes available.

    \param [in] i2c Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [in] addr The I2C address of the target device.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_sendReadCommand(EF_I2C_TYPE_PTR i2c, uint8_t addr);



//! Sends a read command to the I2C device (non-blocking).
/*!
    This function attempts to send a read command to the I2C device at the specified 
    address. If the command FIFO is unavailable, the function returns immediately.

    \param [in] i2c          Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [in] addr         The I2C address of the target device.
    \param [out] command_sent Pointer to a boolean where the command status will be stored:
                              - `true`: Command was sent successfully.
                              - `false`: Command FIFO was unavailable.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_sendReadCommandNonBlocking(EF_I2C_TYPE_PTR i2c, uint8_t addr, bool *command_sent);



//! Sends a start condition on the I2C bus (blocking).
/*!
    This function sends a start condition on the I2C bus. It blocks until the 
    command FIFO becomes available.

    \param [in] i2c Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_sendStartCommand(EF_I2C_TYPE_PTR i2c);



//! Sends a start condition on the I2C bus (non-blocking).
/*!
    This function attempts to send a start condition on the I2C bus. If the command FIFO 
    is unavailable, the function returns immediately.

    \param [in] i2c          Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [out] command_sent Pointer to a boolean where the command status will be stored:
                              - `true`: Start condition was sent successfully.
                              - `false`: Command FIFO was unavailable.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_sendStartCommandNonBlocking(EF_I2C_TYPE_PTR i2c, bool *command_sent);


//! Sends a stop condition on the I2C bus (blocking).
/*!
    This function sends a stop condition on the I2C bus. It blocks until the 
    command FIFO becomes available.

    \param [in] i2c Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_sendStopCommand(EF_I2C_TYPE_PTR i2c);



//! Sends a stop condition on the I2C bus (non-blocking).
/*!
    This function attempts to send a stop condition on the I2C bus. If the command FIFO 
    is unavailable, the function returns immediately.

    \param [in] i2c          Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [out] command_sent Pointer to a boolean where the command status will be stored:
                              - `true`: Stop condition was sent successfully.
                              - `false`: Command FIFO was unavailable.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_sendStopCommandNonBlocking(EF_I2C_TYPE_PTR i2c, bool *command_sent);



//! Sends a "write multiple" command on the I2C bus (blocking).
/*!
    This function sends a "write multiple" command on the I2C bus. It blocks until the 
    command FIFO becomes available.

    \param [in] i2c Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_sendWriteMultipleCommand(EF_I2C_TYPE_PTR i2c, uint8_t addr);



//! Sends a "write multiple" command on the I2C bus (non-blocking).
/*!
    This function attempts to send a "write multiple" command on the I2C bus. If the command FIFO 
    is unavailable, the function returns immediately.

    \param [in] i2c          Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [out] command_sent Pointer to a boolean where the command status will be stored:
                              - `true`: The "write multiple" command was sent successfully.
                              - `false`: Command FIFO was unavailable.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_sendWriteMultipleCommandNonBlocking(EF_I2C_TYPE_PTR i2c, uint8_t addr, bool *command_sent);


//! Writes data to the I2C Write FIFO (blocking).
/*!
    This function writes a single byte of data to the I2C Write FIFO. It blocks until the FIFO becomes available.

    \param [in] i2c  Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [in] data Data byte to be written to the FIFO.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_writeDataToWriteFIFO(EF_I2C_TYPE_PTR i2c, uint8_t data);


//! Writes data to the I2C Write FIFO (non-blocking).
/*!
    This function attempts to write a single byte of data to the I2C Write FIFO. If the FIFO is unavailable, 
    the function returns immediately.

    \param [in] i2c          Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [in] data         Data byte to be written to the FIFO.
    \param [out] data_written Pointer to a boolean where the write status will be stored:
                              - `true`: The data was written successfully.
                              - `false`: Write FIFO was unavailable.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_writeDataToWriteFIFONonBlocking(EF_I2C_TYPE_PTR i2c, uint8_t data, bool *data_written);



//! Reads data from the I2C Read FIFO (blocking).
/*!
    This function reads a single byte of data from the I2C Read FIFO. It blocks until the FIFO becomes available 
    and validates the data read.

    \param [in] i2c Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [out] data Pointer to a variable where the read data byte will be stored.

    \return status A value of type \ref EF_DRIVER_STATUS:
                   - EF_DRIVER_OK: The operation completed successfully.
                   - EF_DRIVER_ERROR_PARAMETER: `i2c` or `data` is NULL.
                   - EF_DRIVER_ERROR_I2C_INVALID_DATA: The data read is invalid.
*/
EF_DRIVER_STATUS EF_I2C_readDataFromReadFIFO(EF_I2C_TYPE_PTR i2c, uint8_t *data);



//! Reads data from the I2C Read FIFO (non-blocking).
/*!
    This function attempts to read a single byte of data from the I2C Read FIFO. If the FIFO is unavailable, 
    the function returns immediately. The validity of the data is also checked.

    \param [in] i2c          Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [out] data        Pointer to a variable where the read data byte will be stored.
    \param [out] data_read   Pointer to a boolean where the read status will be stored:
                             - `true`: Data was read successfully and is valid.
                             - `false`: Read FIFO was unavailable or data is invalid.

    \return status A value of type \ref EF_DRIVER_STATUS:
                   - EF_DRIVER_OK: The operation completed successfully.
                   - EF_DRIVER_ERROR_PARAMETER: `i2c`, `data`, or `data_read` is NULL.
                   - EF_DRIVER_ERROR_I2C_INVALID_DATA: The data read is invalid.
*/
EF_DRIVER_STATUS EF_I2C_readDataFromReadFIFONonBlocking(EF_I2C_TYPE_PTR i2c, uint8_t *data, bool *data_read);


//! Transmits a single byte to a specified I2C address (blocking).
/*!
    This function transmits a single byte to a specified I2C address using the Write FIFO. It blocks until 
    all operations (data write, write command, and stop command) are completed.

    \param [in] i2c  Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [in] data Data byte to be transmitted.
    \param [in] addr I2C address to which the data will be sent.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_transmitByte(EF_I2C_TYPE_PTR i2c, uint8_t data, uint8_t addr);



//! Transmits a single byte to a specified I2C address (non-blocking).
/*!
    This function attempts to transmit a single byte to a specified I2C address using the Write FIFO in a 
    non-blocking manner. If any step of the process (data write, write command, or stop command) cannot 
    complete immediately, the function returns.

    \param [in] i2c          Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [in] data         Data byte to be transmitted.
    \param [in] addr         I2C address to which the data will be sent.
    \param [out] transmitted Pointer to a boolean where the transmission status will be stored:
                             - `true`: Data was transmitted successfully.
                             - `false`: Transmission could not be completed.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_transmitByteNonBlocking(EF_I2C_TYPE_PTR i2c, uint8_t data, uint8_t addr, bool *transmitted);



//! Receives a single byte from a specified I2C address (blocking).
/*!
    This function reads a single byte from a specified I2C address. It blocks until all operations 
    (read command, stop command, and data retrieval) are completed.

    \param [in] i2c  Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [out] data Pointer to a uint8_t where the received data byte will be stored.
    \param [in] addr I2C address from which the data will be read.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_receiveByte(EF_I2C_TYPE_PTR i2c, uint8_t *data, uint8_t addr);


//! Receives a single byte from a specified I2C address (non-blocking).
/*!
    This function attempts to read a single byte from a specified I2C address in a non-blocking manner. 
    If any step of the process (read command, stop command, or data retrieval) cannot complete immediately, 
    the function returns.

    \param [in] i2c       Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [out] data     Pointer to a uint8_t where the received data byte will be stored.
    \param [in] addr      I2C address from which the data will be read.
    \param [out] received Pointer to a boolean where the reception status will be stored:
                          - `true`: Data was received successfully.
                          - `false`: Reception could not be completed.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_receiveByteNonBlocking(EF_I2C_TYPE_PTR i2c, uint8_t *data, uint8_t addr, bool *received);


//! Transmits an array of bytes to a specified I2C address (blocking).
/*!
    This function sends an array of bytes to a specified I2C address. It handles writing the 
    data to the I2C FIFO and ensures the last byte is appropriately marked.

    \param [in] i2c         Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [in] data        Pointer to the array of bytes to be transmitted.
    \param [in] data_length Number of bytes in the array to transmit.
    \param [in] addr        I2C address to which the data will be sent.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_transmitCharArr(EF_I2C_TYPE_PTR i2c, uint8_t *data, uint32_t data_length, uint8_t addr);


//! Receives an array of bytes from a specified I2C address (blocking).
/*!
    This function reads an array of bytes from a specified I2C address. It issues the read 
    command for each byte, stores the data in the provided buffer, and sends a stop command after 
    successful reception.

    \param [in] i2c         Pointer to the I2C base address structure \ref EF_I2C_TYPE_PTR.
    \param [out] data       Pointer to the buffer where the received bytes will be stored.
    \param [in] data_length Number of bytes to receive.
    \param [in] addr        I2C address from which the data will be read.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_recieveCharArr(EF_I2C_TYPE_PTR i2c, uint8_t *data, uint32_t data_length, uint8_t addr);


/******************************************************************************
* External Variables
******************************************************************************/



#endif // EF_I2C_H

/******************************************************************************
* End of File
******************************************************************************/
