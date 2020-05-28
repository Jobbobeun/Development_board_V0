/*
 * Motor_Driver.c
 *
 *  Created on: 27 mei 2020
 *      Author: Rob
 */

#include "Motor_Driver.h"
#include "gpio.h"
#include "pwm.h"

#define Motor_drive_pin_A 1
#define Motor_drive_pin_B 2
#define Motor_drive_pin_C 3
#define Motor_drive_pin_D 4


void MotordriverIni(void){
	void StartPWM_1(void);
	void StartPWM_2(void);
	void StartPWM_3(void);
	void StartPWM_4(void);
}

void Rotate_motor(void){
	PWM_Duty_Cycle(PWM_1,60);
	PWM_Duty_Cycle(PWM_2,60);
	PWM_Duty_Cycle(PWM_3,60);
	PWM_Duty_Cycle(PWM_4,60);
}
