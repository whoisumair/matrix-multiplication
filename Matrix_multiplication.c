#include <stdio.h>
#include <stdlib.h>

#define M 1000
#define N 1000
#define P 1000

void matrix_multiply(double A[M][N], double B[N][P], double C[M][P]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            C[i][j] = 0.0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    double A[M][N], B[N][P], C[M][P];

    // Initialize matrices A and B with some values
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = (double)rand() / RAND_MAX;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            B[i][j] = (double)rand() / RAND_MAX;
        }
    }

    matrix_multiply(A, B, C);

    printf("Matrix multiplication completed.\n");
    return 0;
}