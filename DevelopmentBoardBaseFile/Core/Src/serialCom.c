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

char data1[10];


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
void serialcom_SendChar(char data[], uint8_t delay)
{
	HAL_UART_Transmit(&huart2, (uint8_t*)data, strlen(data), 1000);
	HAL_Delay(delay);
}


//------------------------
/* RECEIVING FUNCTIONS */
//------------------------

int serialcom_ReceiveChar()
{

	HAL_UART_Receive(&huart2, (uint8_t*)data1, strlen(data1), 1000);
	//HAL_Delay(delay1);
	return data1[10];
}



/*while(1)
{

	HAL_UART_Receive(&huart2, (uint8_t*)data1, sizeof(data1), 1000);
	//HAL_Delay(5000);
	HAL_UART_Transmit(&huart2, (uint8_t*)data, sizeof(data), 1000);

}*/
