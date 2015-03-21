/*
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - blinking led
 */


#include <attiny13_helper.h>

#define	LED_PIN	D0				// D0 (PB0) as LED pin

void
setup(void)
{
	pin_mode(LED_PIN, OUTPUT);		// Set LED pin as output
	digital_reset();			// Set all digital pins to LOW
}

void
loop(void)
{

	while (1) {
		digital_toggle(LED_PIN);	// Toggle LED pin
		sleep(200); 			// Pause a while (200ms)
	}
}
