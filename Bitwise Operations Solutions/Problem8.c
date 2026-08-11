#include <stdio.h>
int main()
{
int number;
int count = 0;
 
//Input Number
printf("Enter any number: ");
scanf("%d", &number);

//Iterate bits 
for(int i=31; i>=0; i--){
    //Stop if current bit=1
    if ((number>>i)&1){
        break;
    }
    count++;
}
printf("Number of leading zeros in %d is %d\n", number, count);
return 0;
}
