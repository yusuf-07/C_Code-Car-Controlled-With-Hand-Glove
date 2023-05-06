/*
 * EXTINT.c
 *
 *  Created on: 3 Sep 2022
 *      Author: yabul
 */
#include "EXTINT.h"
#include "Bit_Math.h"
#include "Std_Types.h"
#include "EXTINT_Reg.h"
#include "EXTINT.h"

void EXTINT_voidConfigureEXTINT(EXTINT_ID_T INTid,EXTINT_SenseCtrl_T SenseCtrl)
{
	switch(INTid)
	{


	case EXT_INT0:
		//Configure sense control
		if (SenseCtrl == EXT_RiseEdge)
		{
			SET_BIT(MCUCR_REG,0);
			SET_BIT(MCUCR_REG,1);

		}
		else if (SenseCtrl == EXT_FallEdge)
		{
			CLEAR_BIT(MCUCR_REG,0);
			SET_BIT(MCUCR_REG,1);
		}
		else if (SenseCtrl == EXT_BothEdge)
		{
			SET_BIT(MCUCR_REG,0);
			CLEAR_BIT(MCUCR_REG,1);
		}
		else if (SenseCtrl == EXT_LowLevel)
		{
			CLEAR_BIT(MCUCR_REG,0);
			CLEAR_BIT(MCUCR_REG,1);
		}
		else
		{
			// DO NOTHING
		}
		//Enable INT0 Interrupt
		SET_BIT(GICR_REG,INT0_EN_BIT); //Magic Number
		break;

	case EXT_INT1:
		//Configure sense control
		if (SenseCtrl == EXT_RiseEdge)
		{
			SET_BIT(MCUCR_REG,2);
			SET_BIT(MCUCR_REG,3);

		}
		else if (SenseCtrl == EXT_FallEdge)
		{
			CLEAR_BIT(MCUCR_REG,2);
			SET_BIT(MCUCR_REG,3);
		}
		else if (SenseCtrl == EXT_BothEdge)
		{
			SET_BIT(MCUCR_REG,2);
			CLEAR_BIT(MCUCR_REG,3);
		}
		else if (SenseCtrl == EXT_LowLevel)
		{
			CLEAR_BIT(MCUCR_REG,2);
			CLEAR_BIT(MCUCR_REG,3);
		}
		else
		{
			// DO NOTHING
		}
		SET_BIT(GICR_REG,INT1_EN_BIT); //Magic Number
		break;

	case EXT_INT2:
		if (SenseCtrl == EXT_FallEdge)
		{
			CLEAR_BIT(MCUCSR_REG,6);

		}
		else if (SenseCtrl == EXT_RiseEdge)
		{
			SET_BIT(MCUCSR_REG,6);

		}
		else
		{
			// DO NOTHING
		}
		SET_BIT(GICR_REG,INT2_EN_BIT); //Magic Number
		break;


	}

}
void EXTINT_voidDisableEXTINT(EXTINT_ID_T INTid)
{
	switch (INTid)
	{
	case EXT_INT0:
		CLEAR_BIT(GICR_REG,INT0_EN_BIT);
		break;
	case EXT_INT1:
		CLEAR_BIT(GICR_REG,INT1_EN_BIT);
		break;
	case EXT_INT2:
		CLEAR_BIT(GICR_REG,INT2_EN_BIT);
		break;
	}
}

