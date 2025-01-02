#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n;
int **dist;
int **dp;

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return dist[pos][0];
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }
    int min_dist = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int new_mask = mask | (1 << city);
            int new_dist = dist[pos][city] + tsp(new_mask, city);
            if (new_dist < min_dist) {
                min_dist = new_dist;
            }
        }
    }
    return dp[mask][pos] = min_dist;
}

int main() {
    int i, j; // Declare i and j outside the loops
    scanf("%d", &n);
    dist = (int **)malloc(n * sizeof(int *));
    dp = (int **)malloc((1 << n) * sizeof(int *));
    for (i = 0; i < n; i++) {
        dist[i] = (int *)malloc(n * sizeof(int));
    }
    for (i = 0; i < (1 << n); i++) {
        dp[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }
    printf("%d\n", tsp(1, 0));

    for (i = 0; i < n; i++) {
        free(dist[i]);
    }
    free(dist);
    for (i = 0; i < (1 << n); i++) {
        free(dp[i]);
    }
    free(dp);

    return 0;
}
