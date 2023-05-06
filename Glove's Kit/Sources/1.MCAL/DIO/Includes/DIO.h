/*
 * DIO.h
 *
 *  Created on: 26 Aug 2022
 *      Author: yabul
 */

#ifndef DIO_H_
#define DIO_H_
#include "DIO_TYPES.h"
#include "Std_Types.h"

void DIO_voidconfigureChannel(DIO_PORT_T,DIO_PIN_T,DIO_DIR_T);

void DIO_voidWRITEChannel(DIO_PORT_T,DIO_PIN_T,DIO_LEVEL_T);
void DIO_voidWRITEChannelGroup(DIO_PORT_T,u8 data,u8 mask);
DIO_LEVEL_T DIO_voidREADChannel(DIO_PORT_T,DIO_PIN_T);
void DIO_voidPULLUpEnable(DIO_PORT_T,DIO_PIN_T);
void DIO_voidFlipChannel(DIO_PORT_T port,DIO_PIN_T pin);
void WakeUp_Call(void);



#endif /* DIO_H_ */
