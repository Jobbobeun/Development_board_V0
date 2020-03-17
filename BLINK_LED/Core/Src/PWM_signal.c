/*
 * PWM_signal.c
 *
 *  Created on: 11 mrt. 2020
 *      Author: Job Heijlighen
 */


#include "PWM_signal.h"
#include "main.h"
#include "Math.h"
#include "Initialization.h"


void PWM_Init(void){

	MX_TIM1_Init();
    MX_TIM2_Init();
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);

}

void PWM_Set(uint8_t Pinnr, uint16_t PWM_value){


if (PWM_value > 100){
	PWM_value = 100;
} else if (PWM_value < 0){
		PWM_value = 0;
}

PWM_value = map(PWM_value, 0, 100, 0, 65535);

	if (Pinnr == 1){
		TIM1->CCR1 = PWM_value;
	}else if (Pinnr == 2){
		TIM1->CCR2 = PWM_value;
	}else if (Pinnr == 3){
		TIM1->CCR3 = PWM_value;
	}else if (Pinnr == 4){
		TIM1->CCR4 = PWM_value;
	}else if (Pinnr == 5){
		TIM2->CCR1 = PWM_value;
	}else if (Pinnr == 6){
		TIM2->CCR2 = PWM_value;
	}

}


