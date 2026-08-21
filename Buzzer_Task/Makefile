MCU = atmega32
F_CPU = 8000000UL
CC = avr-gcc
OBJCOPY = avr-objcopy

# إضافة -ILIB تخلي الـ compiler يشوف فولدر LIB على طول
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -O2 -Wall -ILIB

SRCS = main.c \
       MCAL/DIO/DIO_program.c \
       MCAL/TIMER0/TIMER0_program.c \
       MCAL/GIE/GIE_program.c

TARGET = main

all: $(TARGET).hex

$(TARGET).elf: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET).elf

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $(TARGET).elf $(TARGET).hex

clean:
	rm -f $(TARGET).elf $(TARGET).hex