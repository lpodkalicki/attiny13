/**
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - Led on/off on external interrupt triggered by two switches.
 */


#include <attiny13_digital.h>
#include <attiny13_sleep.h>
#include <attiny13_interrupt.h>

#define	LED_PIN		D0			// D0 (PB0) as LED pin
#define	SWITCH_ON_PIN	PCINT1			// PCINT1 (PB1) as SWITCH pin to turn led ON
#define	SWITCH_OFF_PIN	PCINT2			// PCINT2 (PB2) as SWITCH pin to turn led OFF

volatile uint8_t pcint_history = 0xFF;		// Switches' pins are set to HIGH on start
volatile uint8_t on = 0;
volatile uint8_t off = 0;

void
setup(void)
{
	pin_mode(LED_PIN, OUTPUT);		// Set LED pin as output
	pin_mode(SWITCH_ON_PIN, INPUT);		// Set SWITCH pin as input
	pin_mode(SWITCH_OFF_PIN, INPUT);	// Set SWITCH pin as input
	digital_write(SWITCH_ON_PIN, HIGH);	// Set pull-up
	digital_write(SWITCH_OFF_PIN, HIGH);	// Set pull-up
	PCINT1_enable();			// Enable pin change interrupt
	PCINT2_enable();			// Enable pin change interrupt
	sei();					// Enable global interrupts
}

void
loop(void)
{
	while (1) {
		if (on) {
			on = 0;
			digital_write(LED_PIN, HIGH);
		} else if (off) {
			off = 0;
			digital_write(LED_PIN, LOW);
		}
		sleep(50);
	}
}

PCINT_handler()
{
	uint8_t changed_bits;

	changed_bits = PINB ^ pcint_history;
	pcint_history = PINB;

	if (changed_bits & (1 << SWITCH_ON_PIN)) {
		on = 1;
	}

	if (changed_bits & (1 << SWITCH_OFF_PIN)) {
		off = 1;
	}
}
