/*
 * Adc.c
 *
 *  Created on: Mar 18, 2020
 *      Author: Job Heijlighen
 */

#include "Adc.h"
#include "Initialization.h"
#include "main.h"

void ADC_Init(void){

	HAL_ADC_Start_DMA(&hadc1, ADC_array, 7);

}


