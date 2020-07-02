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

void DevBoardInit(void){

	ADC_init();
	lcd_init();
	Indicator_init();
	serialcom_init();
	PCF_Init();

}
