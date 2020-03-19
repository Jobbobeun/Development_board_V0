/*
 * Serial.debug.c
 *
 *  Created on: Mar 16, 2020
 *      Author: Job Heijlighen
 */


#include "application.h"
#include "gpio.h"
#include "main.h"
#include "PWM_signal.h"
#include "stm32f1xx_hal_gpio.h"
#include "Serialdebug.h"
#include "Initialization.h"
#include "stm32f1xx_hal_uart.h"


void Debugprint(char data[])
{
	HAL_UART_Transmit(&huart2, (uint8_t*)data, strlen(data) ,HAL_MAX_DELAY);

}
void Debugprintln(char data[])
{
	char data2[10];

	 sprintf(data2, "%s\r\n", data);
	HAL_UART_Transmit(&huart2, (uint8_t*)data2, strlen(data2) ,HAL_MAX_DELAY);

}
void Debugprintvar(char data[])
{
	char data2[10];

		 sprintf(data2, "%hu\r\n", data);
		HAL_UART_Transmit(&huart2, (uint8_t*)data2, strlen(data2) ,HAL_MAX_DELAY);
}
