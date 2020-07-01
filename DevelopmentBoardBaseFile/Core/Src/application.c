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

		if (Counter <=4){
			MainCase = Switch_Off;
			Counter ++;
		}
		else {
			MainCase = Drive_On;
		}
		}
		break;

	case Switch_Off:

	//Reset Servo angle so pusher goes back
	MainCase = Drive_On;
		break;

	case Drive_On:

	//DC-engine are activate for a few seconds (in combination with Ultrasonic-sensor)
	MainCase = Drive_Off;
		break;

	case Drive_Off:

	//Box will stop when time is up or Ultrasonic-sensor see a object.
		break;

	case Lift_Up:

		//Liftsystem up with DC-engine till reed-sensor switched.
		//LED-light blink till switched.
		//LCD show funny text (Useless).
		MainCase = Lift_Down;
		break;

	case Lift_Down:

		//Liftsystem down with DC-engine till reed-sensor switched back.
		//Back to origin.
		MainCase = Switch_On;
		break;

	}

}
