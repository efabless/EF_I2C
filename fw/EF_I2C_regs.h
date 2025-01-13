/*
	Copyright 2024 Efabless Corp.

	Author: Efabless Corp. (ip_admin@efabless.com)

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

#ifndef IO_TYPES
#define IO_TYPES
#define   __R     volatile const unsigned int
#define   __W     volatile       unsigned int
#define   __RW    volatile       unsigned int
#endif

#define EF_I2C_STATUS_REG_BUSY_BIT	0
#define EF_I2C_STATUS_REG_BUSY_MASK	0x1
#define EF_I2C_STATUS_REG_BUS_CONT_BIT	1
#define EF_I2C_STATUS_REG_BUS_CONT_MASK	0x2
#define EF_I2C_STATUS_REG_BUS_ACT_BIT	2
#define EF_I2C_STATUS_REG_BUS_ACT_MASK	0x4
#define EF_I2C_STATUS_REG_MISS_ACK_BIT	3
#define EF_I2C_STATUS_REG_MISS_ACK_MASK	0x8
#define EF_I2C_STATUS_REG_CMD_EMPTY_BIT	8
#define EF_I2C_STATUS_REG_CMD_EMPTY_MASK	0x100
#define EF_I2C_STATUS_REG_CMD_FULL_BIT	9
#define EF_I2C_STATUS_REG_CMD_FULL_MASK	0x200
#define EF_I2C_STATUS_REG_CMD_OVF_BIT	10
#define EF_I2C_STATUS_REG_CMD_OVF_MASK	0x400
#define EF_I2C_STATUS_REG_WR_EMPTY_BIT	11
#define EF_I2C_STATUS_REG_WR_EMPTY_MASK	0x800
#define EF_I2C_STATUS_REG_WR_FULL_BIT	12
#define EF_I2C_STATUS_REG_WR_FULL_MASK	0x1000
#define EF_I2C_STATUS_REG_WR_OVF_BIT	13
#define EF_I2C_STATUS_REG_WR_OVF_MASK	0x2000
#define EF_I2C_STATUS_REG_RD_EMPTY_BIT	14
#define EF_I2C_STATUS_REG_RD_EMPTY_MASK	0x4000
#define EF_I2C_STATUS_REG_RD_FULL_BIT	15
#define EF_I2C_STATUS_REG_RD_FULL_MASK	0x8000
#define EF_I2C_COMMAND_REG_CMD_ADDRESS_BIT	0
#define EF_I2C_COMMAND_REG_CMD_ADDRESS_MASK	0x7f
#define EF_I2C_COMMAND_REG_CMD_START_BIT	8
#define EF_I2C_COMMAND_REG_CMD_START_MASK	0x100
#define EF_I2C_COMMAND_REG_CMD_READ_BIT	9
#define EF_I2C_COMMAND_REG_CMD_READ_MASK	0x200
#define EF_I2C_COMMAND_REG_CMD_WRITE_BIT	10
#define EF_I2C_COMMAND_REG_CMD_WRITE_MASK	0x400
#define EF_I2C_COMMAND_REG_CMD_WRITE_MULTIPLE_BIT	11
#define EF_I2C_COMMAND_REG_CMD_WRITE_MULTIPLE_MASK	0x800
#define EF_I2C_COMMAND_REG_CMD_STOP_BIT	12
#define EF_I2C_COMMAND_REG_CMD_STOP_MASK	0x1000
#define EF_I2C_DATA_REG_DATA_BIT	0
#define EF_I2C_DATA_REG_DATA_MASK	0xff
#define EF_I2C_DATA_REG_DATA_VALID_BIT	8
#define EF_I2C_DATA_REG_DATA_VALID_MASK	0x100
#define EF_I2C_DATA_REG_DATA_LAST_BIT	9
#define EF_I2C_DATA_REG_DATA_LAST_MASK	0x200

#define EF_I2C_MISS_ACK_FLAG	0x1
#define EF_I2C_CMDE_FLAG	0x2
#define EF_I2C_CMDF_FLAG	0x4
#define EF_I2C_CMDOVF_FLAG	0x8
#define EF_I2C_WRE_FLAG	0x10
#define EF_I2C_WRF_FLAG	0x20
#define EF_I2C_WROVF_FLAG	0x40
#define EF_I2C_RDE_FLAG	0x80
#define EF_I2C_RDF_FLAG	0x100

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




#endif