#include<stdio.h>
void reverse(int b[],int n){
    int *pwalk,*last,temp;
     for(pwalk =b,last = b+n-1;pwalk<last;pwalk++,last--){
        temp =*(pwalk);
        *pwalk = *last;
        *last = temp;
    }
}
int main(){
   int n,i;
   printf("enter the number of elements:\n");
   scanf("%d",&n);
   int b[n];
   printf("enter earray elements:\n");
   for (i = 0; i < n; i++)
    scanf("%d",&b[i]);
   printf("\narray before reverse:\n");
   for ( i = 0; i < n; i++)
    printf("%d ",b[i]);
   printf("\narray after reverse:\n");
    reverse(b,n);
    for (i = 0; i < n; i++)
        printf("%d ",b[i]);  
}