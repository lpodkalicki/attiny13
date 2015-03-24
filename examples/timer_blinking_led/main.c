/*
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - blinking led - version with timer
 */


#include <attiny13_digital.h>
#include <attiny13_timer.h>

#define	LED_PIN	D0				// D0 (PB0) as LED pin

timer_ovf_handler()
{

	digital_toggle(LED_PIN);                // Toggle LED pin
}

void
setup(void)
{
	pin_mode(LED_PIN, OUTPUT);		// Set LED pin as output
	timer_prescale(1024);			// Prescale 1024
	timer_ovf_enable();			// Enable timer OVF interrupt handler
	sei();					// Enable interrupt
}

void
loop(void)
{

	while (1); 				// Empty loop
}
