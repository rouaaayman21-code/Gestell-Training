#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "../../LIB/STD_Types.h"

//Port Options
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

//Pin Options
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

//Direction Options
#define DIO_PIN_INPUT 0
#define DIO_PIN_OUTPUT 1

//Value Options
#define DIO_PIN_LOW 0
#define DIO_PIN_HIGH 1


//Function Prototypes
void DIO_voidSetPinDirection (uint8_t copy_u8Port, uint8_t copy_u8Pin, uint8_t copy_u8Direction); 
void DIO_voidSetPinValue (uint8_t copy_u8Port, uint8_t copy_u8Pin, uint8_t copy_u8Value); 
void DIO_voidTogglePinValue (uint8_t copy_u8Port, uint8_t copy_u8Pin);
uint8_t DIO_uint8GetPinValue(uint8_t copy_u8Port, uint8_t copy_u8Pin);

#endif
