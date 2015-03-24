/*
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - blinking led - version with watchdog
 */


#include <attiny13_digital.h>
#include <attiny13_watchdog.h>

#define	LED_PIN	D0				// D0 (PB0) as LED pin

watchdog_handler()
{

	digital_toggle(LED_PIN);                // Toggle LED pin
}

void
setup(void)
{
	pin_mode(LED_PIN, OUTPUT);		// Set LED pin as output
	watchdog_prescale(32);			// Watchdog oscilator prescale - 32 (0.25s)
	watchdog_enable();			// Enable watchdog
	sei();					// Enable interrupts
}

void
loop(void)
{

	while (1);
}
