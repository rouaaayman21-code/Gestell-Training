#include <stdio.h>

int main() {
int num1;
int num2;

//input numbers
printf("Enter any two numbers: ");
scanf("%d %d", &num1, &num2);

//Original numbers
printf("Original value of num1 = %d\n", num1);
printf("Original value of num2 = %d\n", num2);

//Bitwise operation "XOR"
num1 = num1 ^ num2;
num2 = num1 ^ num2;
num1 = num1 ^ num2;

printf ("Num1 after swapping = %d\n", num1);
printf ("Num2 after swapping = %d\n", num2);
return 0;
}