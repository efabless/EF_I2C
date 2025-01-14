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
| define  | [**EF\_DRIVER\_ERROR\_I2C\_INVALID\_DATA**](#define-ef_driver_error_i2c_invalid_data)  ((uint32\_t)7)<br>_Invalid I2C data._ |
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

### define `EF_DRIVER_ERROR_I2C_INVALID_DATA`

_Invalid I2C data._
```c
#define EF_DRIVER_ERROR_I2C_INVALID_DATA ((uint32_t)7)
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
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getDataLast**](#function-ef_i2c_getdatalast) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, bool \*data\_last) <br>_Reads the data last flag from the I2C data register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getDataValid**](#function-ef_i2c_getdatavalid) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, bool \*data\_valid) <br>_Reads the data valid flag from the I2C data register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getIM**](#function-ef_i2c_getim) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t \*im\_value) <br>_Reads the Interrupt Mask (IM) register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getMIS**](#function-ef_i2c_getmis) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t \*mis\_value) <br>_Reads the Masked Interrupt Status (MIS) register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getPrescaler**](#function-ef_i2c_getprescaler) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t \*prescaler\_value) <br>_Gets the I2C prescaler value._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getRIS**](#function-ef_i2c_getris) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t \*ris\_value) <br>_Reads the Raw Interrupt Status (RIS) register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_isBusy**](#function-ef_i2c_isbusy) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, bool \*is\_busy) <br>_Checks if the I2C peripheral is busy._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_isCommandFIFOAvailable**](#function-ef_i2c_iscommandfifoavailable) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, bool \*is\_available) <br>_Checks if the command FIFO is available._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_isReadFIFOAvailable**](#function-ef_i2c_isreadfifoavailable) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, bool \*is\_available) <br>_Checks if the read FIFO is available._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_isWriteFIFOAvailable**](#function-ef_i2c_iswritefifoavailable) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, bool \*is\_available) <br>_Checks if the write FIFO is available._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_readDataFromReadFIFO**](#function-ef_i2c_readdatafromreadfifo) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char \*data) <br>_Reads data from the I2C Read FIFO (blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_readDataFromReadFIFONonBlocking**](#function-ef_i2c_readdatafromreadfifononblocking) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char \*data, bool \*data\_read) <br>_Reads data from the I2C Read FIFO (non-blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_receiveByte**](#function-ef_i2c_receivebyte) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char \*data, char addr) <br>_Receives a single byte from a specified I2C address (blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_receiveByteNonBlocking**](#function-ef_i2c_receivebytenonblocking) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char \*data, char addr, bool \*received) <br>_Receives a single byte from a specified I2C address (non-blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_recieveCharArr**](#function-ef_i2c_recievechararr) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char \*data, uint32\_t data\_length, char addr) <br>_Receives an array of characters from a specified I2C address (blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_sendReadCommand**](#function-ef_i2c_sendreadcommand) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char addr) <br>_Sends a read command to the I2C device (blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_sendReadCommandNonBlocking**](#function-ef_i2c_sendreadcommandnonblocking) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char addr, bool \*command\_sent) <br>_Sends a read command to the I2C device (non-blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_sendStartCommand**](#function-ef_i2c_sendstartcommand) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c) <br>_Sends a start condition on the I2C bus (blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_sendStartCommandNonBlocking**](#function-ef_i2c_sendstartcommandnonblocking) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, bool \*command\_sent) <br>_Sends a start condition on the I2C bus (non-blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_sendStopCommand**](#function-ef_i2c_sendstopcommand) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c) <br>_Sends a stop condition on the I2C bus (blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_sendStopCommandNonBlocking**](#function-ef_i2c_sendstopcommandnonblocking) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, bool \*command\_sent) <br>_Sends a stop condition on the I2C bus (non-blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_sendWriteCommand**](#function-ef_i2c_sendwritecommand) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char addr) <br>_Sends a write command to the I2C device (blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_sendWriteCommandNonBlocking**](#function-ef_i2c_sendwritecommandnonblocking) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char addr, bool \*command\_sent) <br>_Sends a write command to the I2C device (non-blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_sendWriteMultipleCommand**](#function-ef_i2c_sendwritemultiplecommand) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c) <br>_Sends a "write multiple" command on the I2C bus (blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_sendWriteMultipleCommandNonBlocking**](#function-ef_i2c_sendwritemultiplecommandnonblocking) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, bool \*command\_sent) <br>_Sends a "write multiple" command on the I2C bus (non-blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setCommandReg**](#function-ef_i2c_setcommandreg) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t value) <br>_Sets the command register of the I2C controller._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setCommandRegNonBlocking**](#function-ef_i2c_setcommandregnonblocking) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t value, bool \*command\_sent) <br>_Writes a command value to the I2C command register (non-blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setDataLast**](#function-ef_i2c_setdatalast) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c) <br>_Sets the data last flag in the I2C data register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setGclkEnable**](#function-ef_i2c_setgclkenable) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t value) <br>_Sets the GCLK enable bit in the I2C register to a certain value._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setIM**](#function-ef_i2c_setim) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t mask) <br>_Sets the Interrupt Mask (IM) register._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setPrescaler**](#function-ef_i2c_setprescaler) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, uint32\_t value) <br>_Sets the I2C prescaler value._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_transmitByte**](#function-ef_i2c_transmitbyte) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char data, char addr) <br>_Transmits a single byte to a specified I2C address (blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_transmitByteNonBlocking**](#function-ef_i2c_transmitbytenonblocking) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char data, char addr, bool \*transmitted) <br>_Transmits a single byte to a specified I2C address (non-blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_transmitCharArr**](#function-ef_i2c_transmitchararr) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char \*data, uint32\_t data\_length, char addr) <br>_Transmits an array of characters to a specified I2C address (blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_writeDataToWriteFIFO**](#function-ef_i2c_writedatatowritefifo) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char data) <br>_Writes data to the I2C Write FIFO (blocking)._ |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_writeDataToWriteFIFONonBlocking**](#function-ef_i2c_writedatatowritefifononblocking) ([**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr) i2c, char data, bool \*data\_written) <br>_Writes data to the I2C Write FIFO (non-blocking)._ |

## Macros

| Type | Name |
| ---: | :--- |
| define  | [**EF\_I2C\_COMMAND\_REG\_CMD\_CORRECT\_MASK**](#define-ef_i2c_command_reg_cmd_correct_mask)  0xFFFFE080<br> |
| define  | [**EF\_I2C\_IC\_REG\_MAX\_VALUE**](#define-ef_i2c_ic_reg_max_value)  0x000001FF<br> |
| define  | [**EF\_I2C\_IM\_REG\_MAX\_VALUE**](#define-ef_i2c_im_reg_max_value)  0x000001FF<br> |
| define  | [**EF\_I2C\_PR\_MAX\_VALUE**](#define-ef_i2c_pr_max_value)  0x0000FFFF<br> |


## Functions Documentation

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
### function `EF_I2C_isBusy`

_Checks if the I2C peripheral is busy._
```c
EF_DRIVER_STATUS EF_I2C_isBusy (
    EF_I2C_TYPE_PTR i2c,
    bool *is_busy
) 
```


! Sets the Interrupt Clear (ICR) register. \*!

This function checks the `STATUS` register of the I2C peripheral to determine if the bus is currently busy. The result is stored in the memory location pointed to by`is_busy`.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `is_busy` Pointer to a boolean where the busy status will be stored:

  * `true`: I2C is busy.
  * `false`: I2C is idle.


**Returns:**

status A value of type EF\_DRIVER\_STATUS:

* EF\_DRIVER\_OK: The operation completed successfully.
* EF\_DRIVER\_ERROR\_PARAMETER: `i2c` or`is_busy` is NULL.
### function `EF_I2C_isCommandFIFOAvailable`

_Checks if the command FIFO is available._
```c
EF_DRIVER_STATUS EF_I2C_isCommandFIFOAvailable (
    EF_I2C_TYPE_PTR i2c,
    bool *is_available
) 
```


This function checks the `STATUS` register of the I2C peripheral to determine if the command FIFO is not full and ready to accept new commands. The result is stored in the memory location pointed to by`is_available`.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `is_available` Pointer to a boolean where the availability status will be stored:

  * `true`: Command FIFO is available.
  * `false`: Command FIFO is full.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_isReadFIFOAvailable`

_Checks if the read FIFO is available._
```c
EF_DRIVER_STATUS EF_I2C_isReadFIFOAvailable (
    EF_I2C_TYPE_PTR i2c,
    bool *is_available
) 
```


This function checks the `STATUS` register of the I2C peripheral to determine if the read FIFO is not empty and has data available to be read. The result is stored in the memory location pointed to by`is_available`.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `is_available` Pointer to a boolean where the availability status will be stored:

  * `true`: Read FIFO is available.
  * `false`: Read FIFO is empty.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_isWriteFIFOAvailable`

_Checks if the write FIFO is available._
```c
EF_DRIVER_STATUS EF_I2C_isWriteFIFOAvailable (
    EF_I2C_TYPE_PTR i2c,
    bool *is_available
) 
```


This function checks the `STATUS` register of the I2C peripheral to determine if the write FIFO is not full and ready to accept new data. The result is stored in the memory location pointed to by`is_available`.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `is_available` Pointer to a boolean where the availability status will be stored:

  * `true`: Write FIFO is available.
  * `false`: Write FIFO is full.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_readDataFromReadFIFO`

_Reads data from the I2C Read FIFO (blocking)._
```c
EF_DRIVER_STATUS EF_I2C_readDataFromReadFIFO (
    EF_I2C_TYPE_PTR i2c,
    char *data
) 
```


This function reads a single byte of data from the I2C Read FIFO. It blocks until the FIFO becomes available and validates the data read.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `data` Pointer to a variable where the read data byte will be stored.


**Returns:**

status A value of type EF\_DRIVER\_STATUS:

* EF\_DRIVER\_OK: The operation completed successfully.
* EF\_DRIVER\_ERROR\_PARAMETER: `i2c` or`data` is NULL.
* EF\_DRIVER\_ERROR\_I2C\_INVALID\_DATA: The data read is invalid.
### function `EF_I2C_readDataFromReadFIFONonBlocking`

_Reads data from the I2C Read FIFO (non-blocking)._
```c
EF_DRIVER_STATUS EF_I2C_readDataFromReadFIFONonBlocking (
    EF_I2C_TYPE_PTR i2c,
    char *data,
    bool *data_read
) 
```


This function attempts to read a single byte of data from the I2C Read FIFO. If the FIFO is unavailable, the function returns immediately. The validity of the data is also checked.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `data` Pointer to a variable where the read data byte will be stored. 
* `data_read` Pointer to a boolean where the read status will be stored:

  * `true`: Data was read successfully and is valid.
  * `false`: Read FIFO was unavailable or data is invalid.


**Returns:**

status A value of type EF\_DRIVER\_STATUS:

* EF\_DRIVER\_OK: The operation completed successfully.
* EF\_DRIVER\_ERROR\_PARAMETER: `i2c`,`data`, or`data_read` is NULL.
* EF\_DRIVER\_ERROR\_I2C\_INVALID\_DATA: The data read is invalid.
### function `EF_I2C_receiveByte`

_Receives a single byte from a specified I2C address (blocking)._
```c
EF_DRIVER_STATUS EF_I2C_receiveByte (
    EF_I2C_TYPE_PTR i2c,
    char *data,
    char addr
) 
```


This function reads a single byte from a specified I2C address. It blocks until all operations (read command, stop command, and data retrieval) are completed.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `data` Pointer to a char where the received data byte will be stored. 
* `addr` I2C address from which the data will be read.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_receiveByteNonBlocking`

_Receives a single byte from a specified I2C address (non-blocking)._
```c
EF_DRIVER_STATUS EF_I2C_receiveByteNonBlocking (
    EF_I2C_TYPE_PTR i2c,
    char *data,
    char addr,
    bool *received
) 
```


This function attempts to read a single byte from a specified I2C address in a non-blocking manner. If any step of the process (read command, stop command, or data retrieval) cannot complete immediately, the function returns.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `data` Pointer to a char where the received data byte will be stored. 
* `addr` I2C address from which the data will be read. 
* `received` Pointer to a boolean where the reception status will be stored:

  * `true`: Data was received successfully.
  * `false`: Reception could not be completed.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_recieveCharArr`

_Receives an array of characters from a specified I2C address (blocking)._
```c
EF_DRIVER_STATUS EF_I2C_recieveCharArr (
    EF_I2C_TYPE_PTR i2c,
    char *data,
    uint32_t data_length,
    char addr
) 
```


This function reads an array of characters from a specified I2C address. It issues the read command for each byte, stores the data in the provided buffer, and sends a stop command after successful reception.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `data` Pointer to the buffer where the received characters will be stored. 
* `data_length` Number of characters to receive. 
* `addr` I2C address from which the data will be read.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_sendReadCommand`

_Sends a read command to the I2C device (blocking)._
```c
EF_DRIVER_STATUS EF_I2C_sendReadCommand (
    EF_I2C_TYPE_PTR i2c,
    char addr
) 
```


This function sends a read command to the I2C device at the specified address. It blocks until the command FIFO becomes available.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `addr` The I2C address of the target device.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_sendReadCommandNonBlocking`

_Sends a read command to the I2C device (non-blocking)._
```c
EF_DRIVER_STATUS EF_I2C_sendReadCommandNonBlocking (
    EF_I2C_TYPE_PTR i2c,
    char addr,
    bool *command_sent
) 
```


This function attempts to send a read command to the I2C device at the specified address. If the command FIFO is unavailable, the function returns immediately.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `addr` The I2C address of the target device. 
* `command_sent` Pointer to a boolean where the command status will be stored:

  * `true`: Command was sent successfully.
  * `false`: Command FIFO was unavailable.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_sendStartCommand`

_Sends a start condition on the I2C bus (blocking)._
```c
EF_DRIVER_STATUS EF_I2C_sendStartCommand (
    EF_I2C_TYPE_PTR i2c
) 
```


This function sends a start condition on the I2C bus. It blocks until the command FIFO becomes available.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_sendStartCommandNonBlocking`

_Sends a start condition on the I2C bus (non-blocking)._
```c
EF_DRIVER_STATUS EF_I2C_sendStartCommandNonBlocking (
    EF_I2C_TYPE_PTR i2c,
    bool *command_sent
) 
```


This function attempts to send a start condition on the I2C bus. If the command FIFO is unavailable, the function returns immediately.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `command_sent` Pointer to a boolean where the command status will be stored:

  * `true`: Start condition was sent successfully.
  * `false`: Command FIFO was unavailable.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_sendStopCommand`

_Sends a stop condition on the I2C bus (blocking)._
```c
EF_DRIVER_STATUS EF_I2C_sendStopCommand (
    EF_I2C_TYPE_PTR i2c
) 
```


This function sends a stop condition on the I2C bus. It blocks until the command FIFO becomes available.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_sendStopCommandNonBlocking`

_Sends a stop condition on the I2C bus (non-blocking)._
```c
EF_DRIVER_STATUS EF_I2C_sendStopCommandNonBlocking (
    EF_I2C_TYPE_PTR i2c,
    bool *command_sent
) 
```


This function attempts to send a stop condition on the I2C bus. If the command FIFO is unavailable, the function returns immediately.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `command_sent` Pointer to a boolean where the command status will be stored:

  * `true`: Stop condition was sent successfully.
  * `false`: Command FIFO was unavailable.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_sendWriteCommand`

_Sends a write command to the I2C device (blocking)._
```c
EF_DRIVER_STATUS EF_I2C_sendWriteCommand (
    EF_I2C_TYPE_PTR i2c,
    char addr
) 
```


This function sends a write command to the I2C device at the specified address. It blocks until the command FIFO becomes available.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `addr` The I2C address of the target device.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_sendWriteCommandNonBlocking`

_Sends a write command to the I2C device (non-blocking)._
```c
EF_DRIVER_STATUS EF_I2C_sendWriteCommandNonBlocking (
    EF_I2C_TYPE_PTR i2c,
    char addr,
    bool *command_sent
) 
```


This function attempts to send a write command to the I2C device at the specified address. If the command FIFO is unavailable, the function returns immediately.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `addr` The I2C address of the target device. 
* `command_sent` Pointer to a boolean where the command status will be stored:

  * `true`: Command was sent successfully.
  * `false`: Command FIFO was unavailable.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_sendWriteMultipleCommand`

_Sends a "write multiple" command on the I2C bus (blocking)._
```c
EF_DRIVER_STATUS EF_I2C_sendWriteMultipleCommand (
    EF_I2C_TYPE_PTR i2c
) 
```


This function sends a "write multiple" command on the I2C bus. It blocks until the command FIFO becomes available.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_sendWriteMultipleCommandNonBlocking`

_Sends a "write multiple" command on the I2C bus (non-blocking)._
```c
EF_DRIVER_STATUS EF_I2C_sendWriteMultipleCommandNonBlocking (
    EF_I2C_TYPE_PTR i2c,
    bool *command_sent
) 
```


This function attempts to send a "write multiple" command on the I2C bus. If the command FIFO is unavailable, the function returns immediately.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `command_sent` Pointer to a boolean where the command status will be stored:

  * `true`: The "write multiple" command was sent successfully.
  * `false`: Command FIFO was unavailable.


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


This ia a blocking function that writes a specified value directly to the I2C command register. It allows manual configuration of the I2C controller for advanced or custom operations.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `value` The 32-bit value to write to the I2C command register. This value typically contains specific bit fields to configure the I2C operation.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_setCommandRegNonBlocking`

_Writes a command value to the I2C command register (non-blocking)._
```c
EF_DRIVER_STATUS EF_I2C_setCommandRegNonBlocking (
    EF_I2C_TYPE_PTR i2c,
    uint32_t value,
    bool *command_sent
) 
```


This function attempts to write a specified command value to the I2C command register in a non-blocking manner. It checks the availability of the command FIFO before writing and updates the provided flag to indicate success.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `value` The command value to be written to the command register. 
* `command_sent` Pointer to a boolean flag that indicates whether the command was successfully sent:

  * true: Command was written successfully.
  * false: Command was not written (FIFO unavailable or error).


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_setDataLast`

_Sets the data last flag in the I2C data register._
```c
EF_DRIVER_STATUS EF_I2C_setDataLast (
    EF_I2C_TYPE_PTR i2c
) 
```


This function modifies the data last flag in the I2C data register. The flag indicates whether the current data is the last in an I2C transaction.



**Parameters:**


* `i2c` An [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr), which points to the base memory address of I2C registers.[**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) is a structure that contains the I2C registers.
* `valid` A boolean value specifying the state of the data last flag. Set to `true` to mark the data as the last in the transaction, or`false` to clear the flag.


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
### function `EF_I2C_transmitByte`

_Transmits a single byte to a specified I2C address (blocking)._
```c
EF_DRIVER_STATUS EF_I2C_transmitByte (
    EF_I2C_TYPE_PTR i2c,
    char data,
    char addr
) 
```


This function transmits a single byte to a specified I2C address using the Write FIFO. It blocks until all operations (data write, write command, and stop command) are completed.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `data` Data byte to be transmitted. 
* `addr` I2C address to which the data will be sent.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_transmitByteNonBlocking`

_Transmits a single byte to a specified I2C address (non-blocking)._
```c
EF_DRIVER_STATUS EF_I2C_transmitByteNonBlocking (
    EF_I2C_TYPE_PTR i2c,
    char data,
    char addr,
    bool *transmitted
) 
```


This function attempts to transmit a single byte to a specified I2C address using the Write FIFO in a non-blocking manner. If any step of the process (data write, write command, or stop command) cannot complete immediately, the function returns.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `data` Data byte to be transmitted. 
* `addr` I2C address to which the data will be sent. 
* `transmitted` Pointer to a boolean where the transmission status will be stored:

  * `true`: Data was transmitted successfully.
  * `false`: Transmission could not be completed.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_transmitCharArr`

_Transmits an array of characters to a specified I2C address (blocking)._
```c
EF_DRIVER_STATUS EF_I2C_transmitCharArr (
    EF_I2C_TYPE_PTR i2c,
    char *data,
    uint32_t data_length,
    char addr
) 
```


This function sends an array of characters to a specified I2C address. It handles writing the data to the I2C FIFO and ensures the last byte is appropriately marked.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `data` Pointer to the array of characters to be transmitted. 
* `data_length` Number of characters in the array to transmit. 
* `addr` I2C address to which the data will be sent.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_writeDataToWriteFIFO`

_Writes data to the I2C Write FIFO (blocking)._
```c
EF_DRIVER_STATUS EF_I2C_writeDataToWriteFIFO (
    EF_I2C_TYPE_PTR i2c,
    char data
) 
```


This function writes a single byte of data to the I2C Write FIFO. It blocks until the FIFO becomes available.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `data` Data byte to be written to the FIFO.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code
### function `EF_I2C_writeDataToWriteFIFONonBlocking`

_Writes data to the I2C Write FIFO (non-blocking)._
```c
EF_DRIVER_STATUS EF_I2C_writeDataToWriteFIFONonBlocking (
    EF_I2C_TYPE_PTR i2c,
    char data,
    bool *data_written
) 
```


This function attempts to write a single byte of data to the I2C Write FIFO. If the FIFO is unavailable, the function returns immediately.



**Parameters:**


* `i2c` Pointer to the I2C base address structure [**EF\_I2C\_TYPE\_PTR**](#typedef-ef_i2c_type_ptr).
* `data` Data byte to be written to the FIFO. 
* `data_written` Pointer to a boolean where the write status will be stored:

  * `true`: The data was written successfully.
  * `false`: Write FIFO was unavailable.


**Returns:**

status A value of type [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) : returns a success or error code

## Macros Documentation

### define `EF_I2C_COMMAND_REG_CMD_CORRECT_MASK`

```c
#define EF_I2C_COMMAND_REG_CMD_CORRECT_MASK 0xFFFFE080
```

### define `EF_I2C_IC_REG_MAX_VALUE`

```c
#define EF_I2C_IC_REG_MAX_VALUE 0x000001FF
```

### define `EF_I2C_IM_REG_MAX_VALUE`

```c
#define EF_I2C_IM_REG_MAX_VALUE 0x000001FF
```

### define `EF_I2C_PR_MAX_VALUE`

```c
#define EF_I2C_PR_MAX_VALUE 0x0000FFFF
```


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
| define  | [**EF\_I2C\_STATUS\_REG\_BUSY\_BIT**](#define-ef_i2c_status_reg_busy_bit)  ((uint32\_t)0)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_BUSY\_MASK**](#define-ef_i2c_status_reg_busy_mask)  ((uint32\_t)0x1)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_BUS\_ACT\_BIT**](#define-ef_i2c_status_reg_bus_act_bit)  ((uint32\_t)2)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_BUS\_ACT\_MASK**](#define-ef_i2c_status_reg_bus_act_mask)  ((uint32\_t)0x4)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_BUS\_CONT\_BIT**](#define-ef_i2c_status_reg_bus_cont_bit)  ((uint32\_t)1)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_BUS\_CONT\_MASK**](#define-ef_i2c_status_reg_bus_cont_mask)  ((uint32\_t)0x2)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_CMD\_EMPTY\_BIT**](#define-ef_i2c_status_reg_cmd_empty_bit)  ((uint32\_t)8)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_CMD\_EMPTY\_MASK**](#define-ef_i2c_status_reg_cmd_empty_mask)  ((uint32\_t)0x100)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_CMD\_FULL\_BIT**](#define-ef_i2c_status_reg_cmd_full_bit)  ((uint32\_t)9)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_CMD\_FULL\_MASK**](#define-ef_i2c_status_reg_cmd_full_mask)  ((uint32\_t)0x200)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_CMD\_OVF\_BIT**](#define-ef_i2c_status_reg_cmd_ovf_bit)  ((uint32\_t)10)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_CMD\_OVF\_MASK**](#define-ef_i2c_status_reg_cmd_ovf_mask)  ((uint32\_t)0x400)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_MISS\_ACK\_BIT**](#define-ef_i2c_status_reg_miss_ack_bit)  ((uint32\_t)3)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_MISS\_ACK\_MASK**](#define-ef_i2c_status_reg_miss_ack_mask)  ((uint32\_t)0x8)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_RD\_EMPTY\_BIT**](#define-ef_i2c_status_reg_rd_empty_bit)  ((uint32\_t)14)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_RD\_EMPTY\_MASK**](#define-ef_i2c_status_reg_rd_empty_mask)  ((uint32\_t)0x4000)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_RD\_FULL\_BIT**](#define-ef_i2c_status_reg_rd_full_bit)  ((uint32\_t)15)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_RD\_FULL\_MASK**](#define-ef_i2c_status_reg_rd_full_mask)  ((uint32\_t)0x8000)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_WR\_EMPTY\_BIT**](#define-ef_i2c_status_reg_wr_empty_bit)  ((uint32\_t)11)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_WR\_EMPTY\_MASK**](#define-ef_i2c_status_reg_wr_empty_mask)  ((uint32\_t)0x800)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_WR\_FULL\_BIT**](#define-ef_i2c_status_reg_wr_full_bit)  ((uint32\_t)12)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_WR\_FULL\_MASK**](#define-ef_i2c_status_reg_wr_full_mask)  ((uint32\_t)0x1000)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_WR\_OVF\_BIT**](#define-ef_i2c_status_reg_wr_ovf_bit)  ((uint32\_t)13)<br> |
| define  | [**EF\_I2C\_STATUS\_REG\_WR\_OVF\_MASK**](#define-ef_i2c_status_reg_wr_ovf_mask)  ((uint32\_t)0x2000)<br> |
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

### define `EF_I2C_STATUS_REG_BUSY_BIT`

```c
#define EF_I2C_STATUS_REG_BUSY_BIT ((uint32_t)0)
```

### define `EF_I2C_STATUS_REG_BUSY_MASK`

```c
#define EF_I2C_STATUS_REG_BUSY_MASK ((uint32_t)0x1)
```

### define `EF_I2C_STATUS_REG_BUS_ACT_BIT`

```c
#define EF_I2C_STATUS_REG_BUS_ACT_BIT ((uint32_t)2)
```

### define `EF_I2C_STATUS_REG_BUS_ACT_MASK`

```c
#define EF_I2C_STATUS_REG_BUS_ACT_MASK ((uint32_t)0x4)
```

### define `EF_I2C_STATUS_REG_BUS_CONT_BIT`

```c
#define EF_I2C_STATUS_REG_BUS_CONT_BIT ((uint32_t)1)
```

### define `EF_I2C_STATUS_REG_BUS_CONT_MASK`

```c
#define EF_I2C_STATUS_REG_BUS_CONT_MASK ((uint32_t)0x2)
```

### define `EF_I2C_STATUS_REG_CMD_EMPTY_BIT`

```c
#define EF_I2C_STATUS_REG_CMD_EMPTY_BIT ((uint32_t)8)
```

### define `EF_I2C_STATUS_REG_CMD_EMPTY_MASK`

```c
#define EF_I2C_STATUS_REG_CMD_EMPTY_MASK ((uint32_t)0x100)
```

### define `EF_I2C_STATUS_REG_CMD_FULL_BIT`

```c
#define EF_I2C_STATUS_REG_CMD_FULL_BIT ((uint32_t)9)
```

### define `EF_I2C_STATUS_REG_CMD_FULL_MASK`

```c
#define EF_I2C_STATUS_REG_CMD_FULL_MASK ((uint32_t)0x200)
```

### define `EF_I2C_STATUS_REG_CMD_OVF_BIT`

```c
#define EF_I2C_STATUS_REG_CMD_OVF_BIT ((uint32_t)10)
```

### define `EF_I2C_STATUS_REG_CMD_OVF_MASK`

```c
#define EF_I2C_STATUS_REG_CMD_OVF_MASK ((uint32_t)0x400)
```

### define `EF_I2C_STATUS_REG_MISS_ACK_BIT`

```c
#define EF_I2C_STATUS_REG_MISS_ACK_BIT ((uint32_t)3)
```

### define `EF_I2C_STATUS_REG_MISS_ACK_MASK`

```c
#define EF_I2C_STATUS_REG_MISS_ACK_MASK ((uint32_t)0x8)
```

### define `EF_I2C_STATUS_REG_RD_EMPTY_BIT`

```c
#define EF_I2C_STATUS_REG_RD_EMPTY_BIT ((uint32_t)14)
```

### define `EF_I2C_STATUS_REG_RD_EMPTY_MASK`

```c
#define EF_I2C_STATUS_REG_RD_EMPTY_MASK ((uint32_t)0x4000)
```

### define `EF_I2C_STATUS_REG_RD_FULL_BIT`

```c
#define EF_I2C_STATUS_REG_RD_FULL_BIT ((uint32_t)15)
```

### define `EF_I2C_STATUS_REG_RD_FULL_MASK`

```c
#define EF_I2C_STATUS_REG_RD_FULL_MASK ((uint32_t)0x8000)
```

### define `EF_I2C_STATUS_REG_WR_EMPTY_BIT`

```c
#define EF_I2C_STATUS_REG_WR_EMPTY_BIT ((uint32_t)11)
```

### define `EF_I2C_STATUS_REG_WR_EMPTY_MASK`

```c
#define EF_I2C_STATUS_REG_WR_EMPTY_MASK ((uint32_t)0x800)
```

### define `EF_I2C_STATUS_REG_WR_FULL_BIT`

```c
#define EF_I2C_STATUS_REG_WR_FULL_BIT ((uint32_t)12)
```

### define `EF_I2C_STATUS_REG_WR_FULL_MASK`

```c
#define EF_I2C_STATUS_REG_WR_FULL_MASK ((uint32_t)0x1000)
```

### define `EF_I2C_STATUS_REG_WR_OVF_BIT`

```c
#define EF_I2C_STATUS_REG_WR_OVF_BIT ((uint32_t)13)
```

### define `EF_I2C_STATUS_REG_WR_OVF_MASK`

```c
#define EF_I2C_STATUS_REG_WR_OVF_MASK ((uint32_t)0x2000)
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


