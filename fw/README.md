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
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getCommandReg**](#function-ef_i2c_getcommandreg) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, uint32\_t \*command\_value) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getDataLast**](#function-ef_i2c_getdatalast) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, bool \*data\_last) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getDataReg**](#function-ef_i2c_getdatareg) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, uint32\_t \*data\_reg\_value) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getDataValid**](#function-ef_i2c_getdatavalid) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, bool \*data\_valid) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getIM**](#function-ef_i2c_getim) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, uint32\_t \*im\_value) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getMIS**](#function-ef_i2c_getmis) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, uint32\_t \*mis\_value) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getPrescaler**](#function-ef_i2c_getprescaler) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, uint32\_t \*prescaler\_value) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_getRIS**](#function-ef_i2c_getris) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, uint32\_t \*ris\_value) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_readCmd**](#function-ef_i2c_readcmd) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, char addr) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_readData**](#function-ef_i2c_readdata) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, char \*data) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setCommandReg**](#function-ef_i2c_setcommandreg) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, uint32\_t value) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setDataLast**](#function-ef_i2c_setdatalast) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, bool valid) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setDataReg**](#function-ef_i2c_setdatareg) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, uint32\_t value) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setDataValid**](#function-ef_i2c_setdatavalid) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, bool valid) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setGclkEnable**](#function-ef_i2c_setgclkenable) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, uint32\_t value) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setIM**](#function-ef_i2c_setim) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, uint32\_t mask) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_setPrescaler**](#function-ef_i2c_setprescaler) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, uint32\_t value) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_startCmd**](#function-ef_i2c_startcmd) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_stopCmd**](#function-ef_i2c_stopcmd) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_writeAddress**](#function-ef_i2c_writeaddress) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, char addr) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_writeCmd**](#function-ef_i2c_writecmd) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, char addr) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_writeData**](#function-ef_i2c_writedata) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c, char data) <br> |
|  [**EF\_DRIVER\_STATUS**](#typedef-ef_driver_status) | [**EF\_I2C\_writeMultipleCmd**](#function-ef_i2c_writemultiplecmd) ([**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr) i2c) <br> |



## Functions Documentation

### function `EF_I2C_getCommandReg`

```c
EF_DRIVER_STATUS EF_I2C_getCommandReg (
    EF_I2C_PTR i2c,
    uint32_t *command_value
) 
```

### function `EF_I2C_getDataLast`

```c
EF_DRIVER_STATUS EF_I2C_getDataLast (
    EF_I2C_PTR i2c,
    bool *data_last
) 
```

### function `EF_I2C_getDataReg`

```c
EF_DRIVER_STATUS EF_I2C_getDataReg (
    EF_I2C_PTR i2c,
    uint32_t *data_reg_value
) 
```

### function `EF_I2C_getDataValid`

```c
EF_DRIVER_STATUS EF_I2C_getDataValid (
    EF_I2C_PTR i2c,
    bool *data_valid
) 
```

### function `EF_I2C_getIM`

```c
EF_DRIVER_STATUS EF_I2C_getIM (
    EF_I2C_PTR i2c,
    uint32_t *im_value
) 
```

### function `EF_I2C_getMIS`

```c
EF_DRIVER_STATUS EF_I2C_getMIS (
    EF_I2C_PTR i2c,
    uint32_t *mis_value
) 
```

### function `EF_I2C_getPrescaler`

```c
EF_DRIVER_STATUS EF_I2C_getPrescaler (
    EF_I2C_PTR i2c,
    uint32_t *prescaler_value
) 
```

### function `EF_I2C_getRIS`

```c
EF_DRIVER_STATUS EF_I2C_getRIS (
    EF_I2C_PTR i2c,
    uint32_t *ris_value
) 
```

### function `EF_I2C_readCmd`

```c
EF_DRIVER_STATUS EF_I2C_readCmd (
    EF_I2C_PTR i2c,
    char addr
) 
```

### function `EF_I2C_readData`

```c
EF_DRIVER_STATUS EF_I2C_readData (
    EF_I2C_PTR i2c,
    char *data
) 
```

### function `EF_I2C_setCommandReg`

```c
EF_DRIVER_STATUS EF_I2C_setCommandReg (
    EF_I2C_PTR i2c,
    uint32_t value
) 
```

### function `EF_I2C_setDataLast`

```c
EF_DRIVER_STATUS EF_I2C_setDataLast (
    EF_I2C_PTR i2c,
    bool valid
) 
```

### function `EF_I2C_setDataReg`

```c
EF_DRIVER_STATUS EF_I2C_setDataReg (
    EF_I2C_PTR i2c,
    uint32_t value
) 
```

### function `EF_I2C_setDataValid`

```c
EF_DRIVER_STATUS EF_I2C_setDataValid (
    EF_I2C_PTR i2c,
    bool valid
) 
```

### function `EF_I2C_setGclkEnable`

```c
EF_DRIVER_STATUS EF_I2C_setGclkEnable (
    EF_I2C_PTR i2c,
    uint32_t value
) 
```

### function `EF_I2C_setIM`

```c
EF_DRIVER_STATUS EF_I2C_setIM (
    EF_I2C_PTR i2c,
    uint32_t mask
) 
```

### function `EF_I2C_setPrescaler`

```c
EF_DRIVER_STATUS EF_I2C_setPrescaler (
    EF_I2C_PTR i2c,
    uint32_t value
) 
```

### function `EF_I2C_startCmd`

```c
EF_DRIVER_STATUS EF_I2C_startCmd (
    EF_I2C_PTR i2c
) 
```

### function `EF_I2C_stopCmd`

```c
EF_DRIVER_STATUS EF_I2C_stopCmd (
    EF_I2C_PTR i2c
) 
```

### function `EF_I2C_writeAddress`

```c
EF_DRIVER_STATUS EF_I2C_writeAddress (
    EF_I2C_PTR i2c,
    char addr
) 
```

### function `EF_I2C_writeCmd`

```c
EF_DRIVER_STATUS EF_I2C_writeCmd (
    EF_I2C_PTR i2c,
    char addr
) 
```

### function `EF_I2C_writeData`

```c
EF_DRIVER_STATUS EF_I2C_writeData (
    EF_I2C_PTR i2c,
    char data
) 
```

### function `EF_I2C_writeMultipleCmd`

```c
EF_DRIVER_STATUS EF_I2C_writeMultipleCmd (
    EF_I2C_PTR i2c
) 
```



## File EF_I2C_regs.h





## Structures and Types

| Type | Name |
| ---: | :--- |
| typedef [**EF\_I2C\_TYPE**](#typedef-ef_i2c_type) \* | [**EF\_I2C\_PTR**](#typedef-ef_i2c_ptr)  <br> |
| typedef struct [**\_EF\_I2C\_TYPE\_**](#struct-_ef_i2c_type_) | [**EF\_I2C\_TYPE**](#typedef-ef_i2c_type)  <br> |
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

### typedef `EF_I2C_PTR`

```c
typedef EF_I2C_TYPE* EF_I2C_PTR;
```

### typedef `EF_I2C_TYPE`

```c
typedef struct _EF_I2C_TYPE_ EF_I2C_TYPE;
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


