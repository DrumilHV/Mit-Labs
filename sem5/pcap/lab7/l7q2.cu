#include <stdio.h>
#include <stdlib.h>

// Define matrix dimensions
#define N 4
#define M 4
#define K 4

// CUDA kernel for matrix multiplication where each row is computed by one thread
__global__ void matrixMultRow(float *a, float *b, float *c) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < N && col < M) {
        float sum = 0.0f;
        for (int k = 0; k < K; k++) {
            sum += a[row * K + k] * b[k * M + col];
        }
        c[row * M + col] = sum;
    }
}

// CUDA kernel for matrix multiplication where each column is computed by one thread
__global__ void matrixMultColumn(float *a, float *b, float *c) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < N && col < M) {
        float sum = 0.0f;
        for (int k = 0; k < K; k++) {
            sum += a[row * K + k] * b[k * M + col];
        }
        c[row * M + col] = sum;
    }
}

// CUDA kernel for matrix multiplication where each element is computed by one thread
__global__ void matrixMultElement(float *a, float *b, float *c) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < N && col < M) {
        float sum = 0.0f;
        for (int k = 0; k < K; k++) {
            sum += a[row * K + k] * b[k * M + col];
        }
        c[row * M + col] = sum;
    }
}

int main() {
    float *h_a, *h_b, *h_c; // Host matrices
    float *d_a, *d_b, *d_c; // Device matrices

    // Allocate memory on the host
    h_a = (float *)malloc(N * K * sizeof(float));
    h_b = (float *)malloc(K * M * sizeof(float));
    h_c = (float *)malloc(N * M * sizeof(float));

    // Initialize host matrices
    for (int i = 0; i < N * K; i++) {
        h_a[i] = 1.0f;
    }
    for (int i = 0; i < K * M; i++) {
        h_b[i] = 2.0f;
    }

    // Allocate memory on the device
    cudaMalloc((void **)&d_a, N * K * sizeof(float));
    cudaMalloc((void **)&d_b, K * M * sizeof(float));
    cudaMalloc((void **)&d_c, N * M * sizeof(float));

    // Copy host matrices to device
    cudaMemcpy(d_a, h_a, N * K * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, K * M * sizeof(float), cudaMemcpyHostToDevice);

    // Define thread and block dimensions
    dim3 threadsPerBlock(16, 16);
    dim3 numBlocks((M + 15) / 16, (N + 15) / 16);

    // Launch kernels
    matrixMultRow<<<numBlocks, threadsPerBlock>>>(d_a, d_b, d_c);
    //matrixMultColumn<<<numBlocks, threadsPerBlock>>>(d_a, d_b, d_c);
    //matrixMultElement<<<numBlocks, threadsPerBlock>>>(d_a, d_b, d_c);

    // Copy the result back to the host
    cudaMemcpy(h_c, d_c, N * M * sizeof(float), cudaMemcpyDeviceToHost);

    // Print the result
    printf("Result of Matrix Multiplication:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%.2f\t", h_c[i * M + j]);
        }
        printf("\n");
    }

    // Free device and host memory
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
    free(h_a);
    free(h_b);
    free(h_c);

    return 0;
}
