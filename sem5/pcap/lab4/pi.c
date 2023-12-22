// #include <stdio.h>
// #include <math.h>
// #include <mpi.h>

// double f(double x) {
//     return 4.0 / (1.0 + x * x)-;
// }

// int main(int argc, char** argv) {
//     MPI_Init(&argc, &argv);

//     int rank, size;
//     MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//     MPI_Comm_size(MPI_COMM_WORLD, &size);

//     int num_rectangles = 1000000; // Total number of rectangles
//     int local_rectangles = num_rectangles / size; // Number of rectangles per process

//     double local_sum = 0.0;
//     double total_sum;

//     double interval = 1.0 / (double)num_rectangles;
//     double local_start = (double)rank * local_rectangles * interval;
//     double local_end = local_start + local_rectangles * interval;

//     for (int i = 0; i < local_rectangles; i++) {
//         double x_midpoint = local_start + (i + 0.5) * interval;
//         local_sum += f(x_midpoint) * interval;
//     }

//     MPI_Reduce(&local_sum, &total_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

//     if (rank == 0) {
//         printf("Estimated π value: %.15f\n", total_sum);
//         printf("Difference from true π value: %.15f\n", fabs(M_PI - total_sum));
//     }

//     MPI_Finalize();
//     return 0;
// }
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<mpi.h>

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

int main(int argc, char* argv[])
{
    int rank, size;
    float ans;

    MPI_Init(&argc,&argv);

    int error_code;
    error_code = MPI_Comm_size(MPI_COMM_WORLD, &size);
    error_code = MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    Error_Handler(error_code);

    float val = (1 + pow(((rank + 0.5)/(size)),2));
    float final = 4 / (val * (size));

    MPI_Reduce(&final,&ans,1,MPI_FLOAT,MPI_SUM,0,MPI_COMM_WORLD);
    
    if(rank == 0){
        printf("The value of pi is : %.15f\n",ans);
        printf("The difference is : %.15f\n",M_PI-ans);
    }

    MPI_Finalize();
}