#include <stdio.h>
int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void printFibonacciSeries(int length) {
    if (length <= 0) {
        printf("Please enter a positive integer.\n");
        return;
    }
    int i;  // Declare the loop variable outside
    for (i = 0; i < length; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printFibonacciSeries(n);
    return 0;
}
