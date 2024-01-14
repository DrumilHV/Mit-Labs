#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size, M, N;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("Enter the value of M: ");
        fflush(stdout);
        scanf("%d", &M);
        printf("Enter the value of N: ");
        fflush(stdout);
        scanf("%d", &N);
    }

    MPI_Bcast(&M, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int *data = NULL;
    if (rank == 0) {
        data = (int *)malloc(M * N * sizeof(int));
        printf("Enter %d x %d elements:\n", N, M);
        for (int i = 0; i < M * N; i++) {
            scanf("%d", &data[i]);
        }
    }

    int *local_data = (int *)malloc(M * sizeof(int));
    MPI_Scatter(data, M, MPI_INT, local_data, M, MPI_INT, 0, MPI_COMM_WORLD);

    double local_average = 0.0;
    for (int i = 0; i < M; i++) {
        local_average += local_data[i];
    }
    local_average /= M;

    double *averages = NULL;
    if (rank == 0) {
        averages = (double *)malloc(size * sizeof(double));
    }

    MPI_Gather(&local_average, 1, MPI_DOUBLE, averages, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        double total_average = 0.0;
        for (int i = 0; i < size; i++) {
        	printf(" %f \n",averages[i]);
            total_average += averages[i];
        }
                	printf(" %f \n",total_average);
        total_average /= N;
        printf("Total average: %lf\n", total_average);
        free(data);
        free(averages);
    }

    free(local_data);
    MPI_Finalize();
    return 0;
}
