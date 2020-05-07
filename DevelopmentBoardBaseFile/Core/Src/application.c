/*
 * application.c
 *
 *  Created on: Apr 21, 2020
 *      Author: Job Heijlighen
 */


#include "application.h"
#include "adc.h"
#include "gpio.h"


void application(void){

for (i = 1 ; i < 8 ; i++){

	if (i ==1 ){
	HAL_GPIO_TogglePin(GPIOB, OUT_8_Pin);
	} else if (i ==2 ){
	HAL_GPIO_TogglePin(GPIOB, OUT_9_Pin);
	}else if (i ==3 ){
	HAL_GPIO_TogglePin(GPIOB, OUT_3_Pin);
	}else if (i ==4 ){
	HAL_GPIO_TogglePin(GPIOB, OUT_4_Pin);
	}else if (i ==5 ){
	HAL_GPIO_TogglePin(GPIOB, OUT_5_Pin);
	}else if (i ==6 ){
	HAL_GPIO_TogglePin(GPIOB, OUT_6_Pin);
	}else if (i ==7 ){
	HAL_GPIO_TogglePin(GPIOA, OUT_7_Pin);
	}

	HAL_Delay(100);
}

}
