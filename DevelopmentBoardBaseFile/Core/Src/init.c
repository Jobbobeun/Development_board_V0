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

}
