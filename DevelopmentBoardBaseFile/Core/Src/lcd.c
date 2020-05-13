/*
 * lcd.c
 *
 *  Created on: 11 mei 2020
 *      Author: Job Heijlighen
 */

#include "lcd.h"


extern I2C_HandleTypeDef hi2c1;

#define SLAVE_ADDRESS_LCD 0x4E

int intToAscii(int number);
char data_string;
bool lcdScrollStatus;
bool lcdCursorStatus;

void lcd_send_cmd (char cmd)
{
  char data_u, data_l;
	uint8_t data_t[4];
	data_u = (cmd&0xf0);
	data_l = ((cmd<<4)&0xf0);
	data_t[0] = data_u|0x0C;  //en=1, rs=0
	data_t[1] = data_u|0x08;  //en=0, rs=0
	data_t[2] = data_l|0x0C;  //en=1, rs=0
	data_t[3] = data_l|0x08;  //en=0, rs=0
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_send_data (char data)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (data&0xf0);
	data_l = ((data<<4)&0xf0);
	data_t[0] = data_u|0x0D;  //en=1, rs=0
	data_t[1] = data_u|0x09;  //en=0, rs=0
	data_t[2] = data_l|0x0D;  //en=1, rs=0
	data_t[3] = data_l|0x09;  //en=0, rs=0
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_clear (void)
{
	lcd_send_cmd (0x80);
	for (int i=0; i<70; i++)
	{
		lcd_send_data (' ');
	}
}

void lcd_put_cur(int row, int col)
{
    switch (row)
    {
        case 0:
            col |= 0x80;
            break;
        case 1:
            col |= 0xC0;
            break;
    }

    lcd_send_cmd (col);
}


void lcd_init (void)
{
	// 4 bit initialisation
	HAL_Delay(50);
	lcd_send_cmd (0x30);
	HAL_Delay(5);
	lcd_send_cmd (0x30);
	HAL_Delay(1);
	lcd_send_cmd (0x30);
	HAL_Delay(10);
	lcd_send_cmd (0x20);
	HAL_Delay(10);

	// dislay initialisation
	lcd_send_cmd (0x28); // Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
	HAL_Delay(1);
	lcd_send_cmd (0x08); //Display on/off control --> D=0,C=0, B=0  ---> display off
	HAL_Delay(1);
	lcd_send_cmd (0x01);  // clear display
	HAL_Delay(1);
	HAL_Delay(1);
	lcd_send_cmd (0x06); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
	HAL_Delay(1);
	lcd_send_cmd (0x0C); //Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)

	lcdScrollStatus = false;
	lcdCursorStatus = false;
}

void lcd_send_string (char *str)
{
	while (*str) lcd_send_data (*str++);
}

void lcdPrint(char *data, int row, int column)
{
	lcd_put_cur(row, column);
	lcd_send_string((char *)data);
}

void lcdPrintInt(int data, int row, int column)
{

	data_string = intToAscii(data);

	lcdPrint(&data_string,0,13);

}

bool lcdCursor(bool status)
{
	if (status && !lcdCursorStatus)
	{
		lcd_send_cmd (0x0F);
		lcdCursorStatus = true;
		return true;
	}
	else if (!status && lcdCursorStatus)
	{
		lcd_send_cmd (0x0C);
		lcdCursorStatus = false;
		return true;
	}
	else {
		return false;
	}
}

bool lcdScroll (bool status)
{
	if (status && !lcdScrollStatus)
	{

		lcd_send_cmd (0x07);
		lcdScrollStatus = true;
		return true;
	}

	else if (!status && lcdScrollStatus)
	{
		lcd_send_cmd (0x04);
		lcd_send_cmd (0x02);
		lcdScrollStatus = false;
		return true;
	}

	else
	{
		return false;
	}

}

void lcd_Demo(){

	// Example how to display a text to LCD:
	lcdCursor(true);
	lcdPrint("Hallo world",0,0);
	HAL_Delay(500);
	lcdPrint("Hallo world",1,5);
	HAL_Delay(5000);
	lcdCursor(false);
	HAL_Delay(10);
	lcdScroll(true);
	HAL_Delay(100);

	// Example how to display a int in the LCD:
	for (int i = 0 ; i < 10 ; i++){
		lcdPrintInt(i,0,13);
		HAL_Delay(100);
	}

	// Turn scrolling off
	lcdScroll(false);
	HAL_Delay(500);

}


int intToAscii(int number) {

   return '0' + number;
}
