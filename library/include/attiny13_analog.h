/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 */

#ifndef	_ATTINY13_ANALOG_H_
#define	_ATTINY13_ANALOG_H_

#include "attiny13_io.h"

int analog_read(uint8_t pin);
void analog_write(uint8_t pin, int value);

#endif	/* !_ATTINY13_ANALOG_H_ */
