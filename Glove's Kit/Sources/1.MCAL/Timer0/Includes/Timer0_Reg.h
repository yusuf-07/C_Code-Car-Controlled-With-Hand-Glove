/*
 * Timer0_Reg.h
 *
 *  Created on: 17 Sep 2022
 *      Author: yabul
 */

#ifndef SOURCES_1_MCAL_TIMER0_INCLUDES_TIMER0_REG_H_
#define SOURCES_1_MCAL_TIMER0_INCLUDES_TIMER0_REG_H_

#define TIMER_TCCR0_REG	(*(u8*)0x53)		//TIMER CONTROL REGISTER BIT 6,3 =0 //BIT 0:2 = 1 0 1
#define TIMER_TCNT0_REG	(*(u8*)0x52)		//TIMER COUNTER REGISTER
#define TIMER_OCR0_REG	(*(u8*)0x5C)		//Compare match with TCNT0
#define TIMER_TIMSK_REG	(*(u8*)0x59)		//BIT 1 INTERRUPT MATCH //BIT 0 OVERFLOW INTERRUPT IS ENAABLED
#define TIMER_PRESCALAR_MASK (0xF8)
#define TIMER_PRESCALAR_VALUE (0x04)

#endif /* SOURCES_1_MCAL_TIMER0_INCLUDES_TIMER0_REG_H_ */