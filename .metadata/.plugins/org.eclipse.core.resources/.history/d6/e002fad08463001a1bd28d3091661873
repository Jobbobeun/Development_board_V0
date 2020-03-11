/*
 * Application.c
 *
 *  Created on: 9 Mar 2020
 *      Author: Rick
 */

#include "application.h"
#include "stm32f1xx_hal.h"
#include "main.h"

void Application()
{
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9);
	HAL_Delay(2000);

	for (int i = 0; i<65535; i+=100){
		TIM1->CCR1 = i;
		HAL_Delay(1);
	}

	for (int i = 65535; i>0; i-=100){
		TIM1->CCR1 = i;
		HAL_Delay(1);
	}

}
