/*
 * gpio.h
 *
 *  Created on: 12 Mar 2020
 *      Author: Rick
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_


#include "stm32f1xx_hal.h"

void GPIO_Write(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);

void GPIO_Read(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

void GPIO_Toggle(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);


#endif /* INC_GPIO_H_ */
