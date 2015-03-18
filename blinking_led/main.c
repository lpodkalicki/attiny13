/*
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - blinking led
 */

#define F_CPU	(1200000UL)

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

#define	LED_PORT	PB0		// Digital pin 0

int
main(void)
{

	DDRB = 1 << LED_PORT; 		// Set the LED pin as output
	PORTB = 0; 			// Set all digital pins to LOW

	while (1) {
		PORTB ^= 1 << LED_PORT; // Toggle LED pin
		_delay_ms(200); 	// Pause a while (200ms)
	}

	return (0);
}
