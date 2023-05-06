/*
 * glove_sender.c
 *
 *  Created on: 14 Oct 2022
 *      Author: Radwa
 */

#include "All_includes.h"

#define min_unbent 800
#define max_unbent 1000
#define min_bent 120
#define max_bent 600

#define min_no_motion 800
#define max_no_motion 1000
#define min_low_speed 600
#define max_low_speed 200
#define min_full_speed 299
#define max_full_speed 120


#define thumb ADC_u16ReadSteps(ADC_ADC4)
#define index_finger ADC_u16ReadSteps(ADC_ADC5)
#define middle_finger ADC_u16ReadSteps(ADC_ADC6)

void ReadySteadyGo(void)
{
	LCD_voidCMD(_LCD_CLEAR);
	LCD_voidMatrix(0,0);
	//LCD_voidDisplayStr("ADC STEPS: ");
	LCD_voidDisplayStr("HI!!!");
	_delay_ms(4000);
	LCD_voidCMD(_LCD_CLEAR);
	LCD_voidMatrix(0,0);
	LCD_voidDisplayStr("READY");
	_delay_ms(400);
	LCD_voidMatrix(0,5);
	LCD_voidDisplayStr(".");
	_delay_ms(400);
	LCD_voidMatrix(0,6);
	LCD_voidDisplayStr(".");
	_delay_ms(400);
	LCD_voidMatrix(0,7);
	LCD_voidDisplayStr(".");
	_delay_ms(6000);

	LCD_voidCMD(_LCD_CLEAR);
	LCD_voidMatrix(0,0);
	LCD_voidDisplayStr("STEADY");
	_delay_ms(400);
	LCD_voidMatrix(0,6);
	LCD_voidDisplayStr(".");
	_delay_ms(400);
	LCD_voidMatrix(0,7);
	LCD_voidDisplayStr(".");
	_delay_ms(400);
	LCD_voidMatrix(0,8);
	LCD_voidDisplayStr(".");
	_delay_ms(6000);

	LCD_voidCMD(_LCD_CLEAR);
	LCD_voidMatrix(0,0);
	LCD_voidDisplayStr("GO!!!!");

}

void GloveSendInit(void)
{
	UART_voidInit(9600,UART_PARITY_DISABLED,UART_AsynchronousOperation,UART_STOP_2_BIT);
	UART_Init(9600);
	DC_Motor_voidInit();
	//ADC_voidInit();
	ADC_voidInit(ADC_AVCC);

}
void CarForward_Send(void)
{
	UART_voidSendByte('q');
}
void CarForwardFullSpeed_Send(void)
{
	UART_voidSendByte('w');
}
void CarBackward_Send(void)
{
	UART_voidSendByte('s');
}
void CarSteerRight_Send(void)
{
	UART_voidSendByte('d');
}
void CarSteerLeft_Send(void)
{
	UART_voidSendByte('a');
}
void CarStop_Send(void)
{
	UART_voidSendByte('x');
}

boolean Thumb_IsBent(){
	if(thumb<=min_low_speed && thumb>=max_full_speed){
		return 1;
	}
	else return 0;
}

boolean MiddleFinger_IsBent(){
	if(middle_finger>=min_bent && middle_finger<=max_bent){
		return 1;
	}
	else return 0;
}

boolean IndexFinger_IsBent(){
	if(index_finger>=min_bent && index_finger<=max_bent){
		return 1;
	}
	else return 0;
}

boolean Thumb_IsLowSpeed(){
	if(thumb<=min_low_speed && thumb>max_low_speed){
		return 1;
	}
	else return 0;
}

boolean Thumb_IsFullSpeed(){
	if(thumb<=min_full_speed && thumb>max_full_speed){
		return 1;
	}
	else return 0;
}

void Execute_glove_sender()
{
	if(Thumb_IsBent()){
		if(MiddleFinger_IsBent())
		{
			//steer right
			CarSteerRight_Send();
			return;
		}
		else if(IndexFinger_IsBent()){
			//steer left
			CarSteerLeft_Send();
			return;
		}
		else {
			if(Thumb_IsLowSpeed()){
				//move forward low speed
				CarForward_Send();
				return;
			}
			else if(Thumb_IsFullSpeed()){
				//move forward full speed
				CarForwardFullSpeed_Send();
				return;
			}
		}
	}

	else if(IndexFinger_IsBent()){
		if(MiddleFinger_IsBent()){
			//lights
			LED_voidFLASH(LED0);
			LED_voidFLASH(LED1);
			LED_voidFLASH(LED2);
			return;
		}
		else{
			//backward
			CarBackward_Send();
			return;
		}
	}
	else if(MiddleFinger_IsBent() && (!Thumb_IsBent() && !IndexFinger_IsBent())){
		//break
		CarStop_Send();
		return;
	}
}
