MCU = atmega32
F_CPU = 8000000UL
CC = avr-gcc
OBJCOPY = avr-objcopy

# إضافة مسارات LIB و MCAL لخيارات الـ Compiler
CFLAGS = -Wall -Os -mmcu=$(MCU) -DF_CPU=$(F_CPU) -I. -ILIB -IMCAL/DIO -IMCAL/TIMER0

TARGET = main

SRCS = $(wildcard *.c) $(wildcard */*.c) $(wildcard */*/*.c)
OBJS = $(SRCS:.c=.o)

all: $(TARGET).hex

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET).elf $(TARGET).hex