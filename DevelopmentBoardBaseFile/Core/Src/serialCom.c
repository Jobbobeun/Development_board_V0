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

//char data1[10];


//------------------------
/* INITIALIZATION */
//------------------------
void serialcom_init(void)
{
	HAL_Init();
	MX_GPIO_Init();
	MX_USART2_UART_Init();
}

//------------------------
/* SENDING FUNCTIONS */
//------------------------
void serialcom_SendString(char data[], uint16_t delay)
{
	HAL_UART_Transmit(&huart2, (uint8_t*)data, strlen(data), 1000);
	HAL_Delay(delay);
}

//------------------------
/* RECEIVING FUNCTIONS */
//------------------------

uint8_t* serialcom_ReceiveChar(void)
{

	HAL_UART_Receive(&huart2, data1, sizeof(data1), 1000);

	return data1;
}


