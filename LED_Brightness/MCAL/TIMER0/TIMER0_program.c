#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"

#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"

void TIMER0_voidInit(void)
{
#if TIMER0WAVEFORM_GENERATION_MODE == TIMER0_FAST_PWM_MODE
    SET_BIT(TCCR0_REG, WGM00);
    SET_BIT(TCCR0_REG, WGM01);

    #if TIMER0_OC0_MODE == TIMER0_OC0_NON_INVERTING
    CLR_BIT(TCCR0_REG, COM00);
    SET_BIT(TCCR0_REG, COM01);

    #elif TIMER0_OC0_MODE == TIMER0_OC0_INVERTING
    SET_BIT(TCCR0_REG, COM00);
    SET_BIT(TCCR0_REG, COM01);
    #endif

    TCCR0_REG &= 0XF8;
    TCCR0_REG |= TIMER0_PRESCALER;
#endif
}

void TIMER0_voidSetCompareMatchValue(uint8_t Copy_u8CompareValue)
{
    OCR0_REG = Copy_u8CompareValue;
}