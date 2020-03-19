/*
 * Application.c
 *
 *  Created on: 9 Mar 2020
 *      Author: Rick
 */


#include "application.h"
#include "gpio.h"
#include "main.h"
#include "PWM_signal.h"
#include "stm32f1xx_hal_gpio.h"
#include "Serialdebug.h"
#include "Initialization.h"
#include "stm32f1xx_hal_uart.h"



void Application(void)
{

	 uint16_t raw;
	  char msg[10];

	GPIO_Write(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);

	for (uint8_t i = 0; i<100; i++){
		PWM_Set(PWM_1, i);
		HAL_Delay(1);
	}

	GPIO_Write(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);

	for (uint8_t i = 100; i>0; i--){
		PWM_Set(PWM_1, i);
		HAL_Delay(1);
	}


	//uint8_t Test[] = "Hello World laalaa !!!\r\n";
		Debugprintvar(233);

	//HAL_UART_Transmit(&huart2,Test,sizeof(Test),10);
	// HAL_Delay(1000);

	HAL_ADC_Start(&hadc1);
	    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);

	    raw = HAL_ADC_GetValue(&hadc1);

	    sprintf(msg, "%hu\r\n", raw);
	       HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

}


