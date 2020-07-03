/**
  ******************************************************************************
  * File Name          : IWDG.c
  * Description        : This file provides code for the configuration
  *                      of the IWDG instances.
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

/* Includes ------------------------------------------------------------------*/
#include "iwdg.h"

/* USER CODE BEGIN 0 */
#include "main.h"
#include "stm32f1xx_hal.h"
#include "gpio.h"
/* USER CODE END 0 */

IWDG_HandleTypeDef hiwdg;

/* IWDG init function */
void MX_IWDG_Init(void)
{

  hiwdg.Instance = IWDG;
  hiwdg.Init.Prescaler = IWDG_PRESCALER_32;
  hiwdg.Init.Reload = 4095;
  if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
  {
    Error_Handler();
  }

}

/* USER CODE BEGIN 1 */

void WatchDogHandler(void)
{
	 // HAL_IWDG_Start(&hiwdg);

		if (__HAL_RCC_GET_FLAG(RCC_FLAG_IWDGRST) != RESET)	// If watchdog is interrupt.
		{
			__HAL_RCC_CLEAR_RESET_FLAGS();
			IoWrite(OUT_1, true);
			HAL_Delay(5000);
		}
}

void HelloWatchDog(void)
{
	HAL_IWDG_Refresh(&hiwdg);
}
/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
