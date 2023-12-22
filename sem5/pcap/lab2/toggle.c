// Write a MPI program using synchronous send. The sender process sends a word to the
// receiver. The second process receives the word, toggles each letter of the word and sends
// it back to the first process. Both processes use synchronous send operations.

#include <mpi.h>
#include<stdio.h>
int main(int argc, char  **argv)
{
	int rank,size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Status status;
	char m[6]="HELLO";
	printf("The word before toggle is: %s\n",m);
	if(rank==0){
		MPI_Ssend(m,5,MPI_CHAR,1,1,MPI_COMM_WORLD);
		MPI_Recv(m,5,MPI_CHAR,1,1,MPI_COMM_WORLD,&status);
		printf("after toggle : %s\n", m);
	}else{
		MPI_Recv(m,5,MPI_CHAR,0,1,MPI_COMM_WORLD,&status);
		int i=0;
		while(i != 5){

			m[i]= m[i]+32;
			i++;
		}
		// printf("%s\n",m);
		MPI_Ssend(m,5,MPI_CHAR,0,1,MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;
}

// mpirun -n 6 ./ms
// -----------------------------------------
// output
// -----------------------------------------
// The word before toggle is: HELLO
// The word before toggle is: HELLO
// The word before toggle is: HELLO
// The word before toggle is: HELLO
// The word before toggle is: HELLO
// The word before toggle is: HELLO
// after toggle : hello
