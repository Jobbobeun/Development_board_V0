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
	PWM_Duty_Cycle(PWM_2, 100);
	PWM_Duty_Cycle(PWM_3, 100);
	PWM_Duty_Cycle(PWM_4, 100);
	PWM_Duty_Cycle(PWM_5, 100);
	PWM_Duty_Cycle(PWM_6, 100);
	HAL_GPIO_TogglePin(GPIOB, OUT_1_Pin);
	HAL_GPIO_TogglePin(GPIOB, OUT_2_Pin);
	HAL_GPIO_TogglePin(GPIOB, OUT_3_Pin);
	HAL_GPIO_TogglePin(GPIOB, OUT_4_Pin);
	HAL_GPIO_TogglePin(GPIOB, OUT_5_Pin);
	HAL_GPIO_TogglePin(GPIOB, OUT_6_Pin);
	HAL_GPIO_TogglePin(GPIOA, OUT_7_Pin);
}
