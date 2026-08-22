#include "LIB/STD_Types.h"
#include "LIB/Bit_Math.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER0/TIMER0_interface.h"

/* Common Cathode 7-Segment Patterns (0 to 9) */
static const uint8_t Ku8SevenSegNumbers[10] = {
    0x3F, /* 0 */
    0x06, /* 1 */
    0x5B, /* 2 */
    0x4F, /* 3 */
    0x66, /* 4 */
    0x6D, /* 5 */
    0x7D, /* 6 */
    0x07, /* 7 */
    0x7F, /* 8 */
    0x6F  /* 9 */
};

int main(void)
{
    uint8_t local_u8Counter = 0;

    /* Set PORTC Pins (PC0 to PC6) as Output */
    for (uint8_t pin = 0; pin < 7; pin++)
    {
        DIO_voidSetPinDirection(DIO_PORTC, pin, DIO_PIN_OUTPUT);
    }

    /* Initialize Timer0 */
    TIMER0_voidInit();

    while (1)
    {
        /* Display Current Second */
        for (uint8_t pin = 0; pin < 7; pin++)
        {
            DIO_voidSetPinValue(DIO_PORTC, pin, GET_BIT(Ku8SevenSegNumbers[local_u8Counter], pin));
        }

        /* Wait 1 Second using Timer0 */
        TIMER0_voidSetDelayMs(1000);

        /* Increment Second Counter (0 -> 9) */
        local_u8Counter++;
        if (local_u8Counter > 9)
        {
            local_u8Counter = 0;
        }
    }

    return 0;
}