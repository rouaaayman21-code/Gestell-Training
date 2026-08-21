#include "../../LIB/STD_Types.h"
#include "../../LIB/Bit_Math.h"

#define SREG_REG   *((volatile uint8_t*)0x5F)

void GIE_voidEnable(void)
{
    SET_BIT(SREG_REG, 7);
}

void GIE_voidDisable(void)
{
    CLR_BIT(SREG_REG, 7);
}