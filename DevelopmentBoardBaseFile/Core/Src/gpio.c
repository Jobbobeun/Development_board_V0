/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
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
#include "gpio.h"
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, OUT_4_Pin|OUT_3_Pin|OUT_2_Pin|OUT_1_Pin 
                          |OUT_6_Pin|OUT_5_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(OUT_7_GPIO_Port, OUT_7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = IN_4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(IN_4_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin */
  GPIO_InitStruct.Pin = IN_3_Pin|IN_1_Pin|IN_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = IN_5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(IN_5_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin 
                           PBPin PBPin */
  GPIO_InitStruct.Pin = OUT_4_Pin|OUT_3_Pin|OUT_2_Pin|OUT_1_Pin 
                          |OUT_6_Pin|OUT_5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = OUT_7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(OUT_7_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

bool IoWrite(uint8_t Output_Pin, bool Output_State){

	switch(Output_Pin){

	case 1:
		HAL_GPIO_WritePin(GPIOB, OUT_1_Pin, Output_State);
		return true;
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, OUT_2_Pin, Output_State);
		return true;
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, OUT_3_Pin, Output_State);
		return true;
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, OUT_4_Pin, Output_State);
		return true;
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, OUT_5_Pin, Output_State);
		return true;
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, OUT_6_Pin, Output_State);
		return true;
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOA, OUT_7_Pin, Output_State);
		return true;
		break;

	default:
		return false;

		}

	}

	bool IoRead(uint8_t Input_Pin){

		switch(Input_Pin){
		case 1:
			HAL_GPIO_ReadPin(GPIOB, IN_1_Pin);
			return true;
			break;
		case 2:
			HAL_GPIO_ReadPin(GPIOB, IN_2_Pin);
			return true;
			break;
		case 3:
			HAL_GPIO_ReadPin(GPIOB, IN_3_Pin);
			return true;
			break;
		case 4:
			HAL_GPIO_ReadPin(GPIOC, IN_4_Pin);
			return true;
			break;
		case 5:
			HAL_GPIO_ReadPin(GPIOB, IN_5_Pin);
			return true;
			break;

		default:
			return false;

			}
		}

bool IoToggle(uint8_t Toggle_Pin){

	switch(Toggle_Pin){
		case 1:
			HAL_GPIO_TogglePin(GPIOB, OUT_1_Pin);
			return true;
			break;
		case 2:
			HAL_GPIO_TogglePin(GPIOB, OUT_2_Pin);
			return true;
			break;
		case 3:
			HAL_GPIO_TogglePin(GPIOB, OUT_3_Pin);
			return true;
			break;
		case 4:
			HAL_GPIO_TogglePin(GPIOB, OUT_4_Pin);
			return true;
			break;
		case 5:
			HAL_GPIO_TogglePin(GPIOB, OUT_5_Pin);
			return true;
			break;
		case 6:
			HAL_GPIO_TogglePin(GPIOB, OUT_6_Pin);
			return true;
			break;
		case 7:
			HAL_GPIO_TogglePin(GPIOC, OUT_7_Pin);
			return true;
			break;

		default:
			return false;

			}

		}




void GPIO_test(void){
	IoWrite(1,true);
	HAL_Delay(500);
	IoWrite(1,false);
	HAL_Delay(500);
}
/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
