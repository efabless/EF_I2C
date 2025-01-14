/*
        Copyright 2024 Mohamed Shalan

        Author: Mohamed Shalan (mshalan@efabless.com)

        Licensed under the Apache License, Version 2.0 (the "License");
        you may not use this file except in compliance with the License.
        You may obtain a copy of the License at

            http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.

*/

#ifndef EF_I2CREGS_H
#define EF_I2CREGS_H

/******************************************************************************
* Includes
******************************************************************************/
#include "EF_Driver_Common.h"


/******************************************************************************
* Macros and Constants
******************************************************************************/
#ifndef IO_TYPES
#define IO_TYPES
#define   __R     volatile const uint32_t
#define   __W     volatile       uint32_t
#define   __RW    volatile       uint32_t
#endif


#define EF_I2C_STATUS_REG_BUSY_BIT	                    ((uint32_t)0)
#define EF_I2C_STATUS_REG_BUSY_MASK	                    ((uint32_t)0x1)
#define EF_I2C_STATUS_REG_BUS_CONT_BIT	                ((uint32_t)1)
#define EF_I2C_STATUS_REG_BUS_CONT_MASK	                ((uint32_t)0x2)
#define EF_I2C_STATUS_REG_BUS_ACT_BIT	                ((uint32_t)2)
#define EF_I2C_STATUS_REG_BUS_ACT_MASK	                ((uint32_t)0x4)
#define EF_I2C_STATUS_REG_MISS_ACK_BIT	                ((uint32_t)3)
#define EF_I2C_STATUS_REG_MISS_ACK_MASK	                ((uint32_t)0x8)
#define EF_I2C_STATUS_REG_CMD_EMPTY_BIT	                ((uint32_t)8)
#define EF_I2C_STATUS_REG_CMD_EMPTY_MASK	            ((uint32_t)0x100)
#define EF_I2C_STATUS_REG_CMD_FULL_BIT	                ((uint32_t)9)
#define EF_I2C_STATUS_REG_CMD_FULL_MASK	                ((uint32_t)0x200)
#define EF_I2C_STATUS_REG_CMD_OVF_BIT	                ((uint32_t)10)
#define EF_I2C_STATUS_REG_CMD_OVF_MASK	                ((uint32_t)0x400)
#define EF_I2C_STATUS_REG_WR_EMPTY_BIT	                ((uint32_t)11)
#define EF_I2C_STATUS_REG_WR_EMPTY_MASK	                ((uint32_t)0x800)
#define EF_I2C_STATUS_REG_WR_FULL_BIT	                ((uint32_t)12)
#define EF_I2C_STATUS_REG_WR_FULL_MASK	                ((uint32_t)0x1000)
#define EF_I2C_STATUS_REG_WR_OVF_BIT	                ((uint32_t)13)
#define EF_I2C_STATUS_REG_WR_OVF_MASK	                ((uint32_t)0x2000)
#define EF_I2C_STATUS_REG_RD_EMPTY_BIT	                ((uint32_t)14)
#define EF_I2C_STATUS_REG_RD_EMPTY_MASK	                ((uint32_t)0x4000)
#define EF_I2C_STATUS_REG_RD_FULL_BIT	                ((uint32_t)15)
#define EF_I2C_STATUS_REG_RD_FULL_MASK	                ((uint32_t)0x8000)
#define EF_I2C_COMMAND_REG_CMD_ADDRESS_BIT              ((uint32_t)0)
#define EF_I2C_COMMAND_REG_CMD_ADDRESS_MASK             ((uint32_t)0x7f)
#define EF_I2C_COMMAND_REG_CMD_START_BIT                ((uint32_t)8)
#define EF_I2C_COMMAND_REG_CMD_START_MASK               ((uint32_t)0x100)
#define EF_I2C_COMMAND_REG_CMD_READ_BIT                 ((uint32_t)9)
#define EF_I2C_COMMAND_REG_CMD_READ_MASK                ((uint32_t)0x200)
#define EF_I2C_COMMAND_REG_CMD_WRITE_BIT                ((uint32_t)10)
#define EF_I2C_COMMAND_REG_CMD_WRITE_MASK               ((uint32_t)0x400)
#define EF_I2C_COMMAND_REG_CMD_WRITE_MULTIPLE_BIT       ((uint32_t)11)
#define EF_I2C_COMMAND_REG_CMD_WRITE_MULTIPLE_MASK      ((uint32_t)0x800)
#define EF_I2C_COMMAND_REG_CMD_STOP_BIT                 ((uint32_t)12)
#define EF_I2C_COMMAND_REG_CMD_STOP_MASK                ((uint32_t)0x1000)
#define EF_I2C_DATA_REG_DATA_BIT                        ((uint32_t)0)
#define EF_I2C_DATA_REG_DATA_MASK                       ((uint32_t)0xff)
#define EF_I2C_DATA_REG_DATA_VALID_BIT                  ((uint32_t)8)
#define EF_I2C_DATA_REG_DATA_VALID_MASK                 ((uint32_t)0x100)
#define EF_I2C_DATA_REG_DATA_LAST_BIT                   ((uint32_t)9)
#define EF_I2C_DATA_REG_DATA_LAST_MASK                  ((uint32_t)0x200)
#define EF_I2C_MISS_ACK_FLAG	                        ((uint32_t)0x1)
#define EF_I2C_CMDE_FLAG	                            ((uint32_t)0x2)
#define EF_I2C_CMDF_FLAG	                            ((uint32_t)0x4)
#define EF_I2C_CMDOVF_FLAG	                            ((uint32_t)0x8)
#define EF_I2C_WRE_FLAG	                                ((uint32_t)0x10)
#define EF_I2C_WRF_FLAG	                                ((uint32_t)0x20)
#define EF_I2C_WROVF_FLAG	                            ((uint32_t)0x40)
#define EF_I2C_RDE_FLAG	                                ((uint32_t)0x80)
#define EF_I2C_RDF_FLAG	                                ((uint32_t)0x100)


/******************************************************************************
* Typedefs and Enums
******************************************************************************/
typedef struct _EF_I2C_TYPE_ {
    __R 	STATUS;
    __W 	COMMAND;
    __RW    DATA;
    __W     PR;
    __R     reserved_1[16316];
    __RW	IM;
    __R 	MIS;
    __R 	RIS;
    __R     reserved_2;
    __W 	GCLK;
} EF_I2C_TYPE;


typedef EF_I2C_TYPE * EF_I2C_TYPE_PTR;                   // EF_I2C_PTR is a pointer to a structure of type EF_I2C_TYPE


/******************************************************************************
* Function Prototypes
******************************************************************************/



/******************************************************************************
* External Variables
******************************************************************************/




#endif // EF_I2CREGS_H

/******************************************************************************
* End of File
******************************************************************************/