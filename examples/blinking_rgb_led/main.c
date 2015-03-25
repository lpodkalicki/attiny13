/**
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - Simple blinking RGB led with common cathode (-)
 */


#include <attiny13_digital.h>
#include <attiny13_sleep.h>

#define	LED_RED		D0				// D0 (PB0) as LED RED pin
#define	LED_GREEN	D1				// D1 (PB1) as LED GREEN pin
#define	LED_BLUE	D2				// D1 (PB2) as LED BLUE pin
#define	PAUSE		(500)				// Pause time (ms)

static uint8_t led_pin[3] = {LED_RED, LED_GREEN, LED_BLUE};

void
setup(void)
{
	uint8_t i;
	for (i = 0; i < 3; ++i) {
		pin_mode(led_pin[i], OUTPUT);		// Set LED RED as output
	}
}



void
loop(void)
{
	uint8_t i;
	while (1) {
		for (i = 0; i < 3; ++i) {
			digital_write(led_pin[i],HIGH);	// LED ON
			sleep(PAUSE); 			// Pause a while
			digital_write(led_pin[i],LOW);	// LED OFF
		}
	}
}
