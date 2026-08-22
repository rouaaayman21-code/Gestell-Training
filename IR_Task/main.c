#include "LIB/STD_Types.h"
#include "LIB/Bit_Math.h"
#include "MCAL/DIO/DIO_interface.h"

//Pin Assignment
#define IR_SENSOR_PORT   DIO_PORTA
#define IR_SENSOR_PIN    DIO_PIN0

#define LED_PORT         DIO_PORTB
#define LED_PIN          DIO_PIN0


int main(void)
{
    uint8_t local_u8IRState = DIO_PIN_HIGH;
    DIO_voidSetPinDirection(IR_SENSOR_PORT, IR_SENSOR_PIN, DIO_PIN_INPUT);
    
    DIO_voidSetPinDirection(LED_PORT, LED_PIN, DIO_PIN_OUTPUT);
    DIO_voidSetPinValue(LED_PORT, LED_PIN, DIO_PIN_LOW);

    while(1)
    {
        local_u8IRState = DIO_uint8GetPinValue(IR_SENSOR_PORT, IR_SENSOR_PIN);
        if (local_u8IRState == DIO_PIN_LOW)
        {
            DIO_voidSetPinValue(LED_PORT, LED_PIN, DIO_PIN_HIGH); 
        }
        else
        {
            DIO_voidSetPinValue(LED_PORT, LED_PIN, DIO_PIN_LOW);  
        }
    }
return 0;
}