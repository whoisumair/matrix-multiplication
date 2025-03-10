#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define MAX_SIZE 2000  // Max matrix size



// Function to initialize matrix
void initialize_matrix(double A[MAX_SIZE][MAX_SIZE], int N) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            A[i][j] = (i + j) * 0.01;
}

// **Sequential Matrix Multiplication**
void matrix_multiply_sequential(double A[MAX_SIZE][MAX_SIZE], double B[MAX_SIZE][MAX_SIZE], double C[MAX_SIZE][MAX_SIZE], int N) {
    double start = omp_get_wtime();
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

    double end = omp_get_wtime();
    printf("Sequential Matrix Multiplication Time: %.6f sec\n", end - start);
}

int main() {
    int sizes[] = {512, 1024, 2000};  // Test different array sizes

    for (int s = 0; s < 3; s++) {
        int N = sizes[s];
        printf("\nMatrix Size: %d x %d\n", N, N);

        static double A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
        initialize_matrix(A, N);
        initialize_matrix(B, N);

        matrix_multiply_sequential(A, B, C, N);
    }
    
    return 0;
}
