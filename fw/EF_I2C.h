#ifndef EF_I2C_H
#define EF_I2C_H

#include <EF_I2C_regs.h>
#include <stdint.h>
#include <stdbool.h>


void EF_I2C_writeAddress(uint32_t i2c_base, char addr);
void EF_I2C_startCmd(uint32_t i2c_base);
void EF_I2C_readCmd(uint32_t i2c_base);
void EF_I2C_writeCmd(uint32_t i2c_base);
void EF_I2C_writeMultipleCmd(uint32_t i2c_base);
void EF_I2C_stopCmd(uint32_t i2c_base);
void EF_I2C_setCommandReg(uint32_t i2c_base, int value);
int EF_I2C_getCommandReg(uint32_t i2c_base);
void EF_I2C_writeData(uint32_t i2c_base, char data);
char EF_I2C_readData(uint32_t i2c_base);
void EF_I2C_setDataValid(uint32_t i2c_base, bool valid);
bool EF_I2C_getDataValid(uint32_t i2c_base);
void EF_I2C_setDataLast(uint32_t i2c_base, bool valid);
bool EF_I2C_getDataLast(uint32_t i2c_base);
void EF_I2C_setDataReg(uint32_t i2c_base, int value);
int EF_I2C_getDataReg(uint32_t i2c_base);
void EF_I2C_setPrescaler(uint32_t i2c_base, int value);
int EF_I2C_getPrescaler(uint32_t i2c_base);
int EF_I2C_getRIS(uint32_t i2c_base);
int EF_I2C_getMIS(uint32_t i2c_base);
void EF_I2C_setIM(uint32_t i2c_base, int mask);
int EF_I2C_getIM(uint32_t i2c_base);

#endif