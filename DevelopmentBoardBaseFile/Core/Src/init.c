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
#include "tim.h"
#include "serialCom.h"
#include "LowPowerControl.h"
#include "gpio.h"
#include "MotorDriver.h"
#include "stdint.h"
bool Stepp;
void DevBoardInit(void){
	GPIO_init();
	ADC_init();
	lcd_init();
	Indicator_init();
	serialcom_init();
	PCF_Init();
	MotordriverIni();
}
