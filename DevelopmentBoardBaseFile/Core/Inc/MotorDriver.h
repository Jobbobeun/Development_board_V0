/*
 * Motor_Driver.h
 *
 *  Created on: 27 mei 2020
 *      Author: Rob
 */

#ifndef INC_MOTORDRIVER_H_
#define INC_MOTORDRIVER_H_

#include "stdbool.h"
#include "stdint.h"



enum MotorDriverDirection{
	CW,
	CCW,
	STOP,
	BRAKE
};

enum MotorNumber{
	Motor1,
	Motor2,
	Stepper
};

enum StepperStates{
	Stepper_Idle,
	Stepper_CW,
	Stepper_CCW,
	Stepper_Stop,
	Stepper_Brake
};


void StepperController(uint8_t StepperNumber);
uint8_t StepperState (uint8_t StepperNumber);
void MotordriverIni(void);
void MotorErrorHandler(void);
bool Motor(uint8_t MotorOutputNumber, uint8_t Direction, uint8_t Speed);

#endif /* INC_MOTORDRIVER_H_ */
