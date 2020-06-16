/*
 * LowPowerControl.h
 *
 *  Created on: Jun 4, 2020
 *      Author: Job Heijlighen
 */

#ifndef INC_LOWPOWERCONTROL_H_
#define INC_LOWPOWERCONTROL_H_

#include "stdbool.h"
#include "stdint.h"

void EnterSleepMode(void);
bool SleepStatus(void);
void EnterStopMode(void);
void EnterStandbyMode(void);
void LowPowerMode_init(uint8_t PinNumber);


#endif /* INC_LOWPOWERCONTROL_H_ */
