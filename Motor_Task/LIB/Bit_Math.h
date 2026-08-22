#ifndef Bit_Math_H
#define Bit_Math_H

#define SET_BIT(REG, BIT)    ((REG) |=  (1 << (BIT)))
#define CLR_BIT(REG, BIT)    ((REG) &= ~(1 << (BIT)))
#define TGL_BIT(REG, BIT)    ((REG) ^=  (1 << (BIT)))
#define GET_BIT(REG, BIT)    (((REG) >> (BIT)) & 1)

#endif //Bit_Math_H
