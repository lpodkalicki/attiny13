/*
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - simple analog read
 */


#include <attiny13_helper.h>

#define	LED_PIN	DAC0				// DAC 0 (PB0) as LED pin

void
setup(void)
{
	pin_mode(LED_PIN, OUTPUT);		// Set LED pin as output
	timer_wgm(PWM);				// start fast PWM
	timer_prescale(8);			// Clock source = CLK/64
}

void
loop(void)
{
	int i;

	while (1) {

		for (i = 0; i < 128; ++i) {
			analog_write(LED_PIN, i);
			sleep(10);
		}

		for (i = 128; i > 0; --i) {
                        analog_write(LED_PIN, i);
                        sleep(10);
                }

	}
}
