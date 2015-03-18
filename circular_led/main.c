/*
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * Attiny13 - circular led
 */

#define F_CPU	(1200000UL)

#include <attiny13_helper.h>

#define	delay	(200)

void
init(void)
{
	pin_mode(P0, OUTPUT);
	pin_mode(P1, OUTPUT);
	pin_mode(P2, OUTPUT);
	pin_mode(P3, OUTPUT);
	pin_mode(P4, OUTPUT);
	digital_reset();
}

int
main(void)
{

	init();

	while (1) {
		digital_write(P0, HIGH);
		sleep(delay);
		digital_write(P0, LOW);

		digital_write(P1, HIGH);
                sleep(delay);
                digital_write(P1, LOW);

		digital_write(P2, HIGH);
                sleep(delay);
                digital_write(P2, LOW);

		digital_write(P3, HIGH);
                sleep(delay);
                digital_write(P3, LOW);

		digital_write(P4, HIGH);
                sleep(delay);
                digital_write(P4, LOW);
	}

	return (0);
}
