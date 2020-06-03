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

void DevBoardInit(void){

	ADC_init();
	lcd_init();
	Indicator_init();

	StartPWM_1();
	StartPWM_2();
	StartPWM_3();
	StartPWM_4();
	StartPWM_5();
	StartPWM_6();

}
