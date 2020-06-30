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
#include "pwm.h"
/* USER CODE BEGIN 0 */

uint8_t Out_status[13];
#define Outpin_Quantity 13
bool TEST1;

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
  HAL_GPIO_WritePin(GPIOA, OUT_5_Pin|OUT_6_Pin|PROG_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, OUT_8_Pin|OUT_7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = IN_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(IN_2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = OUT_5_Pin|OUT_6_Pin|PROG_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin 
                           PBPin PBPin */
  GPIO_InitStruct.Pin = IN_3_Pin|IN_4_Pin|IN_7_Pin|IN_8_Pin 
                          |IN_6_Pin|IN_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = IN_9_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(IN_9_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin */
  GPIO_InitStruct.Pin = OUT_8_Pin|OUT_7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = IN_5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(IN_5_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 2 */
void GPIO_init(void)
{
	StartENABLE_A();
	StartENABLE_B();
	StartPWM_1();
	StartPWM_2();
	StartPWM_3();
	StartPWM_4();
}

bool IoWrite(uint8_t Output_Pin, bool Output_State)
{

	switch(Output_Pin){

	case OUT_1:
		if (Output_State != Out_status[Output_Pin - 1])
		{
			if (Output_State){
				PWM_Duty_Cycle(PWM_1, 100);
		} else{
			PWM_Duty_Cycle(PWM_1, 0);
		}
		Out_status[Output_Pin - 1] = Output_State;

	return true;
	}
	else
	{
		return false;
	}
					break;

	case OUT_2:
		if (Output_State != Out_status[Output_Pin - 1])
		{
			if (Output_State){
				PWM_Duty_Cycle(PWM_2, 100);
		} else{
			PWM_Duty_Cycle(PWM_2, 0);
		}
		Out_status[Output_Pin - 1] = Output_State;

	return true;
	}
	else
	{
		return false;
	}
					break;

	case OUT_3:
		if (Output_State != Out_status[Output_Pin - 1])
		{
			if (Output_State){
				PWM_Duty_Cycle(PWM_3, 100);
		} else{
			PWM_Duty_Cycle(PWM_3, 0);
		}
		Out_status[Output_Pin - 1] = Output_State;

	return true;
	}
	else
	{
		return false;
	}
					break;

	case OUT_4:
		if (Output_State != Out_status[Output_Pin - 1])
		{
			if (Output_State){
				PWM_Duty_Cycle(PWM_4, 100);
		} else{
			PWM_Duty_Cycle(PWM_4, 0);
		}
		Out_status[Output_Pin - 1] = Output_State;

	return true;
	}
	else
	{
		return false;
	}
					break;

	case OUT_5:

		if (Output_State != Out_status[Output_Pin - 1])
		{
			HAL_GPIO_WritePin(GPIOA, OUT_5_Pin, Output_State);
			Out_status[Output_Pin - 1] = Output_State;

		return true;
		}
		else
		{
			return false;
		}

		break;

	case OUT_6:
		if (Output_State != Out_status[Output_Pin - 1])
		{
			HAL_GPIO_WritePin(GPIOA, OUT_6_Pin, Output_State);
			Out_status[Output_Pin - 1] = Output_State;

		return true;
		}
		else
		{
			return false;
		}
		break;

	case OUT_7:
		if (Output_State != Out_status[Output_Pin - 1])
		{
			HAL_GPIO_WritePin(GPIOB, OUT_7_Pin, Output_State);
			Out_status[Output_Pin - 1] = Output_State;

		return true;
		}
		else
		{
			return false;
		}
		break;

	case OUT_8:
		if (Output_State != Out_status[Output_Pin - 1])
		{
			HAL_GPIO_WritePin(GPIOB, OUT_8_Pin, Output_State);
			Out_status[Output_Pin - 1] = Output_State;

		return true;
		}
		else
		{
			return false;
		}
		break;

	case OUT_9:

		return false;

				break;

	case OUT_10:

		return false;

				break;

	case OUT_11:

		return false;

				break;

	case OUT_12:

		return false;

				break;

	case PROG_LED:

		if (Output_State != Out_status[Output_Pin - 1])
		{
			HAL_GPIO_WritePin(GPIOA, PROG_LED_Pin, Output_State);
			Out_status[Output_Pin - 1] = Output_State;

		return true;
		}
		else
		{
			return false;
		}
		break;

	default:
		return false;

		}
}

bool IoRead(uint8_t Input_Pin)
{

		switch(Input_Pin){
		case IN_1:

			return HAL_GPIO_ReadPin(GPIOB, IN_1_Pin);
			break;

		case IN_2:

			return HAL_GPIO_ReadPin(GPIOC, IN_2_Pin);
			break;

		case IN_3:

			return HAL_GPIO_ReadPin(GPIOB, IN_3_Pin);
			break;

		case IN_4:

			return HAL_GPIO_ReadPin(GPIOB, IN_4_Pin);
			break;

		case IN_5:

			return HAL_GPIO_ReadPin(GPIOB, IN_5_Pin);
			break;

		case IN_6:

			return HAL_GPIO_ReadPin(GPIOB, IN_6_Pin);
			break;

		case IN_7:

			return HAL_GPIO_ReadPin(GPIOB, IN_7_Pin);
			break;

		case IN_8:

			return HAL_GPIO_ReadPin(GPIOB, IN_8_Pin);
			break;

		case IN_9:

			return HAL_GPIO_ReadPin(GPIOB, IN_9_Pin);
			break;

		default:
			return false;

			}
}

bool IoToggle(uint8_t Toggle_Pin)
{

	if(Toggle_Pin <= Outpin_Quantity){

		if (Out_status[Toggle_Pin - 1] == 1)
		{
			IoWrite(Toggle_Pin, 0);
			return true;
			}
		else
		{
			IoWrite(Toggle_Pin, 1);
			return true;
			}
		}
		else
		{
			return false;
			}
}


bool GPIO_Status(uint8_t Output_pin){

return Out_status[Output_pin - 1];

}

void GPIO_test(void){

}


/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
