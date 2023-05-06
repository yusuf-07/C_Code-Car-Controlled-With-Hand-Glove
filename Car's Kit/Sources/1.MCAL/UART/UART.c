/*
 * UART.c
 *
 *  Created on: Sep 16, 2022
 *      Author: 4hmed
 */
#include "UART.h"

void UART_voidInit(uint32_t baudrate, UART_mode_t mode, UART_databits_t databits, UART_stopbits_t stopbits, UART_Parity_t parity)
{
	switch (mode)
	{
	case RX:
		enableReciever();
		disableTransmitter();
		break;

	case TX:
		enableTransmitter();
		disableReciever();
		break;

	case RTX:
		enableTransmitter();
		enableReciever();
		break;
	}

	config(databits, stopbits, parity);
	setBaudrate(baudrate);
}

void UART_voidEnableRecieveInt(void)
{
	GINT_Enable();
	SET_BIT(UCSRB_RXCIE, UCSRB_REG);
}

void UART_voidSendByte(uint8_t byte)
{
	while(!CHECK_BIT(UCSRA_UDRE, UCSRA_REG));
	UDR_REG = byte;
}

void UART_voidSendStr(uint8_t* str)
{
	uint8_t i = 0;
	while(str[i] != '\0')
	{
		UART_voidSendByte(str[i]);
		i++;
	}
}

uint8_t UART_voidRecieveByte(void)
{
	if (CHECK_BIT(UCSRA_RXC, UCSRA_REG)) return (UDR_REG);
	else return 0;
}

static void config(UART_databits_t databits, UART_stopbits_t stopbits, UART_Parity_t parity)
{
	switch (databits)
	{
	case DATABITS_5:
		if (stopbits == STOPBITS_2)
		{
			switch (parity)
			{
			case NO_PARITY:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_USBS);
				break;

			case EVEN:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1) | (1 << UCSRC_USBS);
				break;

			case ODD:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1) | (1 << UCSRC_UPM0) | (1 << UCSRC_USBS);
				break;
			}
		}
		else
		{
			switch (parity)
			{
			case NO_PARITY:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL);
				break;

			case EVEN:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1);
				break;

			case ODD:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1) | (1 << UCSRC_UPM0);
				break;
			}
		}
		break;

	case DATABITS_6:
		if (stopbits == STOPBITS_2)
		{
			switch (parity)
			{
			case NO_PARITY:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_USBS) | (1 << UCSRC_UCSZ0);
				break;

			case EVEN:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1) | (1 << UCSRC_USBS) | (1 << UCSRC_UCSZ0);
				break;

			case ODD:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1) | (1 << UCSRC_UPM0) | (1 << UCSRC_USBS) | (1 << UCSRC_UCSZ0);
				break;
			}
		}
		else
		{
			switch (parity)
			{
			case NO_PARITY:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UCSZ0);
				break;

			case EVEN:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1) | (1 << UCSRC_UCSZ0);
				break;

			case ODD:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1) | (1 << UCSRC_UPM0) | (1 << UCSRC_UCSZ0);
				break;
			}
		}
		break;

	case DATABITS_7:
		if (stopbits == STOPBITS_2)
		{
			switch (parity)
			{
			case NO_PARITY:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_USBS) | (1 << UCSRC_UCSZ1);
				break;

			case EVEN:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1) | (1 << UCSRC_USBS) | (1 << UCSRC_UCSZ1);
				break;

			case ODD:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1) | (1 << UCSRC_UPM0) | (1 << UCSRC_USBS) | (1 << UCSRC_UCSZ1);
				break;
			}
		}
		else
		{
			switch (parity)
			{
			case NO_PARITY:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UCSZ1);
				break;

			case EVEN:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1) | (1 << UCSRC_UCSZ1);
				break;

			case ODD:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1) | (1 << UCSRC_UPM0) | (1 << UCSRC_UCSZ1);
				break;
			}
		}
		break;

	case DATABITS_8:
		if (stopbits == STOPBITS_2)
		{
			switch (parity)
			{
			case NO_PARITY:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_USBS) | (1 << UCSRC_UCSZ1) | (1 << UCSRC_UCSZ0);
				break;

			case EVEN:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1) | (1 << UCSRC_USBS) | (1 << UCSRC_UCSZ1) | (1 << UCSRC_UCSZ0);
				break;

			case ODD:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1) | (1 << UCSRC_UPM0) | (1 << UCSRC_USBS) | (1 << UCSRC_UCSZ1) | (1 << UCSRC_UCSZ0);
				break;
			}
		}
		else
		{
			switch (parity)
			{
			case NO_PARITY:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UCSZ1) | (1 << UCSRC_UCSZ0);
				break;

			case EVEN:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1) | (1 << UCSRC_UCSZ1) | (1 << UCSRC_UCSZ0);
				break;

			case ODD:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1) | (1 << UCSRC_UPM0) | (1 << UCSRC_UCSZ1) | (1 << UCSRC_UCSZ0);
				break;
			}
		}
		break;

	case DATABITS_9:

		SET_BIT(UCSRB_UCSZ2, UCSRB_REG);

		if (stopbits == STOPBITS_2)
		{
			switch (parity)
			{
			case NO_PARITY:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_USBS) | (1 << UCSRC_UCSZ1) | (1 << UCSRC_UCSZ0);
				break;

			case EVEN:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1) | (1 << UCSRC_USBS) | (1 << UCSRC_UCSZ1) | (1 << UCSRC_UCSZ0);
				break;

			case ODD:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1) | (1 << UCSRC_UPM0) | (1 << UCSRC_USBS) | (1 << UCSRC_UCSZ1) | (1 << UCSRC_UCSZ0);
				break;
			}
		}
		else
		{
			switch (parity)
			{
			case NO_PARITY:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UCSZ1) | (1 << UCSRC_UCSZ0);
				break;

			case EVEN:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1) | (1 << UCSRC_UCSZ1) | (1 << UCSRC_UCSZ0);
				break;

			case ODD:
				UCSRC_REG = (UCSRC_REG & 0xF9) | (1 << UCSRC_URSEL) | (1 << UCSRC_UPM1) | (1 << UCSRC_UPM0) | (1 << UCSRC_UCSZ1) | (1 << UCSRC_UCSZ0);
				break;
			}
		}
		break;
	}
}

static void enableTransmitter(void)
{
	DIO_voidConfig(DIO_PIN1, DIO_PORTD, DIO_OUTPUT);
	SET_BIT(UCSRB_TXEN, UCSRB_REG);
}

static void disableTransmitter(void)
{
	while (!CHECK_BIT(UCSRA_TXC, UCSRA_REG));
	CLEAR_BIT(UCSRB_TXEN, UCSRB_REG);
}

static void enableReciever(void)
{
	DIO_voidConfig(DIO_PIN0, DIO_PORTD, DIO_INPUT);
	SET_BIT(UCSRB_RXEN, UCSRB_REG);
}

static void disableReciever(void)
{
	while (!CHECK_BIT(UCSRA_RXC, UCSRA_REG));
	CLEAR_BIT(UCSRB_RXEN, UCSRB_REG);
}

static void setBaudrate(uint32_t baudrate)
{
	UBRRL_REG = ((FCPU/(16 * baudrate)) - 1);
	UBRRH_REG = (((FCPU/(16 * baudrate)) - 1) >> 8);
}

