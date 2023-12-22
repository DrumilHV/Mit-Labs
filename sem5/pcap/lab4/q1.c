#include <stdio.h>
#include <mpi.h>

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2) {
        fprintf(stderr, "This program requires at least 2 processes.\n");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    int N = 5; // Number of factorials to sum
    int local_factorial = factorial(rank + 1);
    int local_sum = local_factorial;
    int total_sum;

    int scan_result = MPI_Scan(&local_sum, &total_sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    if (scan_result != MPI_SUCCESS) {
        fprintf(stderr, "MPI_Scan failed with error code %d\n", scan_result);
        MPI_Abort(MPI_COMM_WORLD, scan_result);
        MPI_Finalize();
    }

    if (rank == size - 1) {
        printf("Process %d: Total sum of factorials from 1! to %d! = %d\n", rank, N, total_sum);
    }

    MPI_Finalize();
    return 0;
}
