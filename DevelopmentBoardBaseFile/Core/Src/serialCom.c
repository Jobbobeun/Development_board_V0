/*
 * serialCom.c
 *
 *  Created on: 14 mei 2020
 *      Author: wojtek
 */

//uint8_t serial;

#include "serialCom.h"
#include "stdio.h"

uint8_t data[10];
uint8_t data1[] = {0,1,2,3,4,5,6,7,8,9};


int serialcom_init(void)
{

	//MX_GPIO_Init();
	//MX_USART2_UART_Init();

	while(1)
	{
		//HAL_UART_Receive(&huart2, data, 10, 1000);
		HAL_UART_Transmit(&huart2, data1, 10, 1000);
	}

}
