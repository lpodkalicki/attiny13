/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 */

#include <avr/interrupt.h>
#include "attiny13_io.h"
#include "attiny13_utils.h"
#include "attiny13_digital.h"

uint8_t
digital_read(uint8_t pin)
{

        if ((PINB & (1 << pin)) > 0)
                return HIGH;

        return LOW;
}

void
digital_write(uint8_t pin, uint8_t value)
{
	uint8_t sreg;
	
	if (value == HIGH) {
		sreg = SREG;
		cli();
		sbi(PORTB, pin);
		SREG = sreg;
	} else { // value == LOW
		sreg = SREG;
		cli();
		cbi(PORTB, pin);
		SREG = sreg;
	}
}

void
digital_toggle(uint8_t pin)
{
	
	PORTB ^= 1 << (pin);
}
