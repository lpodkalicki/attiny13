/*
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - fading led (PWM version with DAC)
 */


#include <attiny13_digital.h>
#include <attiny13_analog.h>
#include <attiny13_timer.h>
#include <attiny13_sleep.h>

#define	LED_PIN	DAC0				// DAC 0 (PB0) as LED pin

void
setup(void)
{
	pin_mode(LED_PIN, OUTPUT);		// Set LED pin as output
	timer_mode(PWM);			// Start PWM
	timer_prescale(8);			// Clock source = CLK/8
}

void
loop(void)
{
	int i;

	while (1) {
		// Fade-in
		for (i = 0; i < 128; ++i) {
			analog_write(LED_PIN, i);
			sleep(10);
		}
		// Fade-out
		for (i = 128; i > 0; --i) {
                        analog_write(LED_PIN, i);
                        sleep(10);
                }

	}
}
