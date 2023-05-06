/*
 * Timer0.c
 *
 *  Created on: 14 Sep 2022
 *      Author: yabul
 */
#include <Timer0_Modes.h>
#include "Timer0.h"
#include "Timer0_ConfigurationMode.h"
#include <util/delay.h>
#include "Bit_Math.h"
#include "Std_Types.h"
#include "GINT.h"

void Timer0_voidInit(void)
{
	//select operation mode
	//select compare output mode

#if (Operation_Mode==Normal_Mode)

	CLEAR_BIT(TIMER_TCCR0_REG,3);
	CLEAR_BIT(TIMER_TCCR0_REG,6);

#elif (Operation_Mode==PhaseCorrect_Mode)

	CLEAR_BIT(TIMER_TCCR0_REG,3);
	SET_BIT(TIMER_TCCR0_REG,6);

	#if (CompareMatch_Mode==NonInverted_Mode)

	SET_BIT(TIMER_TCCR0_REG,5);
	CLEAR_BIT(TIMER_TCCR0_REG,4);

	#elif (CompareMatch_Mode==Inverted_Mode)

	SET_BIT(TIMER_TCCR0_REG,5);
	SET_BIT(TIMER_TCCR0_REG,4);

	#endif

#elif (Operation_Mode==CTC_Mode)

	SET_BIT(TIMER_TCCR0_REG,3);
	CLEAR_BIT(TIMER_TCCR0_REG,6);

#elif (Operation_Mode==FastPWM_Mode)

	SET_BIT(TIMER_TCCR0_REG,3);
	SET_BIT(TIMER_TCCR0_REG,6);

	#if (CompareMatch_Mode==NonInverted_Mode)

	SET_BIT(TIMER_TCCR0_REG,5);
	CLEAR_BIT(TIMER_TCCR0_REG,4);

	#elif (CompareMatch_Mode==Inverted_Mode)

	SET_BIT(TIMER_TCCR0_REG,5);
	SET_BIT(TIMER_TCCR0_REG,4);

	#endif
#else
#error "You shall define Timer Operation Mode in Timer0_ConfigurationMode.h"

#endif

}
#if (Operation_Mode==Normal_Mode)

void Timer0_voidSetPreload(u8 preload)
{
	//TCNT0 = Preload
	TIMER_TCNT0_REG = preload;
}
u8 Timer0_voidGetPreload(void)
{
	return(TIMER_TCNT0_REG);
}

void Timer0_voidEnableOVERFLOWInterrupt(void)
{
	//enable all interrupts
	GINT_voidEnableAllInterrupts();

	//enable the overflow interrupt
	SET_BIT(TIMER_TIMSK_REG,0);
}
void Timer0_voidDisableOVERFLOWInterrupt(void)
{
	CLEAR_BIT(TIMER_TIMSK_REG,0);
}

#endif

#if (Operation_Mode==Normal_Mode)||(Operation_Mode==CTC_Mode)

void Timer0_voidTimerStart(Timer0_PRESCALER_T prescaler)
{
	TIMER_TCCR0_REG = (TIMER_TCCR0_REG & TIMER_PRESCALAR_MASK) |prescaler;
}
void Timer0_voidTimerStop(void)
{
	TIMER_TCCR0_REG = (TIMER_TCCR0_REG & TIMER_PRESCALAR_MASK);
}

#endif

#if (Operation_Mode==CTC_Mode)

void Timer0_voidEnableCTCInterrupt(void)
{
	//enable all interrupts
	GINT_voidEnableAllInterrupts();

	//enable the compare match interrupt
	SET_BIT(TIMER_TIMSK_REG,1);
}
void Timer0_voidDisableCTCInterrupt(void)
{
	CLEAR_BIT(TIMER_TIMSK_REG,1);
}
void Timer0_voidSetOCR(u8 OCR_Value)
{
	TIMER_OCR0_REG=OCR_Value;
}
#endif

