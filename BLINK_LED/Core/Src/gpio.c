/*
 * gpio.c
 *
 *  Created on: 12 Mar 2020
 *      Author: Rick
 */
#include "gpio.h"

// Params
// GPIOx port 	with x as A B C D...
// GPIOx pin 	0..15
// PinSate   	GPIO_PIN_RESET or GPIO_PIN_SET

void GPIO_Write(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
}

// Params
// GPIOx port 	with x as A B C D...
// GPIOx pin 	0..15

void GPIO_Read(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
}

// Params
// GPIOx port 	with x as A B C D...
// GPIOx pin 	0..15
void GPIO_Toggle(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	HAL_GPIO_TogglePin(GPIOx, GPIO_Pin);
}
