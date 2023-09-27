F_CPU = 16000000UL
DEVICE = atmega32

CC = avr-gcc
CFLAGS = -Wall -Os -g2 -std=gnu99 -mmcu=${DEVICE} -DF_CPU=${F_CPU}
CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums 
CFLAGS += -ffunction-sections -fdata-sections


OBJCOPY= avr-objcopy 

INCLUDES = /usr/lib/avr/include/

compile:
	${CC} ${CFLAGS} -c main.c -o Debug/main.o 
	${CC} ${CFLAGS} -c dio/dio.c -o Debug/dio.o 
	${CC} ${CFLAGS} -c _7seg/_7seg.c -o Debug/_7seg.o 
	${CC} ${CFLAGS} -c button/button.c -o Debug/button.o
	${CC} ${CFLAGS} -c POV_7seg/POV_7seg.c -o Debug/POV_7seg.o 
	${CC} ${CFLAGS} -o Debug/main.elf Debug/dio.o Debug/_7seg.o Debug/main.o Debug/button.o Debug/POV_7seg.o 
	${OBJCOPY} -j .data -j .text -O ihex Debug/main.elf Debug/flash.hex
	clear
	@echo project successfully build 100%.
	@avr-size --format=avr --mcu=atmega32 Debug/main.elf

clean:
	@rm -f Debug/*.bin
	@rm -f Debug/*.elf
	@rm -f Debug/*.o 
	@rm -f Debug/*.hex

compile2:
	@${CC} ${CFLAGS} main.c dio/dio.c APP/app.c lcd/lcd.c keypad/keypad.c adc/adc.prog.c LM45/lm45.c GIE/GIE.c -o Debug/a.elf
	@${OBJCOPY} -j .data -j .text -O ihex Debug/a.elf Debug/flash2.hex