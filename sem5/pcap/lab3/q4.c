#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size < 2) {
        if (rank == 0) {
            printf("This program requires at least 2 processes.\n");
        }
        MPI_Finalize();
        return 1;
    }

    int string_length, local_length;
    char s1[100], s2[100], local_result[100], global_result[100];

    if (rank == 0) {
        printf("Enter String S1: ");
        scanf("%s", s1);

        printf("Enter String S2: ");
        scanf("%s", s2);

        string_length = strlen(s1);

        if (string_length % size != 0) {
            printf("String length should be evenly divisible by the number of processes.\n");
            MPI_Finalize();
            return 1;
        }
    }

    MPI_Bcast(&string_length, 1, MPI_INT, 0, MPI_COMM_WORLD);

    local_length = string_length / size;

    MPI_Scatter(s1, local_length, MPI_CHAR, s1, local_length, MPI_CHAR, 0, MPI_COMM_WORLD);
    MPI_Scatter(s2, local_length, MPI_CHAR, s2, local_length, MPI_CHAR, 0, MPI_COMM_WORLD);

    for (int i = 0; i < local_length; i++) {
        if (i % 2 == 0) {
            local_result[i] = s1[i];
        } else {
            local_result[i] = s2[i];
        }
    }

    MPI_Gather(local_result, local_length, MPI_CHAR, global_result, local_length, MPI_CHAR, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        global_result[string_length] = '\0';
        printf("Resultant String: %s\n", global_result);
    }

    MPI_Finalize();
    return 0;
}
