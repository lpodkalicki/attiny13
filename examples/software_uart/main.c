/**
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - very simple blinking led
 */

#include <attiny13_digital.h>
#include <attiny13_sleep.h>
#include <attiny13_uart.h>

#define	LED_PIN	D0

void
setup(void)
{
	pin_mode(LED_PIN, OUTPUT);
}

void
loop(void)
{
	char c = 'A';

	uart_puts("HELLO!\n");

	while (1) {
		c = uart_getc();
		switch(c) {
		case 'H':
			digital_write(LED_PIN, HIGH);
			uart_puts("HIGH\n");
			break;
		case 'L':
			digital_write(LED_PIN, LOW);
			uart_puts("LOW\n");
                        break;
		}
		sleep(200); 			// Pause a while (200ms)
	}
}
