#include <stdio.h>
#include<mpi.h>
#include<math.h>
int rev(int &num){
	int temp = 0;
	int res =0;
	while(num){
		temp = num%10;
		res+=temp;
		num /=10;
	}
	return res;
}
int  main(int argc, char  **argv)
{
	int rank, size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	int n = 5;
	int arr[n] = [1234,4321,398,456,567];
	arr[rank] = rev(arr[rank]);

	MPI_Finalize();
	return 0;
}