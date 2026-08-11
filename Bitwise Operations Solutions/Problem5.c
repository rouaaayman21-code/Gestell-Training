#include <stdio.h>

int main() {
    int number;
    int order = -1;

    // Input Number
    printf("Enter any number: ");
    scanf("%d", &number);

    // Iterate through bits 
    for (int i = 31; i >= 0; i--) {
        // Check if ith bit is set
        if ((number >> i) & 1) {
            order = i; 
            break; 
        }
    }

    if (order != -1) {
        printf("Highest order set bit in %d is %d\n", number, order);
    } else {
        printf("0 has no set bit\n");
    }

    return 0;
}