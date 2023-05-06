/*
 * TIMER.h
 *
 *  Created on: Oct 1, 2022
 *      Author: 4hmed
 */

#ifndef SOURCES_1_MCAL_TIMER_TIMER_H_
#define SOURCES_1_MCAL_TIMER_TIMER_H_

#include "StandardTypes.h"
#include "BitMasking.h"
#include "GINT.h"
#include "DIO.h"

/********** TIMER0 Modes **********/
#define NORMAL				0
#define CTC					1

/********** PWM Modes ************/
#define FAST_PWM0			0
#define PHASE_CORRECT_PWM0	1

/********** PWM COM Modes ********/
#define NON_INVERTED		0
#define INVERTED			1

extern uint32_t TIMER_nOVF;
extern uint32_t TIMER_nCompMatch;
extern uint32_t TIMER_intialPreload;

typedef enum
{
	TIMER0,
	TIMER1,
	TIMER2

} TIMER_Channel_t;

void TIMER_Init(TIMER_Channel_t);
void TIMER_SetTime(TIMER_Channel_t, uint32_t);
void TIMER_Start(TIMER_Channel_t);
void TIMER_Stop(TIMER_Channel_t);
void TIMER_SetCallBack(TIMER_Channel_t, void (*)(void));
static void TIMER_SetTCNT(TIMER_Channel_t, uint16__t);
static void TIMER_SetOCR(TIMER_Channel_t, uint16__t);

void TIMER_PWM_Init(TIMER_Channel_t);
void TIMER_PWM_Start(TIMER_Channel_t);
void TIMER_PWM_Stop(TIMER_Channel_t);
void TIMER_PWM1_SetFrequency(uint32_t);
void TIMER_PWM_SetDutyCycle(TIMER_Channel_t, uint8_t);

#endif /* SOURCES_1_MCAL_TIMER_TIMER_H_ */
