#include <stdio.h>
#include <stdlib.h>
int sum(int freq[], int i, int j) {
    int total = 0;
    int k;
    for (k = i; k <= j; k++) {
        total += freq[k];
    }
    return total;
}
int optimalSearchTree(int keys[], int freq[], int n) {
    int cost[n][n];
    int i, j, r, len;
    for (i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }
    
    for (len = 2; len <= n; len++) {
        for (i = 0; i < n - len + 1; i++) {
            j = i + len - 1;
            cost[i][j] = 2147483647;
            for (r = i; r <= j; r++) {
                int leftCost = (r > i) ? cost[i][r-1] : 0;
                int rightCost = (r < j) ? cost[r+1][j] : 0;
                int currentCost = leftCost + rightCost + sum(freq, i, j);
                if (currentCost < cost[i][j]) {
                    cost[i][j] = currentCost;
                }
            }
        }
    }
    
    return cost[0][n-1];
}
int main() {
    int n;
    scanf("%d", &n);
    
    int keys[n], freq[n];
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }
    
    for (i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }
    
    int result = optimalSearchTree(keys, freq, n);
    printf("%d\n", result);
    
    return 0;
}
