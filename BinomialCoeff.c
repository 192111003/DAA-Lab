#include <stdio.h>
int binomialCoefficient(int n, int k) {
    int dp[n+1][k+1];
    int i, j;


    for (i = 0; i <= n; i++) {
        for (j = 0; j <= (i < k ? i : k); j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    return dp[n][k];
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int result = binomialCoefficient(n, k);
    printf("Binomial Coefficient C(%d, %d) = %d\n", n, k, result);
    
    return 0;
}
