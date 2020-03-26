/*
 * Application.c
 *
 *  Created on: 9 Mar 2020
 *      Author: Rick & Job
 */

#include "main.h"
#include "application.h"
#include "gpio.h"
#include "PWM_signal.h"
#include "stm32f1xx_hal_gpio.h"
#include "Serialdebug.h"
#include "Initialization.h"
#include "stm32f1xx_hal_uart.h"
#include "i2c.h"


//Main function

void Application(void)
{

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

	//I2C_ADXL345_test();

}


