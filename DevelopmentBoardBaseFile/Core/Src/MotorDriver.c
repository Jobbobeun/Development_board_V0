/*
 * Motor_Driver.c
 *
 *  Created on: 27 mei 2020
 *      Author: Job Heijlighen
 */

#include "MotorDriver.h"
#include "gpio.h"
#include "stdbool.h"
#include "pwm.h"
#include "stdint.h"


uint8_t MotorDriverActualDirection[3];
uint8_t MotorDriverActualSpeed[3];
uint8_t StepperStateVariable[2];
uint8_t MotorOutputStatus[4];
uint8_t MotorStart[2];
uint8_t MotorProfileState[3];
uint8_t MotorProfileSpeed[3];
uint8_t MotorProfileSettlingTime[3];

bool ControlMotor_CW(uint8_t MotorOutputNumber);
bool ControlMotor_CCW(uint8_t MotorOutputNumber);
bool ControlMotor_Brake(uint8_t MotorOutputNumber);
bool ControlMotor_Stop(uint8_t MotorOutputNumber);

void MotordriverIni(void)
{

	MotorDriverActualDirection[Motor1] = 255;
	MotorDriverActualDirection[Motor2] = 255;
	MotorOutputStatus[0] = 0;
	MotorOutputStatus[1] = 0;
	MotorOutputStatus[2] = 0;
	MotorOutputStatus[3] = 0;
	MotorStart[Motor1] = false;
	MotorStart[Motor2] = false;
	MotorProfileState[Motor1] = Motor_Idle;
	MotorProfileState[Motor2] = Motor_Idle;
	MotorProfileState[Stepper] = Motor_Idle;
	MotorProfileSpeed[Motor1] = 0;
	MotorProfileSpeed[Motor2] = 0;
	MotorProfileSpeed[Stepper] = 0;
	MotorProfileSettlingTime[Motor1] = 0;
	MotorProfileSettlingTime[Motor2] = 0;
	MotorProfileSettlingTime[Stepper] = 0;

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
			MotorErrorHandler(MotorOutputNumber);
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
			MotorErrorHandler(MotorOutputNumber);
			return false;
		}
	}

	else if ((Direction == BRAKE)  && (MotorDriverActualDirection[MotorOutputNumber] != Direction))
	{
		if (ControlMotor_Brake(MotorOutputNumber)){
			MotorDriverActualDirection[MotorOutputNumber] = Direction;
			return true;
		} else {
			MotorErrorHandler(MotorOutputNumber);
			return false;
		}
	}

	else if ((Direction == STOP)  && (MotorDriverActualDirection[MotorOutputNumber] != Direction))
	{
		if (ControlMotor_Stop(MotorOutputNumber)){
			MotorDriverActualDirection[MotorOutputNumber] = Direction;
			return true;
		} else {
			MotorErrorHandler(MotorOutputNumber);
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
	bool TempStatus1 = false;
	bool TempStatus2 = false;

	switch(MotorOutputNumber){

	case Motor1:
		if (MotorOutputStatus[0] != 1){
			if (IoWrite(MD_A1, true)){				// OUT NEEDS TO BE CHANGED!!!
				MotorOutputStatus[0] = 1;
				TempStatus1 = true;
			}
			else {
				return false;
			}
		} else if(!MotorStart[Motor1]){
			MotorStart[Motor1] = true;
			TempStatus1 = true;
		}

		if (MotorOutputStatus[1] != 0){
			if (IoWrite(MD_A2, false)){				// OUT NEEDS TO BE CHANGED!!!
				MotorOutputStatus[1] = 0;
				TempStatus2 = true;

			} else{
				return false;
			}
		}  else if(!MotorStart[Motor1]){
			MotorStart[Motor1] = true;
			TempStatus2 = true;
		}

		if (TempStatus1 && TempStatus2){
			return true;
		} else {
			return false;
		}

		break;

	case Motor2:
		if (MotorOutputStatus[2] != 1){
			if (IoWrite(MD_A3, true)){				// OUT NEEDS TO BE CHANGED!!!
				MotorOutputStatus[2] = 1;
				TempStatus1 = true;
			}
			else {
				return false;
			}
		} else if(!MotorStart[Motor2]){
			MotorStart[Motor2] = true;
			TempStatus1 = true;
		}

		if (MotorOutputStatus[3] != 0){
			if (IoWrite(MD_A4, false)){				// OUT NEEDS TO BE CHANGED!!!
				MotorOutputStatus[3] = 0;
				TempStatus2 = true;

			} else{
				return false;
			}
		}  else if(!MotorStart[Motor2]){
			MotorStart[Motor2] = true;
			TempStatus2 = true;
		}

		if (TempStatus1 && TempStatus2){
			return true;
		} else {
			return false;
		}

		break;

	case Stepper:
		StepperStateVariable[0] = Stepper_CW;
		return true;
		break;

	default:
		MotorErrorHandler(MotorOutputNumber);
		return false;
	}

}

bool ControlMotor_CCW(uint8_t MotorOutputNumber)
{
	bool TempStatus1 = false;
	bool TempStatus2 = false;

	switch(MotorOutputNumber){

	case Motor1:
		if (MotorOutputStatus[0] != 0){
			if (IoWrite(MD_A1, false)){				// OUT NEEDS TO BE CHANGED!!!
				MotorOutputStatus[0] = 0;
				TempStatus1 = true;
			}
			else {
				return false;
			}
		} else if(!MotorStart[Motor1]){
			MotorStart[Motor1] = true;
			TempStatus1 = true;
		}

		if (MotorOutputStatus[1] != 1){
			if (IoWrite(MD_A2, true)){				// OUT NEEDS TO BE CHANGED!!!
				MotorOutputStatus[1] = 1;
				TempStatus2 = true;

			} else{
				return false;
			}
		}  else if(!MotorStart[Motor1]){
			MotorStart[Motor1] = true;
			TempStatus2 = true;
		}

		if (TempStatus1 && TempStatus2){
			return true;
		} else {
			return false;
		}

		break;

	case Motor2:
		if (MotorOutputStatus[2] != 0){
			if (IoWrite(MD_A3, false)){				// OUT NEEDS TO BE CHANGED!!!
				MotorOutputStatus[2] = 0;
				TempStatus1 = true;
			}
			else {
				return false;
			}
		} else if(!MotorStart[Motor2]){
			MotorStart[Motor2] = true;
			TempStatus1 = true;
		}

		if (MotorOutputStatus[3] != 1){
			if (IoWrite(MD_A4, true)){				// OUT NEEDS TO BE CHANGED!!!
				MotorOutputStatus[3] = 1;
				TempStatus2 = true;

			} else{
				return false;
			}
		}  else if(!MotorStart[Motor2]){
			MotorStart[Motor2] = true;
			TempStatus2 = true;
		}

		if (TempStatus1 && TempStatus2){
			return true;
		} else {
			return false;
		}
		break;


	case Stepper:
		StepperStateVariable[0] = Stepper_CCW;
		return true;
		break;

	default:
		MotorErrorHandler(MotorOutputNumber);
		return false;
	}



}

bool ControlMotor_Brake(uint8_t MotorOutputNumber)
{
	bool TempError = false;

	switch(MotorOutputNumber){

	case Motor1:

		if(MotorOutputStatus[0] != true){
			if(IoWrite(MD_A1, true)){				// OUT NEEDS TO BE CHANGED!!!
				MotorOutputStatus[0] = true;
			} else{
				TempError = true;
			}
		}
		if(MotorOutputStatus[1] != true){
			if(IoWrite(MD_A2, true)){				// OUT NEEDS TO BE CHANGED!!!
				MotorOutputStatus[1] = true;
			} else{
				TempError = true;
			}
		}

		PWM_Duty_Cycle(ENABLE_A, 100);

		if (MotorOutputStatus[0] && MotorOutputStatus[1]){
				MotorStart[Motor1] = false;
		} else{
			TempError = true;
		}

		if (TempError){
			return false;
		}else{
			return true;
		}

		break;

	case Motor2:

		if(MotorOutputStatus[2] != true){
			if(IoWrite(MD_A3, true)){				// OUT NEEDS TO BE CHANGED!!!
				MotorOutputStatus[2] = true;
			} else{
				TempError = true;
			}
		}
		if(MotorOutputStatus[3] != true){
			if(IoWrite(MD_A4, true)){				// OUT NEEDS TO BE CHANGED!!!
				MotorOutputStatus[3] = true;
			} else{
				TempError = true;
			}
		}
		PWM_Duty_Cycle(ENABLE_B, 100);

		if (MotorOutputStatus[2] && MotorOutputStatus[3]){
			MotorStart[Motor2] = false;
		}

		if (TempError){
			return false;
		}else{
			return true;
		}

		break;

	case Stepper:
		StepperStateVariable[0] = Stepper_Brake;
		return true;
		break;

	default:
		MotorErrorHandler(MotorOutputNumber);
		return false;
	}


}

bool ControlMotor_Stop(uint8_t MotorOutputNumber)
{
	bool TempError = false;

	switch(MotorOutputNumber){

	case Motor1:

		if(MotorOutputStatus[0] != false){
			if(IoWrite(MD_A1, false)){				// OUT NEEDS TO BE CHANGED!!!
				MotorOutputStatus[0] = false;
			} else{
				TempError = true;
			}
		}
		if(MotorOutputStatus[1] != false){
			if(IoWrite(MD_A2, false)){				// OUT NEEDS TO BE CHANGED!!!
				MotorOutputStatus[1] = false;
			} else{
				TempError = true;
			}
		}

		PWM_Duty_Cycle(ENABLE_A, 0);

		if (!MotorOutputStatus[0] && !MotorOutputStatus[1]){
				MotorStart[Motor1] = false;
		} else{
			TempError = true;
		}

		if (TempError){
			return false;
		}else{
			return true;
		}

		break;

	case Motor2:

		if(MotorOutputStatus[2] != false){
			if(IoWrite(MD_A3, false)){				// OUT NEEDS TO BE CHANGED!!!
				MotorOutputStatus[2] = false;
			} else{
				TempError = true;
			}
		}
		if(MotorOutputStatus[3] != false){
			if(IoWrite(MD_A4, false)){				// OUT NEEDS TO BE CHANGED!!!
				MotorOutputStatus[3] = false;
			} else{
				TempError = true;
			}
		}
		PWM_Duty_Cycle(ENABLE_B, 0);

		if (!MotorOutputStatus[2] && !MotorOutputStatus[3]){
			MotorStart[Motor2] = false;
		}

		if (TempError){
			return false;
		}else{
			return true;
		}

		break;

	case Stepper:
		StepperStateVariable[0] = Stepper_Stop;
		return true;
		break;

	default:
		MotorErrorHandler(MotorOutputNumber);
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
		MotorErrorHandler(Stepper);
	}

}

uint8_t StepperState (uint8_t StepperNumber)
{
	return StepperStateVariable[StepperNumber-1];
}


// Set all Motor variables back to default.
void MotorErrorHandler(uint8_t MotorOutputNumber){

	switch(MotorOutputNumber){
	case Motor1:
		ControlMotor_Stop(Motor1);
		MotorOutputStatus[0] = 0;
		MotorOutputStatus[1] = 0;
		MotorStart[Motor1] = false;
		break;

	case Motor2:
		ControlMotor_Stop(Motor2);
		MotorOutputStatus[2] = 0;
		MotorOutputStatus[3] = 0;
		MotorStart[Motor2] = false;
		break;

	case Stepper:
		StepperStateVariable[0] = Stepper_Idle;
		break;

	default:
		MotordriverIni();
	}

}

bool MotorProfile(uint8_t MotorOutputNumber, uint8_t Direction, uint8_t Speed, uint8_t SettlingTime)
{
	switch(MotorProfileState[MotorOutputNumber]){

	case Motor_Idle:

		return true;

		break;

	case Motor_Acceleration:

		return true;

		break;

	case Motor_Constant:

		return true;

		break;

	case Motor_Slow:

		return true;

		break;

	default:
		return false;
	}
}

