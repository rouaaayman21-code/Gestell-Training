#include "LIB/STD_Types.h"
#include "LIB/Bit_Math.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include <util/delay.h>

int main (void)
{
    DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT);
    DIO_voidSetPinDirection(DIO_PORTA, DIO_PIN1, DIO_PIN_OUTPUT);
//Forward
    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN0, DIO_PIN_HIGH);
    DIO_voidSetPinValue(DIO_PORTA, DIO_PIN1, DIO_PIN_LOW);

    TIMER0_voidInit();
    while(1)
    {
        for (uint8_t speed = 0 ; speed<=100; speed+=20)
        {
            TIMER0_voidSetDutyCycle(speed);
            _delay_ms(1000);
        }
        for (uint8_t speed = 100 ; speed>=0; speed-=20)
        {
            TIMER0_voidSetDutyCycle(speed);
            _delay_ms(1000);
        }
    }
    return 0;
}