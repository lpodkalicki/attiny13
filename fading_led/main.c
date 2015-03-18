/*
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - pulsing led
 */

#define F_CPU	(1200000UL)			// 1.2 MHz

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

#define LED_PORT	PB0
#define	DELAY_MAX	(700)
#define	DELAY_MIN	(1)
#define	FADE_IN		(0)
#define	FADE_OUT	(1)

int
main(void)
{
	uint8_t fade_type = FADE_IN;		// Start with fade-in
	uint16_t delay = DELAY_MIN;		// Set delay start value

	DDRB |= 1 << LED_PORT;			// Set the LED port as output

	while (1) {

		PORTB |= (1 << LED_PORT); 	// Set the LED port bit to "1" - LED will be turned on.
		_delay_loop_2(delay);		//  Wait a little. The delay function simply does N-number of "empty" loops.
		PORTB &= ~(1 << LED_PORT);	// Set the LED port bit to "0" - LED will be turned off.
		_delay_loop_2(DELAY_MAX-delay);	// Wait a while, again

		if (fade_type == FADE_IN) {
			delay++;
			if (delay >= DELAY_MAX - 1) {
				fade_type = FADE_OUT;
			}
		} else {
      			delay--;
      			if (delay <= DELAY_MIN) {
				fade_type = FADE_IN;
				_delay_ms(200);
			}
    		}
	}

	return (0);
}
