/*
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - blinking led
 */

#define F_CPU	(1200000UL)			// 1.2 MHz

#include <attiny13_helpers.h>

#define	LED_PIN	P0				// P0 (PB0) as LED pin

static void
init(void)
{
	pin_mode(LED_PIN, OUTPUT);		// Set LED pin as output
	digital_reset();			// Set all digital pins to LOW
}

int
main(void)
{
	init();

	while (1) {
		digital_toggle(LED_PIN);	// Toggle LED pin
		sleep(200); 			// Pause a while (200ms)
	}

	return (0);
}
