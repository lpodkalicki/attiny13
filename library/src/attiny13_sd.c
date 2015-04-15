/**
 * Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
 * Attiny13 - software SPI
 */

#include "attiny13_sd.h"
#include "attiny13_spi.h"
#include "attiny13_sleep.h"
#include "attiny13_uart.h"

unsigned long sd_sector;
unsigned short sd_pos;

int8_t
sd_init(void)
{
	uint8_t i;
	
	spi_init();
	
	sleep(100);
	
	spi_cs_disable();
	for(i=0; i<10; i++) // idle for 1 bytes / 80 clocks
		spi_transfer(0xFF);
	
	//uart_puts("X1\n");
	
	// [0x40 0x00 0x00 0x00 0x00 0x95 r:8] until we get "1"
	for(i=0; i<10 && sd_command(0x40, 0x00000000, 0x95, 8) != 1; i++)
		sleep(100);

	//uart_puts("X2\n");
	
	if(i == 10) // card did not respond to initialization
		return -1;
	
	//uart_puts("X3\n");
	
	// CMD1 until card comes out of idle, but maximum of 10 times
	for(i=0; i<10 && sd_command(0x41, 0x00000000, 0xFF, 8) != 0; i++)
		sleep(100);

	//uart_puts("X4\n");
	
	
	if(i == 10) // card did not come out of idle
		return -2;
	
	// SET_BLOCKLEN to 512
	sd_command(0x50, 0x00000200, 0xFF, 8);

	sd_sector = sd_pos = 0;
	
	return (0);
}

int8_t
sd_command(uint8_t cmd, unsigned long arg, uint8_t crc, uint8_t read)
{
	uint8_t i, buffer[8], retval = 0xFF;
	
	uart_puts("CMD ");
	uart_puth(cmd);
	
	spi_cs_enable();
	spi_transfer(cmd);
	spi_transfer(arg>>24);
	spi_transfer(arg>>16);
	spi_transfer(arg>>8);
	spi_transfer(arg);
	spi_transfer(crc);
	
	for(i = 0; i < read; ++i)
		buffer[i] = spi_transfer(0xFF);

	spi_cs_disable();
	
	for(i=0; i<read; i++) {
		uart_putc(' ');
		uart_puth(buffer[i]);
		if(buffer[i] != 0xFF)
			retval = buffer[i];
	}
	
	uart_putc('\n');
	
	return retval;
}


