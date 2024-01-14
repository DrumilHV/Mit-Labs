#include <stdio.h>

__global__ void matrixMul(int* A, int* B, int* C, int m, int n, int k) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < m && col < k) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += A[row * n + i] * B[i * k + col];
        }
        C[row * k + col] = sum;
    }
}

int main() {
    int m = 2; // Number of rows in matrix A
    int n = 3; // Number of columns in matrix A and rows in matrix B
    int k = 2; // Number of columns in matrix B
    int* A, * B, * C;
    int *d_A, *d_B, *d_C;

    // Dynamically allocate memory for matrices A, B, and C
    A = (int*)malloc(m * n * sizeof(int));
    B = (int*)malloc(n * k * sizeof(int));
    C = (int*)malloc(m * k * sizeof(int));

    // Initialize matrices A and B with your data
    printf("Enter row of dim %d X %d:\n",m,n );
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &A[i*m+j]);
        }
    }
    printf("Enter row of dim %d X %d:\n",n,k );
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            scanf("%d", &B[i*n+j]);
        }
    }
    // Allocate memory on the device
    cudaMalloc((void**)&d_A, m * n * sizeof(int));
    cudaMalloc((void**)&d_B, n * k * sizeof(int));
    cudaMalloc((void**)&d_C, m * k * sizeof(int));

    // Copy matrices A and B from host to device
    cudaMemcpy(d_A, A, m * n * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, n * k * sizeof(int), cudaMemcpyHostToDevice);

    // Define grid and block dimensions
    dim3 dimGrid(k , m);
    dim3 dimBlock(16, 16);

    // Launch the matrix multiplication kernel
    matrixMul<<<dimGrid, dimBlock>>>(d_A, d_B, d_C, m, n, k);

    // Copy the result matrix C from device to host
    cudaMemcpy(C, d_C, m * k * sizeof(int), cudaMemcpyDeviceToHost);

    // Print the result matrix C
    printf("This is matrix C: \n");
    for(int i=0;i<m;i++){
        for (int j = 0; j < k; j++)
        {
            printf("%3d",C[i*m+j] );
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    free(A);
    free(B);
    free(C);

    // Free device memory
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return 0;
}
