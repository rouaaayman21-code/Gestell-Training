#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#define TCCR0_REG   *((volatile uint8_t*)0x53)
#define TCNT0_REG   *((volatile uint8_t*)0x52)
#define OCR0_REG    *((volatile uint8_t*)0x5C)
#define TIMSK_REG   *((volatile uint8_t*)0x59)
#define TIFR_REG    *((volatile uint8_t*)0x58)

#define CS00         0
#define CS01         1
#define CS02         2
#define WGM01        3
#define COM00        4
#define COM01        5
#define WGM00        6

#define TIMER0_NORMAL_MODE            1
#define TIMER0_PWM_PHASE_CORRECT_MODE 2
#define TIMER0_CTC_MODE               3
#define TIMER0_FAST_PWM_MODE          4

#define TIMER0_OC0_DISCONNECTED       1
#define TIMER0_OC0_NON_INVERTING      2
#define TIMER0_OC0_INVERTING          3

/* القيم الحقيقية للـ Prescaler Bits في الـ TCCR0 Register */
#define TIMER0_NO_CLOCK               0b00000000
#define TIMER0_PRESCALER_1            0b00000001
#define TIMER0_PRESCALER_8            0b00000010
#define TIMER0_PRESCALER_64           0b00000011
#define TIMER0_PRESCALER_256          0b00000100
#define TIMER0_PRESCALER_1024         0b00000101

#endif