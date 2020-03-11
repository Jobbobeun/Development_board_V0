/*
 * PWM_signal.h
 *
 *  Created on: 11 mrt. 2020
 *      Author: Jan de Brandweerman
 */

#ifndef INC_PWM_SIGNAL_H_
#define INC_PWM_SIGNAL_H_
#include "stm32f1xx_hal.h"



// define
#define PWM_1 1
#define PWM_2 2
#define PWM_3 3
#define PWM_4 4
#define PWM_5 5
#define PWM_6 6

// functions
void PWM_Init(void);
void PWM_Set(uint8_t Pinnr, uint16_t PWM_value);

#endif /* INC_PWM_SIGNAL_H_ */
