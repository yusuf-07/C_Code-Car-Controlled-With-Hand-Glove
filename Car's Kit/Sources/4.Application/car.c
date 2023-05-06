/*
 * main.c
 *
 *  Created on: Oct 12, 2022
 *      Author: 4hmed
 */
#include "avr/interrupt.h"

// MCAL Includes
#include "TIMER.h"
#include "UART.h"
#include "ADC.h"

// HAL Includes
#include "LCD.h"
#include "DC_Motor.h"

#define FORWARD						'q'
#define FORWARD_FULL_SPEED			'w'
#define BACKWARD					's'
#define BRAKE						'x'
#define RIGHT						'd'
#define LEFT						'a'

void Forward(void)
{
	Forward_fullSpeed();
	DC_Motor_voidAdjustSpeed(50);
}

void Forward_fullSpeed(void)
{
	DC_Motor_voidStart(MOTOR_A, CW);
	DC_Motor_voidStart(MOTOR_B, CW);
}

void Backward(void)
{
	DC_Motor_voidStart(MOTOR_A, CCW);
	DC_Motor_voidStart(MOTOR_B, CCW);
}

void Brake(void)
{
	DC_Motor_voidBrake(MOTOR_A);
	DC_Motor_voidBrake(MOTOR_B);

	_delay_ms(1000);

	DC_Motor_voidStop(MOTOR_A);
	DC_Motor_voidStop(MOTOR_B);
}

void Right(void)
{
	DC_Motor_voidStart(MOTOR_A, CCW);
	DC_Motor_voidStart(MOTOR_B, CW);

	_delay_ms(450);

	Brake();
	//Forward_fullSpeed();
}

void Left(void)
{
	DC_Motor_voidStart(MOTOR_A, CW);
	DC_Motor_voidStart(MOTOR_B, CCW);

	_delay_ms(750);

	Brake();
	//Forward_fullSpeed();
}

uint8_t recievedCommand;

ISR(USART_RXC_vect)
{
	recievedCommand = UDR_REG;
	LCD_voidSetCursor(1,0);
	LCD_voidDispStr("UART RX:         ");
	LCD_voidSetCursor(1, 9);
	LCD_voidDispChar(recievedCommand);

	switch (recievedCommand)
	{
	case BRAKE:
		Brake();
		break;

	case RIGHT:
		Right();
		break;

	case LEFT:
		Left();
		break;

	default: break;
	}
}

int main(void)
{
	UART_voidInit(9600, RTX, DATABITS_8, STOPBITS_1, NO_PARITY);
	UART_voidEnableRecieveInt();

	UART_voidSendStr("UART Initialized.\r\n");

	LCD_voidInit();
	LCD_voidDispStr("LCD Initialized.");

	DC_Motor_voidInit();

	while (True)
	{
		switch (recievedCommand)
		{
		case FORWARD:
			Forward();
			break;

		case FORWARD_FULL_SPEED:
			Forward_fullSpeed();
			break;

		case BACKWARD:
			Backward();
			break;

		default: break;
		}
	}
	return 0;
}
