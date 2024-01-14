// #include <stdio.h>
// #include <stdlib.h>
// #include <mpi.h>

// void printMatrix(int matrix[][3]) {
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             printf("%d ", matrix[i][j]);
//         }
//         printf("\n");
//     }
// }

// int main(int argc, char** argv) {
//     MPI_Init(&argc, &argv);

//     int rank, size;
//     MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//     MPI_Comm_size(MPI_COMM_WORLD, &size);

//     if (size != 3) {
//         fprintf(stderr, "This program requires exactly 3 processes.\n");
//         MPI_Abort(MPI_COMM_WORLD, 1);
//     }

//     int matrix[3][3];
//     int searchElement;
//     int localCount = 0;
//     int totalCount;

//     if (rank == 0) {
//         printf("Enter elements of the 3x3 matrix:\n");
//         for (int i = 0; i < 3; i++) {
//             for (int j = 0; j < 3; j++) {
//                 scanf("%d", &matrix[i][j]);
//             }
//         }

//         printf("Enter an element to search: ");
//         scanf("%d", &searchElement);
//     }

//     MPI_Bcast(&searchElement, 1, MPI_INT, 0, MPI_COMM_WORLD);

//     for (int i = rank; i < 3; i+=size) {
//         for (int j = 0; j < 3; j++) {
//             if (matrix[i][j] == searchElement) {
//                 localCount++;
//             }
//         }
//     }

//     MPI_Reduce(&localCount, &totalCount, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

//     if (rank == 0) {
//         printf("Matrix:\n");
//         printMatrix(matrix);
//         printf("Element %d occurs %d times in the matrix.\n", searchElement, totalCount);
//     }

//     MPI_Finalize();
//     return 0;
// }
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100

void Error_Handler(int error_code) {
  if (error_code != MPI_SUCCESS) {
    char error_string[BUFSIZE];
    int length_of_error_string, error_class;
    MPI_Error_class(error_code, & error_class);
    MPI_Error_string(error_code, error_string, & length_of_error_string);
    printf("%d %s\n", error_class, error_string);
  }
}

int main(int argc, char *argv[])
{
    int rank, size, elem, ttl_cnt, cnt=0, mat[3][3];

    MPI_Init(&argc,&argv);

    int error_code;
    error_code = MPI_Comm_size(MPI_COMM_WORLD, &size);
    Error_Handler(error_code);

    error_code = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    Error_Handler(error_code);

    if(rank==0)
    {
        printf("Enter 3x3 Matrix : \n");
        
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                scanf("%d", &mat[i][j]);
            }
        }

        printf("Enter Element to be searched : ");
        scanf("%d", &elem);
    } 

    for(int i=0; i<3; i++)
        MPI_Bcast(mat[i], 3, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&elem, 1, MPI_INT, 0, MPI_COMM_WORLD);

    for(int j=0; j<3; j++){
        if(mat[rank][j] == elem)
            cnt++;
    }

    MPI_Reduce (&cnt, &ttl_cnt, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank==0)
        printf("The count of element '%d' in Matrix is : '%d'\n", elem, ttl_cnt);
    
    MPI_Finalize();
}