#include <stdio.h>
int main() {
int number;

//Input number
printf("Enter any number: ");
scanf("%d", &number);

//Bitwise Operation "AND"
int result = number & 1;
if (result == 1) {
printf("LSB of %d is set (1).\n", number);
    }
else 
    {
        printf("LSB of %d is unset (0).\n", number);
    }
    return 0;
}