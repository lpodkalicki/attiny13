/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 */

#ifndef	_ATTINY13_CONFIG_H_
#define	_ATTINY13_CONFIG_H_

#include "attiny13.h"

#ifndef	F_CPU
# define	F_CPU  		(1200000UL)	// 1.2 MHz
#endif	/* !F_CPU */

#if !defined(UART_TX) && defined(UART_TX_ENABLED)
# define	UART_TX		D3
#endif	/* !UART_TX */

#if !defined(UART_RX) && defined(UART_RX_ENABLED)
# define	UART_RX		D4
#endif	/* !UART_RX */

#if !defined(UART_BAUDRATE) && (defined(UART_TX_ENABLED) || defined(UART_RX_ENABLED))
# define	UART_BAUDRATE	(9600)
#endif	/* !UART_BAUDRATE */

#endif	/* !_ATTINY13_CONFIG_H_ */
