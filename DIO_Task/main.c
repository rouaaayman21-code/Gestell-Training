#define F_CPU 8000000UL

#ifndef __AVR_ATmega32__
#define __AVR_ATmega32__
#endif

#include <util/delay.h>

#include "STD_Types.h"
#include "Bit_Math.h"
#include "DIO_interface.h"

int main(void)
{
    
    DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT);

    while (1)
    {
        
        DIO_voidTogglePinValue(DIO_PORTA, DIO_PIN0);
        _delay_ms(500);
    }

    return 0;
}