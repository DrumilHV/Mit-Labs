#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>

#define N 1024 // Input signal size
#define M 5    // Filter size

__constant__ float d_Filter[M]; // Declare filter coefficients in constant memory

__global__ void convolution(const float *d_Input, float *d_Output) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    float result = 0.0f;

    for (int i = 0; i < M; i++) {
        int idx = tid - (M / 2) + i;
        if (idx >= 0 && idx < N) {
            result += d_Input[idx] * d_Filter[i];
        }
    }

    d_Output[tid] = result;
}

int main() {
    float *h_Input, *h_Output;
    float *d_Input, *d_Output;

    // Initialize host arrays
    h_Input = (float*)malloc(N * sizeof(float));
    h_Output = (float*)malloc(N * sizeof(float));
    for (int i = 0; i < N; i++) {
        h_Input[i] = static_cast<float>(i);
    }

    // Initialize filter coefficients in host constant memory
    float h_Filter[M] = {1.0, 2.0, 3.0, 2.0, 1.0};
    cudaMemcpyToSymbol(d_Filter, h_Filter, M * sizeof(float)); // Copy filter to constant memory

    // Allocate device memory
    cudaMalloc((void**)&d_Input, N * sizeof(float));
    cudaMalloc((void**)&d_Output, N * sizeof(float));

    // Copy data from host to device
    cudaMemcpy(d_Input, h_Input, N * sizeof(float), cudaMemcpyHostToDevice);

    // Define thread block and grid dimensions
    dim3 threadsPerBlock(256);
    dim3 numBlocks((N + threadsPerBlock.x - 1) / threadsPerBlock.x);

    // Launch the convolution kernel
    convolution<<<numBlocks, threadsPerBlock>>>(d_Input, d_Output);

    // Copy results back from device to host
    cudaMemcpy(h_Output, d_Output, N * sizeof(float), cudaMemcpyDeviceToHost);

    // Free device and host memory
    cudaFree(d_Input);
    cudaFree(d_Output);
    free(h_Input);
    free(h_Output);

    // Print or process the results as needed

    return 0;
}
