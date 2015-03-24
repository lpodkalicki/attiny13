/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 */

#include "attiny13_io.h"
#include "attiny13_utils.h"
#include "attiny13_timer.h"

void
timer_prescale(uint16_t value)
{
	TCCR0B &= ~((1<<CS02)|(1<<CS01)|(1<<CS00));		// prescale 0 (clear)
	switch (value) {
	case 1: TCCR0B |= 1<<CS00; break;
	case 8: TCCR0B |= 1<<CS01; break;
	case 64: TCCR0B |= (1<<CS01)|(1<<CS00); break;
	case 256: TCCR0B |= (1<<CS02); break;
        case 1024: TCCR0B |= (1<<CS02)|(1<<CS00); break;
	default: break;
	}
}

void
timer_mode(wgm_t mode)
{
	TCCR0A &= ~((1<<WGM01)|(1<<WGM00));
	TCCR0B &= ~(1<<WGM02); 
	switch(mode) {
	case PWM: TCCR0A |= 1<<WGM00; break; 
	case CTC: TCCR0A |= 1<<WGM01; break;
	case FAST_PWM: TCCR0A |= (1<<WGM01)|(1<<WGM00); break;
	case PWMX: TCCR0A |= 1<<WGM00; TCCR0B |= 1<<WGM02; break;
	case FAST_PWMX: TCCR0A |= (1<<WGM01)|(1<<WGM00); TCCR0B |= 1<<WGM02; break;	
	case NORMAL:
	default:
		break;
	}
}
