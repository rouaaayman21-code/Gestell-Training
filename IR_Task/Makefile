# Microcontroller Configurations
MCU = atmega32
F_CPU = 8000000UL
CC = avr-gcc
OBJCOPY = avr-objcopy

# Compiler Flags
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -O2 -Wall -ILIB -IMCAL/DIO

# Project Name
TARGET = main

# Source Files
SRCS = main.c MCAL/DIO/DIO_program.c

# Object Files
OBJS = $(SRCS:.c=.o)

# Default Rule
all: $(TARGET).hex

# Compile C files to Object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link Object files to ELF
$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

# Generate HEX file
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

# Clean Build Artifacts
clean:
	rm -f $(OBJS) $(TARGET).elf $(TARGET).hex