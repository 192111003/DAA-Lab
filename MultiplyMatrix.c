#include <stdio.h>

void multiplyMatrices(int first[][10], int second[][10], int result[][10], int rowFirst, int colFirst, int rowSecond, int colSecond) {
    int i, j, k;
    if (colFirst != rowSecond) {
        printf("Matrix multiplication is not possible.\n");
        return;
    }
    for (i = 0; i < rowFirst; i++) {
        for (j = 0; j < colSecond; j++) {
            result[i][j] = 0;
        }
    }
    for (i = 0; i < rowFirst; i++) {
        for (j = 0; j < colSecond; j++) {
            for (k = 0; k < colFirst; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

void printMatrix(int matrix[][10], int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int first[10][10], second[10][10], result[10][10];
    int rowFirst, colFirst, rowSecond, colSecond;
    int i, j;
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rowFirst, &colFirst);
    printf("Enter the elements of the first matrix:\n");
    for (i = 0; i < rowFirst; i++) {
        for (j = 0; j < colFirst; j++) {
            scanf("%d", &first[i][j]);
        }
    }

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rowSecond, &colSecond);

    printf("Enter the elements of the second matrix:\n");
    for (i = 0; i < rowSecond; i++) {
        for (j = 0; j < colSecond; j++) {
            scanf("%d", &second[i][j]);
        }
    }

    multiplyMatrices(first, second, result, rowFirst, colFirst, rowSecond, colSecond);
    printf("Resultant Matrix:\n");
    printMatrix(result, rowFirst, colSecond);

    return 0;
}
