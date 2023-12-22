#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>

// Define the number of threads per block
#define THREADS_PER_BLOCK 256

// Function to perform SpMV using CSR format
__global__ void spmv_csr_kernel(const float* values, const int* column_indices,
                                const int* row_offsets, const float* vector,
                                float* result, int num_rows) {
    int row = blockIdx.x * blockDim.x + threadIdx.x;
    
    if (row < num_rows) {
        float dot_product = 0.0f;
        int row_start = row_offsets[row];
        int row_end = row_offsets[row + 1];
        
        for (int j = row_start; j < row_end; ++j) {
            int col = column_indices[j];
            dot_product += values[j] * vector[col];
        }
        
        result[row] = dot_product;
    }
}

int main() {
    int num_rows, num_cols, num_nonzeros;

    // Get dimensions and number of non-zero elements from the user
    printf("Enter the number of rows: ");
    scanf("%d", &num_rows);
    printf("Enter the number of columns: ");
    scanf("%d", &num_cols);
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &num_nonzeros);

    // Allocate memory for CSR arrays on the host
    float* values = (float*)malloc(sizeof(float) * num_nonzeros);
    int* column_indices = (int*)malloc(sizeof(int) * num_nonzeros);
    int* row_offsets = (int*)malloc(sizeof(int) * (num_rows + 1));

    // Get user input for CSR arrays
    printf("Enter the non-zero values (one per line):\n");
    for (int i = 0; i < num_nonzeros; ++i) {
        scanf("%f", &values[i]);
    }
    
    printf("Enter the column indices (one per line):\n");
    for (int i = 0; i < num_nonzeros; ++i) {
        scanf("%d", &column_indices[i]);
    }
    
    printf("Enter the row offsets (one per line, including 0 at the beginning and the end):\n");
    for (int i = 0; i <= num_rows; ++i) {
        scanf("%d", &row_offsets[i]);
    }

    // Allocate memory for the vector on the host
    float* vector = (float*)malloc(sizeof(float) * num_cols);

    // Get user input for the vector
    printf("Enter the vector elements (one per line):\n");
    for (int i = 0; i < num_cols; ++i) {
        scanf("%f", &vector[i]);
    }

    // Allocate memory for the result on the host
    float* result = (float*)malloc(sizeof(float) * num_rows);

    // Allocate memory for CSR arrays and the vector on the device
    float* d_values;
    int* d_column_indices;
    int* d_row_offsets;
    float* d_vector;
    float* d_result;

    cudaMalloc((void**)&d_values, sizeof(float) * num_nonzeros);
    cudaMalloc((void**)&d_column_indices, sizeof(int) * num_nonzeros);
    cudaMalloc((void**)&d_row_offsets, sizeof(int) * (num_rows + 1));
    cudaMalloc((void**)&d_vector, sizeof(float) * num_cols);
    cudaMalloc((void**)&d_result, sizeof(float) * num_rows);

    // Copy CSR arrays and vector from host to device
    cudaMemcpy(d_values, values, sizeof(float) * num_nonzeros, cudaMemcpyHostToDevice);
    cudaMemcpy(d_column_indices, column_indices, sizeof(int) * num_nonzeros, cudaMemcpyHostToDevice);
    cudaMemcpy(d_row_offsets, row_offsets, sizeof(int) * (num_rows + 1), cudaMemcpyHostToDevice);
    cudaMemcpy(d_vector, vector, sizeof(float) * num_cols, cudaMemcpyHostToDevice);

    // Launch the CUDA kernel
    int num_blocks = (num_rows + THREADS_PER_BLOCK - 1) / THREADS_PER_BLOCK;
    spmv_csr_kernel<<<num_blocks, THREADS_PER_BLOCK>>>(d_values, d_column_indices, d_row_offsets, d_vector, d_result, num_rows);

    // Copy the result from device to host
    cudaMemcpy(result, d_result, sizeof(float) * num_rows, cudaMemcpyDeviceToHost);

    // Print the result
    printf("Result vector:\n");
    for (int i = 0; i < num_rows; ++i) {
        printf("%f\n", result[i]);
    }

    // Free device memory
    cudaFree(d_values);
    cudaFree(d_column_indices);
    cudaFree(d_row_offsets);
    cudaFree(d_vector);
    cudaFree(d_result);

    // Clean up host memory
    free(values);
    free(column_indices);
    free(row_offsets);
    free(vector);
    free(result);

    return 0;
}
