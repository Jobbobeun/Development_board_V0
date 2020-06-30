/*
 * application.h
 *
 *  Created on: Apr 21, 2020
 *      Author: Job Heijlighen
 */

#ifndef INC_APPLICATION_H_
#define INC_APPLICATION_H_
#include "stdbool.h"
#include "stdint.h"

void application(void);
enum{
	Main_Idle,
	Main_Wait,
	Main_Toggle,
	Main_Stop
};

uint8_t MainCase;


#endif /* INC_APPLICATION_H_ */
