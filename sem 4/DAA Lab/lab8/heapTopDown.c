#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// function to create a heap from a list of integers using top-down heap construction algorithm
void topDownHeap(int* arr, int n) {
    int i, j, k, v;
    for (i = floor(n/2); i >= 1; i--) {
        k = i;
        v = arr[k];
        int heap = 0;
        while (!heap && 2*k <= n) {
            j = 2*k;
            if (j < n) {
                if (arr[j] < arr[j+1]) {
                    j++;
                }
            }
            if (v >= arr[j]) {
                heap = 1;
            } else {
                arr[k] = arr[j];
                k = j;
            }
        }
        arr[k] = v;
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));
    
    // fill the array with random integers
    // srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % n + 1;
    }
    
    // build the heap
    topDownHeap(arr, n);
    
    // print the heap
    printf("The heap is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // free the memory allocated for the array
    free(arr);
    
    return 0;
}
