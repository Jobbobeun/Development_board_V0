/*
 * application.c
 *
 *  Created on: Apr 21, 2020
 *      Author: Job Heijlighen
 */


#include "application.h"
#include "adc.h"
#include "lcd.h"


void application(void){



	lcdPrint("Hallo world",0,0);
HAL_Delay(500);
lcdPrint("Hallo world",1,0);
HAL_Delay(500);
for (int i = 0 ; i < 10 ; i++){
	char string = i + '0';
	lcdPrint(string ,0,13);
	HAL_Delay(100);
}
lcd_clear();
HAL_Delay(500);

}
