/**
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - Software UART example (parrot)
 */

#include <attiny13_uart.h>

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
