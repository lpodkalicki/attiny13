# --
# Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
#
# Makfile
# --

include ../example.in

all:
	${CC} ${CFLAGS} -o main.o main.c
	${OBJCOPY} -j .text -j .data -O ihex main.o main.hex	

flash:
	${AVRDUDE} -p ${MCU} -c usbasp -U flash:w:main.hex:i -F -P usb

clean:
	rm -f *.o *.hex
