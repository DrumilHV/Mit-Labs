#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int factorial(int n) {
	int ans = 1;
    while(n--){
    	ans*=n;
    }
    return ans;
}

int main(int argc, char *argv[]) {
    int rank, size, N;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("Enter the value of N: ");
        fflush(stdout);
        scanf("%d", &N);
    }

    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int value = rank + 1;
    int local_factorial = factorial(value);

    int *factorials = NULL;
    if (rank == 0) {
        factorials = (int *)malloc(size * sizeof(int));
    }

    MPI_Gather(&local_factorial, 1, MPI_INT, factorials, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        int total_factorial_sum = 0;
        for (int i = 0; i < size; i++) {
            total_factorial_sum += factorials[i];
        }
        printf("Sum of factorials: %d\n", total_factorial_sum);
        free(factorials);
    }

    MPI_Finalize();
    return 0;
}
