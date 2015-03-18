/*
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - blink
 */

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

#define	sleep(x) _delay_ms(x)

int
main(void)
{

    DDRB = 1 << DDB4; 		// Set up Port B pin 4 mode to output
    PORTB = 0; 			// Set up Port B data to be all low

    while (1) {
        PORTB ^= 1 << PB4; 	// Toggle Port B pin 4 output state
        sleep(100); 		// Pause for a 100ms
    }

    return (0);
}
