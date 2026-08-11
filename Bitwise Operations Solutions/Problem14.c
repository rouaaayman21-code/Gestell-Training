#include <stdio.h>

int main() {
    int number;

    // Input number
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("Converted binary: ");

    // Bitwise operation
    for (int i = 31; i >= 0; i--) {
        int result = (number >> i) & 1;
        printf("%d", result);
    }

    return 0;
}