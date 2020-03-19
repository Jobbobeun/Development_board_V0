/*
 * Serial.debug.h
 *
 *  Created on: Mar 16, 2020
 *      Author: Job Heijlighen
 */


#ifndef INC_SERIALDEBUG_H_
#define INC_SERIALDEBUG_H_

#include "stdint.h"
 #include "stdio.h"
 #include "stdlib.h"
 #include "string.h"


void Debugprint(char data[]);
void Debugprintln(char data[]);
void Debugprintvar(char data[]);


#endif /* INC_SERIALDEBUG_H_ */
