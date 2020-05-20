/*
 * serialCom.c
 *
 *  Created on: 14 mei 2020
 *      Author: wojtek
 */

//uint8_t serial;

#include "serialCom.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char data[8];
//uint8_t data1[] = {0,1,2,3,4,5,6,7,8,9};
char data1[] = {"h"};

int serialcom_init(void)
{

	//MX_GPIO_Init();
	//MX_USART2_UART_Init();

	while(1)
	{
		HAL_UART_Receive(&huart2, (uint8_t*)data, strlen(data), HAL_MAX_DELAY);
		HAL_UART_Transmit(&huart2, (uint8_t*)data1, strlen(data1) ,HAL_MAX_DELAY);
	}

}
