#include <stdio.h>
int main ()
{
int number;
int position;

//Input Number
printf("Enter any number: ");
scanf("%d", &number);

//Bit Position
printf("Enter nth bit to check (0-31): ");
scanf("%d", &position);

//Shifting the bit to the left
int shiftedbit= 1 << position;

//Bitwise Operation "AND"
int result= number & shiftedbit;
if (result !=0 ){
printf("The %d bit is set to 1\n", position);
    }
else
    {
        printf("The %d bit is set to 0\n", position);
}
return 0;
}