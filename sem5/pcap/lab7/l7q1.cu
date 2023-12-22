#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define matrix dimensions
#define N 4
#define M 4

// CUDA kernel for adding two matrices where each row is computed by one thread
__global__ void addMatricesRow(float *a, float *b, float *c) {
    int row = threadIdx.x;
    for (int col = 0; col < M; col++) {
        int idx = row * M + col;
        c[idx] = a[idx] + b[idx];
    }
}

// CUDA kernel for adding two matrices where each column is computed by one thread
__global__ void addMatricesColumn(float *a, float *b, float *c) {
    int col = threadIdx.x;
    for (int row = 0; row < N; row++) {
        int idx = row * M + col;
        c[idx] = a[idx] + b[idx];
    }
}

// CUDA kernel for adding two matrices where each element is computed by one thread
__global__ void addMatricesElement(float *a, float *b, float *c) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    if (row < N && col < M) {
        int idx = row * M + col;
        c[idx] = a[idx] + b[idx];
    }
}

int main() {
    float *h_a, *h_b, *h_c; // Host matrices
    float *d_a, *d_b, *d_c; // Device matrices

    // Allocate memory on the host
    h_a = (float *)malloc(N * M * sizeof(float));
    h_b = (float *)malloc(N * M * sizeof(float));
    h_c = (float *)malloc(N * M * sizeof(float));

    // Initialize host matrices
    for (int i = 0; i < N * M; i++) {
        // h_a[i] = 1.0f;
        // h_b[i] = 2.0f;
        h_a[i] = rand()%100;
        h_b[i] = rand()%100;
    }
    printf("This is matrix A: \n");
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%.3f ", h_a[i*M +j]);
        }
        printf("\n");
    }
    printf("This is matrix B: \n");
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%.3f ", h_b[i*M +j]);
        }
        printf("\n");
    }

    // Allocate memory on the device
    cudaMalloc((void **)&d_a, N * M * sizeof(float));
    cudaMalloc((void **)&d_b, N * M * sizeof(float));
    cudaMalloc((void **)&d_c, N * M * sizeof(float));

    // Copy host matrices to device
    cudaMemcpy(d_a, h_a, N * M * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, N * M * sizeof(float), cudaMemcpyHostToDevice);

    // Define thread and block dimensions for element-wise addition
    dim3 threadsPerBlock(16, 16);
    dim3 numBlocks((N + 15) / 16, (M + 15) / 16);

    // Launch kernels
    addMatricesRow<<<1, N>>>(d_a, d_b, d_c);
    addMatricesColumn<<<1, M>>>(d_a, d_b, d_c);
    addMatricesElement<<<numBlocks, threadsPerBlock>>>(d_a, d_b, d_c);

    // Copy the result back to the host
    cudaMemcpy(h_c, d_c, N * M * sizeof(float), cudaMemcpyDeviceToHost);

    // Print the result (for the element-wise addition)
    printf("Result of Element-Wise Addition:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%.3f\t", h_c[i * M + j]);
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
