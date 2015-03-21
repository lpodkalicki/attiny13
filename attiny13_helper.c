/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * Attiny13 helper functions
 */

#include "attiny13_helper.h"

/* ----- Basics ----- */

void
pin_mode(uint8_t pin, uint8_t mode)
{
	uint8_t tmp;

	if (mode == OUTPUT) {
		tmp = SREG;
		cli();
		set_bit(DDRB, pin);
		SREG = tmp;
	} else { // mode == INPUT
		tmp = SREG;
		cli();
		clear_bit(DDRB, pin);
		SREG = tmp;
	}
}

/* ----- Digital I/O ----- */

void
digital_reset(void)
{
	uint8_t tmp = SREG;
	cli();
	PORTB = 0;
	SREG = tmp;
}

uint8_t
digital_read(uint8_t pin)
{

        if ((PINB & (1 << pin)) > 0)
                return HIGH;

        return LOW;
}

void
digital_write(uint8_t pin, uint8_t value)
{
	uint8_t tmp;

	if (value == HIGH) {
		tmp = SREG;
                cli();
		set_bit(PORTB, pin);
		SREG = tmp;
	} else { // value == LOW
		tmp = SREG;
		cli();
		clear_bit(PORTB, pin);
		SREG = tmp;
	}
}

void
digital_toggle(uint8_t pin)
{

	PORTB ^= 1 << pin;
}


/* ----- Analog I/O ----- */

static adc_ref_mode_t _adc_reference_mode = INTERNAL;

void
analog_enable()
{
	
	set_bit(ADCSRA, ADEN);
}

void
analog_disable()
{
	
	clear_bit(ADCSRA, ADEN);
}

void
analog_reference(adc_ref_mode_t mode)
{

	_adc_reference_mode = mode;
}

static uint8_t
_pin2mux(uint8_t pin)
{
	switch(pin) {
	case ADC0: return 0;
	case ADC1: return (1<<MUX0);
	case ADC2: return (1<<MUX1);
	case ADC3: return ((1<<MUX0)|(1<<MUX1));
	default: return 0;
	}
}

int
analog_read(uint8_t pin)
{
	uint8_t low, high;

	ADMUX = _pin2mux(pin);
	if (_adc_reference_mode == VCC)
		ADMUX |= (1 << REFS0);

	//ADCSRA = (1<<ADEN)

	set_bit(ADCSRA, ADSC);			// Run single conversion
	while(bit_is_set(ADCSRA, ADSC));	// Wait conversion is done

	// Read values
	low = ADCL;
        high = ADCH;

        // combine the two bytes
        return (high << 8) | low;
}

void
analog_write(uint8_t pin, int value)
{
	
}

static inline long
map(long value, long in_min, long in_max, long out_min, long out_max)
{

	return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/* ----- Interrupts ----- */

void
timer_prescale(uint16_t v)
{
	TCCR0B &= ~((1<<CS02)|(1<<CS01)|(1<<CS00));	// prescale 0 (clear)
	switch (v) {
	case 1: TCCR0B |= 1<<CS00; break;
	case 8: TCCR0B |= 1<<CS01; break;
	case 64: TCCR0B |= (1<<CS01)|(1<<CS00); break;
	case 256: TCCR0B |= (1<<CS02); break;
        case 1024: TCCR0B |= (1<<CS02)|(1<<CS00); break;
	default: break;
	}
}

/* ----- Layout's helpers ----- */

int
main(void)
{
	setup();
	while (1) loop();
	return (0);
}

