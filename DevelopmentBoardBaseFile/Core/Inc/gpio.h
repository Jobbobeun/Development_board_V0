/**
  ******************************************************************************
  * File Name          : gpio.h
  * Description        : This file contains all the functions prototypes for 
  *                      the gpio  
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __gpio_H
#define __gpio_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "stdbool.h"
/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
 enum Output_numbers {
	 EMPTY_Output,
	 OUT_1,	// PWM STM32
	 OUT_2, // PWM STM32
	 OUT_3, // PWM STM32
	 OUT_4, // PWM STM32
	 OUT_5,	// GPIO STM32
	 OUT_6, // GPIO STM32
	 OUT_7, // GPIO STM32
	 OUT_8, // GPIO STM32
	 OUT_9,	// IO expander P0
	 OUT_10, // IO expander P1
	 OUT_11, // IO expander P2
	 OUT_12, // IO expander P3
	 PROG_LED
 };

 enum Input_numbers{
	 EMPTY_Input,
	 IN_1,
	 IN_2,
	 IN_3,
	 IN_4,
	 IN_5,
	 IN_6,
	 IN_7,
	 IN_8,
	 IN_9
 };
/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */

bool IoWrite(uint8_t Output_pin, bool Output_State);
bool IoRead(uint8_t Input_pin);
bool IoToggle(uint8_t Toggle_pin);
bool OutStatus(uint8_t Output_pin);
void GPIO_test(void);

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
