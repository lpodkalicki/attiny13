/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * Attiny13 - software UART
 */

#ifndef	_ATTINY13_UART_H_
#define	_ATTINY13_UART_H_

#include <avr/pgmspace.h>
#include "attiny13_config.h"

#define	TXDELAY 	(int)(((F_CPU/UART_BAUDRATE)-7 +1.0)/3)
#define	RXDELAY		(int)(((F_CPU/UART_BAUDRATE)-5 +1.0)/3)
#define	RXDELAY2	(int)((RXDELAY*1.5)-2.5)
#define	RXROUNDED	(((F_CPU/UART_BAUDRATE)-5 +2)/3)
#if RXROUNDED > 127
# error low baud rates unsupported - use higher UART_BAUDRATE
#endif

char uart_getc();
void uart_putc(char c);
void uart_puth(char n);
void uart_puts(const char *s);
void uart_putp(const char *s);

#endif	/* !_ATTINY13_UART_H_ */
