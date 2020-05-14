/*
 * servo.h
 *
 *  Created on: May 14, 2020
 *      Author: Job Heijlighen
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include "main.h"
#include "pwm.h"
#include "gpio.h"
#include "stdbool.h"


void Servo_int(void);
void servo_demo(void);
bool SetServoAngle(uint16_t angle);


#endif /* INC_SERVO_H_ */
