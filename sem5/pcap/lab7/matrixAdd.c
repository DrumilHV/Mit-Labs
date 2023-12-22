#include <stdio.h>
#include<stdlib.h>
#include<cuda_runtime.h>

#define M 4
#define N 4
__global__ addMatrixRow(int *d_a, int *d_b,int *d_c){
	int row = threadIdx.x;
	if(row<M){
		for(int col=0;col<N;col++){
			int idx = row * M + col;
			d_c[idx] = d_b[idx] + d_c[idx];
		}
	}
		
}
__global__ addMatrixCol(int *d_a, int *d_b,int *d_c){
	int col = threadIdx.x;
	if(col<N){
		for(int row=0;row<N;row++){
			int idx = row * M + col;
			d_c[idx] = d_b[idx] + d_c[idx];
		}
	}		
}
__global__ addMatrixEle(int *d_a, int *d_b,int *d_c){
	int row = blockIdx.y * blockDim.y + threadIdx.y;
	int col = blockIdx.x * blockDim.x + threadIdx.x;
	if(row<M && col<N){
		int idx = row * M + col;
		d_c[idx] = d_b[idx]+d_a[idx];
	}	
}
void printFn(int *mat){
	printf("\n");
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			printf("%3d ",mat[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int h_a[M][N],h_b[M][N], h_c[M][N];
	int *d_a, *d_b, *d_c;

	cudaMalloc((void**)&d_a, sizeof(int)*M*N);
	cudaMalloc((void**)&d_b, sizeof(int)*M*N);
	cudaMalloc((void**)&d_c, sizeof(int)*M*N);

	for (int i = 0; i < N * M; i++) {
        // h_a[i] = 1.0f;
        // h_b[i] = 2.0f;
        h_a[i] = rand()%100;
        h_b[i] = rand()%100;
    }
    printf("This is matrix A: \n");
    printFn(h_a);
    printf("This is matrix B: \n");
    printFn(h_b);

	cudaMemcpy(d_a,h_a, sizeof(int)*M*N, cudaMemcpyHostToDevice );
	cudaMemcpy(d_b,h_b, sizeof(int)*M*N, cudaMemcpyHostToDevice );

	// dim3 gridDim()
	addMatricesRow<<<1, M>>>(d_a,d_b,d_c);
	cudaMemcpy(h_c,d_c, sizeof(int)*M*N, cudaMemcpyDeviceToHost );
	printFn(h_c);
	cudaFree(d_c);
	cudaMalloc((void**)&d_c, sizeof(int)*M*N);
	addMatricesCol<<<1, N>>>(d_a,d_b,d_c);
	cudaMemcpy(h_c,d_c, sizeof(int)*M*N, cudaMemcpyDeviceToHost );
	printFn(h_c);
	cudaFree(d_c);
	cudaMalloc((void**)&d_c, sizeof(int)*M*N);
	addMatricesEle<<<M, N>>>(d_a,d_b,d_c);
	cudaMemcpy(h_c,d_c, sizeof(int)*M*N, cudaMemcpyDeviceToHost );
	printFn(h_c);
	cudaFree(d_c);
	cudaFree(d_b);
	cudaFree(d_a);
	return 0;
	// cudaMalloc((void**)&d_c, sizeof(int)*M*N);



}
