/*
 * pwm.c
 *
 *  Created on: 22 apr. 2020
 *      Author: nlrstem
 */

#include "pwm.h"
#include "tim.h"

/**
 * @brief  Start PWM Channel 1
 */
void StartPWM_1(void) {
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
}

/**
 * @brief  Start PWM Channel 2
 */
void StartPWM_2(void) {
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
}

/**
 * @brief  Start PWM Channel 3
 */
void StartPWM_3(void) {
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
}

/**
 * @brief  Start PWM Channel 4
 */
void StartPWM_4(void) {
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
}

/**
 * @brief  Start PWM Channel 5
 */
void StartPWM_5(void) {
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
}

/**
 * @brief  Start PWM Channel 6
 */
void StartPWM_6(void) {
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}

/**
 * @brief  Start all PWM channels
 */
void StartPWM_All(void) {
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_ALL);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_ALL);
}

long map(long x, long in_min, long in_max, long out_min, long out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/**
 * @brief  Fixed led brightness
 * @param  PWM Channel DevBoard PWM_x labels
 * @param  Percentage from 0 to 100%
 */
void LedBrightness(uint8_t PWM_Channel, uint16_t Brightness) {

	long map_val = map(Brightness, 0, 100, 0, 1024);

	switch (PWM_Channel) {
	case PWM_1:
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, map_val);
		break;

	case PWM_2:
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, map_val);
		break;

	case PWM_3:
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, map_val);
		break;

	case PWM_4:
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, map_val);
		break;

	case PWM_5:
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, map_val);
		break;

	case PWM_6:
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, map_val);
		break;
	}
}
