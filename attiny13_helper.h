/**
* Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
* Attiny13 helper functions
*/

#ifndef	_ATTINY13_HELPERS_H_
#define	_ATTINY13_HELPERS_H_

#ifndef	F_CPU
# define F_CPU   (1200000UL)	// 1.2 MHz
#endif	/* !F_CPU */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define	LOW	(0)
#define	HIGH 	(1)
#define	INPUT	(0)
#define	OUTPUT	(1)

#define	P0	PB0
#define P1      PB1
#define P2      PB2
#define P3      PB3
#define P4      PB4
#define	P5	PB5

/* ----- General helpers ----- */

static inline void
pin_mode(uint8_t pin, uint8_t mode)
{

	if (mode == OUTPUT)
		DDRB |= 1 << pin;
	else // mode == INPUT
		DDRB &= ~(1 << pin);
}

static inline void
sleep(uint16_t value)
{

        _delay_ms(value);
}

static inline void
usleep(uint16_t value)
{

        _delay_loop_2(value);
}

/* ----- Digital I/O helpers ----- */

static inline void
digital_reset(void)
{

	PORTB = 0;
}

static inline void
digital_write(uint8_t pin, uint8_t value)
{

	if (value == HIGH)
		PORTB |= 1 << pin;
	else // value == LOW
		PORTB &= ~(1 << pin);
}

static inline void
digital_toggle(uint8_t pin)
{

	PORTB ^= 1 << pin;
}

static inline uint8_t
digital_read(uint8_t pin)
{

	if ((PINB & (1 << pin)) > 0)
		return HIGH;

	return LOW;
}

/* ----- Interrupt's helpers ----- */

#define	timer_prescale0()	TCCR0B &= ~((1<<CS02)|(1<<CS01)|(1<<CS00))


#define	timer_prescale1() do {				\
	timer_prescale0();				\
	TCCR0B |= 1<<CS00;				\
} while(0)

#define timer_prescale8() do {				\
        timer_prescale0();				\
        TCCR0B |= 1<<CS01;				\
} while(0)

#define timer_prescale64() do {				\
        timer_prescale0();				\
        TCCR0B |= (1<<CS01)|(1<<CS00);			\
} while(0)

#define timer_prescale256() do {			\
        timer_prescale0();				\
        TCCR0B |= (1<<CS02);				\
} while(0)

#define timer_prescale1024() do {			\
        timer_prescale0();				\
        TCCR0B |= (1<<CS02)|(1<<CS00);			\
} while(0)

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

#define	disable_interrupts	cli
#define	enable_interrupts	sei

/* ----- Layout's helpers ----- */

void setup();
void loop();

int
main(void)
{

	setup();

	while (1) {
		loop();
	}

	return (0);
}

#endif	/* !_ATTINY13_HELPERS_H_ */
