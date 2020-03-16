/*
 * Application.c
 *
 *  Created on: 9 Mar 2020
 *      Author: Rick
 */

#include "application.h"
#include "gpio.h"
#include "main.h"


void Application(void)
{
	GPIO_Write(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
	HAL_Delay(1000);
	GPIO_Write(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
	HAL_Delay(500);

/*
	for (int i = 0; i<65535; i+=100){
		TIM1->CCR1 = i;
		HAL_Delay(1);
	}

	for (int i = 65535; i>0; i-=100){
		TIM1->CCR1 = i;
		HAL_Delay(1);
	}
*/

}
