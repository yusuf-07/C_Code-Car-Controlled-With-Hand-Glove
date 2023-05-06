/*
 * GINT.c
 *
 *  Created on: 3 Sep 2022
 *      Author: yabul
 */
#include "GINT.h"
#include "Bit_Math.h"
#include "GINT_Reg.h"

void GINT_voidEnableAllInterrupts(void)
{
	SET_BIT(GINT_SREG_REG,7);
}
void GINT_voidDisableAllInterrupts(void)
{
	CLEAR_BIT(GINT_SREG_REG,7);
}
//enable int0 PD2
//int1 PD3
//int2 PB2
//rising edge



