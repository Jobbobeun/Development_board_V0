/*
 * serialCom.h
 *
 *  Created on: 14 mei 2020
 *      Author: wojtek
 */

#include "stm32f1xx_hal.h"
#include "application.h"
#include "gpio.h"
#include "main.h"

#include "usart.h"

#ifndef INC_SERIALCOM_H_
#define INC_SERIALCOM_H_

//-------------------------------------------------------------------
// This function is to initialize the serial communication over UART
// The baudrate is set to 115200
// The data length is set to 8 bits including 1 stop bit
// No parity in the transfer
//-------------------------------------------------------------------
void serialcom_init(void);

//---------------------------------------------------------------------------
// This function sends 1 character over UART
// For correct usage you have to fill in two variables
// char data[] => here you fill in the character that has to be send
// uint8_t delay => here you fill in the delay of between the send characters
//----------------------------------------------------------------------------
void serialcom_SendChar(char data[], uint8_t delay);


int serialcom_ReceiveChar();


#endif /* INC_SERIALCOM_H_ */


