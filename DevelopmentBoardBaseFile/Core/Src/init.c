/*
 * init.c
 *
 *  Created on: Apr 15, 2020
 *      Author: nlrstem
 */

#include "adc.h"
#include "pwm.h"
#include "lcd.h"

void DevBoardInit(void){

	ADC_init();
	lcd_init();

	StartPWM_1();
	StartPWM_2();
	StartPWM_3();
	StartPWM_4();
	StartPWM_5();
	StartPWM_6();

}
