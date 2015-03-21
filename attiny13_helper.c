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
		sbi(DDRB, pin);
		SREG = tmp;
	} else { // mode == INPUT
		tmp = SREG;
		cli();
		cbi(DDRB, pin);
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

	if (value == HIGH) {
		sbi(PORTB, pin);
	} else { // value == LOW
		cbi(PORTB, pin);
	}
}

/* ----- Analog I/O ----- */

static uint8_t _adc_reference_mode = 0;

void
analog_reference(uint8_t mode)
{

	_adc_reference_mode = mode;
}

static uint8_t
_pin2mux(uint8_t pin)
{
	switch(pin) {
	case ADC1: return (1<<MUX0);
	case ADC2: return (1<<MUX1);
	case ADC3: return ((1<<MUX0)|(1<<MUX1));
	case ADC0: 	
	default:
		return 0;
	}
}

int
analog_read(uint8_t pin)
{
	uint8_t low, high;

	ADMUX = _pin2mux(pin);
	if (_adc_reference_mode > 0)
		ADMUX |= (1 << REFS0);

	//ADCSRA = (1<<ADEN)

	sbi(ADCSRA, ADSC);					// Run single conversion
	while(bit_is_set(ADCSRA, ADSC));			// Wait conversion is done

	// Read values
	low = ADCL;
        high = ADCH;

        // combine the two bytes
        return (high << 8) | low;
}

void
analog_write(uint8_t pin, int value)
{
	//pin_mode(pin, OUTPUT);				// Make sure the PWM output is enabled for this pin
	if (pin == DAC0) {	
		sbi(TCCR0A, COM0A1); 				// connect pwm to pin on timer 0, channel A
		OCR0A = value; 					// set pwm duty
	} else if (pin == DAC1) {
		sbi(TCCR0A, COM0B1); 				// connect pwm to pin on timer 0, channel B
		OCR0B = value; 					// set pwm duty	
	}
}

/* ----- Timer ----- */

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
timer_wgm(waveform_generation_mode_t mode)
{
	TCCR0A &= ~((1 << WGM01)|(1 << WGM00));
	TCCR0B &= ~(1 << WGM02); 
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

/* ----- Layout's helpers ----- */

int
main(void)
{
	
	setup();
	while (1) loop();
	return (0);
}

