#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_COPIES 3  // Number of times to replicate each character

__global__ void replicateString(const char* input, char* output) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    char currentChar;

    while ((currentChar = input[tid / NUM_COPIES]) != '\0') {
        output[tid] = currentChar;
        tid += blockDim.x * gridDim.x;
    }
    output[tid] = '\0';  // Null-terminate the output string
}

int main() {
    const char* inputString = "PCAP"; // Input string
    const int inputLength = strlen(inputString);

    char* d_inputString;  // Device variable for input string
    char* d_outputString; // Device variable for output string

    // Calculate the size of the output string based on the replication factor
    const int outputLength = inputLength * NUM_COPIES;

    // Allocate memory on the host for the input and output strings
    char* h_outputString = (char*)malloc(outputLength * sizeof(char));

    // Allocate memory on the device for input and output strings
    cudaMalloc((void**)&d_inputString, inputLength * sizeof(char));
    cudaMalloc((void**)&d_outputString, outputLength * sizeof(char));

    // Copy input string from host to device
    cudaMemcpy(d_inputString, inputString, inputLength * sizeof(char), cudaMemcpyHostToDevice);

    // Define thread and block configurations
    int blockSize = 256;
    int numBlocks = (outputLength) / blockSize;

    // Launch the CUDA kernel
    replicateString<<<numBlocks, blockSize>>>(d_inputString, d_outputString);

    // Copy the result back to the host
    cudaMemcpy(h_outputString, d_outputString, outputLength * sizeof(char), cudaMemcpyDeviceToHost);

    // Free device memory
    cudaFree(d_inputString);
    cudaFree(d_outputString);

    // Print the output string
    printf("Input string S: %s\n", inputString);
    printf("Output string RS: %s\n", h_outputString);

    // Free host memory
    free(h_outputString);

    return 0;
}
