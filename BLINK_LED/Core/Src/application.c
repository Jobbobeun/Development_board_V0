/*
 * Application.c
 *
 *  Created on: 9 Mar 2020
 *      Author: Rick
 */

#include "application.h"
#include "stm32f1xx_hal.h"

void Application()
{
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9);
	HAL_Delay(2000);
}
