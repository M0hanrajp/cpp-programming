// User function Template for C
#include <stdlib.h>
void transpose(int N, int matrix[][N]) {
    // copy the matrix
    int **matrixC = calloc(N, sizeof(int *));
    for(int i = 0; i < N; i++) {
        *(matrixC + i) = calloc(N, sizeof(int));
        for(int j = 0; j < N; j++) {
            matrixC[i][j] = matrix[i][j];
        }
    }
    // transpose
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            matrix[i][j] = matrixC[j][i];
        }
    }
    // free the allocated memory
    for(int i = 0; i < N; i++) {
        free(matrixC[i]);
    }
    free(matrixC);
    matrixC = NULL;
}
