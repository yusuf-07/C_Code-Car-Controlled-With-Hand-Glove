/*
 * MG995.h
 *
 *  Created on: Oct 11, 2022
 *      Author: 4hmed
 */

#ifndef SOURCES_2_HAL_MG995_MG995_H_
#define SOURCES_2_HAL_MG995_MG995_H_

#include "StandardTypes.h"
#include "StandardFunctions.h"
#include "TIMER.h"
#include <math.h>
#include "ADC.h"

#define NORMAL 		0
#define REVERSE 	1

void MG995_Init(void);
void MG995_SetAngle(uint8_t);
void MG995_SetAngleFromADC(ADC_Channel_t);
void MG995_Start(void);
void MG995_Stop(void);

#endif /* SOURCES_2_HAL_MG995_MG995_H_ */
