#include <stdio.h>
int main ()
{
int number;
int position;
//Input Number
printf("Enter any number: ");
scanf("%d", &number);

//Position
printf("Enter nth bit to set (0-31): ");
scanf("%d", &position);

//Shifting the bit to left 
int shiftedbit= 1<<position;

//Bitwise operation "OR"
int result= number|shiftedbit;
printf("Bit set successfully.\n");
printf("Number before setting %d bit: %d (in decimal)\n", position, number);
printf("Number after setting %d bit: %d (in decimal)\n", position, result);
return 0;
}