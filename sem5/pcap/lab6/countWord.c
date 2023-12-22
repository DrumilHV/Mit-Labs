#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1024
#define MAX_WORD_LENGTH 32

__global__ void countWordOccurrences(const char* sentence, const char* targetWord, int* result) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    
    // Iterate through the sentence and count word occurrences
    while (tid < strlen(sentence)) {
        int match = 1; // Assume a match
        for (int i = 0; i < strlen(targetWord); i++) {
            if (sentence[tid + i] != targetWord[i]) {
                match = 0; // No match
                break;
            }
        }
        if (match) {
            atomicAdd(result, 1); // Increment the result atomically
            tid += strlen(targetWord); // Skip the matched word
        } else {
            tid++;
        }
    }
}

int main() {
    const char* sentence = "This is a test sentence. This sentence contains the word test multiple times. Test, test, test!";
    const char* targetWord = "test";

    int* d_result; // Device variable for result
    int result = 0; // Host variable for result

    // Allocate memory on the device for the result
    cudaMalloc((void**)&d_result, sizeof(int));
    cudaMemcpy(d_result, &result, sizeof(int), cudaMemcpyHostToDevice);

    // Define thread and block configurations
    int blockSize = 256;
    int numBlocks = (strlen(sentence) + blockSize - 1) / blockSize;

    // Launch the CUDA kernel
    countWordOccurrences<<<numBlocks, blockSize>>>(sentence, targetWord, d_result);

    // Copy the result back to the host
    cudaMemcpy(&result, d_result, sizeof(int), cudaMemcpyDeviceToHost);

    // Free device memory
    cudaFree(d_result);

    // Print the result
    printf("The word '%s' appears %d times in the sentence.\n", targetWord, result);

    return 0;
}
