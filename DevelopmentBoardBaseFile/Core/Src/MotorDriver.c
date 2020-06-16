/*
 * Motor_Driver.c
 *
 *  Created on: 27 mei 2020
 *      Author: Rob
 */

#include "MotorDriver.h"
#include "gpio.h"
#include "pwm.h"
#include "stdint.h"

#define MotorDriver_IO


void MotordriverIni(void)
{
	StartPWM_1(); // Enable A
	StartPWM_2(); // Enable B
}

bool Motor(uint8_t MotorOutputNumber, uint8_t Direction, uint8_t Speed)
{
	switch(MotorOutputNumber){

		case Motor1:

			if (Direction == CW){

				PWM_Duty_Cycle(PWM_1, Speed);
			}



		break;

		case Motor2:

		break;

		case Stepper:

		break;

		default:

			return false;

	}

	return false;
}

