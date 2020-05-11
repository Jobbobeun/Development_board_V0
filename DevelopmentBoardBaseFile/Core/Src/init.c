/*
 * init.c
 *
 *  Created on: Apr 15, 2020
 *      Author: nlrstem
 */

#include "adc.h"
#include "pwm.h"

void DevBoardInit(void){
	ADC_init();

	StartPWM_1();
	StartPWM_2();
	StartPWM_3();
	StartPWM_4();
	StartPWM_5();
	StartPWM_6();

	PWM_Duty_Cycle(PWM_1, 100);
	PWM_Duty_Cycle(PWM_2, 80);
	PWM_Duty_Cycle(PWM_3, 60);
	PWM_Duty_Cycle(PWM_4, 40);
	PWM_Duty_Cycle(PWM_5, 20);
	PWM_Duty_Cycle(PWM_6, 10);

}
