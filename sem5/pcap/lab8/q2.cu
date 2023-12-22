#include <stdio.h>
#include <cuda_runtime.h>

// Function to replace each row with elements raised to a power
__global__ void modify_matrix_kernel(float* matrix, int M, int N) {
    int row = blockIdx.x * blockDim.x + threadIdx.x;
    
    if (row < M) {
        for (int col = 0; col < N; ++col) {
            int index = row * N + col;
            int power = row + 1; // Power for this row (1 for the first row, 2 for the second row, and so on)
            
            // Raise the element to the power
            float element = matrix[index];
            float powered_element = 1.0;
            for (int i = 0; i < power; ++i) {
                powered_element *= element;
            }
            
            matrix[index] = powered_element;
        }
    }
}

int main() {
    int M, N;

    // Get matrix dimensions (M and N) from the user
    printf("Enter the number of rows (M): ");
    scanf("%d", &M);
    printf("Enter the number of columns (N): ");
    scanf("%d", &N);

    // Allocate memory for the matrix on the host
    float* matrix = (float*)malloc(sizeof(float) * M * N);

    // Get user input for the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%f", &matrix[i * N + j]);
        }
    }

    // Allocate memory for the matrix on the device
    float* d_matrix;
    cudaMalloc((void**)&d_matrix, sizeof(float) * M * N);

    // Copy the matrix from host to device
    cudaMemcpy(d_matrix, matrix, sizeof(float) * M * N, cudaMemcpyHostToDevice);

    // Launch the CUDA kernel to modify the matrix
    int num_threads = 256;
    int num_blocks = (M + num_threads - 1) / num_threads;
    modify_matrix_kernel<<<num_blocks, num_threads>>>(d_matrix, M, N);

    // Copy the modified matrix from device to host
    cudaMemcpy(matrix, d_matrix, sizeof(float) * M * N, cudaMemcpyDeviceToHost);

    // Print the modified matrix
    printf("Modified Matrix:\n");
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%f ", matrix[i * N + j]);
        }
        printf("\n");
    }

    // Free device and host memory
    cudaFree(d_matrix);
    free(matrix);

    return 0;
}
