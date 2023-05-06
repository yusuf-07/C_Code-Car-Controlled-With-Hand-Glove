/*
 * DIO_TYPES.h
 *
 *  Created on: 27 Aug 2022
 *      Author: yabul
 */

#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

typedef enum
{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD

}DIO_PORT_T;
typedef enum
{
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7

}DIO_PIN_T;

typedef enum
{
	DIO_INPUT,
	DIO_OUTPUT

}DIO_DIR_T;

typedef enum
{
	DIO_LOW,
	DIO_HIGH

}DIO_LEVEL_T;



#endif /* DIO_TYPES_H_ */
