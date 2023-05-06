/*
 * Timer0.h
 *
 *  Created on: 14 Sep 2022
 *      Author: yabul
 */

#ifndef SOURCES_1_MCAL_TIMER0_INCLUDES_TIMER0_H_
#define SOURCES_1_MCAL_TIMER0_INCLUDES_TIMER0_H_
#include "Std_Types.h"
#include "Timer0_Types.h"
#include "Timer0_Reg.h"

void Timer0_voidInit(void);
void Timer0_voidSetPreload(u8 preload);
u8 Timer0_voidGetPreload(void);
void Timer0_voidSetOCR(u8 OCR_Value);

void Timer0_voidTimerStart(Timer0_PRESCALER_T prescaler);
void Timer0_voidTimerStop(void);

void Timer0_voidEnableOVERFLOWInterrupt(void);
void Timer0_voidDisableOVERFLOWInterrupt(void);

void Timer0_voidEnableCTCInterrupt(void);
void Timer0_voidDisableCTCInterrupt(void);

#endif /* SOURCES_1_MCAL_TIMER0_INCLUDES_TIMER0_H_ */
