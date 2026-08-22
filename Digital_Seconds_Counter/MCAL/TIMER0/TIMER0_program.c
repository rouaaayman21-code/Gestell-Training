#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"

#include "TIMER0_private.h"
#include "TIMER0_config.h"
#include "TIMER0_interface.h"

void TIMER0_voidInit(void)
{
#if TIMER0_WAVEFORM_GENERATION_MODE == TIMER0_NORMAL_MODE
    /* Select Normal Mode (WGM00 = 0, WGM01 = 0) */
    CLR_BIT(TCCR0_REG, 6);
    CLR_BIT(TCCR0_REG, 3);
#endif
}

void TIMER0_voidSetDelayMs(uint32_t copy_u32DelayMs)
{
    uint32_t local_u32RequiredOverflows = (copy_u32DelayMs * 1000UL) / 8192UL;
    uint32_t local_u32Counter = 0;

    /* Start Timer with Prescaler 256 */
    TCCR0_REG &= 0xF8;
    TCCR0_REG |= TIMER0_PRESCALER_256;

    while (local_u32Counter < local_u32RequiredOverflows)
    {
        /* Wait for Overflow Flag */
        while (GET_BIT(TIFR_REG, 0) == 0);

        /* Clear Overflow Flag */
        SET_BIT(TIFR_REG, 0);

        local_u32Counter++;
    }

    /* Stop Timer */
    TCCR0_REG &= 0xF8;
}