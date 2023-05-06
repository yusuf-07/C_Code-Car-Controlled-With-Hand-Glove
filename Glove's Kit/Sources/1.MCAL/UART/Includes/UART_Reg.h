/*
 * UART_Reg.h
 *
 *  Created on: 16 Sep 2022
 *      Author: yabul
 */

#ifndef SOURCES_1_MCAL_UART_INCLUDES_UART_REG_H_
#define SOURCES_1_MCAL_UART_INCLUDES_UART_REG_H_
#include "Std_Types.h"
#include "Bit_Math.h"

#define UART_UDR_Reg			(*(volatile u8*)0x2C)
#define UART_UBRRH_Reg 			(*(volatile u8*)0x40)
#define UART_UBRRL_Reg			(*(volatile u8*)0x29)


#define UART_UCSRA_Reg			(*(volatile u8*)0x2B)
#define UART_RXC_BIT			(7)
#define UART_TXC_BIT			(6)
#define UART_UDRE_BIT			(5)

#define UART_UCSRB_Reg			(*(volatile u8*)0x2A)
#define UART_RXEN_BIT			(4)
#define UART_TXEN_BIT			(3)
#define UART_UCSZ2_BIT			(2)

#define UART_UCSRC_Reg			(*(volatile u8*)0x40)
#define UART_URSEL_BIT			(7)
#define UART_UMSEL_BIT			(6)
#define UART_UPM1_BIT			(5)
#define UART_UPM0_BIT			(4)
#define UART_USBS_BIT			(3)
#define UART_UCSZ1_BIT			(2)
#define UART_UCSZ0_BIT			(1)

#endif /* SOURCES_1_MCAL_UART_INCLUDES_UART_REG_H_ */
