#include <avr/interrupt.h>
#include <stddef.h>

#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"

#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "TIMER0_interface.h"

static void (*TIMER0_pvCallBackFunc)(void) = NULL;

void TIMER0_voidInit(void)
{
#if TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_FAST_PWM_MODE
    /* Set Fast PWM Mode (WGM00 = 1, WGM01 = 1) */
    SET_BIT(TCCR0_REG, 6);
    SET_BIT(TCCR0_REG, 3);

    /* Set Non-Inverting PWM Mode (COM01 = 1, COM00 = 0) */
    SET_BIT(TCCR0_REG, 5);
    CLR_BIT(TCCR0_REG, 4);

#elif TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_NORMAL_MODE
    /* Select Normal Mode */
    CLR_BIT(TCCR0_REG, 6);
    CLR_BIT(TCCR0_REG, 3);

    /* Clear Timer Counter Register */
    TCNT0_REG = 0;

    /* Enable Overflow Interrupt (TOIE0) */
    SET_BIT(TIMSK_REG, 0);
#endif

    /* Set Prescaler Value */
    TCCR0_REG &= 0xF8;
    TCCR0_REG |= TIMER0_PRESCALER;
}

void TIMER0_voidSetDutyCycle(uint8_t copy_u8DutyCycle)
{
    if (copy_u8DutyCycle <= 100)
    {
        /* Convert 0-100% Duty Cycle to 0-255 OCR0 Value */
        OCR0_REG = (uint8_t)(((uint16_t)copy_u8DutyCycle * 255) / 100);
    }
}

void TIMER0_voidSetCallBack(void (*Copy_pvCallBackFunc)(void))
{
    if (Copy_pvCallBackFunc != NULL)
    {
        TIMER0_pvCallBackFunc = Copy_pvCallBackFunc;
    }
}

ISR(TIMER0_OVF_vect)
{
    if (TIMER0_pvCallBackFunc != NULL)
    {
        TIMER0_pvCallBackFunc();
    }
}