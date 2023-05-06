/*
 * glove_sender.h
 *
 *  Created on: 14 Oct 2022
 *      Author: Radwa
 */

#ifndef SOURCES_5__PROJECT_GLOVE_SENDER_INCLUDES_GLOVE_SENDER_H_
#define SOURCES_5__PROJECT_GLOVE_SENDER_INCLUDES_GLOVE_SENDER_H_
#include "DIO.h"
#include "UART.h"
#include "DC_Motor.h"
#include "DC_Direction.h"
#include "DC_MOTOR_Type.h"
#include "ADC.h"

void GloveSendInit(void);
void CarForward_Send(void);
void CarForwardFullSpeed_Send(void);
void CarBackward_Send(void);
void CarSteerRight_Send(void);
void CarSteerLeft_Send(void);
void CarStop_Send(void);
void ReadySteadyGo(void);
boolean Thumb_IsBent(void);
boolean MiddleFinger_IsBent(void);
boolean IndexFinger_IsBent(void);
boolean Thumb_IsLowSpeed(void);
boolean Thumb_IsFullSpeed(void);
void Execute_glove_sender(void);


#endif /* SOURCES_5__PROJECT_GLOVE_SENDER_INCLUDES_GLOVE_SENDER_H_ */
