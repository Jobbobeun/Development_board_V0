/*
 * pwm.h
 *
 *  Created on: 22 apr. 2020
 *      Author: nlrstem
 */

#ifndef INC_PWM_H_
#define INC_PWM_H_

#include "main.h"


enum PWM {ENABLE_A, ENABLE_B, PWM_1, PWM_2, PWM_3, PWM_4};

void StartENABLE_A(void);
void StartENABLE_B(void);
void StartPWM_1(void);
void StartPWM_2(void);
void StartPWM_3(void);
void StartPWM_4(void);
void StartPWM_All(void);

void PWM_Duty_Cycle(uint8_t PWM_Channel, uint16_t Duty_Cycle);

#endif /* INC_PWM_H_ */
