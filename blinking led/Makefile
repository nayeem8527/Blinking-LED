CC=avr-gcc
CFLAGS=-Wall -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU)
MCU=atmega328p
F_CPU=16000000UL

OBJCOPY=avr-objcopy
BIN_FORMAT=ihex

PORT=/dev/ttyACM0
BAUD=9600
PROTOCOL=stk500v1
PART=atmega328p
AVRDUDE=avrdude -F -V

RM=rm -f

all: blink.hex
	sudo $(AVRDUDE) -c $(PROTOCOL) -p $(PART) -P $(PORT) $(BAUD) -U flash:w:$<

compile: blink.hex

blink.hex: blink.elf 
	 $(OBJCOPY) -O $(BIN_FORMAT) -R .eeprom $< $@

blink.elf: blink.s 
	 $(CC) $(CFLAGS) -s -o $@ $<

blink.s: blink.c 
	 $(CC) $(CFLAGS) -S -o $@ $<

upload : 
	sudo $(AVRDUDE) -c $(PROTOCOL) -p $(PART) -P $(PORT) $(BAUD) -U flash:w:blink.hex

clean:
	$(RM) blink.elf blink.hex blink.s blink.out


