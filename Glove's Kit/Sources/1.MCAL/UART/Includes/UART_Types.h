/*
 * UART_Types.h
 *
 *  Created on: 17 Sep 2022
 *      Author: yabul
 */

#ifndef SOURCES_1_MCAL_UART_INCLUDES_UART_TYPES_H_
#define SOURCES_1_MCAL_UART_INCLUDES_UART_TYPES_H_

typedef enum
{
	UART_PARITY_DISABLED,
	UART_PARITY_RESERVED,
	UART_PARITY_EVEN,
	UART_PARITY_ODD

}UART_PARITY_T;

typedef enum
{
	UART_AsynchronousOperation,
	UART_SynchronousOperation
}UART_MODE_T;
typedef enum
{
	UART_STOP_1_BIT,
	UART_STOP_2_BIT
}UART_STOP_T;

#endif /* SOURCES_1_MCAL_UART_INCLUDES_UART_TYPES_H_ */
