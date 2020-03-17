/*
 * Serial.debug.c
 *
 *  Created on: Mar 16, 2020
 *      Author: Job Heijlighen
 */

#include "Serialdebug.h"
#include "main.h"
#include "Initialization.h"


//int8_t data[] = "Hello World\r\n";
 // = "15151\r\n";

static void concatenate(char p[], char q[]) ;
void concatenate_string(char *original, char *add);

void Debugprint(char data[])
{
char space[] = "\r\n";
//gets(data);
//gets(space);

strcat(data, space);

	HAL_UART_Transmit(&huart2, data, sizeof(data), HAL_MAX_DELAY);

}


/*
void Debugprintln(uint8_t data[])
{
data = data + "\r\n";

	HAL_UART_Transmit(&huart2, data, sizeof(data), 20);

}
*/


