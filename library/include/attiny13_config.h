/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 */

#ifndef	_ATTINY13_CONFIG_H_
#define	_ATTINY13_CONFIG_H_

#include "attiny13.h"
#include "config.h"

#ifndef	F_CPU
# define	F_CPU  		(1200000UL)	// Default FUSE settings, 1.2 MHz
#endif	/* !F_CPU */

/* ----- Software UART Configuration ----- */

#if !defined(UART_TX) && defined(UART_TX_ENABLED)
# define	UART_TX		PB0
#endif	/* !UART_TX */

#if !defined(UART_RX) && defined(UART_RX_ENABLED)
# define	UART_RX		PB1
#endif	/* !UART_RX */

#if !defined(UART_BAUDRATE) && (defined(UART_TX_ENABLED) || defined(UART_RX_ENABLED))
# define	UART_BAUDRATE	(9600)
#endif	/* !UART_BAUDRATE */

/* ----- Software SPI Configuration ----- */

#if !defined(SPI_CS) && defined(SPI_ENABLED)
# define	SPI_CS		PB3		
#endif	/* !SPI_CS */

#if !defined(SPI_MOSI) && defined(SPI_ENABLED)
# define	SPI_MOSI	PB2		
#endif	/* !SPI_MOSI */

#if !defined(SPI_MISO) && defined(SPI_ENABLED)
# define	SPI_MISO	PB4		
#endif	/* !SPI_MISO */

#if !defined(SPI_SCK) && defined(SPI_ENABLED)
# define	SPI_SCK		PB1		
#endif	/* !SPI_SCK */

#endif	/* !_ATTINY13_CONFIG_H_ */
