/*
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - reading variable resistor example
 */


#include <attiny13_digital.h>
#include <attiny13_analog.h>
#include <attiny13_sleep.h>

#define	LED_PIN		D0				// D0 (PB0) as LED pin
#define	RESISTOR_PIN	ADC1				// ADC1 (PB2) as RESITOR pin

void
setup(void)
{
	pin_mode(LED_PIN, OUTPUT);			// Set LED pin as output
	pin_mode(RESISTOR_PIN, INPUT);			// Set RESISTOR pin as input
	digital_write(RESISTOR_PIN, HIGH);		// Set pull-up
}

void
loop(void)
{
	int value = 0, i;

	while (1) {
		digital_toggle(LED_PIN);		// Toggle LED on/off
		value = analog_read(RESISTOR_PIN);
		for (i = 0; i < value; i++) {
			usleep(100);
		}
	}
}
