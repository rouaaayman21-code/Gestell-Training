#include <stdio.h>
int main() {
int number;
int zeros=0;
int ones=0;

//Input Number
printf("Enter any number: ");
scanf("%d", &number);

//Iterate Bits
for (int i=0;i<32;i++){
    if ((number>>i)&1){
        ones++;
    }
    else{
        zeros++;
    }
}
printf("Total zero bit is %d \n",zeros);
printf("Total one bit is %d\n ", ones);
return 0;

}