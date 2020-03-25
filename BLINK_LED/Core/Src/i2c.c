/*
 * i2c.c
 *
 *  Created on: Mar 24, 2020
 *      Author: nlrstem
 */

#include "i2c.h"

//Params

void I2C_Write (uint8_t reg, uint8_t i2c_adress, uint8_t value)
{
	uint8_t data[2];
	data[0] = reg;
	data[1] = value;

	HAL_I2C_Master_Transmit(&hi2c1, i2c_adress, data, 2, HAL_MAX_DELAY); //hal max delay?
}

//Params

void I2C_Read (uint8_t reg, uint8_t i2c_adress, uint8_t AmountOfBytes)
{
	HAL_I2C_Mem_Read(&hi2c1, i2c_adress, reg, 1, data_rec, AmountOfBytes, HAL_MAX_DELAY);
	//HAL_I2C_Master_Receive(&hi2c1, adxl_adress, reg, 1, HAL_MAX_DELAY); //doesnt work?
}

//Params

void I2C_ADXL_Init(void)
{
	I2C_Read (0x00, ADXL345_address, 1);
	I2C_Write (0x2d, ADXL345_address, 0x00);  // Reset all bits
	I2C_Write (0x2d, ADXL345_address, 0x08);  // 8hz config
	I2C_Write (0x31, ADXL345_address, 0x01);  // Range format 4g
	//data_rec[2] = 0xFF;	 // Debug test
	//data_rec[5] = 0x02;	 // Debug test
}

// Params

void I2C_ReadVals (uint8_t i2c_address, uint8_t reg)
{
   HAL_I2C_Mem_Read (&hi2c1, i2c_address, reg, 1, (uint8_t *)data_rec, 6, 100);
}

// Params

void I2C_ADXL345_test(void)
{
	I2C_ReadVals (ADXL345_address, 0x32);					//Read 6 bytes from adress 0x32
	x = ((data_rec[1]<<8)|data_rec[0]);		//X vals in data array
	y = ((data_rec[3]<<8)|data_rec[2]);		//Y vals in data array
	z = ((data_rec[5]<<8)|data_rec[4]); 	//Z vals in data array
}
