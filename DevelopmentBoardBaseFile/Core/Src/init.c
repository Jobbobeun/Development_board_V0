/*
 * init.c
 *
 *  Created on: Apr 15, 2020
 *      Author: nlrstem
 */

#include "adc.h"
#include "pwm.h"
#include "lcd.h"
#include "tim.h"
#include "serialCom.h"
#include "LowPowerControl.h"
#include "gpio.h"
#include "MotorDriver.h"

void DevBoardInit(void){

	ADC_init();
	lcd_init();
	Indicator_init();
	serialcom_init();
	MotordriverIni();
	for (int i = 0; i <100; i++){
	Motor(Motor1, CW, 50);
	Motor(Motor2, CW, 50);
	HAL_Delay(2000);
	Motor(Motor1, CCW, 100);
	Motor(Motor2, CCW, 100);
	HAL_Delay(2000);
	}
}
