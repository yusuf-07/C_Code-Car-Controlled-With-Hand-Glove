/*
 * LCD.h
 *
 *  Created on: 31 Aug 2022
 *      Author: yabul
 */









#ifndef SOURCES_2_ECUAL_LCD_INCLUDE_LCD_H_
#define SOURCES_2_ECUAL_LCD_INCLUDE_LCD_H_
#include "Std_Types.h"
#include "LCD_Types.h"

void LCD_voidInit(void);
void LCD_voidDisplayChar(u8 chr);
void LCD_voidCMD(LCD_CMD_Type cmd);
void LCD_voidMatrix(u8 row, u8 col);
void LCD_voidDisplayStr(u8 str[]);
void LCD_voidDIsplayInteger(u32 num);
void LCD_voidDisplayFloat(f64 num);
void LCD_voidCustomChar1(void);


#endif /* SOURCES_2_ECUAL_LCD_INCLUDE_LCD_H_ */
