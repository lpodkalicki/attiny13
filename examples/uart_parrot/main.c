/**
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - Software UART example (parrot)
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
	char c;

	uart_puts("UART parrot!\n");

	while (1) {
		c = uart_getc();
		uart_putc(c);
	}
}
