// Write a MPI program to read an integer value in the root process. Root process sends this
// value to Process1, Process1 sends this value to Process2 and so on. Last process sends the
// value back to root process. When sending the value each process will first increment the
// received value by one. Write the program using point to point communication routines.
#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int rank,size,i,a;

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
	i=1;
	if(rank==0){

		MPI_Ssend(&i,1,MPI_INT,rank+1,0,MPI_COMM_WORLD);
		// MPI_Recv(&a,1,MPI_INT,size,0,MPI_COMM_WORLD,&status);
		// printf("%d ",a);
		
	}else if(rank>0 && rank!=size){
		MPI_Recv(&a,1,MPI_INT,rank-1,0,MPI_COMM_WORLD,&status);
		printf("%d ",a);
		a+=1;
		MPI_Ssend(&a,1,MPI_INT,rank+1,0,MPI_COMM_WORLD);
	}else if(rank==size){
		MPI_Recv(&a,1,MPI_INT,rank-1,0,MPI_COMM_WORLD,&status);
		printf("%d ",a);
		a+=1;
		// MPI_Ssend(&a,1,MPI_INT,0,0,MPI_COMM_WORLD);

	}

	MPI_Finalize();
	return 0;
}

// mpicc eventChain.c -o eventChain
// mpirun -n 5 ./eventChain
// output
// -----------------------
// 1 2 3 4