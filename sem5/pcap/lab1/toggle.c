// Write a program in MPI to toggle the character of a given string indexed by the rank of the
// process. Hint: Suppose the string is HELLO and there are 5 processes, then process 0 tog-
// gle ‘H’ to ‘h’, process 1 toggle ‘E’ to ‘e’ and so on.
#include <stdio.h>
#include<mpi.h>
#include<math.h>
int  main(int argc, char  **argv)
{
	int rank, size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	char M[6] = "HELLO";
	M[rank] = M[rank] + 32;
	printf("%s -> %d",M,rank);
	// printf("%s\n",M);
	MPI_Finalize();
	return 0;
}