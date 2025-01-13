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

//! Sets the GCLK enable bit in the I2C register to a certain value
    /*!
        \param [in] i2c An \ref EF_I2C_TYPE_PTR , which points to the base memory address of I2C registers. \ref EF_I2C_TYPE is a structure that contains the I2C registers.
        \param [in] value The value of the GCLK enable bit
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_I2C_setGclkEnable (EF_I2C_TYPE_PTR i2c, uint32_t value);

//! Performs an I2C write operation to a specific address.
/*!
        This function enables communication over the I2C bus by writing a single data byte to a specific address. 
        It follows the standard I2C sequence for writing:
        1. Loads the data to be sent into the I2C data buffer.
        2. Sends the target device address as a command.
        3. Issues a stop condition to signal the end of the transaction.
        4. Waits for the I2C hardware to complete the operation.

        \param [in] i2c An \ref EF_I2C_TYPE_PTR , which points to the base memory address of I2C registers. \ref EF_I2C_TYPE is a structure that contains the I2C registers.
        \param [in] addr The address to write to
        \param [in] data The data to write
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
    */
EF_DRIVER_STATUS EF_I2C_writeToAddress(EF_I2C_TYPE_PTR i2c, char addr, char data);


//! Issues an I2C read command to a specific address and waits for completion.
/*!
        This function initiates a read operation on the I2C bus. It performs the following steps:
        1. Sends a read command to the specified address on the I2C bus.
        2. Issues a stop condition to signal the end of the transaction.
        3. Waits for the I2C hardware to complete the read operation.

        \param [in] i2c An \ref EF_I2C_TYPE_PTR , which points to the base memory address of I2C registers. \ref EF_I2C_TYPE is a structure that contains the I2C registers.
        \param [in] addr The address on the I2C bus from which to read. 
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
*/
EF_DRIVER_STATUS EF_I2C_readCommand(EF_I2C_TYPE_PTR i2c, char addr);


//! Writes an address to the I2C command register
/*!
        This function writes an address to the I2C command register. It performs the following steps:
        1. Clears the field bits in the register using the defined mask.
        2. Sets the bits with the given value at the defined offset.

        \param [in] i2c An \ref EF_I2C_TYPE_PTR , which points to the base memory address of I2C registers. \ref EF_I2C_TYPE is a structure that contains the I2C registers.
        \param [in] addr The address to write to
        
        \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
*/
EF_DRIVER_STATUS EF_I2C_writeAddress(EF_I2C_TYPE_PTR i2c, char addr);


//! Issues a start condition on the I2C bus.
/*!
    This function sends a start condition to initiate an I2C transaction. The start condition
    is a signal to indicate the beginning of communication with an I2C device.

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
*/
EF_DRIVER_STATUS EF_I2C_startCmd(EF_I2C_TYPE_PTR i2c);


//! Sends a read command to the specified address on the I2C bus.
/*!
    This function configures the I2C controller to read from the specified address on the I2C bus.
    It sets the read bit and writes the target address into the I2C command register.

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.
    \param [in] addr The target address on the I2C bus to read from. This is typically a 7-bit or 10-bit address.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
*/
EF_DRIVER_STATUS EF_I2C_readCmd(EF_I2C_TYPE_PTR i2c, char addr);


//! Sends a write command to the specified address on the I2C bus.
/*!
    This function configures the I2C controller to write to the specified address on the I2C bus.
    It sets the write bit and writes the target address into the I2C command register.

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.
    \param [in] addr The target address on the I2C bus to write to. This is typically a 7-bit or 10-bit address.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
*/
EF_DRIVER_STATUS EF_I2C_writeCmd(EF_I2C_TYPE_PTR i2c, char addr);


//! Enables the write multiple command mode for the I2C controller.
/*!
    This function configures the I2C controller to enter write multiple command mode, allowing 
    consecutive data writes without sending a stop condition between each write. 

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
*/
EF_DRIVER_STATUS EF_I2C_writeMultipleCmd(EF_I2C_TYPE_PTR i2c);


//! Issues a stop condition on the I2C bus.
/*!
    This function sends a stop condition, signaling the end of an I2C transaction. The stop condition 
    releases the I2C bus for other devices to communicate.

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code 
*/
EF_DRIVER_STATUS EF_I2C_stopCmd(EF_I2C_TYPE_PTR i2c);


//! Sets the command register of the I2C controller.
/*!
    This function writes a specified value directly to the I2C command register. It allows manual 
    configuration of the I2C controller for advanced or custom operations. 

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.
    \param [in] value The 32-bit value to write to the I2C command register. This value typically 
                      contains specific bit fields to configure the I2C operation.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_setCommandReg(EF_I2C_TYPE_PTR i2c, uint32_t value);


//! Gets the value of the I2C command register.
/*!
    This function reads the current value of the I2C command register. It allows the user to 
    retrieve the current configuration of the I2C controller for debugging or monitoring purposes.

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.
    \param [out] command_value A pointer to a 32-bit variable where the command register value will be stored.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_getCommandReg(EF_I2C_TYPE_PTR i2c, uint32_t* command_value);


//! Writes a data value to the I2C data register.
/*!
    This function writes a data value to the I2C data register. The data register is used to store 
    the data to be transmitted or received over the I2C bus. write to push on write data FIFO, read to pull from read data FIFO.

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.
    \param [in] data The 8-bit data value to write to the I2C data register.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_writeData(EF_I2C_TYPE_PTR i2c, char data);


//! Reads a data value from the I2C data register.
/*!
    This function reads the current value of the I2C data register. The data register is used to store 
    the data to be transmitted or received over the I2C bus. read to pull from read data FIFO.

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.
    \param [out] data A pointer to an 8-bit variable where the data register value will be stored.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_readData(EF_I2C_TYPE_PTR i2c, char *data);


//! Sets the data valid flag in the I2C data register.
/*!
    This function modifies the data valid flag in the I2C data register. The flag indicates whether 
    the current data in the register is valid for an I2C transaction.

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.
    \param [in] valid A boolean value specifying the state of the data valid flag. 
                      Set to `true` to mark the data as valid, or `false` to clear the flag.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_setDataValid(EF_I2C_TYPE_PTR i2c, bool valid);

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
EF_DRIVER_STATUS EF_I2C_setDataLast(EF_I2C_TYPE_PTR i2c, bool valid);


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


//! Writes a value to the I2C data register.
/*!
    This function writes a 32-bit value to the I2C data register. The data register is used for 
    handling the I2C read and write FIFOs, along with managing data validity and the last byte flag.  

    **Data Register Breakdown**:
    - Bits [0-7]: Data - Used to push data into the write FIFO or pull data from the read FIFO.
    - Bit [8]: Data Valid - Indicates whether the read data is valid. Must be accessed atomically 
               with 16-bit reads and writes.
    - Bit [9]: Data Last - Indicates the last byte of a block write (write_multiple). Must be accessed 
               atomically with 16-bit reads and writes.
    - Bits [10-31]: Reserved - These bits are reserved for future use and should always be written 
                    as zero to avoid undefined behavior.

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.
    \param [in] value A 32-bit value to write to the data register. The value should include all 
                      relevant fields (data, data valid, data last) as specified in the register breakdown.  
                      The reserved bits (10-31) must always be set to zero.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_setDataReg(EF_I2C_TYPE_PTR i2c, uint32_t value);


//! Reads the value from the I2C data register.
/*!
    This function reads the 32-bit value from the I2C data register. The data register holds the 
    I2C data (either for reading or writing) and status flags for data validity and the last byte in a block write. 

    **Data Register Breakdown**:
    - Bits [0-7]: Data - Contains the data pulled from the read FIFO or to be pushed into the write FIFO.
    - Bit [8]: Data Valid - Indicates whether the read data is valid.
    - Bit [9]: Data Last - Indicates if the byte read or written is the last byte of a block write (write_multiple).
    - Bits [10-31]: Reserved - These bits are reserved.

    \param [in] i2c An \ref EF_I2C_TYPE_PTR, which points to the base memory address of I2C registers. 
                    \ref EF_I2C_TYPE is a structure that contains the I2C registers.
    \param [out] data_reg_value A pointer to a 32-bit variable where the value of the data register 
                                will be stored.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_getDataReg(EF_I2C_TYPE_PTR i2c, uint32_t* data_reg_value);


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


//! Sets the Interrupt Clear (ICR) register.
/*!
    This function writes a mask value to the interrupt clear register (ICR) of the I2C peripheral. 
    The ICR register is used to clear the interrupt status bits. Writing a 1 to a bit in the ICR 
    register clears the corresponding interrupt status bit in the RIS register.
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
    \param [in] mask A 32-bit mask value to be written to the ICR register. Each bit corresponds 
                     to a specific interrupt source, with 1 clearing the interrupt status and 0 leaving it unchanged.

    \return status A value of type \ref EF_DRIVER_STATUS : returns a success or error code
*/
EF_DRIVER_STATUS EF_I2C_setICR(EF_I2C_TYPE_PTR i2c, uint32_t mask);


EF_DRIVER_STATUS EF_I2C_waitBusy(EF_I2C_TYPE_PTR i2c);
/******************************************************************************
* External Variables
******************************************************************************/



#endif // EF_I2C_H

/******************************************************************************
* End of File
******************************************************************************/
