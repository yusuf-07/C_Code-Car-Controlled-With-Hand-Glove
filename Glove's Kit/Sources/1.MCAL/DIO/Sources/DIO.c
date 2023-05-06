/*
 * DIO.c
 *
 *  Created on: 26 Aug 2022
 *      Author: yabul
 */
#include "Bit_Math.h"
#include "DIO.h"
#include "DIO_REG.h"
#include "Std_Types.h"

#include "LED.h"
#include "Button.h"
#include "BUZZER.h"
#include "SSD.h"
#include "LCD.h"
#include "ADC.h"

void DIO_voidconfigureChannel(DIO_PORT_T port,DIO_PIN_T pin,DIO_DIR_T dir)
{
	switch(port)
	{
	case DIO_PORTA:
		if (dir == DIO_INPUT)
		{
			CLEAR_BIT(DIO_DDRA_REG,pin);
		}
		else
		{
			SET_BIT(DIO_DDRA_REG,pin);

		}
		break;

	case DIO_PORTB:
		if (dir == DIO_INPUT)
		{
			CLEAR_BIT(DIO_DDRB_REG,pin);
		}
		else
		{
			SET_BIT(DIO_DDRB_REG,pin);

		}
		break;

	case DIO_PORTC:
		if (dir == DIO_INPUT)
		{
			CLEAR_BIT(DIO_DDRC_REG,pin);
		}
		else
		{
			SET_BIT(DIO_DDRC_REG,pin);
		}
		break;


	case DIO_PORTD:
		if (dir == DIO_INPUT)
		{
			CLEAR_BIT(DIO_DDRD_REG,pin);
		}
		else
		{
			SET_BIT(DIO_DDRD_REG,pin);
		}
		break;
	}


}
void DIO_voidWRITEChannel(DIO_PORT_T port,DIO_PIN_T pin,DIO_LEVEL_T level)
{
	switch (port)
	{
	case DIO_PORTA:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_PORTA_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_PORTA_REG,pin);
		}
		break;
	case DIO_PORTB:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_PORTB_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_PORTB_REG,pin);
		}
		break;
	case DIO_PORTC:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_PORTC_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_PORTC_REG,pin);
		}
		break;
	case DIO_PORTD:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_PORTD_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_PORTD_REG,pin);
		}
		break;
	}
}
DIO_LEVEL_T DIO_voidREADChannel(DIO_PORT_T port,DIO_PIN_T pin)
{
	DIO_LEVEL_T localstatus;
	switch(port)
	{
	case DIO_PORTA:
		localstatus = CHECK_BIT(DIO_PINA_REG, pin);
		break;
	case DIO_PORTB:

		localstatus= CHECK_BIT(DIO_PINB_REG, pin);
		break;
	case DIO_PORTC:

		localstatus = CHECK_BIT(DIO_PINC_REG, pin);

		break;
	case DIO_PORTD:

		localstatus = CHECK_BIT(DIO_PIND_REG, pin);
		break;
	}
	return localstatus;
}
void DIO_voidWRITEChannelGroup(DIO_PORT_T port,u8 data, u8 mask)
{
	switch (port)
	{
	case DIO_PORTA:
		DIO_PORTA_REG = (DIO_PORTA_REG & mask)|(data); //0000 0101 -> 0101 0000
		break;
		// we must shift 5, 4 places or we will write 0000 0101 on the 8 pins
		// after shift 5 will be 0101 and will be written on the first 4 pins
		// 0101 0000
	case DIO_PORTB:
		DIO_PORTB_REG = (DIO_PORTB_REG & mask)|(data);
		break;
	case DIO_PORTC:
		DIO_PORTC_REG = (DIO_PORTC_REG & mask)|(data);
		break;
	case DIO_PORTD:
		DIO_PORTD_REG = (DIO_PORTD_REG & mask)|(data);
		break;
	}

}
void DIO_voidPULLUpEnable(DIO_PORT_T port,DIO_PIN_T pin)
{
	switch (port)
	{
	case DIO_PORTA:
		SET_BIT(DIO_PORTA_REG,pin);
		break;
	case DIO_PORTB:
		SET_BIT(DIO_PORTB_REG,pin);
		break;
	case DIO_PORTC:
		SET_BIT(DIO_PORTC_REG,pin);
		break;
	case DIO_PORTD:
		SET_BIT(DIO_PORTD_REG,pin);
		break;
	}
}
void DIO_voidFlipChannel(DIO_PORT_T port,DIO_PIN_T pin)
{
	switch (port)
	{
	case DIO_PORTA:
		FLIP_BIT(DIO_PORTA_REG,pin);
		break;
	case DIO_PORTB:
		FLIP_BIT(DIO_PORTB_REG,pin);
		break;
	case DIO_PORTC:
		FLIP_BIT(DIO_PORTC_REG,pin);
		break;
	case DIO_PORTD:
		FLIP_BIT(DIO_PORTD_REG,pin);
		break;
	}
}
void WakeUp_Call(void)
{
	LED_voidInit();
	BUTTONS_voidInit();
	Buzzer_voidInit();
	SSD_voidInit();
	LCD_voidInit();
	ADC_voidInit(ADC_AVCC);
}
