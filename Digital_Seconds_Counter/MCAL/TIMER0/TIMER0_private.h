#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCCR0_REG    *((volatile uint8_t*)0x53)
#define TCNT0_REG    *((volatile uint8_t*)0x52)
#define TIFR_REG     *((volatile uint8_t*)0x58)

#define TIMER0_NORMAL_MODE                 0
#define TIMER0_CTC_MODE                    1
#define TIMER0_FAST_PWM_MODE               2
#define TIMER0_PHASE_CORRECT_PWM_MODE      3

#define TIMER0_NO_CLOCK                    0
#define TIMER0_PRESCALER_1                 1
#define TIMER0_PRESCALER_8                 2
#define TIMER0_PRESCALER_64                3
#define TIMER0_PRESCALER_256               4
#define TIMER0_PRESCALER_1024              5

#endif