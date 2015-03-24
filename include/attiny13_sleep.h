/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 */

#ifndef	_ATTINY13_SLEEP_H_
#define	_ATTINY13_SLEEP_H_

#include "attiny13_config.h"
#include <util/delay.h>

#define	sleep(value)	_delay_ms(value)	
#define	usleep(value)	_delay_us(value)

#endif	/* !_ATTINY13_SLEEP_H_ */