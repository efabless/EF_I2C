# API Reference

## Header files

- [EF_Driver_Common.h](#file-ef_driver_commonh)
- [EF_I2C.h](#file-ef_i2ch)
- [EF_I2C_regs.h](#file-ef_i2c_regsh)

## File EF_Driver_Common.h

_C header file for common driver definitions and types._



## Structures and Types

| Type | Name |
| ---: | :--- |
| typedef uint32\_t | [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status)  <br>_A type that is used to return the status of the driver functions._ |


## Macros

| Type | Name |
| ---: | :--- |
| define  | [**EF\_DRIVER\_ERROR**](#define-ef_driver_error)  ((uint32\_t)1)<br>_Unspecified error._ |
| define  | [**EF\_DRIVER\_ERROR\_BUSY**](#define-ef_driver_error_busy)  ((uint32\_t)2)<br>_Driver is busy._ |
| define  | [**EF\_DRIVER\_ERROR\_PARAMETER**](#define-ef_driver_error_parameter)  ((uint32\_t)5)<br>_Parameter error._ |
| define  | [**EF\_DRIVER\_ERROR\_SPECIFIC**](#define-ef_driver_error_specific)  ((uint32\_t)6)<br>_Start of driver specific errors._ |
| define  | [**EF\_DRIVER\_ERROR\_TIMEOUT**](#define-ef_driver_error_timeout)  ((uint32\_t)3)<br>_Timeout occurred._ |
| define  | [**EF\_DRIVER\_ERROR\_UNSUPPORTED**](#define-ef_driver_error_unsupported)  ((uint32\_t)4)<br>_Operation not supported._ |
| define  | [**EF\_DRIVER\_OK**](#define-ef_driver_ok)  ((uint32\_t)0)<br>_Operation succeeded._ |

## Structures and Types Documentation

### typedef `EF_DRIVER_STATUS`

_A type that is used to return the status of the driver functions._
```c
typedef uint32_t EF_DRIVER_STATUS;
```



## Macros Documentation

### define `EF_DRIVER_ERROR`

_Unspecified error._
```c
#define EF_DRIVER_ERROR ((uint32_t)1)
```

### define `EF_DRIVER_ERROR_BUSY`

_Driver is busy._
```c
#define EF_DRIVER_ERROR_BUSY ((uint32_t)2)
```

### define `EF_DRIVER_ERROR_PARAMETER`

_Parameter error._
```c
#define EF_DRIVER_ERROR_PARAMETER ((uint32_t)5)
```

### define `EF_DRIVER_ERROR_SPECIFIC`

_Start of driver specific errors._
```c
#define EF_DRIVER_ERROR_SPECIFIC ((uint32_t)6)
```

### define `EF_DRIVER_ERROR_TIMEOUT`

_Timeout occurred._
```c
#define EF_DRIVER_ERROR_TIMEOUT ((uint32_t)3)
```

### define `EF_DRIVER_ERROR_UNSUPPORTED`

_Operation not supported._
```c
#define EF_DRIVER_ERROR_UNSUPPORTED ((uint32_t)4)
```

### define `EF_DRIVER_OK`

_Operation succeeded._
```c
#define EF_DRIVER_OK ((uint32_t)0)
```


## File EF_I2C.h

_C header file for I2C APIs which contains the function prototypes._




## Functions

| Type | Name |
| ---: | :--- |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getCommandReg**](#function-ef_i2c_getcommandreg) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t \*command\_value) <br>_Gets the value of the I2C command register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getDataLast**](#function-ef_i2c_getdatalast) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, bool \*data\_last) <br>_Reads the data last flag from the I2C data register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getDataReg**](#function-ef_i2c_getdatareg) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t \*data\_reg\_value) <br>_Reads the value from the I2C data register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getDataValid**](#function-ef_i2c_getdatavalid) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, bool \*data\_valid) <br>_Reads the data valid flag from the I2C data register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getIM**](#function-ef_i2c_getim) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t \*im\_value) <br>_Reads the Interrupt Mask (IM) register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getMIS**](#function-ef_i2c_getmis) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t \*mis\_value) <br>_Reads the Masked Interrupt Status (MIS) register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getPrescaler**](#function-ef_i2c_getprescaler) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t \*prescaler\_value) <br>_Gets the I2C prescaler value._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getRIS**](#function-ef_i2c_getris) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t \*ris\_value) <br>_Reads the Raw Interrupt Status (RIS) register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_readCmd**](#function-ef_i2c_readcmd) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char addr) <br>_Sends a read command to the specified address on the I2C bus._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_readCommand**](#function-ef_i2c_readcommand) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char addr) <br>_Issues an I2C read command to a specific address and waits for completion._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_readData**](#function-ef_i2c_readdata) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char \*data) <br>_Reads a data value from the I2C data register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setCommandReg**](#function-ef_i2c_setcommandreg) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t value) <br>_Sets the command register of the I2C controller._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setDataLast**](#function-ef_i2c_setdatalast) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, bool valid) <br>_Sets the data last flag in the I2C data register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setDataReg**](#function-ef_i2c_setdatareg) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t value) <br>_Writes a value to the I2C data register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setDataValid**](#function-ef_i2c_setdatavalid) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, bool valid) <br>_Sets the data valid flag in the I2C data register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setGclkEnable**](#function-ef_i2c_setgclkenable) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t value) <br>_Sets the GCLK enable bit in the I2C register to a certain value._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setIM**](#function-ef_i2c_setim) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t mask) <br>_Sets the Interrupt Mask (IM) register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setPrescaler**](#function-ef_i2c_setprescaler) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t value) <br>_Sets the I2C prescaler value._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_startCmd**](#function-ef_i2c_startcmd) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c) <br>_Issues a start condition on the I2C bus._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_stopCmd**](#function-ef_i2c_stopcmd) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c) <br>_Issues a stop condition on the I2C bus._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_waitBusy**](#function-ef_i2c_waitbusy) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_writeAddress**](#function-ef_i2c_writeaddress) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char addr) <br>_Writes an address to the I2C command register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_writeCmd**](#function-ef_i2c_writecmd) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char addr) <br>_Sends a write command to the specified address on the I2C bus._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_writeData**](#function-ef_i2c_writedata) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char data) <br>_Writes a data value to the I2C data register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_writeMultipleCmd**](#function-ef_i2c_writemultiplecmd) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c) <br>_Enables the write multiple command mode for the I2C controller._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_writeToAddress**](#function-ef_i2c_writetoaddress) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char addr, char data) <br>_Performs an I2C write operation to a specific address._ |



## Functions Documentation

### function `EF_I2C_getCommandReg`

_Gets the value of the I2C command register._
```c
EF_DRIVER_STATUS EF_I2C_getCommandReg (
    EF_I2C_TYPE_PTR i2c,
    uint32_t *command_value
) 
```


This function reads the current value of the I2C command register. It allows the user to retrieve the current configuration of the I2C controller for debugging or monitoring purposes.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `command_value` A pointer to a 32-bit variable where the command register value will be stored.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_getDataLast`

_Reads the data last flag from the I2C data register._
```c
EF_DRIVER_STATUS EF_I2C_getDataLast (
    EF_I2C_TYPE_PTR i2c,
    bool *data_last
) 
```


This function retrieves the current state of the data last flag in the I2C data register. The flag indicates whether the current data is the last in an I2C transaction.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `data_last` A pointer to a boolean variable where the state of the data last flag will be stored. The value is set to `true` if the data is the last in the transaction, or`false` otherwise.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_getDataReg`

_Reads the value from the I2C data register._
```c
EF_DRIVER_STATUS EF_I2C_getDataReg (
    EF_I2C_TYPE_PTR i2c,
    uint32_t *data_reg_value
) 
```


This function reads the 32-bit value from the I2C data register. The data register holds the I2C data (either for reading or writing) and status flags for data validity and the last byte in a block write.

Data Register Breakdown\*\*:

* Bits [0-7]: Data - Contains the data pulled from the read FIFO or to be pushed into the write FIFO.
* Bit [8]: Data Valid - Indicates whether the read data is valid.
* Bit [9]: Data Last - Indicates if the byte read or written is the last byte of a block write (write\_multiple).
* Bits [10-31]: Reserved - These bits are reserved.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `data_reg_value` A pointer to a 32-bit variable where the value of the data register will be stored.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_getDataValid`

_Reads the data valid flag from the I2C data register._
```c
EF_DRIVER_STATUS EF_I2C_getDataValid (
    EF_I2C_TYPE_PTR i2c,
    bool *data_valid
) 
```


This function retrieves the current state of the data valid flag in the I2C data register. The flag indicates whether the data is valid for an I2C transaction.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `data_valid` A pointer to a boolean variable where the state of the data valid flag will be stored. The value is set to `true` if the data is valid, or`false` otherwise.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_getIM`

_Reads the Interrupt Mask (IM) register._
```c
EF_DRIVER_STATUS EF_I2C_getIM (
    EF_I2C_TYPE_PTR i2c,
    uint32_t *im_value
) 
```


This function reads the interrupt mask register (IM) of the I2C peripheral. The IM register contains a mask value that determines which interrupt sources are enabled. It shows the status of interrupt enablement for various interrupt sources. IM Register Breakdown\*\*:

* Bit 0: MISS\_ACK - Slave ACK is missed
* Bit 1: CMDE - Command FIFO is Empty
* Bit 2: CMDF - Command FIFO is Full
* Bit 3: CMDOVF - Command FIFO overflow; write 1 to clear
* Bit 4: WRE - Write FIFO is Empty
* Bit 5: WRF - Write FIFO is Full
* Bit 6: WROVF - Write FIFO overflow; write 1 to clear
* Bit 7: RDE - Read FIFO is Empty
* Bit 8: RDF - Read FIFO is Full
* Bits [9-31]: Reserved. 

**Parameters:**


  * `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
  * `im_value` A pointer to a 32-bit variable where the interrupt mask value will be stored.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_getMIS`

_Reads the Masked Interrupt Status (MIS) register._
```c
EF_DRIVER_STATUS EF_I2C_getMIS (
    EF_I2C_TYPE_PTR i2c,
    uint32_t *mis_value
) 
```


This function reads the masked interrupt status register (MIS) of the I2C peripheral. MIS Register Breakdown\*\*:

* Bit 0: MISS\_ACK - Slave ACK is missed
* Bit 1: CMDE - Command FIFO is Empty
* Bit 2: CMDF - Command FIFO is Full
* Bit 3: CMDOVF - Command FIFO overflow; write 1 to clear
* Bit 4: WRE - Write FIFO is Empty
* Bit 5: WRF - Write FIFO is Full
* Bit 6: WROVF - Write FIFO overflow; write 1 to clear
* Bit 7: RDE - Read FIFO is Empty
* Bit 8: RDF - Read FIFO is Full
* Bits [9-31]: Reserved.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `mis_value` A pointer to a 32-bit variable where the masked interrupt status will be stored.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_getPrescaler`

_Gets the I2C prescaler value._
```c
EF_DRIVER_STATUS EF_I2C_getPrescaler (
    EF_I2C_TYPE_PTR i2c,
    uint32_t *prescaler_value
) 
```


This function reads the current prescaler value from the I2C peripheral. The prescaler determines the clock frequency for the I2C communication.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `prescaler_value` A pointer to a 32-bit variable where the current prescaler value will be stored.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_getRIS`

_Reads the Raw Interrupt Status (RIS) register._
```c
EF_DRIVER_STATUS EF_I2C_getRIS (
    EF_I2C_TYPE_PTR i2c,
    uint32_t *ris_value
) 
```


This function reads the raw interrupt status register (RIS) of the I2C peripheral. The RIS register provides raw interrupt status flags indicating various conditions within the I2C communication. These flags include information such as FIFO states and errors.

RIS Register Breakdown\*\*:

* Bit 0: MISS\_ACK - Slave ACK is missed
* Bit 1: CMDE - Command FIFO is Empty
* Bit 2: CMDF - Command FIFO is Full
* Bit 3: CMDOVF - Command FIFO overflow; write 1 to clear
* Bit 4: WRE - Write FIFO is Empty
* Bit 5: WRF - Write FIFO is Full
* Bit 6: WROVF - Write FIFO overflow; write 1 to clear
* Bit 7: RDE - Read FIFO is Empty
* Bit 8: RDF - Read FIFO is Full
* Bits [9-31]: Reserved.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `ris_value` A pointer to a 32-bit variable where the raw interrupt status will be stored.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_readCmd`

_Sends a read command to the specified address on the I2C bus._
```c
EF_DRIVER_STATUS EF_I2C_readCmd (
    EF_I2C_TYPE_PTR i2c,
    char addr
) 
```


This function configures the I2C controller to read from the specified address on the I2C bus. It sets the read bit and writes the target address into the I2C command register.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `addr` The target address on the I2C bus to read from. This is typically a 7-bit or 10-bit address.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_readCommand`

_Issues an I2C read command to a specific address and waits for completion._
```c
EF_DRIVER_STATUS EF_I2C_readCommand (
    EF_I2C_TYPE_PTR i2c,
    char addr
) 
```


This function initiates a read operation on the I2C bus. It performs the following steps:

* Sends a read command to the specified address on the I2C bus.
* Issues a stop condition to signal the end of the transaction.
* Waits for the I2C hardware to complete the read operation.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) , which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `addr` The address on the I2C bus from which to read.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_readData`

_Reads a data value from the I2C data register._
```c
EF_DRIVER_STATUS EF_I2C_readData (
    EF_I2C_TYPE_PTR i2c,
    char *data
) 
```


This function reads the current value of the I2C data register. The data register is used to store the data to be transmitted or received over the I2C bus. read to pull from read data FIFO.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `data` A pointer to an 8-bit variable where the data register value will be stored.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_setCommandReg`

_Sets the command register of the I2C controller._
```c
EF_DRIVER_STATUS EF_I2C_setCommandReg (
    EF_I2C_TYPE_PTR i2c,
    uint32_t value
) 
```


This function writes a specified value directly to the I2C command register. It allows manual configuration of the I2C controller for advanced or custom operations.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `value` The 32-bit value to write to the I2C command register. This value typically contains specific bit fields to configure the I2C operation.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_setDataLast`

_Sets the data last flag in the I2C data register._
```c
EF_DRIVER_STATUS EF_I2C_setDataLast (
    EF_I2C_TYPE_PTR i2c,
    bool valid
) 
```


This function modifies the data last flag in the I2C data register. The flag indicates whether the current data is the last in an I2C transaction.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `valid` A boolean value specifying the state of the data last flag. Set to `true` to mark the data as the last in the transaction, or`false` to clear the flag.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_setDataReg`

_Writes a value to the I2C data register._
```c
EF_DRIVER_STATUS EF_I2C_setDataReg (
    EF_I2C_TYPE_PTR i2c,
    uint32_t value
) 
```


This function writes a 32-bit value to the I2C data register. The data register is used for handling the I2C read and write FIFOs, along with managing data validity and the last byte flag. 

Data Register Breakdown\*\*:

* Bits [0-7]: Data - Used to push data into the write FIFO or pull data from the read FIFO.
* Bit [8]: Data Valid - Indicates whether the read data is valid. Must be accessed atomically with 16-bit reads and writes.
* Bit [9]: Data Last - Indicates the last byte of a block write (write\_multiple). Must be accessed atomically with 16-bit reads and writes.
* Bits [10-31]: Reserved - These bits are reserved for future use and should always be written as zero to avoid undefined behavior.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `value` A 32-bit value to write to the data register. The value should include all relevant fields (data, data valid, data last) as specified in the register breakdown. 
 The reserved bits (10-31) must always be set to zero.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_setDataValid`

_Sets the data valid flag in the I2C data register._
```c
EF_DRIVER_STATUS EF_I2C_setDataValid (
    EF_I2C_TYPE_PTR i2c,
    bool valid
) 
```


This function modifies the data valid flag in the I2C data register. The flag indicates whether the current data in the register is valid for an I2C transaction.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `valid` A boolean value specifying the state of the data valid flag. Set to `true` to mark the data as valid, or`false` to clear the flag.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_setGclkEnable`

_Sets the GCLK enable bit in the I2C register to a certain value._
```c
EF_DRIVER_STATUS EF_I2C_setGclkEnable (
    EF_I2C_TYPE_PTR i2c,
    uint32_t value
) 
```


**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) , which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `value` The value of the GCLK enable bit


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_setIM`

_Sets the Interrupt Mask (IM) register._
```c
EF_DRIVER_STATUS EF_I2C_setIM (
    EF_I2C_TYPE_PTR i2c,
    uint32_t mask
) 
```


This function writes a mask value to the interrupt mask register (IM) of the I2C peripheral. The IM register enables or disables the interrupt sources. The bits set in this register determine which interrupt sources generate masked interrupts. IM Register Breakdown\*\*:

* Bit 0: MISS\_ACK - Slave ACK is missed
* Bit 1: CMDE - Command FIFO is Empty
* Bit 2: CMDF - Command FIFO is Full
* Bit 3: CMDOVF - Command FIFO overflow; write 1 to clear
* Bit 4: WRE - Write FIFO is Empty
* Bit 5: WRF - Write FIFO is Full
* Bit 6: WROVF - Write FIFO overflow; write 1 to clear
* Bit 7: RDE - Read FIFO is Empty
* Bit 8: RDF - Read FIFO is Full
* Bits [9-31]: Reserved. 

**Parameters:**


  * `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
  * `mask` A 32-bit mask value to be written to the IM register. Each bit corresponds to a specific interrupt source, with 1 enabling the interrupt and 0 disabling it.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_setPrescaler`

_Sets the I2C prescaler value._
```c
EF_DRIVER_STATUS EF_I2C_setPrescaler (
    EF_I2C_TYPE_PTR i2c,
    uint32_t value
) 
```


This function sets the prescaler value for the I2C peripheral. The prescaler is used to configure the speed of the I2C communication by adjusting the clock frequency.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `value` The prescaler value to set for the I2C clock. This value determines the clock frequency for I2C communication.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_startCmd`

_Issues a start condition on the I2C bus._
```c
EF_DRIVER_STATUS EF_I2C_startCmd (
    EF_I2C_TYPE_PTR i2c
) 
```


This function sends a start condition to initiate an I2C transaction. The start condition is a signal to indicate the beginning of communication with an I2C device.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_stopCmd`

_Issues a stop condition on the I2C bus._
```c
EF_DRIVER_STATUS EF_I2C_stopCmd (
    EF_I2C_TYPE_PTR i2c
) 
```


This function sends a stop condition, signaling the end of an I2C transaction. The stop condition releases the I2C bus for other devices to communicate.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_waitBusy`

```c
EF_DRIVER_STATUS EF_I2C_waitBusy (
    EF_I2C_TYPE_PTR i2c
) 
```


! Sets the Interrupt Clear (ICR) register. \*!
### function `EF_I2C_writeAddress`

_Writes an address to the I2C command register._
```c
EF_DRIVER_STATUS EF_I2C_writeAddress (
    EF_I2C_TYPE_PTR i2c,
    char addr
) 
```


This function writes an address to the I2C command register. It performs the following steps:

* Clears the field bits in the register using the defined mask.
* Sets the bits with the given value at the defined offset.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) , which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `addr` The address to write to


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_writeCmd`

_Sends a write command to the specified address on the I2C bus._
```c
EF_DRIVER_STATUS EF_I2C_writeCmd (
    EF_I2C_TYPE_PTR i2c,
    char addr
) 
```


This function configures the I2C controller to write to the specified address on the I2C bus. It sets the write bit and writes the target address into the I2C command register.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `addr` The target address on the I2C bus to write to. This is typically a 7-bit or 10-bit address.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_writeData`

_Writes a data value to the I2C data register._
```c
EF_DRIVER_STATUS EF_I2C_writeData (
    EF_I2C_TYPE_PTR i2c,
    char data
) 
```


This function writes a data value to the I2C data register. The data register is used to store the data to be transmitted or received over the I2C bus. write to push on write data FIFO, read to pull from read data FIFO.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `data` The 8-bit data value to write to the I2C data register.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_writeMultipleCmd`

_Enables the write multiple command mode for the I2C controller._
```c
EF_DRIVER_STATUS EF_I2C_writeMultipleCmd (
    EF_I2C_TYPE_PTR i2c
) 
```


This function configures the I2C controller to enter write multiple command mode, allowing consecutive data writes without sending a stop condition between each write.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_writeToAddress`

_Performs an I2C write operation to a specific address._
```c
EF_DRIVER_STATUS EF_I2C_writeToAddress (
    EF_I2C_TYPE_PTR i2c,
    char addr,
    char data
) 
```


This function enables communication over the I2C bus by writing a single data byte to a specific address. It follows the standard I2C sequence for writing:

* Loads the data to be sent into the I2C data buffer.
* Sends the target device address as a command.
* Issues a stop condition to signal the end of the transaction.
* Waits for the I2C hardware to complete the operation.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) , which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `addr` The address to write to 
* `data` The data to write


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code


## File EF_I2C_regs.h





## Structures and Types

| Type | Name |
| ---: | :--- |
| typedef struct [**\_EF\_I2C\_TYPE\_**](#struct-_ef_i2c_type_) | [**EF\_I2C\_TYPE**](#typedef-ef_i2c_type)  <br> |
| typedef [**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) \* | [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr)  <br> |
| struct | [**\_EF\_I2C\_TYPE\_**](#struct-_ef_i2c_type_) <br> |


## Macros

| Type | Name |
| ---: | :--- |
| define  | [**EF\_I2C\_CMDE\_FLAG**](#define-ef_i2c_cmde_flag)  ((uint32\_t)0x2)<br> |
| define  | [**EF\_I2C\_CMDF\_FLAG**](#define-ef_i2c_cmdf_flag)  ((uint32\_t)0x4)<br> |
| define  | [**EF\_I2C\_CMDOVF\_FLAG**](#define-ef_i2c_cmdovf_flag)  ((uint32\_t)0x8)<br> |
| define  | [**EF\_I2C\_COMMAND\_REG\_CMD\_ADDRESS\_BIT**](#define-ef_i2c_command_reg_cmd_address_bit)  ((uint32\_t)0)<br> |
| define  | [**EF\_I2C\_COMMAND\_REG\_CMD\_ADDRESS\_MASK**](#define-ef_i2c_command_reg_cmd_address_mask)  ((uint32\_t)0x7f)<br> |
| define  | [**EF\_I2C\_COMMAND\_REG\_CMD\_READ\_BIT**](#define-ef_i2c_command_reg_cmd_read_bit)  ((uint32\_t)9)<br> |
| define  | [**EF\_I2C\_COMMAND\_REG\_CMD\_READ\_MASK**](#define-ef_i2c_command_reg_cmd_read_mask)  ((uint32\_t)0x200)<br> |
| define  | [**EF\_I2C\_COMMAND\_REG\_CMD\_START\_BIT**](#define-ef_i2c_command_reg_cmd_start_bit)  ((uint32\_t)8)<br> |
| define  | [**EF\_I2C\_COMMAND\_REG\_CMD\_START\_MASK**](#define-ef_i2c_command_reg_cmd_start_mask)  ((uint32\_t)0x100)<br> |
| define  | [**EF\_I2C\_COMMAND\_REG\_CMD\_STOP\_BIT**](#define-ef_i2c_command_reg_cmd_stop_bit)  ((uint32\_t)12)<br> |
| define  | [**EF\_I2C\_COMMAND\_REG\_CMD\_STOP\_MASK**](#define-ef_i2c_command_reg_cmd_stop_mask)  ((uint32\_t)0x1000)<br> |
| define  | [**EF\_I2C\_COMMAND\_REG\_CMD\_WRITE\_BIT**](#define-ef_i2c_command_reg_cmd_write_bit)  ((uint32\_t)10)<br> |
| define  | [**EF\_I2C\_COMMAND\_REG\_CMD\_WRITE\_MASK**](#define-ef_i2c_command_reg_cmd_write_mask)  ((uint32\_t)0x400)<br> |
| define  | [**EF\_I2C\_COMMAND\_REG\_CMD\_WRITE\_MULTIPLE\_BIT**](#define-ef_i2c_command_reg_cmd_write_multiple_bit)  ((uint32\_t)11)<br> |
| define  | [**EF\_I2C\_COMMAND\_REG\_CMD\_WRITE\_MULTIPLE\_MASK**](#define-ef_i2c_command_reg_cmd_write_multiple_mask)  ((uint32\_t)0x800)<br> |
| define  | [**EF\_I2C\_DATA\_REG\_DATA\_BIT**](#define-ef_i2c_data_reg_data_bit)  ((uint32\_t)0)<br> |
| define  | [**EF\_I2C\_DATA\_REG\_DATA\_LAST\_BIT**](#define-ef_i2c_data_reg_data_last_bit)  ((uint32\_t)9)<br> |
| define  | [**EF\_I2C\_DATA\_REG\_DATA\_LAST\_MASK**](#define-ef_i2c_data_reg_data_last_mask)  ((uint32\_t)0x200)<br> |
| define  | [**EF\_I2C\_DATA\_REG\_DATA\_MASK**](#define-ef_i2c_data_reg_data_mask)  ((uint32\_t)0xff)<br> |
| define  | [**EF\_I2C\_DATA\_REG\_DATA\_VALID\_BIT**](#define-ef_i2c_data_reg_data_valid_bit)  ((uint32\_t)8)<br> |
| define  | [**EF\_I2C\_DATA\_REG\_DATA\_VALID\_MASK**](#define-ef_i2c_data_reg_data_valid_mask)  ((uint32\_t)0x100)<br> |
| define  | [**EF\_I2C\_MISS\_ACK\_FLAG**](#define-ef_i2c_miss_ack_flag)  ((uint32\_t)0x1)<br> |
| define  | [**EF\_I2C\_RDE\_FLAG**](#define-ef_i2c_rde_flag)  ((uint32\_t)0x80)<br> |
| define  | [**EF\_I2C\_RDF\_FLAG**](#define-ef_i2c_rdf_flag)  ((uint32\_t)0x100)<br> |
| define  | [**EF\_I2C\_WRE\_FLAG**](#define-ef_i2c_wre_flag)  ((uint32\_t)0x10)<br> |
| define  | [**EF\_I2C\_WRF\_FLAG**](#define-ef_i2c_wrf_flag)  ((uint32\_t)0x20)<br> |
| define  | [**EF\_I2C\_WROVF\_FLAG**](#define-ef_i2c_wrovf_flag)  ((uint32\_t)0x40)<br> |
| define  | [**IO\_TYPES**](#define-io_types)  <br> |
| define  | [**\_\_R**](#define-__r)  volatile const uint32\_t<br> |
| define  | [**\_\_RW**](#define-__rw)  volatile       uint32\_t<br> |
| define  | [**\_\_W**](#define-__w)  volatile       uint32\_t<br> |

## Structures and Types Documentation

### typedef `EF_I2C_TYPE`

```c
typedef struct _EF_I2C_TYPE_ EF_I2C_TYPE;
```

### typedef `EF_I2C_TYPE_PTR`

```c
typedef EF_I2C_TYPE* EF_I2C_TYPE_PTR;
```

### struct `_EF_I2C_TYPE_`


Variables:

-  [**\_\_W**](#define-__w) COMMAND  

-  [**\_\_RW**](#define-__rw) DATA  

-  [**\_\_W**](#define-__w) GCLK  

-  [**\_\_RW**](#define-__rw) IM  

-  [**\_\_R**](#define-__r) MIS  

-  [**\_\_W**](#define-__w) PR  

-  [**\_\_R**](#define-__r) RIS  

-  [**\_\_R**](#define-__r) STATUS  

-  [**\_\_R**](#define-__r) reserved_1  

-  [**\_\_R**](#define-__r) reserved_2  



## Macros Documentation

### define `EF_I2C_CMDE_FLAG`

```c
#define EF_I2C_CMDE_FLAG ((uint32_t)0x2)
```

### define `EF_I2C_CMDF_FLAG`

```c
#define EF_I2C_CMDF_FLAG ((uint32_t)0x4)
```

### define `EF_I2C_CMDOVF_FLAG`

```c
#define EF_I2C_CMDOVF_FLAG ((uint32_t)0x8)
```

### define `EF_I2C_COMMAND_REG_CMD_ADDRESS_BIT`

```c
#define EF_I2C_COMMAND_REG_CMD_ADDRESS_BIT ((uint32_t)0)
```

### define `EF_I2C_COMMAND_REG_CMD_ADDRESS_MASK`

```c
#define EF_I2C_COMMAND_REG_CMD_ADDRESS_MASK ((uint32_t)0x7f)
```

### define `EF_I2C_COMMAND_REG_CMD_READ_BIT`

```c
#define EF_I2C_COMMAND_REG_CMD_READ_BIT ((uint32_t)9)
```

### define `EF_I2C_COMMAND_REG_CMD_READ_MASK`

```c
#define EF_I2C_COMMAND_REG_CMD_READ_MASK ((uint32_t)0x200)
```

### define `EF_I2C_COMMAND_REG_CMD_START_BIT`

```c
#define EF_I2C_COMMAND_REG_CMD_START_BIT ((uint32_t)8)
```

### define `EF_I2C_COMMAND_REG_CMD_START_MASK`

```c
#define EF_I2C_COMMAND_REG_CMD_START_MASK ((uint32_t)0x100)
```

### define `EF_I2C_COMMAND_REG_CMD_STOP_BIT`

```c
#define EF_I2C_COMMAND_REG_CMD_STOP_BIT ((uint32_t)12)
```

### define `EF_I2C_COMMAND_REG_CMD_STOP_MASK`

```c
#define EF_I2C_COMMAND_REG_CMD_STOP_MASK ((uint32_t)0x1000)
```

### define `EF_I2C_COMMAND_REG_CMD_WRITE_BIT`

```c
#define EF_I2C_COMMAND_REG_CMD_WRITE_BIT ((uint32_t)10)
```

### define `EF_I2C_COMMAND_REG_CMD_WRITE_MASK`

```c
#define EF_I2C_COMMAND_REG_CMD_WRITE_MASK ((uint32_t)0x400)
```

### define `EF_I2C_COMMAND_REG_CMD_WRITE_MULTIPLE_BIT`

```c
#define EF_I2C_COMMAND_REG_CMD_WRITE_MULTIPLE_BIT ((uint32_t)11)
```

### define `EF_I2C_COMMAND_REG_CMD_WRITE_MULTIPLE_MASK`

```c
#define EF_I2C_COMMAND_REG_CMD_WRITE_MULTIPLE_MASK ((uint32_t)0x800)
```

### define `EF_I2C_DATA_REG_DATA_BIT`

```c
#define EF_I2C_DATA_REG_DATA_BIT ((uint32_t)0)
```

### define `EF_I2C_DATA_REG_DATA_LAST_BIT`

```c
#define EF_I2C_DATA_REG_DATA_LAST_BIT ((uint32_t)9)
```

### define `EF_I2C_DATA_REG_DATA_LAST_MASK`

```c
#define EF_I2C_DATA_REG_DATA_LAST_MASK ((uint32_t)0x200)
```

### define `EF_I2C_DATA_REG_DATA_MASK`

```c
#define EF_I2C_DATA_REG_DATA_MASK ((uint32_t)0xff)
```

### define `EF_I2C_DATA_REG_DATA_VALID_BIT`

```c
#define EF_I2C_DATA_REG_DATA_VALID_BIT ((uint32_t)8)
```

### define `EF_I2C_DATA_REG_DATA_VALID_MASK`

```c
#define EF_I2C_DATA_REG_DATA_VALID_MASK ((uint32_t)0x100)
```

### define `EF_I2C_MISS_ACK_FLAG`

```c
#define EF_I2C_MISS_ACK_FLAG ((uint32_t)0x1)
```

### define `EF_I2C_RDE_FLAG`

```c
#define EF_I2C_RDE_FLAG ((uint32_t)0x80)
```

### define `EF_I2C_RDF_FLAG`

```c
#define EF_I2C_RDF_FLAG ((uint32_t)0x100)
```

### define `EF_I2C_WRE_FLAG`

```c
#define EF_I2C_WRE_FLAG ((uint32_t)0x10)
```

### define `EF_I2C_WRF_FLAG`

```c
#define EF_I2C_WRF_FLAG ((uint32_t)0x20)
```

### define `EF_I2C_WROVF_FLAG`

```c
#define EF_I2C_WROVF_FLAG ((uint32_t)0x40)
```

### define `IO_TYPES`

```c
#define IO_TYPES 
```

### define `__R`

```c
#define __R volatile const uint32_t
```

### define `__RW`

```c
#define __RW volatile       uint32_t
```

### define `__W`

```c
#define __W volatile       uint32_t
```


