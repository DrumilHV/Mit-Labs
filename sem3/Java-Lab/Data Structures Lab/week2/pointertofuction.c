#include<stdio.h>
int * smaller(int *px, int *py){
    return(*px < *py ? px : py);
}
int main()
{
    int a,b;
    int *p;
    printf("Enter the values of a and b:\n");
    scanf("%d %d",&a,&b);
    p = smaller(&a,&b);
    printf("The smallest is %d",*p);
    return 0;
}
