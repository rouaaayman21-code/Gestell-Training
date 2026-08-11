#include <stdio.h>
int main()
{
int number;
int rotation;

//input number
printf("Enter any number: ");
scanf("%d", &number);

//rotation
printf("Enter number of rotation: ");
scanf("%d", &rotation);

//bitwise operation
int LeftRotated = (number << rotation) | (number >> (32 - rotation));
int RightRotated = (number >> rotation) | (number << (32 - rotation));

printf("%d left rotated %d times = %d\n", number, rotation, LeftRotated);
printf("%d right rotated %d times = %d\n", number, rotation, RightRotated);
 
return 0;
}