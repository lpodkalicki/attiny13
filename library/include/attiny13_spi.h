/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * Attiny13 - software SPI
 */

#ifndef	_ATTINY13_SPI_H_
#define	_ATTINY13_SPI_H_

#include "attiny13_config.h"

void spi_init();
void spi_cs_enable(void);
void spi_cs_disable(void);
char spi_transfer(char c);

#endif	/* !_ATTINY13_SPI_H_ */
