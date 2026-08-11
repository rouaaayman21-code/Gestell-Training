#include <stdio.h>
int main ()
{
int number;
int position;
//Input Number
printf("Enter any number: ");
scanf("%d", &number);

//Position
printf("Enter nth bit to clear (0-31): ");
scanf("%d", &position);

//Shifting the bit to left 
int shiftedbit= 1<<position;

//Bitwise operation "AND" with the complement
int result= number&(~shiftedbit);
printf("Bit cleared successfully.\n");
printf("Number before clearing %d bit: %d (in decimal)\n", position, number);
printf("Number after clearing %d bit: %d (in decimal)\n", position, result);
return 0;
}