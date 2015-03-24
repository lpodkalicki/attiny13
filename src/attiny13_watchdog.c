/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 */

#include "attiny13_io.h"
#include "attiny13_utils.h"
#include "attiny13_watchdog.h"

void
watchdog_prescale(uint16_t value)
{
	WDTCR &= ~((1<<WDP3)|(1<<WDP2)|(1<<WDP1)|(1<<WDP0));
	switch (value) {	
        case 1024: WDTCR |= (1<<WDP3)|(1<<WDP0); break;			// 8.0s (1048576 cycles) 
	case 512: WDTCR |= 1<<WDP3; break;				// 4.0s (24288 cycles)
	case 256: WDTCR |= (1<<WDP2)|(1<<WDP1)|(1<<WDP0); break;	// 2.0s (62144 cycles)
	case 128: WDTCR |= (1<<WDP2)|(1<<WDP1); break;			// 1.0s (31072 cycles)
	case 64: WDTCR |= (1<<WDP2)|(1<<WDP0); break;			// 0.5s (65536 cycles) 
	case 32: WDTCR |= 1<<WDP2; break;				// 0.25s (32768 cycles) 
	case 16: WDTCR |= (1<<WDP1)|(1<<WDP0); break;			// 0.125 (16384 cycles)
	case 8: WDTCR |= 1<<WDP1; break;				// 64ms (8192 cycles)
	case 4: WDTCR |= 1<<WDP0; break;				// 32ms (4096 cycles)
	case 2:								// 16ms (2048 cycles)
	default: break;
	}
}
