/**
 * Copyright (c) 2015, Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * [P001] Blinking LED - version with sleep function.
 */


#include <attiny13_digital.h>
#include <attiny13_sleep.h>

#define	LED_PIN	D0				// D0 (PB0) as LED pin

void
setup(void)
{

	pin_mode(LED_PIN, OUTPUT);		// Set LED pin as output
}

void
loop(void)
{

	while (1) {				// Infinity loop
		digital_toggle(LED_PIN);	// Toggle LED pin (HIGH/LOW)
		sleep(500); 			// Pause 0.5 sec
	}
}
