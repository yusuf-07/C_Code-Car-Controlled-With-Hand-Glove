/*
 * MG995.c
 *
 *  Created on: Oct 11, 2022
 *      Author: 4hmed
 */

#include "MG995.h"
#include "MG995_Configurations.h"

#define MAX_DUTYCYCLE			floor((MAX_DUTYCYLCE_ms * FREQUENCY / 10))
#define MIN_DUTYCYCLE			ceil((MIN_DUTYCYCLE_ms * FREQUENCY / 10))

void MG995_Init(void)
{
	TIMER_PWM_Init(TIMER1);
	TIMER_PWM1_SetFrequency(FREQUENCY);
	ADC_voidInit(ADC_AVCC);
}

void MG995_SetAngle(uint8_t loc_angle)
{
	if (loc_angle >= MIN_ANGLE && loc_angle <= MAX_ANGLE)
	{
		#if	(ROTATION_MODE == NORMAL)
		uint8_t MG995_dutyCycle = MAX_DUTYCYCLE - MAP(loc_angle, MIN_ANGLE, MAX_ANGLE, MIN_DUTYCYCLE, MAX_DUTYCYCLE);
		#elif (ROTATION_MODE == REVERSE)
		uint8_t MG995_dutyCycle = MAP(loc_angle, MIN_ANGLE, MAX_ANGLE, MIN_DUTYCYCLE, MAX_DUTYCYCLE);
		#else
			#error "Please configure ROTATION_MODE in MG995_Configurations.h"
		#endif

		TIMER_PWM_SetDutyCycle(TIMER1, MG995_dutyCycle);

	} else return;
}

void MG995_SetAngleFromADC(ADC_Channel_t channel)
{
	#if	(ROTATION_MODE == NORMAL)
	uint8_t MG995_dutyCycle = MAX_DUTYCYCLE - MAP(ADC_u16ReadSteps(channel), 0, 1023, MIN_DUTYCYCLE, MAX_DUTYCYCLE);
	#elif (ROTATION_MODE == REVERSE)
	uint8_t MG995_dutyCycle = MAP(ADC_u16ReadSteps(channel), 0, 1023, MIN_DUTYCYCLE, MAX_DUTYCYCLE);
	#else
		#error "Please configure ROTATION_MODE in MG995_Configurations.h"
	#endif

	TIMER_PWM_SetDutyCycle(TIMER1, MG995_dutyCycle);
}

void MG995_Start(void)
{
	TIMER_PWM_Start(TIMER1);
}
void MG995_Stop(void)
{
	TIMER_PWM_Stop(TIMER1);
}

