#include <avr/interrupt.h>

#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"

#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "TIMER0_interface.h"

static void (*TIMER0_pvCallBackFunc)(void) = NULL;

void TIMER0_voidInit(void)
{
    /* Select Normal Mode */
    CLR_BIT(TCCR0_REG, 6);
    CLR_BIT(TCCR0_REG, 3);

    /* Clear Timer Counter Register */
    TCNT0_REG = 0;

    /* Enable Overflow Interrupt (TOIE0) */
    SET_BIT(TIMSK_REG, 0);

    /* Set Prescaler Value */
    TCCR0_REG &= 0xF8;
    TCCR0_REG |= TIMER0_PRESCALER;
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