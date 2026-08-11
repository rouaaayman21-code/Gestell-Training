#include <stdio.h>
int main(){
int number;

//Input Number
printf("Enter any number: ");
scanf("%d", &number);

//Bitwise Operation "AND"
int result = number & 1;
if (result == 1) {
    printf("%d is odd.\n", number);
} 
else {
    printf("%d is even.\n", number);
}
return 0;
}