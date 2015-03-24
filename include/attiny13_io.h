/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 */

#ifndef	_ATTINY13_IO_H_
#define	_ATTINY13_IO_H_

#include <avr/io.h>
#include "attiny13.h"

#define	LOW	(0)
#define	HIGH 	(1)
#define	INPUT	(0)
#define	OUTPUT	(1)

#define	D0	PB0
#define	D1	PB1
#define	D2	PB2
#define	D3	PB3
#define	D4	PB4
#define	D5	PB5

#define	ADC0	PB5
#define	ADC1	PB2
#define	ADC2	PB4
#define	ADC3	PB3

#define	DAC0	PB0
#define	DAC1	PB1

void pin_mode(uint8_t pin, uint8_t mode);

#endif	/* !_ATTINY13_IO_H_ */
