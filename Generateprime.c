#include <stdio.h>
#include <stdbool.h>
void generatePrimes(int n) {
    bool prime[n + 1];
    int i, j;
    
    for (i = 0; i <= n; i++) {
        prime[i] = true;
    }
    
    prime[0] = prime[1] = false; 

    for (i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    
    printf("Prime numbers up to %d are:\n", n);
    for (i = 2; i <= n; i++) {
        if (prime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the upper limit: ");
    scanf("%d", &n);
    
    generatePrimes(n);

    return 0;
}
