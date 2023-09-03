// #include <stdio.h>
// #include <omp.h>
// #include<sys/time.h>

// #define N 200  // Size of matrices

// void matrixMatrixMultiplication(int A[][N], int B[][N], int result[][N]) {
//     #pragma omp parallel for
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             result[i][j] = 0;
//             for (int k = 0; k < N; k++) {
//                 result[i][j] += A[i][k] * B[k][j];
//             }
//         }
//     }
// }

// void initial(int A[][N]){
//     #pragma omp parallel for
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//                 A[i][j] = i+j;
//         }
//     }
// }

// int main() {
//     clock_t start, end;
//     start = clock();
//     int matrixA[N][N] = {0};
// initial(matrixA);
//     int matrixB[N][N] = {0};
// initial(matrixB);
//     int result[N][N] = {0};

//     matrixMatrixMultiplication(matrixA, matrixB, result);

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
//     end = clock();
//     double duration = ((double)end-start)/CLOCKS_PER_SEC;
//     printf("Time Taken: %f",duration);

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 3 // Number of rows in matrices A and C
#define M 4 // Number of columns in matrix A and rows in matrix B
#define P 2 // Number of columns in matrices B and C

void matrixMultiply(int A[N][M], int B[M][P], int C[N][P]) {
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            C[i][j] = 0; // Initialize the result element to 0
            for (int k = 0; k < M; k++) {
                C[i][j] += A[i][k] * B[k][j]; // Matrix multiplication
            }
        }
    }
}

int main() {
    int A[N][M], B[M][P], C[N][P];

    // Initialize matrices A and B with sample values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = i * M + j + 1;
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            B[i][j] = i * P + j + 1;
        }
    }

    // Perform matrix multiplication using OpenMP
    matrixMultiply(A, B, C);

    // Display the result matrix C
    printf("Matrix C (Result of A x B):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

