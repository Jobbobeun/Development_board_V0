/*
 * serialCom.c
 *
 *  Created on: 14 mei 2020
 *      Author: wojtek
 */

#include "serialCom.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


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
void serialcom_SendString(char data[])
{
	HAL_UART_Transmit(&huart2, (uint8_t*)data, strlen(data), 1000);
}

//------------------------
/* RECEIVING FUNCTIONS */
//------------------------

uint8_t* serialcom_ReceiveChar(void)
{

	HAL_UART_Receive(&huart2, data1, sizeof(data1), 1000);

	return data1;
}


