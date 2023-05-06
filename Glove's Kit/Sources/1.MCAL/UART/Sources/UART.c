/*
 * UART.c
 *
 *  Created on: 16 Sep 2022
 *      Author: yabul
 */
#include "UART.h"
#include "UART_Reg.h"
#define FCPU 	(16000000)

void UART_voidInit(u32 baudrate,UART_PARITY_T parity,UART_MODE_T sync,UART_STOP_T StopValue)
{
	//set baud rate
	UART_UBRRL_Reg = ((FCPU/(baudrate*16))-1); 	//put baudrate in the Low
	UART_UBRRH_Reg = (((FCPU/(baudrate*16))-1)>>8);	//shift 8 and put the remaining in the High

	//enable receiver and trasmitter
	SET_BIT(UART_UCSRB_Reg,UART_TXEN_BIT);		//enable transmitter
	SET_BIT(UART_UCSRB_Reg,UART_RXEN_BIT);		//enable receiver

	//set frame format: 8data,1stop bit,even parity

	//parity check
	//UCSRC_Reg=SET_BIT(UCSRC_Reg,7)|CLEAR_BIT(UCSRC_Reg,4)|SET_BIT(UCSRC_Reg,5);
	UART_UCSRC_Reg=SET_BIT(UART_UCSRC_Reg,UART_URSEL_BIT)|(parity<<UART_UPM0_BIT);

	//Asynchronous or Synchronous
	//UCSRC_Reg=SET_BIT(UCSRC_Reg,7)|CLEAR_BIT(UCSRC_Reg,6);
	UART_UCSRC_Reg|=SET_BIT(UART_UCSRC_Reg,UART_URSEL_BIT)|(sync<<UART_UMSEL_BIT);

	//1 stop bit
	//UCSRC_Reg=SET_BIT(UCSRC_Reg,7)|SET_BIT(UCSRC_Reg,3);
	UART_UCSRC_Reg|=SET_BIT(UART_UCSRC_Reg,UART_URSEL_BIT)|(StopValue<<UART_USBS_BIT);

	//Data length
	UART_UCSRC_Reg|=SET_BIT(UART_UCSRC_Reg,UART_URSEL_BIT)|SET_BIT(UART_UCSRC_Reg,UART_UCSZ0_BIT)|SET_BIT(UART_UCSRC_Reg,UART_UCSZ1_BIT)|CLEAR_BIT(UART_UCSRB_Reg,UART_UCSZ2_BIT); //8bit data length


}


void UART_Init(u32 baudRate)
{
	/*	Calculate UBRR Value	*/
	u32 loc_UBBR_val = ((FCPU/(16*baudRate))-1);
	/* Set baud rate */
	UART_UBRRH_Reg = loc_UBBR_val>>8;
	UART_UBRRL_Reg = loc_UBBR_val;
	/* Enable receiver and transmitter */
	UART_UCSRB_Reg = (1<<UART_RXEN_BIT)|(1<<UART_TXEN_BIT);
	/* Set frame format: 8data, 2stop bit */
	UART_UCSRC_Reg = (1<<UART_URSEL_BIT)|(1<<UART_USBS_BIT)|(3<<UART_UCSZ0_BIT);
}


void UART_voidSendByte(u8 DataByte)
{
	//wait for empty transmit buffer
	while(CHECK_BIT(UART_UCSRA_Reg,UART_UDRE_BIT)==0)
		;
	//put data into buffer, sends the data
	UART_UDR_Reg= DataByte;
}
u8 UART_u8ReceiveByte(void)
{
	//wait for data to be received
	while(CHECK_BIT(UART_UCSRA_Reg,UART_RXC_BIT)==0)
		;
	//get and return received data from buffer
	return(UART_UDR_Reg);
}

void UART_voidTransmitString(u8 *str)
{
	//wait for empty transmit buffer
	while(*str != '\0')
	{
		//send charachter by charachter
		UART_voidSendByte(*str);
		str++;
	}
}

