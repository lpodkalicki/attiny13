# --
# Copyright (c) 2015 by Lukasz Marcin Podkalicki <lukasz@podkalicki.com>
#
# Makfile
# --

include ../example.in

LIB_SRC = \
	${LIB_DIR}/attiny13.c \
	${LIB_DIR}/attiny13_digital.c \
	${LIB_DIR}/attiny13_analog.c \
	${LIB_DIR}/attiny13_timer.c

EXAMPLE_SRC = \
	main.c 
	
all:
	${CC} ${CFLAGS} -o main.o ${EXAMPLE_SRC} ${LIB_SRC}
	${OBJCOPY} -j .text -j .data -O ihex main.o main.hex	

flash:
	${AVRDUDE} -p ${MCU} -c usbasp -U flash:w:main.hex:i -F -P usb

clean:
	rm -f *.o *.hex
