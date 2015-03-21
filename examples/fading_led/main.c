/**
 * Copyright (c) 2015 by Łukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * ATtiny13 - pulsing led
 */

#include <attiny13_helper.h>

#define LED_PIN		D0			// D0 (PB0) as LED pin
#define	DELAY_MAX	(700)
#define	DELAY_MIN	(1)
#define	FADE_IN		(0)
#define	FADE_OUT	(1)

void
setup(void)
{
	pin_mode(LED_PIN, OUTPUT);
	digital_reset();
}

void
loop(void)
{
	uint8_t fade_type = FADE_IN;		// Start with fade-in
	uint16_t delay = DELAY_MIN;		// Set delay start value

	while (1) {

		digital_write(LED_PIN, HIGH);	// Set the LED port bit to "1" - LED will be turned on.
		usleep(delay);			// Wait a little. The delay function simply does N-number of "empty" loops.
		digital_write(LED_PIN, LOW);	// Set the LED port bit to "0" - LED will be turned off.
		usleep(DELAY_MAX-delay);	// Wait a little, again

		if (fade_type == FADE_IN) {
			delay++;
			if (delay >= DELAY_MAX - 1) {
				fade_type = FADE_OUT;
			}
		} else {
      			delay--;
      			if (delay <= DELAY_MIN) {
				fade_type = FADE_IN;
				sleep(200);
			}
    		}
	}
}
