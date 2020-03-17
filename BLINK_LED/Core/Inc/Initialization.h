/*
 * Initialization.h
 *
 *  Created on: Mar 13, 2020
 *      Author: Job Heijlighen
 */

#ifndef INC_INITIALIZATION_H_
#define INC_INITIALIZATION_H_

#include "stdint.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
ADC_HandleTypeDef hadc1;
I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;
RTC_HandleTypeDef hrtc;
UART_HandleTypeDef huart2;

 void MX_TIM1_Init(void);
 void MX_TIM2_Init(void);
 void MX_GPIO_Init(void);
 void MX_ADC1_Init(void);
 void MX_I2C1_Init(void);
 void MX_I2C2_Init(void);
 void MX_RTC_Init(void);
 void MX_USART2_UART_Init(void);

#endif /* INC_INITIALIZATION_H_ */
