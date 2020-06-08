/*
 * LowPowerControl.h
 *
 *  Created on: Jun 4, 2020
 *      Author: Job Heijlighen
 */

#ifndef INC_LOWPOWERCONTROL_H_
#define INC_LOWPOWERCONTROL_H_

#include "stdbool.h"

void EnterSleepMode(void);
bool SleepStatus(void);
void EnterStopMode(void);
void EnterStandbyMode(void);
void SleepLowPowerMode_init(void);


#endif /* INC_LOWPOWERCONTROL_H_ */
