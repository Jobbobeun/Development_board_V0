/*
 * Application.c
 *
 *  Created on: 9 Mar 2020
 *      Author: Rick
 */

#include "application.h"
#include "stm32f1xx_hal.h"
#include "main.h"
#include "PWM_signal.h"

void Application()
{
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9);
	//HAL_Delay(2000);

	for (int i = 0; i<100; i++){
		PWM_Set(PWM_1, i);
		HAL_Delay(1);
	}

	for (int i = 100; i>0; i--){
		PWM_Set(PWM_1, i);
		HAL_Delay(1);
	}

}
