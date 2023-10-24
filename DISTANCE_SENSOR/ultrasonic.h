/*
 * ultrasonic.h
 *
 *  Created on: Oct 16, 2023
 *      Author: Wael
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"

/*******************************************
 * 					Macros
 *******************************************/
#define TRIGGER_PORT_ID PORTB_ID
#define TRIGGER_PIN_ID	PIN5_ID

/*******************************************
 * 			Function Prototypes
 *******************************************/

/* Function to initialize the state and registers of the sensor */
void ULTRASONIC_init(void);

/* Function to return the computed distance from the sensor
 * -- ULTRASONIC_trigger is a prerequisite for this function */
uint16 ULTRASONIC_readDistance(void);


#endif /* ULTRASONIC_H_ */
