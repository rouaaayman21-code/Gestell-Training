#include <stdio.h>
int main() {
int number;

//Input Number
printf("Enter any number: ");
scanf("%d", &number);

//Bitwise Operation "NOT"
int result=~number;
printf("Original Number= %d (in decimal)\n", number);
printf("Number after bits are flipped = %d (in decimal)\n",result);
return 0;

}