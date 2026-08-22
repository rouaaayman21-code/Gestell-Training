# Microcontroller Configuration
MCU = atmega32
F_CPU = 8000000UL
CC = avr-gcc
OBJCOPY = avr-objcopy

# Compiler Flags
CFLAGS = -Wall -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU) -I.

# Source Files
SRCS = main.c \
       MCAL/DIO/DIO_program.c \
       MCAL/TIMER0/TIMER0_program.c

# Object Files
OBJS = $(SRCS:.c=.o)

# Target Name
TARGET = main

all: $(TARGET).hex

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

clean:
	rm -f $(OBJS) $(TARGET).elf $(TARGET).hex