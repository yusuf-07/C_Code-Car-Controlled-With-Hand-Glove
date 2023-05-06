/*
 * ADC.h
 *
 *  Created on: Sep 7, 2022
 *      Author: 4hmed
 */

#ifndef SOURCES_1_MCAL_ADC_INCLUDES_ADC_H_
#define SOURCES_1_MCAL_ADC_INCLUDES_ADC_H_

#include "BitMasking.h"
#include "StandardTypes.h"

#define ADC_ADMUX_REG		(*(uint8_t*)0x27)
#define ADC_ADCSRA_REG		(*(uint8_t*)0x26)
#define ADC_ADCH_REG 		(*(uint8_t*)0x25)
#define ADC_ADCL_REG 		(*(uint8_t*)0x24)

#define ADC_ADIF_BIT		4
#define ADC_CONVERSION_BIT	6
#define ADC_ENABLE_BIT		7

#define ADC_VREF_MASK		0x3F
#define ADC_CHANNEL_MASK	0xE0
#define ADC_PRESCALER_MASK	0xF8

#define ADC_PRES_125KHZ		0x07

#define ADC_STEP			(4.8)

typedef enum
{
	ADC_ADC0,
	ADC_ADC1,
	ADC_ADC2,
	ADC_ADC3,
	ADC_ADC4,
	ADC_ADC5,
	ADC_ADC6,
	ADC_ADC7

} ADC_Channel_t;

typedef enum
{
	ADC_AREF,
	ADC_AVCC,
	ADC_256_VREF = 3

} ADC_Vref_t;

void ADC_voidInit(ADC_Vref_t);
uint16__t ADC_u16ReadSteps(ADC_Channel_t);
f64 ADC_f64ReadVolts_mv(ADC_Channel_t);

#endif /* SOURCES_1_MCAL_ADC_INCLUDES_ADC_H_ */
