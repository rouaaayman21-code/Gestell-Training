#include <stdio.h>

int main() {
    int number;
//Input number
    printf("Enter any number: ");
    scanf("%d", &number);

//MSB Shifting
    int MSB = 1 << 31;
    int result = number & MSB;

//Bitwise Operation "AND"
    if (result != 0) {
        printf("MSB of %d is set (1).\n", number);
    } else {
        printf("MSB of %d is unset (0).\n", number);
    }

    return 0;
}