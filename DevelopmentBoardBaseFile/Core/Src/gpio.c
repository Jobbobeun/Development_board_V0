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
#include "i2c.h"
/* USER CODE BEGIN 0 */
#include "pwm.h"
#include "stdint.h"

#define Outpin_Quantity 13

HAL_StatusTypeDef retTr;
HAL_StatusTypeDef retRe;
HAL_StatusTypeDef retRe2;
HAL_StatusTypeDef retTrInit;
uint8_t received_values[1];
uint8_t received_values2[1];

uint8_t Out_status[13];

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
  GPIO_InitStruct.Pin = IN_3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(IN_3_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = OUT_5_Pin|OUT_6_Pin|PROG_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin 
                           PBPin PBPin */
  GPIO_InitStruct.Pin = IN_5_Pin|IN_8_Pin|IN_9_Pin|IN_7_Pin 
                          |IN_4_Pin|IN_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = IN_6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(IN_6_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin */
  GPIO_InitStruct.Pin = OUT_8_Pin|OUT_7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = IN_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(IN_2_GPIO_Port, &GPIO_InitStruct);

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
		if (Output_State != Out_status[Output_Pin - 1])
		{
			IOE_Write(0, Output_State, IOE1_address);
			Out_status[Output_Pin - 1] = Output_State;

		return true;
		}
		else
		{
			return false;
		}
		break;

	case OUT_10:
		if (Output_State != Out_status[Output_Pin - 1])
		{
			IOE_Write(1, Output_State, IOE1_address);
			Out_status[Output_Pin - 1] = Output_State;

		return true;
		}
		else
		{
			return false;
		}
		break;

	case OUT_11:
		if (Output_State != Out_status[Output_Pin - 1])
		{
			IOE_Write(2, Output_State, IOE1_address);
			Out_status[Output_Pin - 1] = Output_State;

		return true;
		}
		else
		{
			return false;
		}
		break;

	case OUT_12:
		if (Output_State != Out_status[Output_Pin - 1])
		{
			IOE_Write(3, Output_State, IOE1_address);
			Out_status[Output_Pin - 1] = Output_State;

		return true;
		}
		else
		{
			return false;
		}
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

		case MD_A1:
			if (Output_State != Out_status[Output_Pin - 1])
					{
						IOE_Write(7, Output_State, IOE1_address);
						Out_status[Output_Pin - 1] = Output_State;

					return true;
					}
					else
					{
						return false;
					}
					break;

		case MD_A2:
			if (Output_State != Out_status[Output_Pin - 1])
					{
						IOE_Write(6, Output_State, IOE1_address);
						Out_status[Output_Pin - 1] = Output_State;

					return true;
					}
					else
					{
						return false;
					}
					break;

		case MD_A3:
			if (Output_State != Out_status[Output_Pin - 1])
					{
						IOE_Write(5, Output_State, IOE1_address);
						Out_status[Output_Pin - 1] = Output_State;

					return true;
					}
					else
					{
						return false;
					}
					break;

		case MD_A4:
			if (Output_State != Out_status[Output_Pin - 1])
					{
						IOE_Write(4, Output_State, IOE1_address);
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
bool ActiveRead;
		switch(Input_Pin){
		case IN_1:

			ActiveRead = HAL_GPIO_ReadPin(GPIOB, IN_1_Pin);
			break;

		case IN_2:

			ActiveRead = HAL_GPIO_ReadPin(GPIOB, IN_2_Pin);
			break;

		case IN_3:

			ActiveRead = HAL_GPIO_ReadPin(GPIOC, IN_3_Pin);
			break;

		case IN_4:

			ActiveRead = HAL_GPIO_ReadPin(GPIOB, IN_4_Pin);
			break;

		case IN_5:

			ActiveRead = HAL_GPIO_ReadPin(GPIOB, IN_5_Pin);
			break;

		case IN_6:

			ActiveRead = HAL_GPIO_ReadPin(GPIOB, IN_6_Pin);
			break;

		case IN_7:

			ActiveRead = HAL_GPIO_ReadPin(GPIOB, IN_7_Pin);
			break;

		case IN_8:

			ActiveRead = HAL_GPIO_ReadPin(GPIOB, IN_8_Pin);
			break;

		case IN_9:

			ActiveRead = HAL_GPIO_ReadPin(GPIOB, IN_9_Pin);
			break;

		default:
			ActiveRead = false;

			}

		if (ActiveRead){
			return false;
		} else if (!ActiveRead) {
			return true;
		} else {
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

void PCF8574_Demo_Write(void){

	//uint8_t buf[2];
	//buf[0] = 0x00; // At first to set all the IO's as outputs (0) next loops to turn off all outputs
	//buf[1] = 0x30; // To turn on P4 and P5

	uint8_t data[1];
	data[0] = 0xEF; // alleen p4 naar 0

	//HAL_Delay(2000);
	// This code toggles output P4 and P5 at 2 Hz
	// First byte after power on defines the IO's as input(1) or as output(0)
	// Seconde byte = pin P4 and P5 HIGH --> binary P7 P6 P5 P4 P3 P2 P1 P0 = 0 0 1 1 0 0 0 0 = 0x30
	// Write address of the PCF is 0x40, two bytes are sent)
	//ret2 = HAL_I2C_Master_Transmit(&hi2c1, 0x40, (uint8_t*) buf, 2, 1000);
	HAL_Delay(2000);

	// One byte is sent (data[0])
	retTr = HAL_I2C_Master_Transmit(&hi2c1, 0x40, (uint8_t*) data, 1, 1000);
	data[0] = 0xFF; // allen p4 weer naar 1

	HAL_Delay(2000);
	retTr = HAL_I2C_Master_Transmit(&hi2c1, 0x40, (uint8_t*) data, 1, 1000);


}

//Het ontvangen lijkt te werken. receiveddata2[2] = {0xE0,0x00} dit wordt overschreven door de ontvangen waarde?
void PCF8574_Demo_Receive(void){

	retRe = HAL_I2C_Master_Receive(&hi2c1, 0x41, (uint8_t*) receiveddata2, 1, 1000);
	//HAL_I2C_Master_Receive(&hi2c1, 0x41, (uint8_t*) receiveddata2, 2, 1000);

}

void PCF_Init(){
	HAL_Delay(3000);

	uint8_t initdata[1] = {0x00};

	//retTrInit = HAL_I2C_Master_Transmit(&hi2c1, 0x4E, (uint8_t*) initdata, 2, 1000);
	retTrInit = HAL_I2C_Master_Transmit(&hi2c1, 0x40, (uint8_t*) initdata, 1, 1000);
}

/**
 * @brief  Write I/O Expander Pins HIGH
 * @param  PWM_Channel DevBoard PWM_x labels
 * @param  Duty_Cycle from 0 to 100%
 */
void IOE_Write(uint8_t pin, bool state, uint8_t IOE_address){



	if (pin == 0)
	{
		GPIO_bitmask.Flag.P0 = state;
	}

	if (pin == 1)
	{
		GPIO_bitmask.Flag.P1 = state;
	}

	if (pin == 2)
	{
		GPIO_bitmask.Flag.P2 = state;
	}

	if (pin == 3)
	{
		GPIO_bitmask.Flag.P3 = state;
	}

	if (pin == 4)
	{
		GPIO_bitmask.Flag.P4 = state;
	}

	if (pin == 5)
	{
		GPIO_bitmask.Flag.P5 = state;
	}

	if (pin == 6)
	{
		GPIO_bitmask.Flag.P6 = state;
	}

	if (pin == 7)
	{
		GPIO_bitmask.Flag.P7 = state;
	}

	//checks the changed bits and updates the PCF with the changed values
	//newdata.All = GPIO_bitmask_actual.All ^ GPIO_bitmask.All;

	//only for one output
	newdata.All = GPIO_bitmask.All;

	//sends the created bitmask to the PCF
	retTr = HAL_I2C_Master_Transmit(&hi2c1, IOE_address, &newdata, 1, 1000);

	//Updates the bitmask actual with the actual states of the IOs of the PCF
	//GPIO_bitmask_actual.All = UpdateIOE();
}

//updates the bitmask actual by reading the actual states from the register of the pcf
uint8_t IOE_Read(void){

	//uint8_t received_values[1]; is nu een globale

	retRe = HAL_I2C_Master_Receive(&hi2c1, 0x41, (uint8_t*) received_values, 1, 1000);
	//HAL_I2C_Master_Receive(&hi2c1, 0x41, (uint8_t*) receiveddata2, 2, 1000);

	return received_values[1];

}

//updates the bitmask actual by reading the actual states from the register of the pcf
uint8_t IOE2_Read(void){

	//uint8_t received_values[1]; is nu een globale

	retRe2 = HAL_I2C_Master_Receive(&hi2c1, 0x4F, (uint8_t*) received_values2, 1, 1000);
	//HAL_I2C_Master_Receive(&hi2c1, 0x41, (uint8_t*) receiveddata2, 2, 1000);

	return received_values2[1];

}

/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
