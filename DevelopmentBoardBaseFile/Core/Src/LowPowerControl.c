/*
 * LowPoerControl.c
 *
 *  Created on: Jun 4, 2020
 *      Author: Job Heijlighen
 */


#include "LowPowerControl.h"
#include "main.h"
#include "stm32f1xx_hal.h"
#include "gpio.h"

bool SleepStatusVal;

void EnterSleepMode(void)
{

	HAL_SuspendTick();
	HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
	SleepStatusVal = true;

}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if ((GPIO_Pin == IN_1_Pin) && SleepStatusVal)
	{
		SystemClock_Config();
		 HAL_ResumeTick();
		 SleepStatusVal = false;
	}
}

bool SleepStatus(void)
{
	return SleepStatusVal;
}

void EnterStopMode(void)
{
	HAL_SuspendTick();
	HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFE);
	SleepStatusVal = true;
}

void EnterStandbyMode(void)
{
	// HAL_PWR_EnterSTANDBYMode();	// Watchdog timer is needed!!
	SleepStatusVal = true;
}

void SleepLowPowerMode_init(void)
{

}
