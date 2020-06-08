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
uint8_t WakeUpPin;

/*
 * @Brief	Function activate the Sleepmode.
 */
void EnterSleepMode(void)
{

	HAL_SuspendTick();
	HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
	SleepStatusVal = true;

}

/*
 * @Brief	Interrupt from Input pin. Case determine witch pin the microcontroller wakeup.
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	switch(WakeUpPin){

	case IN_1:
		if ((GPIO_Pin == IN_1_Pin) && SleepStatusVal)
		{
			SystemClock_Config();
			 HAL_ResumeTick();
			 SleepStatusVal = false;
		}
		break;

	case IN_2:
		if ((GPIO_Pin == IN_2_Pin) && SleepStatusVal)
		{
			SystemClock_Config();
			 HAL_ResumeTick();
			 SleepStatusVal = false;
		}
		break;

	case IN_3:
		if ((GPIO_Pin == IN_3_Pin) && SleepStatusVal)
		{
			SystemClock_Config();
			 HAL_ResumeTick();
			 SleepStatusVal = false;
		}
		break;

	case IN_4:
		if ((GPIO_Pin == IN_4_Pin) && SleepStatusVal)
		{
			SystemClock_Config();
			 HAL_ResumeTick();
			 SleepStatusVal = false;
		}
		break;
	}

}

/*
 * @Brief	Return status if the microcontroller in a sleepmode.
 */
bool SleepStatus(void)
{
	return SleepStatusVal;
}

/*
 * @Brief	Function activate the Stopmode.
 */
void EnterStopMode(void)
{
	HAL_SuspendTick();
	HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFE);
	SleepStatusVal = true;
}

/*
 * @Brief	Function activate the Standbymode. Function not tested yet. Not possible without watchdog timer.
 */
void EnterStandbyMode(void)
{
	// HAL_PWR_EnterSTANDBYMode();	// Watchdog timer is needed!!
	SleepStatusVal = true;
}

/*
 * @Brief	Select PinNumber for wakeup the microcontroller
 * @param 	PinNumber also possible to use IN_1, IN_2, IN_3, IN_4
 */
void LowPowerMode_init(uint8_t PinNumber)
{
	WakeUpPin = PinNumber;
}
