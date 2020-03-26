/*
 * i2c.h
 *
 *  Created on: Mar 24, 2020
 *      Author: nlrstem
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

#include "stm32f1xx_hal.h"
#include "Initialization.h"

#define ADXL345_address 0x53<<1		// ADXL I2C address
#define IO_expander_adress 0x41 <<1 // PCF8574 address
#define IO_expander_adress2 0x20 <<1 // PCF8574 7 bit address without R/W bit

uint8_t data_rec[6];	// Array for raw x, y and z values
uint8_t x;				// Raw x value
uint8_t y;				// Raw y value
uint8_t z;				// Raw z value

void I2C_Write (uint8_t reg, uint8_t i2c_adress, uint8_t value);

void I2C_Read (uint8_t reg, uint8_t i2c_adress, uint8_t AmountOfBytes);

void I2C_ADXL_Init(void);

void I2C_ReadVals (uint8_t i2c_address, uint8_t reg);

void I2C_ADXL345_test(void);

void I2C_IO_Expander_test(uint8_t adress);


#endif /* INC_I2C_H_ */
