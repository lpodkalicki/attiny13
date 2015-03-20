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

static inline void
pin_mode(uint8_t pin, uint8_t mode)
{

	if (mode == OUTPUT)
		DDRB |= 1 << pin;
	else // mode == INPUT
		DDRB &= ~(1 << pin);
}

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
