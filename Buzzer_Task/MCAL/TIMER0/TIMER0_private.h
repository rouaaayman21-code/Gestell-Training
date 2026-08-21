#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

/* Register Definitions */
#define TCCR0_REG   *((volatile u8*)0x53)
#define TCNT0_REG   *((volatile u8*)0x52)
#define OCR0_REG    *((volatile u8*)0x5C)
#define TIMSK_REG   *((volatile u8*)0x59)
#define TIFR_REG    *((volatile u8*)0x58)

/* Prescaler Options */
#define TIMER0_NO_CLOCK               0
#define TIMER0_NO_PRESCALER           1
#define TIMER0_PRESCALER_8            2
#define TIMER0_PRESCALER_64           3
#define TIMER0_PRESCALER_256          4
#define TIMER0_PRESCALER_1024         5

#endif