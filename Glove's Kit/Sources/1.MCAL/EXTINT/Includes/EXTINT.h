/*
 * EXTINT.h
 *
 *  Created on: 3 Sep 2022
 *      Author: yabul
 */

#ifndef SOURCES_1_MCAL_EXTINT_INCLUDES_EXTINT_H_
#define SOURCES_1_MCAL_EXTINT_INCLUDES_EXTINT_H_
#include "EXTINT_Types.h"

#define INT0_EN_BIT		(6)
#define INT1_EN_BIT		(7)
#define INT2_EN_BIT		(5)

void EXTINT_voidConfigureEXTINT(EXTINT_ID_T INTid,EXTINT_SenseCtrl_T SenseCtrl);
void EXTINT_voidDisableEXTINT(EXTINT_ID_T INTid);

#endif /* SOURCES_1_MCAL_EXTINT_INCLUDES_EXTINT_H_ */
