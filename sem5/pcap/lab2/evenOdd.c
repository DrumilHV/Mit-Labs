// Write a MPI program to read N elements of the array in the root process (process 0) where
// N is equal to the total number of processes. The root process sends one value to each of the
// slaves. Let even ranked process finds square of the received element and odd ranked pro-
// cess finds cube of received element. Use Buffered send.

#include <mpi.h>
#include<stdio.h>
int main(int argc, char  **argv)
{
	int rank,size,i;
	int a;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
	int num[size];
	if(rank==0){
			printf("enter value: ");
		for (i = 0; i < size; i++)
		{	
			scanf("\n%d",&num[i]);
		}
		for (i = 1; i < size; i++)
		{	
			
			MPI_Bsend(num,1,MPI_INT,i,0,MPI_COMM_WORLD);
		}
	}
	else if (rank%2)
	{
		MPI_Recv(&a,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf(" rank : %d : %d ",rank,a*a*a);
		fflush(stdout);
	}else{
		MPI_Recv(&a,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf(" rank : %d : %d ",rank,a*a);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}