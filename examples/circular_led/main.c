/**
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * Attiny13 - very simple circular led
 */


#include <attiny13_digital.h>
#include <attiny13_sleep.h>

void
setup(void)
{
	pin_mode(D0, OUTPUT);
	pin_mode(D1, OUTPUT);
	pin_mode(D2, OUTPUT);
	pin_mode(D3, OUTPUT);
	pin_mode(D4, OUTPUT);
}

void
loop(void)
{
	uint8_t pin;

	for (pin = 0; pin < 5; ++pin) {
		digital_write(pin, HIGH);
		sleep(200);
		digital_write(pin, LOW);
	}
}
