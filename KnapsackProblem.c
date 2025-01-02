#include <stdio.h>
typedef struct {
    int value;
    int weight;
    float ratio;
} Item;

void knapsack(Item items[], int n, int W) {
    int i, j;
    float maxValue = 0.0;
    for (i = 0; i < n; i++) {
        items[i].ratio = (float) items[i].value / items[i].weight;
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (W == 0) break;  
        
        if (items[i].weight <= W) {
            maxValue += items[i].value;
            W -= items[i].weight;
        } else {
            maxValue += items[i].value * ((float)W / items[i].weight);
            W = 0; 
        }
    }

    printf("Maximum value in Knapsack = %.2f\n", maxValue);
}

int main() {
    int n, W, i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    Item items[n];

    printf("Enter value and weight for each item:\n");
    for (i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    knapsack(items, n, W);

    return 0;
}
