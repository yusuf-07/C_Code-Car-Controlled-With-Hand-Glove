/*
 * LCD.h
 *
 *  Created on: Aug 31, 2022
 *      Author: 4hmed
 */

#ifndef SOURCES_2_HAL_LCD_INCLUDES_LCD_H_
#define SOURCES_2_HAL_LCD_INCLUDES_LCD_H_

#include "StandardTypes.h"
#include "DIO.h"
#include <util/delay.h>
#include <stdio.h>
#include "stdlib.h"

#define LCD_MASK	(0x0F)

typedef enum
{
	LCD_ON = 0x0F,
	LCD_CLEAR = 0x01,
	LCD_4BIT_MODE = 0x28,
	LCD_8BIT_MODE = 0x38,
	LCD_CURSOR_ON = 0x0F,
	LCD_CURSOR_OFF = 0x0C,
	LCD_CURSOR_INCREMENT = 0x06,
	LCD_CURSOR_UNDERLINE = 0x0E,
	LCD_CURSOR_SHIFT_LEFT = 0x10,
	LCD_CURSOR_SHIFT_RIGHT = 0x14,
	LCD_CGRAM_START_ADDRESS = 0x40

} LCD_Cmd_t;

void LCD_voidInit(void);
void LCD_voidDispChar(uint8_t);
void LCD_voidDispStr(uint8_t*);
void LCD_voidDispInt(uint32_t);
void LCD_voidDispFloat(f64);
void LCD_voidCmd(LCD_Cmd_t);
void LCD_voidSetCursor(uint8_t , uint8_t);

#endif /* SOURCES_2_HAL_LCD_INCLUDES_LCD_H_ */
