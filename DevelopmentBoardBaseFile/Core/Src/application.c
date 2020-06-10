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
#include "i2c.h"

int var;
uint8_t errortest[2] = {0,0};
HAL_StatusTypeDef ret;
//uint8_t receiveddata2[1] = {0xE0}; //1 Byte to store received data

void application(void){

HAL_Delay(2000);
PCF8574_Demo_Write();

	//PCF8574_Demo_Receive();
/*
if (errortest[0] == 0)
{
	HAL_Delay(2000);
	   ret = HAL_I2C_Master_Receive(&hi2c1, 0x41, (uint8_t*) receiveddata2, 1, 100);
		    if ( ret != HAL_OK ) {
		      errortest[0] = 1;
		    } else {
		    	errortest[1] = 2;
		    }
}
	//var = HAL_GPIO_ReadPin(GPIOB, IN_3_Pin);

*/

}

