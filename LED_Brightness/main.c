#ifndef F_CPU
#define F_CPU 8000000UL // 8 MHz
#endif
#include <util/delay.h>

#include "LIB/STD_Types.h"
#include "LIB/Bit_Math.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER0/TIMER0_interface.h"

int main(void)
{
    DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);

    
    TIMER0_voidInit();

    u8 local_u8Brightness = 0;

    while (1)
    {
        
        for (local_u8Brightness = 0; local_u8Brightness < 255; local_u8Brightness++)
        {
            TIMER0_voidSetCompareMatchValue(local_u8Brightness);
            _delay_ms(5);
        }

        for (local_u8Brightness = 255; local_u8Brightness > 0; local_u8Brightness--)
        {
            TIMER0_voidSetCompareMatchValue(local_u8Brightness);
            _delay_ms(5);
        }
    }
}
