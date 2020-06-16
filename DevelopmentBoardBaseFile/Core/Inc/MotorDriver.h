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

void MotordriverIni(void);
bool Motor(uint8_t MotorOutputNumber, uint8_t Direction, uint8_t Speed);

#endif /* INC_MOTORDRIVER_H_ */
