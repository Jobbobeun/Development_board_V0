/*
 * Motor_Driver.c
 *
 *  Created on: 27 mei 2020
 *      Author: Rob
 */

#include "MotorDriver.h"
#include "gpio.h"
#include "stdbool.h"
#include "pwm.h"
#include "stdint.h"


uint8_t MotorDriverActualDirection[3];
uint8_t MotorDriverActualSpeed[3];

bool ControlMotor_CW(uint8_t MotorOutputNumber);
void ControlMotor_CCW(uint8_t MotorOutputNumber);
void ControlMotor_Brake(uint8_t MotorOutputNumber);

void MotordriverIni(void)
{
	StartPWM_1(); // Enable A
	StartPWM_2(); // Enable B

	MotorDriverActualDirection[Motor1] = 255;
	MotorDriverActualDirection[Motor2] = 255;
}

bool Motor(uint8_t MotorOutputNumber, uint8_t Direction, uint8_t Speed)
{
	switch(MotorOutputNumber){

		case Motor1:
		case Motor2:

			if ((Direction == CW) && ((MotorDriverActualDirection[MotorOutputNumber] != Direction) || (MotorDriverActualSpeed[MotorOutputNumber] =! Speed)))
			{
				ControlMotor_CW(MotorOutputNumber);
				PWM_Duty_Cycle(MotorOutputNumber +1, Speed);
				MotorDriverActualDirection[MotorOutputNumber] = Direction;
				MotorDriverActualSpeed[MotorOutputNumber] = Speed;

			}

			else if ((Direction == CCW) && ((MotorDriverActualDirection[MotorOutputNumber] != Direction) || (MotorDriverActualSpeed[MotorOutputNumber] =! Speed)))
			{
				ControlMotor_CCW(MotorOutputNumber);
				PWM_Duty_Cycle(MotorOutputNumber +1, Speed);
				MotorDriverActualDirection[MotorOutputNumber] = Direction;
				MotorDriverActualSpeed[MotorOutputNumber] = Speed;
			}

			else if ((Direction == BRAKE)  && (MotorDriverActualDirection[MotorOutputNumber] != Direction))
			{
				ControlMotor_Brake(MotorOutputNumber);
			}

		break;

		case Stepper:

		break;

		default:

			return false;

	}

	return false;
}

bool ControlMotor_CW(uint8_t MotorOutputNumber)
{
	switch(MotorOutputNumber){

	case Motor1:
		IoWrite(OUT_3, true);				// OUT NEEDS TO BE CHANGED!!!
		IoWrite(OUT_4, false);				// OUT NEEDS TO BE CHANGED!!!
		return true;
		break;

	case Motor2:
		IoWrite(OUT_5, true);				// OUT NEEDS TO BE CHANGED!!!
		IoWrite(OUT_6, false);				// OUT NEEDS TO BE CHANGED!!!
		return true;
		break;
	default:
		return false;
	}

}

void ControlMotor_CCW(uint8_t MotorOutputNumber)
{
	switch(MotorOutputNumber){

	case Motor1:
		IoWrite(OUT_3, false);				// OUT NEEDS TO BE CHANGED!!!
		IoWrite(OUT_4, true);				// OUT NEEDS TO BE CHANGED!!!
		break;

	case Motor2:
		IoWrite(OUT_5, false);				// OUT NEEDS TO BE CHANGED!!!
		IoWrite(OUT_6, true);				// OUT NEEDS TO BE CHANGED!!!
		break;
	}

}

void ControlMotor_Brake(uint8_t MotorOutputNumber)
{
	switch(MotorOutputNumber){

	case Motor1:
		IoWrite(OUT_3, true);				// OUT NEEDS TO BE CHANGED!!!
		IoWrite(OUT_4, true);				// OUT NEEDS TO BE CHANGED!!!
		PWM_Duty_Cycle(PWM_1, 100);
		break;

	case Motor2:
		IoWrite(OUT_5, true);				// OUT NEEDS TO BE CHANGED!!!
		IoWrite(OUT_6, true);				// OUT NEEDS TO BE CHANGED!!!
		PWM_Duty_Cycle(PWM_2, 100);
		break;
	}

}
