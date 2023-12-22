// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// __global__ void countWordOccurrences(const char* sentence,char targetWord, int* result,int n) {
//     int tid = blockIdx.x * blockDim.x + threadIdx.x;
    
//     // Iterate through the sentence and count word occurrences
//     if (sentence[tid]==targetWord)
//     {
//         atomicAdd(result, 1);
//     }
// }

// int main() {
//     const char* sentence = "this is a test sentence. this sentence contains the word test multiple times. Test, test, test!";
//     char targetWord = 't';
//     int* d_result; // Device variable for result
//     int result ; // Host variable for result


//     // Allocate memory on the device for the result
//     cudaMalloc((void**)&d_result, sizeof(int));
//     cudaMemcpy(d_result, &result, sizeof(int), cudaMemcpyHostToDevice);
//     int n = strlen(sentence);

//     // Define thread and block configurations
//     int blockSize = 256;
//     int numBlocks = (n) / blockSize;

//     // Launch the CUDA kernel
//     countWordOccurrences<<<numBlocks, blockSize>>>(sentence, targetWord, d_result,n);

//     // Copy the result back to the host
//     cudaMemcpy(&result, d_result, sizeof(int), cudaMemcpyDeviceToHost);
    
//     // Print the result
//     printf("The word '%c' appears %d times in the sentence.\n", targetWord,result );

//     // // Copy the result back to the host
//     // cudaMemcpy(&result, d_result, sizeof(int), cudaMemcpyDeviceToHost);

//     // Free device memory
//     cudaFree(d_result);

    

//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1024
#define MAX_WORD_LENGTH 32

__global__ void countWordOccurrences(const char* sentence, const char* targetWord, int* d_result, int n) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    
    // Iterate through the sentence and count word occurrences
    if (tid < n) {
        bool match = true; // Assume a match
        for (int i = 0; i < n; i++) {
            if (sentence[tid + i] != targetWord[i]) {
                match = false; // No match
                break;
            }
        }
        if (match) {
            atomicAdd(d_result, 1); // Increment the result atomically
            tid += n; // Skip the matched word
        } 
            else {
            tid++;
        }
    // printf("%3d \n",*d_result );
    }
}

int main() {
    const char* sentence = "This is a test sentence. This sentence contains the word test multiple times. Test, test, test!";
    const char* targetWord = "test";

    int* d_result; // Device variable for result
    int result  = 0; // Host variable for result
    int ans;
    int n = strlen(targetWord);
    // Allocate memory on the device for the result
    cudaMalloc((void**)&d_result, sizeof(int));
    cudaMemcpy(d_result, &result, sizeof(int), cudaMemcpyHostToDevice);

    // Define thread and block configurations
    int blockSize = 16;
    int numBlocks = (strlen(sentence) + blockSize - 1) / blockSize;

    // Launch the CUDA kernel
    countWordOccurrences<<<numBlocks, blockSize>>>(sentence, targetWord, d_result,n);

    // Copy the result back to the host
    cudaMemcpy(&ans, d_result, sizeof(int), cudaMemcpyDeviceToHost);

    // Free device memory
    cudaFree(d_result);

    // Print the result
    printf("The word '%s' appears %d times in the sentence.\n", targetWord, ans);

    return 0;
}