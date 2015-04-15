/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * Attiny13 - TSOP2236 and TSOP2238 driver
 */

#include "attiny13_interrupt.h"
#include "attiny13_digital.h"
#include "driver/tsop223x.h"

static void
TSOP2236_reset()
{
	
}

void
TSOP2236_init(void)
{
	INT0_enable();
	MCUCR |= (1<<ISC01); // falling edge
	sei();
}

void
TSOP2236_default_handler(uint8_t command)
{
}

INT0_handler()
{
	
}
