/**
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - Example how to control LED on/off using Software UART
 */

#include <attiny13_digital.h>
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

	uart_puts("Using UART to control LED on/off\n");

	while (1) {
		c = uart_getc();
		switch(c) {
		case 'H':
			digital_write(LED_PIN, HIGH);
			uart_puts("ON\n");
			break;
		case 'L':
			digital_write(LED_PIN, LOW);
			uart_puts("OFF\n");
                        break;
		}
	}
}
