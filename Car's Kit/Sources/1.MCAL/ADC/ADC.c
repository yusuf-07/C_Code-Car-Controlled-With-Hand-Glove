/*
 * ADC.c
 *
 *  Created on: Sep 7, 2022
 *      Author: 4hmed
 */

#include "ADC.h"

void ADC_voidInit(ADC_Vref_t vrefMode)
{
	// Enable ADC
	SET_BIT(ADC_ENABLE_BIT, ADC_ADCSRA_REG);

	// configure VREF+
	ADC_ADMUX_REG = (ADC_ADMUX_REG & ADC_VREF_MASK) | (vrefMode << 6);

	// Configure prescaler
	ADC_ADCSRA_REG = (ADC_ADCSRA_REG & ADC_PRESCALER_MASK) | (ADC_PRES_125KHZ << 0);
}

uint16__t ADC_u16ReadSteps(ADC_Channel_t channel)
{
	uint16__t loc_steps;

	// Configure channel
	ADC_ADMUX_REG = (ADC_ADMUX_REG & ADC_CHANNEL_MASK) | (channel << 0);

	// Start conversion
	SET_BIT(ADC_CONVERSION_BIT, ADC_ADCSRA_REG);

	// Wait for the ADIF and then clear it by writing 1 to it
	while( CHECK_BIT(ADC_ADIF_BIT, ADC_ADCSRA_REG) != 1 );

	SET_BIT(ADC_ADIF_BIT, ADC_ADCSRA_REG);

	loc_steps = ADC_ADCL_REG | (ADC_ADCH_REG << 8);

	return loc_steps;
}

f64 ADC_f64ReadVolts_mv(ADC_Channel_t channel)
{
	uint16__t loc_steps;
	f64 loc_volts;

	// Configure channel
	ADC_ADMUX_REG = (ADC_ADMUX_REG & ADC_CHANNEL_MASK) | (channel << 0);

	// Start conversion
	SET_BIT(ADC_CONVERSION_BIT, ADC_ADCSRA_REG);

	// Wait for the ADIF and then clear it by writing 1 to it
	while( CHECK_BIT(ADC_ADIF_BIT, ADC_ADCSRA_REG) != 1 );

	SET_BIT(ADC_ADIF_BIT, ADC_ADCSRA_REG);

	loc_steps = ADC_ADCL_REG | (ADC_ADCH_REG << 8);
	loc_volts = loc_steps * ADC_STEP;

	return loc_volts;
}

