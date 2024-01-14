#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mpi.h>

int isVowel(char c) {
    // c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main(int argc, char *argv[]) {
    int rank, size, local_count = 0, total_count = 0;
    char input_string[100];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        printf("Enter a string: ");
        fflush(stdout);
        scanf("%s", input_string);
    }

    int str_len = strlen(input_string);
    int chunk_size = str_len / size;
    char *local_string = (char *)malloc((chunk_size + 1) * sizeof(char));

    MPI_Scatter(input_string, chunk_size, MPI_CHAR, local_string, chunk_size, MPI_CHAR, 0, MPI_COMM_WORLD);
    local_string[chunk_size] = '\0'; // Null-terminate the local string

    for (int i = 0; i < chunk_size; i++) {
        if (!isVowel(local_string[i])) {
            local_count++;
        }
    }

    MPI_Reduce(&local_count, &total_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Number of non-vowels found by each process:\n");
        fflush(stdout);
    }

    MPI_Barrier(MPI_COMM_WORLD);

    printf("Process %d: %d\n", rank, local_count);
    fflush(stdout);

    if (rank == 0) {
        printf("Total number of non-vowels: %d\n", total_count);
    }

    free(local_string);
    MPI_Finalize();
    return 0;
}
