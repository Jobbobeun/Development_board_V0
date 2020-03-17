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
#include "stdint.h"


void Application(void)
{

//uint8_t TEST[] = "45";

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
	//Debugprint("Test");

}
