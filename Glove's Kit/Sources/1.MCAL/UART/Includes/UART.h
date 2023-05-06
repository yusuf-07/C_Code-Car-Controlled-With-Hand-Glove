/*
 * UART.h
 *
 *  Created on: 16 Sep 2022
 *      Author: yabul
 */

#ifndef SOURCES_1_MCAL_UART_INCLUDES_UART_H_
#define SOURCES_1_MCAL_UART_INCLUDES_UART_H_
#include "UART_Reg.h"
#include "UART_Types.h"

void UART_voidInit(u32 baudrate,UART_PARITY_T parity,UART_MODE_T sync,UART_STOP_T StopValue);

void UART_Init(u32 baudRate);

void UART_voidSendByte(u8 byte);
u8 UART_u8ReceiveByte(void);
void UART_voidTransmitString(u8 *str);


#endif /* SOURCES_1_MCAL_UART_INCLUDES_UART_H_ */
