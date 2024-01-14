#include <stdio.h>
#include<stdlib.h>
#include<cuda_runtime.h>
#include <time.h>

#define M 4
#define N 4
__global__ void addMatrixRow(int *d_a, int *d_b,int *d_c){
	int row = threadIdx.x;
	if(row<M){
		for(int col=0;col<N;col++){
			int idx = row * M + col;
			d_c[idx] = d_b[idx] + d_a[idx];
		}
	}
		
}
__global__ void addMatrixCol(int *d_a, int *d_b,int *d_c){
	int col = threadIdx.x;
	if(col<N){
		for(int row=0;row<M;row++){
			int idx = row * N + col;
			d_c[idx] = d_b[idx] + d_a[idx];
		}
	}		
}
__global__ void addMatrixEle(int *d_a, int *d_b,int *d_c){
	int row = blockIdx.y * blockDim.y + threadIdx.y;
	int col = blockIdx.x * blockDim.x + threadIdx.x;
	if(row<M && col<N){
		int idx = row * M + col;
		d_c[idx] = d_b[idx]+d_a[idx];
	}	
}
void printFn(int *mat,char c){
	printf("This is matrix %c: \n",c);
	// printf("\n");
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			printf("%3d ",mat[i*M+j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(){
	int *h_a,*h_b, *h_c;
	int *d_a, *d_b, *d_c;

	h_a = (int *)malloc(N * M * sizeof(int));
    h_b = (int *)malloc(N * M * sizeof(int));
    h_c = (int *)malloc(N * M * sizeof(int));


	cudaMalloc((void**)&d_a, sizeof(int)*M*N);
	cudaMalloc((void**)&d_b, sizeof(int)*M*N);
	cudaMalloc((void**)&d_c, sizeof(int)*M*N);

	for (int i = 0; i < N * M; i++) {
        // h_a[i] = 1.0f;
        // h_b[i] = 2.0f;
        h_a[i] = rand()%100;
        h_b[i] = rand()%100;
    }
    
    printFn(h_a,'A');
    
    printFn(h_b,'B');

	cudaMemcpy(d_a,h_a, sizeof(int)*M*N, cudaMemcpyHostToDevice );
	cudaMemcpy(d_b,h_b, sizeof(int)*M*N, cudaMemcpyHostToDevice );

	dim3 gridDim((N+15)/16,(M+15)/16);
	dim3 blockDim(16,16);


	addMatrixRow<<<M, 1>>>(d_a,d_b,d_c);
	cudaMemcpy(h_c,d_c, sizeof(int)*M*N, cudaMemcpyDeviceToHost );
	printFn(h_c,'C');
	cudaFree(d_c);
	cudaMalloc((void**)&d_c, sizeof(int)*M*N);


	addMatrixCol<<<1, N>>>(d_a,d_b,d_c);
	cudaMemcpy(h_c,d_c, sizeof(int)*M*N, cudaMemcpyDeviceToHost );
	printFn(h_c,'C');
	cudaFree(d_c);
	cudaMalloc((void**)&d_c, sizeof(int)*M*N);



	addMatrixEle<<<gridDim,blockDim>>>(d_a,d_b,d_c);
	cudaMemcpy(h_c,d_c, sizeof(int)*M*N, cudaMemcpyDeviceToHost );
	cudaFree(d_c);
	printFn(h_c,'C');


	cudaFree(d_c);
	cudaFree(d_b);
	cudaFree(d_a);
	return 0;
	// cudaMalloc((void**)&d_c, sizeof(int)*M*N);



}
