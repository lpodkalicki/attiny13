/*
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - simple analog read
 */


#include <attiny13_helper.h>

#define	LED_PIN	D0				// Digital 0 (PB0) as LED pin
#define	ADC_PIN	ADC1				// Analog 0 (PB2) as ADC pin

void
setup(void)
{
	pin_mode(LED_PIN, OUTPUT);		// Set LED pin as output
	pin_mode(ADC_PIN, INPUT);		// Set ADC pin as input
	digital_reset();			// Set all digital pins to LOW
	digital_write(ADC_PIN, HIGH);		// Set pull-up
	analog_enable();			// Enable ADC
}

void
loop(void)
{
	int value, i;

	while (1) {
		digital_toggle(LED_PIN);	// Toggle LED pin
		value = analog_read(ADC_PIN);
		for (i = 0; i < value; i++) {
			usleep(100);
		}
	}
}
