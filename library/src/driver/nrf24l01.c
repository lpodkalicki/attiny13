/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * Attiny13 - software UART
 */

#include "attiny13_spi.h"
#include "attiny13_digital.h"
#include "driver/nrf24l01.h"

#define	csn_low()	digital_write(SPI_CS, LOW);
#define	csn_high()	digital_write(SPI_CS, HIGH);

static void
transfer_sync(uint8_t *dataout, uint8_t *datain, uint8_t len)
{
	uint8_t i;
	for(i = 0;i < len;i++){
		datain[i] = spi_transfer(dataout[i]);
	}
}

static void
transmit_sync(uint8_t *dataout, uint8_t len)
{
	uint8_t i;
	for(i = 0;i < len;i++){
		spi_transfer(dataout[i]);
	}
}

/**
 * Reads an array of bytes from the given start position in the MiRF registers.
 */
static void
read_register(uint8_t reg, uint8_t *value, uint8_t len)
{
	csn_low();
	spi_transfer(R_REGISTER | (REGISTER_MASK & reg));
	transfer_sync(value, value, len);
	csn_high();
}

/**
 * Writes an array of bytes into inte the MiRF registers.
 */
static void
write_register(uint8_t reg, uint8_t *value, uint8_t len)
{
	csn_low();
	spi_transfer(W_REGISTER | (REGISTER_MASK & reg));
	transmit_sync(value, len);
	csn_high();
}

/**
 * Clocks only one byte into the given MiRF register
 */
static void
config_register(uint8_t reg, uint8_t value) 
{
	csn_low();
	spi_transfer(W_REGISTER | (REGISTER_MASK & reg));
	spi_transfer(value);
	csn_high();
}

void
NRF24L01_init(void)
{
	pin_mode(SPI_CS, OUTPUT);
	csn_high();
	spi_init();
}

void
NRF24L01_config(void)
{
	config_register(RF_CH, 0x55);
	config_register(RF_SETUP, 0x07);
	
	csn_low();
	spi_transfer(FLUSH_RX);
	csn_high();
}

uint8_t
NRF24L01_get_status(void)
{
	uint8_t retval = 0;
	read_register(STATUS, &retval, 1);
	return retval;
}

/**
 * Sends a data package to the default address. Be sure to send the correct
 * amount of bytes as configured as payload on the receiver.
 */
void
NRF24L01_send(uint8_t *value)
{
	uint8_t status;
	status = NRF24L01_get_status();
	while (PTX) {
		status = getStatus();
		if ((status & ((1 << TX_DS) | (1 << MAX_RT)))) {
			PTX = 0;
			break;
		}
	} // Wait until last paket is send
	
	//ce_low();
	power_up_tx(); // Set to transmitter mode , Power up
	csn_low(); // Pull down chip select
	spi_transfer(FLUSH_TX); // Write cmd to flush tx fifo
	csn_high(); // 
	';;//////////////
	';;;;;;;;;;;;;;;;;;;/Pull up chip select
	
	csn_low(); // Pull down chip select
	spi_transfer(W_TX_PAYLOAD); // Write cmd to write payload
	transmitSync(value, payload); // Write payload
	csn_high(); // Pull up chip select
	//ce_high(); // Start transmission
}