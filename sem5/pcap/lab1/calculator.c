// Write a program in MPI to simulate simple calculator. Perform each operation using dif-
// ferent process in parallel.
#include <stdio.h>
#include <mpi.h>
int main(int argc, char **argv)

{
	int rank,size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_rank(MPI_COMM_WORLD,&size);
	int a = 5,b = 10;
	if(rank==1){
		printf("%d + %d = %d \n",a,b,a+b);
	}
	else if(rank==2){
		printf("%d - %d = %d \n",a,b,a-b);
	}
	else if(rank==3){
		printf("%d * %d = %d \n",a,b,a*b);
	}
	else if(rank==0){
		printf("%d / %d = %d \n",a,b,a/b);
	}
	MPI_Finalize();
	return 0;
}