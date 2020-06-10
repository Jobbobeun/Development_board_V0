/*
 * init.c
 *
 *  Created on: Apr 15, 2020
 *      Author: nlrstem
 */

#include "adc.h"
#include "pwm.h"
#include "lcd.h"
#include "i2c.h"
#include "gpio.h"

void DevBoardInit(void){

	ADC_init();
	lcd_init();
	//PCF_Init();
	//HAL_I2C_Master_Receive(&hi2c1, 0x41, (uint8_t*) receiveddata2, 2, 1000);
	PCF_Init();
	PCF8574_Demo_Receive();
}
