/*
 * lcd.h
 *
 *  Created on: 11 mei 2020
 *      Author: Job Heijlighen
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#include "stm32f1xx_hal.h"

void lcd_init (void);   // initialize lcd

void lcd_send_cmd (char cmd);  // send command to the lcd

void lcd_send_data (char data);  // send data to the lcd

void lcd_send_string (char *str);  // send string to the lcd

void lcd_put_cur(int row, int col);  // put cursor at the entered position row (0 or 1), col (0-15);

void lcd_clear (void);

void lcdPrint(char *data, int row, int column);

#endif /* INC_LCD_H_ */
