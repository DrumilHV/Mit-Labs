#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int heapBottomUp(int *arr, int n){
    int i,j,k,v,heap;
    for(int i=n/2;i>=1;i--){
        heap = 1;
        k = i;
        v  = arr[k];
        while(!heap && 2*k <= n){
            j = 2*k;
            if(j< n){
                if(arr[j]<arr[j+1]){
                    j++;
                }
            }
            if(v >= arr[j]){
                heap = 1;
            }else{
                arr[k] = arr[j];
                k = j;
                // return 0;
            }
        }
        arr[k] = v;
    }
    return 1;
}

void heapSort(int *arr, int n){
    heapBottomUp(arr,n);
    for(int i=n;i>=2;i--){
        swap(&arr[i],&arr[1]);
        heapBottomUp(arr,n);
    }
}
 void printArray(int *arr,int n){
    printf("\n\n");
    for(int i = 0;i<n;i++){
        printf("%d ", arr[i]);
    }
}
void main(){
    int * arr;
    int n;
    printf("Enter the number of elemets:");
    scanf("%d",&n);
    // n = 10;
    arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        arr[i] = rand()%n +1;
    }
    printArray(arr,n);
    // if(heapBottomUp(arr,n) == 0){
    //     printf("This is not a heap");
    // }
    heapBottomUp(arr,n);
    printArray(arr,n);
    heapSort(arr,n);
    printArray(arr,n);
}