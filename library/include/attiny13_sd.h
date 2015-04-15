/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 */

#ifndef	_ATTINY13_SD_H_
#define	_ATTINY13_SD_H_

#include <stdint.h>

int8_t sd_init(void);
int8_t sd_command(uint8_t cmd, unsigned long arg, uint8_t crc, uint8_t read);

#endif	/* !_ATTINY13_SD_H_ */
