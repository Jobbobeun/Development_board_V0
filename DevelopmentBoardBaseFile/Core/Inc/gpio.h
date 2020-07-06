/**
  ******************************************************************************
  * File Name          : gpio.h
  * Description        : This file contains all the functions prototypes for 
  *                      the gpio  
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __gpio_H
#define __gpio_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include "stdbool.h"
/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

// uint8_t receiveddata[2]; //1 Byte to store received data
 uint8_t receiveddata2[1];



 enum Output_numbers {
	 EMPTY_Output,
	 OUT_1,
	 OUT_2,
	 OUT_3,
	 OUT_4,
	 OUT_5,	// GPIO STM32
	 OUT_6, // GPIO STM32
	 OUT_7, // GPIO STM32
	 OUT_8, // GPIO STM32
	 OUT_9,	// IO expander P0
	 OUT_10, // IO expander P1
	 OUT_11, // IO expander P2
	 OUT_12, // IO expander P3
	 PROG_LED,
	 MD_A1,	// IO expander P7
	 MD_A2, // IO expander P6
	 MD_A3, // IO expander P5
	 MD_A4  // IO expander p4
 };

 enum Input_numbers{
	 EMPTY_Input,
	 IN_1,
	 IN_2,
	 IN_3,
	 IN_4,
	 IN_5,
	 IN_6,
	 IN_7,
	 IN_8,
	 IN_9
 };

 enum IOE_pins{
	 p0 = 0x00,
	 p1 = 0x01,
	 p2 = 0x02,
	 p3 = 0x03,
	 p4 = 0x04,
	 p5 = 0x05,
	 p6 = 0x06,
	 p7 = 0x07
 };

 typedef union IOE_u //bit image
 {
   uint8_t All;
   struct IOE_b
   {
     bool P0 : 1;
     bool P1 : 1;
     bool P2 : 1;
     bool P3 : 1;
     bool P4 : 1;
     bool P5 : 1;
     bool P6 : 1;
     bool P7 : 1;
   } __attribute__((packed)) Flag;
 } __attribute__((packed)) IOE_t;

#define IOE1_address 0x40
#define IOE2_address 0x4F

 IOE_t GPIO_bitmask;
 IOE_t GPIO_bitmask_actual;
 IOE_t newdata;

/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */

bool IoWrite(uint8_t Output_pin, bool Output_State);
bool IoRead(uint8_t Input_pin);
bool IoToggle(uint8_t Toggle_pin);
bool OutStatus(uint8_t Output_pin);
void GPIO_init(void);
void GPIO_test(void);
void PCF8574_Demo_Write(void);
void PCF8574_Demo_Receive(void);
void PCF_Init(void);
void IOE_Write(uint8_t pin, bool state, uint8_t IOE_address);
uint8_t IOE_Read(void);
uint8_t IOE2_Read(void);



/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
