/*
 * LCD.c
 *
 *  Created on: 31 Aug 2022
 *      Author: yabul
 */
#include "LCD.h"
#include "Std_Types.h"
#include "DIO.h"
#define LCDMASK (0b00001111)
#include <util/delay.h>
#include <stdio.h>




void LCD_voidInit(void)
{
	//Initialise COntrol Lines
	DIO_voidconfigureChannel(DIO_PORTB,DIO_PIN1,DIO_OUTPUT);
	DIO_voidconfigureChannel(DIO_PORTB,DIO_PIN2,DIO_OUTPUT);
	DIO_voidconfigureChannel(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
	//Initialise Data Lines
	DIO_voidconfigureChannel(DIO_PORTA,DIO_PIN4,DIO_OUTPUT);
	DIO_voidconfigureChannel(DIO_PORTA,DIO_PIN5,DIO_OUTPUT);
	DIO_voidconfigureChannel(DIO_PORTA,DIO_PIN6,DIO_OUTPUT);
	DIO_voidconfigureChannel(DIO_PORTA,DIO_PIN7,DIO_OUTPUT);
	//RW = 0
	DIO_voidWRITEChannel(DIO_PORTB,DIO_PIN2,DIO_LOW);

	//initialisation steps on data sheet
	_delay_ms(15);
	LCD_voidCMD(0x30);
	_delay_ms(5);
	LCD_voidCMD(0x30);
	_delay_us(100);
	LCD_voidCMD(0x03);
	LCD_voidCMD(0x02);
	LCD_voidCMD(_LCD_4BIT_MODE);

}
static void Pulse(void)
{
	//send Enable pulse
	DIO_voidWRITEChannel(DIO_PORTB,DIO_PIN3,DIO_HIGH);
	_delay_us(1);
	DIO_voidWRITEChannel(DIO_PORTB,DIO_PIN3,DIO_LOW);

}
void LCD_voidDisplayChar(u8 chr)
{
	//RS -> 1
	DIO_voidWRITEChannel(DIO_PORTB,DIO_PIN1,DIO_HIGH);
	//write data [data lines] to LCD, we will send twice because we work on 4 bits

	//MSB (Most significiant bits)	LSB
	// 0b0000						0000
	// chr = 0b1101 1001
	// we split chr into 1101 0000 which goes to MSB
	// and 1001 0000 which goes to LSB
	// the first 4 zeros because we only work on the last 4 pins
	u8 loc_MSB = chr & ~LCDMASK;
	u8 loc_LSB = (chr<<4);

	//write MSB data to LCD
	DIO_voidWRITEChannelGroup(DIO_PORTA,loc_MSB,LCDMASK);
	//send Enable pulse
	Pulse();
	_delay_ms(2);

	//write LSB data to LCD
	DIO_voidWRITEChannelGroup(DIO_PORTA,loc_LSB,LCDMASK);
	//send Enable pulse
	Pulse();
	_delay_ms(2);
}
void LCD_voidCMD(LCD_CMD_Type cmd)
{
	u8 loc_MSB = cmd & ~LCDMASK;
	u8 loc_LSB = (cmd<<4);
	//RS -> 0
	DIO_voidWRITEChannel(DIO_PORTB,DIO_PIN1,DIO_LOW);


	//write MSB data to LCD
	DIO_voidWRITEChannelGroup(DIO_PORTA,loc_MSB,LCDMASK);
	//send Enable pulse
	Pulse();
	_delay_ms(2);

	//write LSB data to LCD
	DIO_voidWRITEChannelGroup(DIO_PORTA,loc_LSB,LCDMASK);
	//send Enable pulse
	Pulse();
	_delay_ms(2);
}
void LCD_voidMatrix(u8 row, u8 col)
{
	switch (row)
	{
	case 0:
		LCD_voidCMD(0x80 + col);
		break;
	case 1:
		LCD_voidCMD(0xC0 + col);
		break;
	}

}

void LCD_voidDisplayStr(u8 str[])
{
//	LCD_voidCMD(_LCD_CLEAR);
//	while (str[i] != '\0')
//	{
//		LCD_voidDisplayChar(str[i]);
//		i++;
//	}
	for (int i=0; i<32;i++)
	{
		if (str[i] != '\0')
		{
			if (i==15)
			{
				LCD_voidMatrix(1,0);
			}
			LCD_voidDisplayChar(str[i]);
		}
		else
		{
			break;
		}
	}
}
void LCD_voidDIsplayInteger(u32 num)
{
	u8 buffer[5];
	sprintf(buffer,"%d",num);
	LCD_voidDisplayStr(buffer);
}
void LCD_voidCustomChar1(void)
{
	u8 cntr=0;
	u8 customChar[] =
	{
			0b00000,
			0b00000,
			0b01010,
			0b10101,
			0b10001,
			0b01010,
			0b00100,
			0b00000
	};
	for (cntr=0;cntr<8;cntr++)
	{
		LCD_voidCMD(0x40+cntr);
		LCD_voidDisplayChar(customChar[cntr]);
	}
	LCD_voidCMD(0x8E); //Equivalent to LCD_voidMatrix(0,0);
	LCD_voidDisplayChar(0); //Placement
}
void LCD_voidDisplayFloat(f64 num)
{
	u8 buffer[10];
	sprintf(buffer,"%1.2f",num);
	LCD_voidDisplayStr(buffer);
}


