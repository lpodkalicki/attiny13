/*
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * Attiny13 - circular led
 */


#include <attiny13_helper.h>

#define	delay	(200)

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

	while (1) {
		digital_write(D0, HIGH);
		sleep(delay);
		digital_write(D0, LOW);

		digital_write(D1, HIGH);
                sleep(delay);
                digital_write(D1, LOW);

		digital_write(D2, HIGH);
                sleep(delay);
                digital_write(D2, LOW);

		digital_write(D3, HIGH);
                sleep(delay);
                digital_write(D3, LOW);

		digital_write(D4, HIGH);
                sleep(delay);
                digital_write(D4, LOW);
	}
}
