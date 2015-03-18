all:
	avr-gcc -std=c99 -Wall -g -Os -mmcu=attiny13 -o main.o main.c
	avr-objcopy -j .text -j .data -O ihex main.o main.hex	

flash:
	sudo avrdude -c usbasp -p t13 -F
	sudo avrdude -p attiny13 -c usbasp -U flash:w:main.hex:i -F -P usb

clean:
	rm -f *.o *.hex
