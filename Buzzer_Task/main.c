#include "LIB/STD_Types.h"
#include "LIB/Bit_Math.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include "MCAL/GIE/GIE_interface.h"

#define BUZZER_PORT    DIO_PORTC
#define BUZZER_PIN     DIO_PIN6

void Buzzer_Timer_ISR(void);

int main(void)
{
    DIO_voidSetPinDirection(BUZZER_PORT, BUZZER_PIN, DIO_PIN_OUTPUT);
    DIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_PIN_LOW);

    TIMER0_voidSetCallBack(Buzzer_Timer_ISR);
    TIMER0_voidInit();
    GIE_voidEnable();

    while (1)
    {
    }

    return 0;
}

void Buzzer_Timer_ISR(void)
{
    static u16 local_u16Counter = 0;
    local_u16Counter++;

    if (local_u16Counter == 31)
    {
        DIO_voidTogglePinValue(BUZZER_PORT, BUZZER_PIN);
        local_u16Counter = 0;
    }
}