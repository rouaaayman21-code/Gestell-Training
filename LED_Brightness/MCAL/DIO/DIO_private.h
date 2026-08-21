#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

//PortA Registers
#define PORTA_REG  *((volatile uint8_t*)0x3B)
#define DDRA_REG   *((volatile uint8_t*)0x3A)
#define PINA_REG   *((volatile uint8_t*)0x39)

//PortB Registers
#define PORTB_REG  *((volatile uint8_t*)0x38)
#define DDRB_REG   *((volatile uint8_t*)0x37)
#define PINB_REG   *((volatile uint8_t*)0x36)

//PortC Registers
#define PORTC_REG  *((volatile uint8_t*)0x35)
#define DDRC_REG   *((volatile uint8_t*)0x34)
#define PINC_REG   *((volatile uint8_t*)0x33)

//PortD Registers
#define PORTD_REG  *((volatile uint8_t*)0x32)
#define DDRD_REG   *((volatile uint8_t*)0x31)
#define PIND_REG   *((volatile uint8_t*)0x30)


#endif 