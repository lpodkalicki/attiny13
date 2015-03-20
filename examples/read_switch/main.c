/*
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - blinking led
 */

#include <attiny13_helper.h>

#define	LED_PIN		P0					// P0 (PB0) as LED pin
#define	SWITCH_PIN	P1					// P1 (PB1) as SWITCH pin

void
setup()
{
	pin_mode(LED_PIN, OUTPUT);				// Set LED pin as output
	pin_mode(SWITCH_PIN, INPUT);				// Set SWITCH pin as input
	digital_reset();					// Set all digital pins to LOW,
	digital_write(SWITCH_PIN, HIGH);			// except SWITCH pin
}

void
loop()
{
	while (1) {
		sleep(10);
		if (digital_read(SWITCH_PIN) == LOW) {		// check SWITCH in on
			digital_toggle(LED_PIN);		// Toggle LED pin
			sleep(30);				// little sleep because of SWITCH bounce
			while(digital_read(SWITCH_PIN) == LOW); // wait for a SWITCH release
			sleep(30);				// and again, little sleep because of SWITCH bounce
		}
	}
}
