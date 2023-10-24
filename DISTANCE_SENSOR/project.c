/*
 * project.c
 *
 *  Created on: Oct 16, 2023
 *      Author: Wael
 */

#include "ultrasonic.h"
#include "lcd.h"
#include <avr/io.h>

int main(void){
	/**************** Initializations *****************/
	/* Enabling global interrupt I-BIT */
	SREG |= (1<<7);

	/* Initializing ultrasonic sensor */
	ULTRASONIC_init();

	/* Initializing lcd */
	LCD_init();
	LCD_displayString("Distance=     cm");

	uint16 distance = 0;

	/**************** Application *****************/
	while(1){
		distance = ULTRASONIC_readDistance();

		/* Writing distance value in LCD */
		LCD_moveCursor(0,10);
		if(distance >= 100)
			LCD_intgerToString(distance);
		else if (distance==0){
			LCD_intgerToString(distance);
			LCD_displayString("  ");
		}
		else
		{
			LCD_intgerToString(distance);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}

	}
	return 0;
}
