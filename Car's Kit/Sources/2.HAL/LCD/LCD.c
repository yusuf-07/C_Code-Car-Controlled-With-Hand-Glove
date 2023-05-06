/*
 * LCD.c
 *
 *  Created on: Aug 31, 2022
 *      Author: 4hmed
 */
#include "LCD.h"


/* Adding custom characters to CGRAM
	for (int i = 0; i < 8; i++)
	{
		LCD_voidCmd(LCD_CGRAM_START_ADDRESS + i);
		LCD_voidDispChar(customChar[i]);
	}
	LCD_voidSetCursor(0,0);
	LCD_voidCmd(LCD_CLEAR);
	LCD_voidDispChar(0);


u8 customChar1[] =
{

};

u8 customChar2[] =
{

};

u8 customChar3[] =

};

u8 customChar4[] =
{

};

u8 customChar5[] =
{

};

u8 customChar6[] =
{

};

u8 customChar7[] =
{

};

u8 customChar8[] =
{

};

*/

static void enablePulse(void)
{
	DIO_voidWrite(DIO_PIN3, DIO_PORTB, DIO_HIGH);
	_delay_us(1);	// 1 microsecond delay

	DIO_voidWrite(DIO_PIN3, DIO_PORTB, DIO_LOW);

	_delay_ms(2);	// 2 millisecond delay for instruction execution
}

void LCD_voidInit(void)
{
	//D4
	DIO_voidConfig(DIO_PIN4, DIO_PORTA, DIO_OUTPUT);

	//D5
	DIO_voidConfig(DIO_PIN5, DIO_PORTA, DIO_OUTPUT);

	//D6
	DIO_voidConfig(DIO_PIN6, DIO_PORTA, DIO_OUTPUT);

	//D7
	DIO_voidConfig(DIO_PIN7, DIO_PORTA, DIO_OUTPUT);

	//RS
	DIO_voidConfig(DIO_PIN1, DIO_PORTB, DIO_OUTPUT);

	//RW
	DIO_voidConfig(DIO_PIN2, DIO_PORTB, DIO_OUTPUT);

	//E
	DIO_voidConfig(DIO_PIN3, DIO_PORTB, DIO_OUTPUT);

	//Setting E to 0
	DIO_voidWrite(DIO_PIN3, DIO_PORTB, DIO_LOW);

	//Setting RW to Write mode
	DIO_voidWrite(DIO_PIN2, DIO_PORTB, DIO_LOW);

	// Initialization sequence
	_delay_ms(15);
	LCD_voidCmd(0x03);
	_delay_ms(5);
	LCD_voidCmd(0x03);
	_delay_us(100);
	LCD_voidCmd(0x03);
	LCD_voidCmd(0x02);

	LCD_voidCmd(LCD_4BIT_MODE);
	LCD_voidCmd(LCD_CLEAR);
	LCD_voidCmd(LCD_CURSOR_OFF);
}

void LCD_voidDispChar(uint8_t character)
{
	uint8_t loc_msb = (character & 0xF0);
	uint8_t loc_lsb = (character << 4);

	//Setting RS to Display mode
	DIO_voidWrite(DIO_PIN1, DIO_PORTB, DIO_HIGH);

	//Sending the MS 4 bytes
	DIO_voidWritePort(loc_msb, LCD_MASK, DIO_PORTA);

	// Sending an Enable pulse
	enablePulse();

	// Sending the LS 4 bytes
	DIO_voidWritePort(loc_lsb, LCD_MASK, DIO_PORTA);
	enablePulse();
}

void LCD_voidDispStr(uint8_t str[])
{
	for (int i = 0; i < 32; i++)
	{
		if (str[i] != '\0')
		{
			if (i == 16)
				LCD_voidSetCursor(1,0);

			LCD_voidDispChar(str[i]);
		}
		else
		{
			break;
		}
	}
}

void LCD_voidDispInt(uint32_t number)
{
	uint8_t buffer[10];
	sprintf(buffer, "%d", number);

	LCD_voidDispStr(buffer);
}

void LCD_voidDispFloat(f64 number)
{
	uint8_t buffer[15];
	dtostrf(number, 7, 2, buffer);
	LCD_voidDispStr(buffer);
}

void LCD_voidCmd(LCD_Cmd_t command)
{
	uint8_t loc_msb = (command & ~LCD_MASK);
	uint8_t loc_lsb = (command << 4);

	//Setting RS to Command mode
	DIO_voidWrite(DIO_PIN1, DIO_PORTB, DIO_LOW);

	//Sending the MS 4 bytes
	DIO_voidWritePort(loc_msb, LCD_MASK, DIO_PORTA);

	// Sending an Enable pulse and waiting for 2 milliseconds
	enablePulse();

	// Sending the LS 4 bytes
	DIO_voidWritePort(loc_lsb, LCD_MASK, DIO_PORTA);
	enablePulse();
}

void LCD_voidSetCursor(uint8_t row, uint8_t col)
{
	switch (row)
	{
	case 0:
		LCD_voidCmd(0x80 + col);
		break;

	case 1:
		LCD_voidCmd(0xC0 + col);
		break;
	}
}
