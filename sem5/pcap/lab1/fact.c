// Write a program in MPI where even ranked process prints factorial of the rank and odd
// ranked process prints ranks Fibonacci number.
#include <stdio.h>
#include <mpi.h>
int main(int argc, char **argv)

{
	int rank,size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_rank(MPI_COMM_WORLD,&size);
	if(rank%2){
		int num1=0, num2=1 , res, num = rank;
		while(num){
			res = num2 + num1;
			num1 = num2;
			num2 = res;
			num--;
		}
		printf("fib(%d) = %d\n",rank,res);
	}else{
		int num = rank,res = 1;
		while(num>=2){
			res *=num;
			num--;
		}
		printf("fact(%d) = %d\n", rank,res);
	}
	MPI_Finalize();
	return 0;
}