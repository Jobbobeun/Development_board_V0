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
	Switch_On,
	Switch_Off,
	Drive_On,
	Drive_Off,
	LCD_On,
	LCD_Off,
	Lift_Up,
	Lift_Down,
};

uint8_t MainCase;
uint8_t Counter;


#endif /* INC_APPLICATION_H_ */
