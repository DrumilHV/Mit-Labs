// #include <stdio.h>
// #include <string.h>

// #define MAX 500

// // function to perform string matching using Horspool's algorithm
// int stringMatch(char* text, char* pattern, int* shift) {
//     int n = strlen(text);
//     int m = strlen(pattern);
//     int i, j, k, comparisons;
    
//     // initialize shift table with default shift value
//     for (i = 0; i < MAX; i++) {
//         shift[i] = m;
//     }
    
//     // compute shift table
//     for (i = 0; i < m-1; i++) {
//         shift[(int)pattern[i]] = m-i-1;
//     }
    
//     // perform string matching
//     i = m-1;
//     comparisons = 0;
//     while (i < n) {
//         k = i;
//         j = m-1;
//         while (j >= 0 && text[k] == pattern[j]) {
//             j--;
//             k--;
//             comparisons++;
//         }
//         if (j == -1) {
//             return comparisons; // successful search
//         } else {
//             i += shift[(int)text[i]];
//             comparisons++;
//         }
//     }
//     printf("comparisons: %d \n", comparisons);
//     return -1; // unsuccessful search
// }

// int main() {
//     char text[MAX], pattern[MAX];
//     int shift[MAX], comparisons;
    
//     printf("Enter the text string: ");
//     fgets(text, MAX, stdin);
//     printf("Enter the pattern string: ");
//     fgets(pattern, MAX, stdin);
    
//     // remove newline character from strings
//     text[strcspn(text, "\n")] = 0;
//     pattern[strcspn(pattern, "\n")] = 0;
    
//     // perform string matching
//     comparisons = stringMatch(text, pattern, shift);
    
//     // print results
//     if (comparisons != -1) {
//         printf("Successful search! Number of key comparisons: %d\n", comparisons);
//     } else {
//         printf("Unsuccessful search!\n");
//     }
    
//     return 0;
// }


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define max 500 
int horsepool(char * text, char * pattern){
    int i,j,k,comparison;
    char shitfTable[max];
    int m  = strlen(pattern);
    int n = strlen(text);

    for(i=0;i<max;i++){
        shitfTable[i] = m;
    }
    for(i=0;i<m-1;i++){
        shitfTable[(int)pattern[i]] = m-i-1;
    }   
    i=m-1;
    while (i<n){
        k=i;
        j=m-1;
        while(j>=0 && text[k]==pattern[j]){
            j--;
            k--;
            comparison++;
        }
        if(j== -1){
            return comparison;
        }else{
            i += shitfTable[(int)text[i]];
            comparison++;
        }
    }
    printf("comparison : %d\n",comparison);
    return -1;
    
}

int main(){
    char text[max], pattern[max];
    int comparison;

    printf("Enter text: ");
    fgets(text,max,stdin);
    printf("Enter pattern: ");
    fgets(pattern,max,stdin);
    
    text[strcspn(text,"\n")] = 0;
    pattern[strcspn(pattern,"\n")]=0;

    comparison = horsepool(text,pattern);
    if(comparison != -1){
        printf("Success!\ncomparison: %d\n",comparison);

    }else{
        printf("No success!");
    }
    
}