#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>

#define N 16
#define THREADS_PER_BLOCK 256

__device__ void merge(int* d_data, int* d_result, int left, int mid, int right) {
    __shared__ int s_data[N];
    int i = left;
    int j = mid + 1;
    int k = threadIdx.x;

    while (i <= mid && j <= right) {
        if (d_data[i] < d_data[j]) {
            s_data[k] = d_data[i];
            i++;
        } else {
            s_data[k] = d_data[j];
            j++;
        }
        k += blockDim.x;
    }

    while (i <= mid) {
        s_data[k] = d_data[i];
        i++;
        k += blockDim.x;
    }

    while (j <= right) {
        s_data[k] = d_data[j];
        j++;
        k += blockDim.x;
    }

    k = threadIdx.x;
    for (int idx = left; idx <= right; idx++) {
        d_result[idx] = s_data[k];
        k += blockDim.x;
    }
}

__global__ void mergeSort(int* d_data, int* d_result, int size) {
    int tid = threadIdx.x + blockIdx.x * blockDim.x;
    int left, mid, right;

    for (int width = 2; width < size; width <<= 1) {
        left = tid * width;
        mid = left + width / 2 - 1;
        right = min(left + width - 1, size - 1);

        if (left < size) {
            merge(d_data, d_result, left, mid, right);
        }
        __syncthreads();

        // Swap data pointers to update the result for the next iteration
        int* temp = d_data;
        d_data = d_result;
        d_result = temp;
    }
}

int main() {
    int h_data[N];
    int h_result[N];
    int* d_data;
    int* d_result;

    // Generate or load your data into h_data array
    for (int i = 0; i < N; i++) {
        h_data[i] = N-i;
        printf("%2d ", h_data[i]);
    }

    cudaMalloc((void**)&d_data, N * sizeof(int));
    cudaMalloc((void**)&d_result, N * sizeof(int));

    cudaMemcpy(d_data, h_data, N * sizeof(int), cudaMemcpyHostToDevice);

    mergeSort<<<1, THREADS_PER_BLOCK>>>(d_data, d_result, N);

    cudaDeviceSynchronize(); // Wait for the sorting to complete

    cudaMemcpy(h_result, d_data, N * sizeof(int), cudaMemcpyDeviceToHost);

    // Print the sorted data
    printf("Sorted Data:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", h_result[i]);
    }
    printf("\n");

    cudaFree(d_data);
    cudaFree(d_result);

    return 0;
}
