/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 */

#ifndef	_ATTINY13_WATCHDOG_H_
#define	_ATTINY13_WATCHDOG_H_

#include <avr/interrupt.h>
#include "attiny13.h"

void watchdog_prescale(uint16_t);
#define	watchdog_handler()	ISR(WDT_vect)
#define	watchdog_enable()	WDTCR |= 1<<WDTIE;

#endif	/* !_ATTINY13_WATCHDOG_H_ */
