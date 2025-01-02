#include <stdio.h>
#include <math.h>
int isArmstrong(int number) {
    int originalNumber, remainder, result = 0, n = 0;

    originalNumber = number;
    
    while (originalNumber != 0) {
        originalNumber /= 10;
        n++;
    }
    originalNumber = number;

    while (originalNumber != 0) {
        remainder = originalNumber % 10;
        result += pow(remainder, n);
        originalNumber /= 10;
    }
    return (result == number);
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isArmstrong(num)) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }
    return 0;
}
