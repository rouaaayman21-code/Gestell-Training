# Microcontroller Configuration
MCU = atmega32
F_CPU = 8000000UL
CC = avr-gcc
OBJCOPY = avr-objcopy

# Compiler Flags
CFLAGS = -Wall -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU) -I. -ILIB
# Target Project Name
TARGET = main

# Source Files
SRCS = main.c \
       MCAL/DIO/DIO_program.c \
       MCAL/TIMER0/TIMER0_program.c

# Object Files
OBJS = $(SRCS:.c=.o)

# Default Rule: Build Everything
all: $(TARGET).hex

# Link Object Files to Create ELF
$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# Create HEX File from ELF
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

# Pattern Rule for Compiling .c Files to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean Up Generated Files
clean:
	rm -f $(OBJS) $(TARGET).elf $(TARGET).hex

.PHONY: all clean