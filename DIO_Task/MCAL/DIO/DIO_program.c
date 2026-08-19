#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidSetPinDirection (uint8_t copy_u8Port, uint8_t copy_u8Pin, uint8_t copy_u8Direction)
{
    if (copy_u8Pin <= DIO_PIN7)
    {
        if (copy_u8Direction == DIO_PIN_OUTPUT)
        {
            switch (copy_u8Port)
            {
                case DIO_PORTA: SET_BIT(DDRA_REG, copy_u8Pin); break;
                case DIO_PORTB: SET_BIT(DDRB_REG, copy_u8Pin); break;
                case DIO_PORTC: SET_BIT(DDRC_REG, copy_u8Pin); break;
                case DIO_PORTD: SET_BIT(DDRD_REG, copy_u8Pin); break;
            }
        }
        else if (copy_u8Direction == DIO_PIN_INPUT)
        {
            switch (copy_u8Port)
            {
                case DIO_PORTA: CLR_BIT(DDRA_REG, copy_u8Pin); break;
                case DIO_PORTB: CLR_BIT(DDRB_REG, copy_u8Pin); break;
                case DIO_PORTC: CLR_BIT(DDRC_REG, copy_u8Pin); break;
                case DIO_PORTD: CLR_BIT(DDRD_REG, copy_u8Pin); break;
            }
        }
    }
}

void DIO_voidSetPinValue(uint8_t copy_u8Port, uint8_t copy_u8Pin, uint8_t copy_u8Value)
{
    if (copy_u8Pin <= DIO_PIN7)
    {
        if (copy_u8Value == DIO_PIN_HIGH)
        {
            switch (copy_u8Port)
            {
                case DIO_PORTA: SET_BIT(PORTA_REG, copy_u8Pin); break;
                case DIO_PORTB: SET_BIT(PORTB_REG, copy_u8Pin); break;
                case DIO_PORTC: SET_BIT(PORTC_REG, copy_u8Pin); break;
                case DIO_PORTD: SET_BIT(PORTD_REG, copy_u8Pin); break;
            }
        }
        else if (copy_u8Value == DIO_PIN_LOW)
        {
            switch (copy_u8Port)
            {
                case DIO_PORTA: CLR_BIT(PORTA_REG, copy_u8Pin); break;
                case DIO_PORTB: CLR_BIT(PORTB_REG, copy_u8Pin); break;
                case DIO_PORTC: CLR_BIT(PORTC_REG, copy_u8Pin); break;
                case DIO_PORTD: CLR_BIT(PORTD_REG, copy_u8Pin); break;
            }
        }
    }
}

void DIO_voidTogglePinValue(uint8_t copy_u8Port, uint8_t copy_u8Pin)
{
    if (copy_u8Pin <= DIO_PIN7)
    {
        switch (copy_u8Port)
        {
            case DIO_PORTA: TGL_BIT(PORTA_REG, copy_u8Pin); break;
            case DIO_PORTB: TGL_BIT(PORTB_REG, copy_u8Pin); break;
            case DIO_PORTC: TGL_BIT(PORTC_REG, copy_u8Pin); break;
            case DIO_PORTD: TGL_BIT(PORTD_REG, copy_u8Pin); break;
        }
    }
}

uint8_t DIO_u8GetPinValue(uint8_t copy_u8Port, uint8_t copy_u8Pin)
{
    uint8_t local_uint8PinVal = DIO_PIN_LOW;
    if (copy_u8Pin <= DIO_PIN7)
    {
        switch (copy_u8Port)
        {
            case DIO_PORTA: local_uint8PinVal = GET_BIT(PINA_REG, copy_u8Pin); break;
            case DIO_PORTB: local_uint8PinVal = GET_BIT(PINB_REG, copy_u8Pin); break;
            case DIO_PORTC: local_uint8PinVal = GET_BIT(PINC_REG, copy_u8Pin); break;
            case DIO_PORTD: local_uint8PinVal = GET_BIT(PIND_REG, copy_u8Pin); break;
        }
    }
    return local_uint8PinVal;
}