// #include <stdio.h>
// #include <stdlib.h>

// void multiply(int r1, int c1, int c2, int res[][10], int mat1[][10], int mat2[][10]);
// void display(int r1, int c1, mat[][10]);
// void accept(int r, int c, int mat[][10]);
// void main()
// {
//     int **mat1, **mat2, **res, i, j, r1, c1, r2, c2, k;

//     printf("\nEnter the Order of the First matrix...\n");
//     scanf("%d %d", &r1, &c1);
//     printf("\nEnter the Order of the Second matrix...\n");
//     scanf("%d %d", &r2, &c2);

//     if (c1 != r2)
//     {
//         printf("Invalid Order of matrix");
//         exit(EXIT_SUCCESS);
//     }

//     mat1 = (int **)malloc(r1 * sizeof(int *));
//     for (i = 0; i < c1; i++)
//         mat1[i] = (int *)malloc(c1 * sizeof(int));

//     mat2 = (int **)malloc(r2 * sizeof(int *));
//     for (i = 0; i < c2; i++)
//         mat2[i] = (int *)malloc(c2 * sizeof(int));

//     res = (int **)calloc(r1, sizeof(int *));

//     for (i = 0; i < c2; i++)
//         res[i] = (int *)calloc(c2, sizeof(int));

//     // Input Matrix1
//     accept(r1, c1, mat1);
//     accept(r2, c2, mat2);
//     // Printing Input Matrix 1 and 2
//     display(r1, c1, mat1);
//     display(r2, c2, mat2);

//     multiply(int r1, int c1, int c2, int res[][10], int mat1[][10], int mat2[][10]);
//     display(r1, c2, res);
// }
// void accept(int r, int c, int mat[][10])
// {
//     int i, j;
//     printf("\n Entered Matrix : \n");
//     printf("\nEnter the array elements..\n");
//     // Input Matrix2
//     for (i = 0; i < r; i++)
//         for (j = 0; j < c; j++)
//             scanf("%d", &mat[i][j]);
// }
// void display(int r1, int c2, int mat[][10])
// {
//     int i, j;
//     printf("\nThe Multiplication of two matrix is\n");
//     for (i = 0; i < r1; i++)
//     {
//         printf("\n");
//         for (j = 0; j < c2; j++)
//             printf("%d\t", mat[i][j]);
//     }
//     printf("\n");
// }
// void multiply(int r1, int c1, int c2, int res[][10], int mat1[][10], int mat2[][10])

//     int i, j, k;

//      mat1 = (int **)malloc(r1 * sizeof(int *));
//     for (i = 0; i < c1; i++)
//         mat1[i] = (int *)malloc(c1 * sizeof(int));

//     mat2 = (int **)malloc(r2 * sizeof(int *));
//     for (i = 0; i < c2; i++)
//         mat2[i] = (int *)malloc(c2 * sizeof(int));

//     res = (int **)calloc(r1, sizeof(int *));

//     for (i = 0; i < c2; i++)
//         res[i] = (int *)calloc(c2, sizeof(int));

//     for (i = 0; i < r1; i++)
//     {
//         for (j = 0; j < c2; j++)
//         {
//             res[i][j] = 0;
//             for (k = 0; k < c1; k++)
//                 res[i][j] += mat1[i][k] * mat2[k][j];
//         }
//         printf("\n");
//     }
// }
//////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

void accept(int r, int c, int mat[][10])
{
    int i, j;
    printf("\nEnter the array elements..\n");
    // Input Matrix2
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);
}
void display(int r1, int c2, int mat[][10])
{
    int i, j;
    for (i = 0; i < r1; i++)
    {
        printf("\n");
        for (j = 0; j < c2; j++)
            printf("%d\t", mat[i][j]);
    }
    printf("\n");
}

void main(){
int **mat1, **mat2,**res,i,j,r1,c1,r2,c2,k;

printf("\nEnter the Order of the First matrix...\n");
scanf("%d %d",&r1,&c1);
printf("\nEnter the Order of the Second matrix...\n");
scanf("%d %d",&r2,&c2);

if(c1!=r2){
    printf("Invalid Order of matrix");
    exit(EXIT_SUCCESS);
}

mat1= (int**) malloc(r1*sizeof(int*));

for(i=0;i<c1;i++)
    mat1[i]=(int*)malloc(c1*sizeof(int));

mat2= (int**) malloc(r2*sizeof(int*));

for(i=0;i<c2;i++)
    mat2[i]=(int*)malloc(c2*sizeof(int));

res=(int**)calloc(r1,sizeof(int*));

for(i=0;i<c2;i++)
    res[i]=(int*)calloc(c2,sizeof(int));

printf("Input Matrix1: ");

    accept(r1,c1,mat1);
printf("Input Matrix 2: ");
    accept(r2,c2,mat2);


//Printing Input Matrix 1 and 2

printf("\n Entered Matrix 1: \n");
display(r1,c1,mat1);

printf("\n Entered Matrix 2: \n");
display(r2,c2,mat2);
       

    for(i=0;i<r1;i++){
        for(j=0;j<c2;j++){
                res[i][j]=0;
                for(k=0;k<c1;k++)
                    res[i][j]+= mat1[i][k]*mat2[k][j];

        }
        printf("\n");
    }

   printf("\nThe Multiplication of two matrix is\n");
   display(r1,c2,res);
    printf("\n");

}