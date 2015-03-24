/*
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - reading a switch on/off
 */

#include <attiny13_digital.h>
#include <attiny13_sleep.h>

#define	LED_PIN		D0					// D0 (PB0) as LED pin
#define	SWITCH_PIN	D1					// D1 (PB1) as SWITCH pin

void
setup()
{
	pin_mode(LED_PIN, OUTPUT);				// Set LED pin as output
	pin_mode(SWITCH_PIN, INPUT);				// Set SWITCH pin as input
	digital_write(SWITCH_PIN, HIGH);			// except SWITCH pin (pull-up)
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
