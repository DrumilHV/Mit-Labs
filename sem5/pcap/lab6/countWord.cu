// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_SENTENCE_LENGTH 1024
// #define MAX_WORD_LENGTH 32

// __global__ void countWordOccurrences(const char* sentence, const char* targetWord, int* d_result, int n) {
//     int tid = blockIdx.x * blockDim.x + threadIdx.x;
    
//     // Iterate through the sentence and count word occurrences
//     while (tid < n) {
//         bool match = true; // Assume a match
//         for (int i = 0; i < n; i++) {
//             if (sentence[tid + i] != targetWord[i]) {
//                 match = false; // No match
//                 break;
//             }
//         }
//         if (match) {
//             atomicAdd(d_result, 1); // Increment the result atomically
//             tid += n; // Skip the matched word
//         } 
//             else {
//             tid++;
//         }
//     // printf("%3d \n",*d_result );
//     }
// }

// int main() {
//     const char* sentence = "This is a test sentence. This sentence contains the word test multiple times. Test, test, test!";
//     const char* targetWord = "test";

//     int* d_result; // Device variable for result
//     int result  = 0; // Host variable for result
//     int ans;
//     int n = strlen(targetWord);
//     // Allocate memory on the device for the result
//     cudaMalloc((void**)&d_result, sizeof(int));
//     cudaMemcpy(d_result, &result, sizeof(int), cudaMemcpyHostToDevice);

//     // Define thread and block configurations
//     int blockSize = 32;
//     int numBlocks = (strlen(sentence) + blockSize - 1) / blockSize;

//     // Launch the CUDA kernel
//     countWordOccurrences<<<numBlocks, blockSize>>>(sentence, targetWord, d_result,n);

//     // Copy the result back to the host
//     cudaMemcpy(&ans, d_result, sizeof(int), cudaMemcpyDeviceToHost);

//     // Free device memory
//     cudaFree(d_result);

//     // Print the result
//     printf("The word '%s' appears %d times in the sentence.\n", targetWord, ans);

//     return 0;
// }
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1024

/* 
write a program in cuda to read a sentence with equal length words, 
count numner of times a word is repeated, use atomin functions
*/

__global__ void CUDACount(char* A, char* B, int* len, int* wordLen, int* cnt){
    int idx = threadIdx.x, flag=1;
    
    if(idx + *wordLen <= *len){
        for(int i=0; i<*wordLen; i++){
            if(A[idx + i] != B[i]){
                flag = 0;
                break;
            }
        }

        if(flag==1)
            atomicAdd(cnt, 1);
    }
}

int main(){
    char A[N], B[N];
    char *d_A, *d_B;

    int count=0, len, wordLen,res;
    int *d_count, *d_len, *d_wordLen;

    cudaError_t err = cudaGetLastError();

    printf("Enter String : ");
    scanf("%[^\n]%*c", A);
    printf("String : %s\n\n", A);

    printf("Enter Word to be searched in String : ");
    scanf("%s", B);
    printf("Word : %s\n\n", B);

    len = strlen(A);
    wordLen = strlen(B);

    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 1 : %s\n", cudaGetErrorString(err));

    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    cudaEventRecord(start, 0);
    
    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 2 : %s\n", cudaGetErrorString(err));

    cudaMalloc((void**)&d_A, strlen(A)*sizeof(char));
    cudaMalloc((void**)&d_B, strlen(B)*sizeof(char));
    cudaMalloc((void**)&d_count, sizeof(int));
    cudaMalloc((void**)&d_len, sizeof(int));
    cudaMalloc((void**)&d_wordLen, sizeof(int));
    cudaMalloc((void**)&res, sizeof(int));

    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 3 : %s\n", cudaGetErrorString(err));

    cudaMemcpy(d_count, &count, sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_len, &len, sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_wordLen, &wordLen, sizeof(int), cudaMemcpyHostToDevice);
    
    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 3.5 : %s\n", cudaGetErrorString(err));
        
    cudaMemcpy(d_A, A, strlen(A)*sizeof(char), cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, B, strlen(B)*sizeof(char), cudaMemcpyHostToDevice);


    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 4 : %s\n", cudaGetErrorString(err));

    CUDACount<<<1, strlen(A)>>>(d_A, d_B, d_len, d_wordLen, d_count);

    err = cudaGetLastError();
    if(err != cudaSuccess)
        printf("CUDA Error Occured 5 : %s\n", cudaGetErrorString(err));

    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);

    float elapsedTime;
    cudaEventElapsedTime(&elapsedTime, start, stop);
    

    cudaMemcpy(&res, d_count, sizeof(int), cudaMemcpyDeviceToHost);
    printf("Total Occurances of '%s' = %d\n", B, res);

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_len);
    cudaFree(d_wordLen);
    cudaFree(d_count);
    return 0;
}