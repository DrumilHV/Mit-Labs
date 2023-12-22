#include <stdio.h>
#include<stdlib.h>
// #include<cuda_runtime.h>
#include<string.h>

__global__ void countLetter(char* sentense,  char letter,int *d_res, int n ){
	int idx = blockIdx.x* blockIdx.x + threadIdx.x;
	if(idx<n){
		if(sentense[idx]==letter){
			atomicAdd(d_res,1);
		}
	}
}

int main()
{
	char *h_sentense = "This is a test, to test the testing code for testing cuda test";
	const char h_letter  = 't';
	// char *d_letter;
	int *h_res = 0;
	int *d_res;
	char *d_sentense;

	//Allocate memory for kernel variables
	cudaMalloc((void **)d_sentense, strlen(h_sentense)*sizeof(char));
	cudaMalloc((void **)d_res, sizeof(int));
	// cudaMalloc(d_letter, sizeof(char));

	//Copy the values to kernel variables
	cudaMemcpy(d_sentense,h_sentense, strlen(h_sentense)*sizeof(char),cudaMemcpyHostToDevice);
	cudaMemcpy(d_res,h_res, sizeof(int),cudaMemcpyHostToDevice);
	// cudaMemcpy(d_letter,h_letter, sizeof(int),cudaMemcpyHostToDevice);

	dim3 gridDim(strlen(h_sentense),1,1);
	dim3 blockDim(256,1,1);
	countLetter<<<gridDim, blockDim>>>(d_sentense, h_letter,d_res ,strlen(h_sentense));

	//copy the result to host variables
	cudaMemcpy(h_res,d_res,sizeof(int), cudaMemcpyDeviceToHost);


	printf("letter %c occurs %d times in : '%s'\n",h_letter, *h_res , h_sentense );
	//Free up the device memory
	cudaFree(d_res);
	// cudaFree(d_letter);
	cudaFree(d_sentense);

	//free host varables memory
	free(h_sentense);
	free(h_res);

	return 0;
	
}