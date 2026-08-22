#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#include "../../LIB/STD_Types.h"

void TIMER0_voidInit(void);
void TIMER0_voidSetDutyCycle(uint8_t copy_u8DutyCycle);
void TIMER0_voidSetCallBack(void (*Copy_pvCallBackFunc)(void));

#endif