/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 */

#include <avr/interrupt.h>
#include "attiny13.h"
#include "attiny13_io.h"
#include "attiny13_utils.h"

void
pin_mode(uint8_t pin, uint8_t mode)
{
	uint8_t sreg;

	if (mode == OUTPUT) {
		sreg = SREG;
		cli();
		sbi(DDRB, pin);
		SREG = sreg;
	} else { // mode == INPUT
		sreg = SREG;
		cli();
		cbi(DDRB, pin);
		SREG = sreg;
	}
}

static void default_setup() {};
static void default_loop() {};

void __attribute__ ((weak, alias ("default_setup"))) setup(void);
void __attribute__ ((weak, alias ("default_loop"))) loop(void);

int
main(void)
{	
	setup();
	while (1) loop();
	return (0);
}
