/*
 * MG995_Configurations.h
 *
 *  Created on: Oct 11, 2022
 *      Author: 4hmed
 */

#ifndef SOURCES_2_HAL_MG995_MG995_CONFIGURATIONS_H_
#define SOURCES_2_HAL_MG995_MG995_CONFIGURATIONS_H_

#include "MG995.h"

// Motor Dependant Configurations
#define FREQUENCY				50
#define	MIN_DUTYCYCLE_ms		0.5
#define MAX_DUTYCYLCE_ms		2.5

// Application and Motor Dependant Configurations
#define ROTATION_MODE			REVERSE							//[NORMAL - REVERSE]
#define MIN_ANGLE				0
#define MAX_ANGLE				180

#endif /* SOURCES_2_HAL_MG995_MG995_CONFIGURATIONS_H_ */
