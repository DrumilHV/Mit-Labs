#include <stdio.h>

#define N 4  // Matrix size (N x N)

__global__ void matrixMul(int* A, int* B, int* C) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    int sum = 0;
    for (int k = 0; k < N; k++) {
        sum += A[row * N + k] * B[k * N + col];
    }

    C[row * N + col] = sum;
}

int main() {
    int A[N][N], B[N][N], C[N][N];
    int *d_A, *d_B, *d_C;

    // Initialize matrices A and B and allocate memory on the device
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i * N + j;
            B[i][j] = j * N + i;
        }
    }

    cudaMalloc((void**)&d_A, N * N * sizeof(int));
    cudaMalloc((void**)&d_B, N * N * sizeof(int));
    cudaMalloc((void**)&d_C, N * N * sizeof(int));

    // Copy matrices A and B to the device
    cudaMemcpy(d_A, A, N * N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, N * N * sizeof(int), cudaMemcpyHostToDevice);

    // Define grid and block dimensions
    dim3 dimGrid(N, N); // 2D grid
    dim3 dimBlock(1, 1); // 2D block

    // Launch the matrix multiplication kernel
    matrixMul<<<dimGrid, dimBlock>>>(d_A, d_B, d_C);

    // Copy the result matrix C back to the host
    cudaMemcpy(C, d_C, N * N * sizeof(int), cudaMemcpyDeviceToHost);

    // Print the result matrix C
    printf("Result Matrix C:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Free device memory
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return 0;
}
