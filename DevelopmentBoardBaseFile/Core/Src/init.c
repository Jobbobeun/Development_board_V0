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
#include "stdint.h"
bool Stepp;
void DevBoardInit(void){

	ADC_init();
	lcd_init();
	Indicator_init();
	serialcom_init();
	MotordriverIni();
	HAL_Delay(1000);
	Stepp = Motor(Motor2, CCW, 50);

	HAL_Delay(500);
	//IoWrite(OUT_6, false);
	HAL_Delay(500);

	Stepp = Motor(Motor2, CW, 50);
	HAL_Delay(2000);
	Stepp = Motor(Motor2, BRAKE, 50);
	HAL_Delay(1000);
	Stepp = Motor(Motor2, CCW, 50);
}
