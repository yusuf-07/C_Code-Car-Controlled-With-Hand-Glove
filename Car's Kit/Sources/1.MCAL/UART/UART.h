/*
 * UART.h
 *
 *  Created on: Sep 16, 2022
 *      Author: 4hmed
 */

#ifndef SOURCES_2_HAL_INCLUDES_UART_H_
#define SOURCES_2_HAL_INCLUDES_UART_H_

#include <string.h>

#include "StandardTypes.h"
#include "BitMasking.h"
#include "DIO.h"
#include "GINT.h"

#define FCPU			16000000

#define UBRRH_REG		(*(volatile uint8_t*)0x40)
#define UBRRL_REG		(*(volatile uint8_t*)0x29)

#define UCSRA_REG		(*(volatile uint8_t*)0x2B)
#define UCSRB_REG		(*(volatile uint8_t*)0x2A)
#define UCSRC_REG		(*(volatile uint8_t*)0x40)

#define UDR_REG			(*(volatile uint8_t*)0x2C)

#define UCSRA_RXC			7
#define UCSRA_TXC			6
#define UCSRA_UDRE			5
#define UCSRA_FE			4
#define UCSRA_DOR			3
#define UCSRA_PE			2
#define UCSRA_U2X			1
#define UCSRA_MPCM			0

#define UCSRB_RXCIE			7
#define UCSRB_TXCIE			6
#define UCSRB_UDRIE			5
#define UCSRB_RXEN			4
#define UCSRB_TXEN			3
#define UCSRB_UCSZ2			2

#define UCSRC_URSEL			7
#define UCSRC_UMSEL			6
#define UCSRC_UPM1			5
#define UCSRC_UPM0			4
#define UCSRC_USBS			3
#define UCSRC_UCSZ1			2
#define UCSRC_UCSZ0			1
#define UCSRC_UCPOL			0

typedef enum
{
	NO_PARITY,
	EVEN =2,
	ODD

} UART_Parity_t;

typedef enum
{
	DATABITS_5,
	DATABITS_6,
	DATABITS_7,
	DATABITS_8,
	DATABITS_9

} UART_databits_t;

typedef enum
{
	STOPBITS_1,
	STOPBITS_2

} UART_stopbits_t;

typedef enum
{
	RX,
	TX,
	RTX

} UART_mode_t;

void UART_voidInit(uint32_t, UART_mode_t, UART_databits_t, UART_stopbits_t, UART_Parity_t);
void UART_voidEnableRecieveInt(void);
void UART_voidSendByte(uint8_t);
uint8_t UART_voidRecieveByte(void);
void UART_voidSendStr(uint8_t*);
uint8_t* UART_p8RecieveStr(void);

static void enableTransmitter(void);
static void disableTransmitter(void);
static void enableReciever(void);
static void disableReciever(void);
static void setBaudrate(uint32_t);
static void config(UART_databits_t, UART_stopbits_t, UART_Parity_t);

#endif /* SOURCES_2_HAL_INCLUDES_UART_H_ */
