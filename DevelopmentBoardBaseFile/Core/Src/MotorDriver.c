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
uint8_t StepperStateVariable[2];

bool ControlMotor_CW(uint8_t MotorOutputNumber);
bool ControlMotor_CCW(uint8_t MotorOutputNumber);
bool ControlMotor_Brake(uint8_t MotorOutputNumber);
bool ControlMotor_Stop(uint8_t MotorOutputNumber);

void MotordriverIni(void)
{
	StartPWM_1(); // Enable A
	StartPWM_2(); // Enable B

	MotorDriverActualDirection[Motor1] = 255;
	MotorDriverActualDirection[Motor2] = 255;
}

bool Motor(uint8_t MotorOutputNumber, uint8_t Direction, uint8_t Speed)
{

	if ((Direction == CW) && ((MotorDriverActualDirection[MotorOutputNumber] != Direction) || (MotorDriverActualSpeed[MotorOutputNumber] =! Speed)))
	{
		if (ControlMotor_CW(MotorOutputNumber)){
			PWM_Duty_Cycle(MotorOutputNumber +1, Speed);
			MotorDriverActualDirection[MotorOutputNumber] = Direction;
			MotorDriverActualSpeed[MotorOutputNumber] = Speed;
			return true;
		} else {
			return false;
		}
	}

	else if ((Direction == CCW) && ((MotorDriverActualDirection[MotorOutputNumber] != Direction) || (MotorDriverActualSpeed[MotorOutputNumber] =! Speed)))
	{
		if (ControlMotor_CCW(MotorOutputNumber)){
			PWM_Duty_Cycle(MotorOutputNumber +1, Speed);
			MotorDriverActualDirection[MotorOutputNumber] = Direction;
			MotorDriverActualSpeed[MotorOutputNumber] = Speed;
			return true;
		} else {
			return false;
		}
	}

	else if ((Direction == BRAKE)  && (MotorDriverActualDirection[MotorOutputNumber] != Direction))
	{
		if (ControlMotor_Brake(MotorOutputNumber)){
			MotorDriverActualDirection[MotorOutputNumber] = Direction;
			return true;
		} else {
			return false;
		}
	}

	else if ((Direction == STOP)  && (MotorDriverActualDirection[MotorOutputNumber] != Direction))
	{
		if (ControlMotor_Stop(MotorOutputNumber)){
			MotorDriverActualDirection[MotorOutputNumber] = Direction;
			return true;
		} else {
			return false;
		}
	}
	else
	{
		return false;
	}


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

	case Stepper:
		StepperStateVariable[0] = Stepper_CW;
		return true;
		break;

	default:
		MotorErrorHandler();
		return false;
	}

}

bool ControlMotor_CCW(uint8_t MotorOutputNumber)
{
	switch(MotorOutputNumber){

	case Motor1:
		IoWrite(OUT_3, false);				// OUT NEEDS TO BE CHANGED!!!
		IoWrite(OUT_4, true);				// OUT NEEDS TO BE CHANGED!!!
		return true;
		break;

	case Motor2:
		IoWrite(OUT_5, false);				// OUT NEEDS TO BE CHANGED!!!
		IoWrite(OUT_6, true);				// OUT NEEDS TO BE CHANGED!!!
		return true;
		break;

	case Stepper:
		StepperStateVariable[0] = Stepper_CCW;
		return true;
		break;

	default:
		MotorErrorHandler();
		return false;
	}

}

bool ControlMotor_Brake(uint8_t MotorOutputNumber)
{
	switch(MotorOutputNumber){

	case Motor1:
		IoWrite(OUT_3, true);				// OUT NEEDS TO BE CHANGED!!!
		IoWrite(OUT_4, true);				// OUT NEEDS TO BE CHANGED!!!
		PWM_Duty_Cycle(PWM_1, 100);
		return true;
		break;

	case Motor2:
		IoWrite(OUT_5, true);				// OUT NEEDS TO BE CHANGED!!!
		IoWrite(OUT_6, true);				// OUT NEEDS TO BE CHANGED!!!
		PWM_Duty_Cycle(PWM_2, 100);
		return true;
		break;

	case Stepper:
		StepperStateVariable[0] = Stepper_Brake;
		return true;
		break;

	default:
		MotorErrorHandler();
		return false;
	}


}

bool ControlMotor_Stop(uint8_t MotorOutputNumber)
{

	switch(MotorOutputNumber){

	case Motor1:
		IoWrite(OUT_3, false);				// OUT NEEDS TO BE CHANGED!!!
		IoWrite(OUT_4, false);				// OUT NEEDS TO BE CHANGED!!!
		PWM_Duty_Cycle(PWM_1, 100);
		return true;
		break;

	case Motor2:
		IoWrite(OUT_5, false);				// OUT NEEDS TO BE CHANGED!!!
		IoWrite(OUT_6, false);				// OUT NEEDS TO BE CHANGED!!!
		PWM_Duty_Cycle(PWM_2, 100);
		return true;
		break;

	case Stepper:
		StepperStateVariable[0] = Stepper_Stop;
		return true;
		break;

	default:
		MotorErrorHandler();
		return false;
	}

}

void StepperController(uint8_t StepperNumber)
{
	switch(StepperState(StepperNumber)){
	case Stepper_Idle:
		break;

	case Stepper_CW:
		break;

	case Stepper_CCW:
		break;

	case Stepper_Stop:
		break;

	case Stepper_Brake:
		break;

	default:
		MotorErrorHandler();
	}

}

uint8_t StepperState (uint8_t StepperNumber)
{
	return StepperStateVariable[StepperNumber-1];
}


// Set all Motor variables back to default.
void MotorErrorHandler(void){
	StepperStateVariable[0] = Stepper_Idle;
}
