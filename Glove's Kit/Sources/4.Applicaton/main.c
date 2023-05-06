	/***************************************
	 * main.c
	 *
	 *  Created on: Aug 23, 2022
	 *  Author: Eng_Fawzi
	 ***************************************/
#include "All_includes.h"

	int main(void)
	{
			//initialize needed drivers
			WakeUp_Call();
			UART_voidInit(9600,UART_PARITY_DISABLED,UART_AsynchronousOperation,UART_STOP_2_BIT);
			UART_Init(9600);
			ReadySteadyGo();

			while(1){
				Execute_glove_sender();
			}
			return 0;
	}
