MCU = atmega32
F_CPU = 8000000UL

CC = avr-gcc
OBJCOPY = avr-objcopy

CFLAGS = -Wall -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU) -I. -IMCAL/DIO -ILIB

SRCS = main.c MCAL/DIO/DIO_program.c
OBJS = $(SRCS:.c=.o)

all: main.hex

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

main.elf: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main.elf

main.hex: main.elf
	$(OBJCOPY) -O ihex -R .eeprom main.elf main.hex

clean:
	rm -f $(OBJS) main.elf main.hex