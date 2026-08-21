#ifndef F_CPU
#define F_CPU 8000000UL
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

    s16 local_s16Brightness = 0; // تغيير النوع لـ s16

    while (1)
    {
        for (local_s16Brightness = 0; local_s16Brightness <= 255; local_s16Brightness += 5)
        {
            TIMER0_voidSetCompareMatchValue((u8)local_s16Brightness);
            _delay_ms(15);
        }

        for (local_s16Brightness = 255; local_s16Brightness >= 0; local_s16Brightness -= 5)
        {
            TIMER0_voidSetCompareMatchValue((u8)local_s16Brightness);
            _delay_ms(15);
        }
    }

    return 0;
}