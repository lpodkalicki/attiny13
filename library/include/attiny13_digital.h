/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 */

#ifndef	_ATTINY13_DIGITAL_H_
#define	_ATTINY13_DIGITAL_H_

#include "attiny13_io.h"

uint8_t digital_read(uint8_t pin);
void digital_write(uint8_t pin, uint8_t value);
void digital_toggle(uint8_t pin);

#endif	/* !_ATTINY13_DIGITAL_H_ */

