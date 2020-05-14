/*
 * init.c
 *
 *  Created on: Apr 15, 2020
 *      Author: nlrstem
 */

#include "adc.h"
#include "pwm.h"
#include "lcd.h"
#include "servo.h"

void DevBoardInit(void){

	ADC_init();
	lcd_init();
	Servo_int();

}
