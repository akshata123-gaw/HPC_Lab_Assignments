// #include <stdio.h>
// #include <omp.h>
// #include<time.h>

// #define N 100 // Size of matrices

// void sumLowerTriangularMatrices(int A[][N], int B[][N], int result[][N]) {
//     #pragma omp num_threads(N*(N+1)/2)
//     #pragma omp parallel for 
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j <= i; j++) {
//             if(j<i) result[i][j] = A[i][j] + B[i][j];
//         }
//     }
// }

// void initiate(int A[][N]) {
//     #pragma omp num_threads(N*(N+1)/2)
//     #pragma omp parallel for 
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j <= i; j++) {
//             A[i][j]=i*j;
//         }
//     }
// }


// int main() {
//     double start, end;
//     start = omp_get_wtime();
//     int matrixA[N][N] = {0};

//     initiate(matrixA);
//     int matrixB[N][N] = {0};

// initiate(matrixB);
//     int result[N][N] = {0};

//     sumLowerTriangularMatrices(matrixA, matrixB, result);
//     // printf("Matrix A:\n");
//     // for (int i = 0; i < N; i++) {
//     //     for (int j = 0; j < N; j++) {
//     //         printf("%d ", matrixA[i][j]);
//     //     }
//     //     printf("\n");
//     // }

//     // printf("\nMatrix B:\n");
//     // for (int i = 0; i < N; i++) {
//     //     for (int j = 0; j < N; j++) {
//     //         printf("%d ", matrixB[i][j]);
//     //     }
//     //     printf("\n");
//     // }

//     printf("\nResult Matrix:\n");
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             printf("%d ", result[i][j]);
//         }
//         printf("\n");
//     }
//     end = omp_get_wtime();

//     printf("Time taken: %f", end-start);

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 5  // Size of the matrices

void sumLowerTriangularMatrices(int A[][N], int B[][N], int C[][N]) {
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() {
    int A[N][N], B[N][N], C[N][N];

    // Initialize matrices A and B (assuming lower triangular)
    // For simplicity, we use random values here.
    srand(1234);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    // Sum the matrices using OpenMP
    sumLowerTriangularMatrices(A, B, C);

    // Display the result matrix C (sum of A and B)
    printf("Matrix C (Sum of A and B):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

