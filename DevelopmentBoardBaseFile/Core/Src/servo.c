/*
 * servo.c
 *
 *  Created on: May 14, 2020
 *      Author: Job Heijlighen
 */


#include "servo.h"
#include "math.h"

extern TIM_HandleTypeDef htim1;
uint8_t ServoAngle;

void Servo_int(void)
{
	StartPWM_1();

	//PWM_Duty_Cycle(0,10);

	// Check if function is called
	HAL_GPIO_TogglePin(GPIOB, OUT_1_Pin);

}

void servo_demo(void){

	SetServoAngle(0);
	HAL_Delay(1000);
	SetServoAngle(180);
	HAL_Delay(1000);

}

bool SetServoAngle(uint16_t angle)
{
	long map_angle = map(angle, 0, 180, 90, 95);

	if (map_angle != ServoAngle)

	{
		PWM_Duty_Cycle(0,map_angle);
		ServoAngle = map_angle;
		return true;
	}
	else
	{
		return false;
	}


}
