/*
 * DC_Motor.h
 *
 *  Created on: Sep 14, 2022
 *      Author: 4hmed
 */

#ifndef SOURCES_2_HAL_INCLUDES_DC_MOTOR_H_
#define SOURCES_2_HAL_INCLUDES_DC_MOTOR_H_

#include <util/delay.h>

#include "DIO.h"
#include "TIMER.h"
#include "BitMasking.h"
#include "StandardTypes.h"

typedef enum
{
	MOTOR_A,
	MOTOR_B

} DC_Motor_Id_t;

typedef enum
{
	CW,
	CCW

} DC_Motor_Direction_t;

void DC_Motor_voidInit(void);
void DC_Motor_voidStart(DC_Motor_Id_t ,DC_Motor_Direction_t);
void DC_Motor_voidAdjustSpeed(uint8_t);
void DC_Motor_voidStop(DC_Motor_Id_t);
void DC_Motor_voidBrake(DC_Motor_Id_t);

#endif /* SOURCES_2_HAL_INCLUDES_DC_MOTOR_H_ */
