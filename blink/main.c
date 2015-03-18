/*
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - blinking led
 */

#define F_CPU	(1000000UL)

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

int
main(void)
{

	DDRB = 1 << DDB4; 		// Set up Port B pin 4 mode to output
	PORTB = 0; 			// Set up Port B data to be all low

	while (1) {
		PORTB ^= 1 << PB4; 	// Toggle Port B pin 4 output state
		_delay_ms(200); 	// Pause for a 200ms
	}

	return (0);
}
