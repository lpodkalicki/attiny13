/**
* Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
* Attiny13 helper functions
*/

#ifndef	_ATTINY13_HELPER_H_
#define	_ATTINY13_HELPER_H_

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

#define D0      PB0
#define D1      PB1
#define D2      PB2
#define D3      PB3
#define D4      PB4
#define D5      PB5

#define	ADC0	PB5
#define	ADC1	PB2
#define	ADC2	PB4
#define	ADC3	PB3

#define	DAC0	PB0
#define	DAC1	PB1

/* ----- Basics ----- */

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

#define sleep(value)	_delay_ms(value)	
#define	usleep(value)	_delay_loop_2(value)

void pin_mode(uint8_t pin, uint8_t mode);

/* ----- Digital I/O ----- */

void digital_reset(void);
uint8_t digital_read(uint8_t pin);
void digital_write(uint8_t pin, uint8_t value);
#define digital_toggle(pin)	(PORTB ^= 1 << (pin))

/* ----- ADC/DAC I/O ----- */

#define adc_enable()	sbi(ADCSRA, ADEN)
#define adc_disable()	cbi(ADCSRA, ADEN)
void adc_reference(uint8_t mode);
int analog_read(uint8_t pin);
void analog_write(uint8_t pin, int value);

/* ----- Timer ----- */

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

#define	disable_interrupts	cli
#define	enable_interrupts	sei

/* ----- Layout ----- */

void setup();
void loop();

#endif	/* !_ATTINY13_HELPER_H_ */

