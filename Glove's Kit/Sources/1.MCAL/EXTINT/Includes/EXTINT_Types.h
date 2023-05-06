/*
 * EXTINT_Types.h
 *
 *  Created on: 3 Sep 2022
 *      Author: yabul
 */

#ifndef SOURCES_1_MCAL_EXTINT_INCLUDES_EXTINT_TYPES_H_
#define SOURCES_1_MCAL_EXTINT_INCLUDES_EXTINT_TYPES_H_

typedef enum
{
	EXT_INT0,
	EXT_INT1,
	EXT_INT2
}EXTINT_ID_T;

typedef enum
{
	EXT_FallEdge,
	EXT_RiseEdge,
	EXT_BothEdge,
	EXT_LowLevel
}EXTINT_SenseCtrl_T;


#endif /* SOURCES_1_MCAL_EXTINT_INCLUDES_EXTINT_TYPES_H_ */
