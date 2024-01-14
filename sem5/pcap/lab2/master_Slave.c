// Write a MPI program where the master process (process 0) sends a number to each of the
// slaves and the slave processes receive the number and prints it. Use standard send.

#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int rank,size,i;

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
    int x,a;
	if(rank==0){
		for (i = 1; i < size; i++)
		{	
			x=i+3;
			MPI_Send(&x,1,MPI_INT,i,0,MPI_COMM_WORLD);
			// printf("i = %d\n ",i);
			// fflush(stdout);
		}
	}else{
		//for (int i = 1; i < 6; ++i)
		//{
			MPI_Recv(&a,1,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
			printf("%d ",a);
			fflush(stdout);
		//}
	}	
	
	MPI_Finalize();
	return 0;
}
// mpicc master_Slave.c -o ms
// mpirun -n 4 ./ms
// -----------------------------------------
// output
// -----------------------------------------
//8 11 5 12 7 4 9 6 10