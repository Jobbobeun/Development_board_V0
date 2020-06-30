/*
 * application.c
 *
 *  Created on: Apr 21, 2020
 *      Author: Job Heijlighen
 */


#include "application.h"
#include "adc.h"
#include "gpio.h"
#include "pwm.h"
#include "lcd.h"
#include "serialCom.h"


void application(void){

	switch(MainCase){

	case Switch_On:

		if (IoRead(IN_1) == true){
//Switch on
//Set Servo installed angle

			MainCase = Switch_Off;
			Counter ++;
		}

		break;

	case Switch_Off:

	//Reset servo angle so pusher goes back


		break;

	case Drive_On:

		break;

	case Drive_Off:

		break;

	case LCD_On:

		break;

	case LCD_Off:

		break;
	case Lift_Up:

		break;

	case Lift_Down:

		break;

	}

}

