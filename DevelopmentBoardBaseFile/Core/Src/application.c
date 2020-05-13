/*
 * application.c
 *
 *  Created on: Apr 21, 2020
 *      Author: Job Heijlighen
 */


#include "application.h"
#include "adc.h"
#include "gpio.h"
#include "pwm.h"
#include "lcd.h"



void application(void){

	lcdPrint("Hello world",0,0);
	HAL_Delay(10);
	lcdPrint("DevBoard",1,0);

for (int i = 0 ; i <10 ; i++){

	lcdPrintInt(i,1,9);

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

	HAL_Delay(300);
	PWM_Duty_Cycle(PWM_1, 0);
	PWM_Duty_Cycle(PWM_2, 0);
	PWM_Duty_Cycle(PWM_3, 0);
	PWM_Duty_Cycle(PWM_4, 0);
	PWM_Duty_Cycle(PWM_5, 0);
	PWM_Duty_Cycle(PWM_6, 0);
	HAL_GPIO_TogglePin(GPIOB, OUT_1_Pin);
	HAL_GPIO_TogglePin(GPIOB, OUT_2_Pin);
	HAL_GPIO_TogglePin(GPIOB, OUT_3_Pin);
	HAL_GPIO_TogglePin(GPIOB, OUT_4_Pin);
	HAL_GPIO_TogglePin(GPIOB, OUT_5_Pin);
	HAL_GPIO_TogglePin(GPIOB, OUT_6_Pin);
	HAL_GPIO_TogglePin(GPIOA, OUT_7_Pin);
	HAL_Delay(300);

}

lcd_clear();

for (int i = 0 ; i <4 ; i++){

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

	HAL_Delay(50);
	PWM_Duty_Cycle(PWM_1, 0);
	PWM_Duty_Cycle(PWM_2, 0);
	PWM_Duty_Cycle(PWM_3, 0);
	PWM_Duty_Cycle(PWM_4, 0);
	PWM_Duty_Cycle(PWM_5, 0);
	PWM_Duty_Cycle(PWM_6, 0);
	HAL_GPIO_TogglePin(GPIOB, OUT_1_Pin);
	HAL_GPIO_TogglePin(GPIOB, OUT_2_Pin);
	HAL_GPIO_TogglePin(GPIOB, OUT_3_Pin);
	HAL_GPIO_TogglePin(GPIOB, OUT_4_Pin);
	HAL_GPIO_TogglePin(GPIOB, OUT_5_Pin);
	HAL_GPIO_TogglePin(GPIOB, OUT_6_Pin);
	HAL_GPIO_TogglePin(GPIOA, OUT_7_Pin);
	HAL_Delay(50);

}
HAL_Delay(500);

}
