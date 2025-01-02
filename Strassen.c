#include <stdio.h>
void add(int a[2][2], int b[2][2], int result[2][2]) {
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void subtract(int a[2][2], int b[2][2], int result[2][2]) {
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void strassen(int A[2][2], int B[2][2], int result[2][2]) {
    int M1[2][2], M2[2][2], M3[2][2], M4[2][2], M5[2][2], M6[2][2], M7[2][2];
    int A11[2][2], A12[2][2], A21[2][2], A22[2][2];
    int B11[2][2], B12[2][2], B21[2][2], B22[2][2];
    int temp1[2][2], temp2[2][2];
    int i, j;

    A11[0][0] = A[0][0]; A11[0][1] = A[0][1]; A11[1][0] = A[1][0]; A11[1][1] = A[1][1];
    A12[0][0] = A[0][1]; A12[0][1] = A[0][2]; A12[1][0] = A[1][1]; A12[1][1] = A[1][2];
    A21[0][0] = A[2][0]; A21[0][1] = A[2][1]; A21[1][0] = A[3][0]; A21[1][1] = A[3][1];
    A22[0][0] = A[2][2]; A22[0][1] = A[2][3]; A22[1][0] = A[3][2]; A22[1][1] = A[3][3];

    B11[0][0] = B[0][0]; B11[0][1] = B[0][1]; B11[1][0] = B[1][0]; B11[1][1] = B[1][1];
    B12[0][0] = B[0][2]; B12[0][1] = B[0][3]; B12[1][0] = B[1][2]; B12[1][1] = B[1][3];
    B21[0][0] = B[2][0]; B21[0][1] = B[2][1]; B21[1][0] = B[3][0]; B21[1][1] = B[3][1];
    B22[0][0] = B[2][2]; B22[0][1] = B[2][3]; B22[1][0] = B[3][2]; B22[1][1] = B[3][3];

    add(A11, A22, temp1);
    add(B11, B22, temp2);
    strassen(temp1, temp2, M1);

    add(A21, A22, temp1);
    strassen(temp1, B11, M2);

    subtract(B12, B22, temp2);
    strassen(A11, temp2, M3);

    subtract(B21, B11, temp2);
    strassen(A22, temp2, M4);

    add(A11, A12, temp1);
    strassen(temp1, B22, M5);

    subtract(A21, A11, temp1);
    add(B11, B12, temp2);
    strassen(temp1, temp2, M6);

    subtract(A12, A22, temp1);
    add(B21, B22, temp2);
    strassen(temp1, temp2, M7);
    add(M1, M4, temp1);
    subtract(temp1, M5, temp2);
    add(temp2, M7, result[0][0]);
    add(M3, M5, result[0][1]);
    add(M2, M4, result[1][0]);

    subtract(M1, M2, result[1][1]);
}
void printMatrix(int matrix[2][2]) {
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int A[2][2], B[2][2], result[2][2];
    int i, j;
    printf("Enter elements of matrix A (2x2):\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter elements of matrix B (2x2):\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    strassen(A, B, result);
    printf("Resultant Matrix after Strassen's Matrix Multiplication:\n");
    printMatrix(result);

    return 0;
}
