/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * Attiny13 - software SPI
 */

#include <stdint.h>
#include <avr/io.h>
#include "attiny13_spi.h"
#include "attiny13_config.h"

#define	SPI_PORT	PORTB
#define	SPI_DDR		DDRB
#define	SPI_PIN		PINB
#define	CS_PIN		(1<<SPI_CS)		// PB3 as default
#define	MOSI_PIN	(1<<SPI_MOSI)		// PB2 as default
#define	MISO_PIN 	(1<<SPI_MISO)		// PB4 as default
#define	SCK_PIN		(1<<SPI_SCK) 		// PB1 as default

#define	read_miso() 	(SPI_PIN & (MISO_PIN))
#define	select_chip() 	(SPI_PORT &= ~(CS_PIN))
#define	deselect_chip() (SPI_PORT |= (CS_PIN))
#define	SPI_SCK_HIGH() 	(SPI_PORT |= SCK_PIN)
#define	SPI_SCK_LOW() 	(SPI_PORT &= ~SCK_PIN)
#define	SPI_MOSI_HIGH() (SPI_PORT |= MOSI_PIN)
#define	SPI_MOSI_LOW() 	(SPI_PORT &= ~MOSI_PIN) 

char
spi_transfer(char c)
{
	uint8_t i;
	
	for (i = 0; i < 8; i++) {
		if (c & (1 << 7)) {
			SPI_MOSI_HIGH();
		} else {
			SPI_MOSI_LOW();
		}
		SPI_SCK_LOW();
		c <<= 1;
		if (read_miso()) {
			c |= 1;
		}
		SPI_SCK_HIGH();
	}
	
	return c;
}

void
spi_init(void)
{
	deselect_chip();
	SPI_DDR = MOSI_PIN|SCK_PIN|CS_PIN;
	SPI_SCK_HIGH();
}

void
spi_cs_enable(void)
{
	select_chip();
}

void
spi_cs_disable(void)
{
	deselect_chip();
}
