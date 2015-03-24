/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * Attiny13 - helper functions
 */

#ifndef	_ATTINY13_HELPER_H_
#define	_ATTINY13_HELPER_H_

#ifndef	F_CPU
# define F_CPU   (1200000UL)	// 1.2 MHz
#endif	/* !F_CPU */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/* ----- Timer/Watchdog ----- */

typedef enum {
	NORMAL = 0,
	PWM = 1,
	CTC = 2,
	FAST_PWM = 3,
	PWMX = 4,
	FAST_PWMX = 5
} waveform_generation_mode_t;

void timer_prescale(uint16_t value);
void timer_wgm(waveform_generation_mode_t mode);

// TIMER0 (OVF)
#define	timer_ovf_handler()	ISR(TIM0_OVF_vect)
#define	timer_ovf_enable() 	TIMSK0 |= 1 << TOIE0
#define	timer_ovf_disable()	TIMSK0 &= ~(1 << TOIE0)

// TIMER1 (COMPA)
#define timer_compa_handler()	ISR(TIM0_COMPA_vect)
#define	timer_compa_enable()	TIMSK0 |= 1 << OCIE0A
#define	timer_compa_disable()	TIMSK0 &= ~(1 << OCIE0A)

// TIMER2 (COMPB)
#define timer_compb_handler()	ISR(TIM0_COMPB_vect)
#define timer_compb_enable()	TIMSK0 |= 1 << OCIE0B
#define timer_compb_disable()	TIMSK0 &= ~(1 << OCIE0B)

//void watchdog_prescale(uint16_t value);

// WATCHDOG (WDT)
#define	watchdog_handler()	ISR(WDT_vect)
#define	watchdog_enable()	WDTCR |= 1<<WDTIE;
#define	watchdog_disable()	WDTCR &= ~(1<<WDTIE);

#define	disable_interrupt	cli
#define	enable_interrupt	sei

/* ----- Layout ----- */

void setup();
void loop();

#endif	/* !_ATTINY13_HELPER_H_ */

