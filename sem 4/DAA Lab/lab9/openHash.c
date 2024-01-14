// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX 100

// // node structure for linked list
// typedef struct node {
//     int key;
//     struct node* next;
// } node;

// // function to create a new node
// node* createNewNode(int key) {
//     node* newNode = (node*)malloc(sizeof(node));
//     newNode->key = key;
//     newNode->next = NULL;
//     return newNode;
// }

// // function to insert a key into the hash table
// void insert(int key, node** hashTable) {
//     int index = key % MAX; // calculate hash index
//     node* newNode = createNewNode(key);
//     newNode->next = hashTable[index];
//     hashTable[index] = newNode;
// }

// // function to search for a key in the hash table
// int search(int key, node** hashTable) {
//     int index = key % MAX; // calculate hash index
//     node* currentNode = hashTable[index];
//     int comparisons = 0;
    
//     while (currentNode != NULL) {
//         comparisons++;
//         if (currentNode->key == key) {
//             return comparisons; // successful search
//         }
//         currentNode = currentNode->next;
//     }
    
//     return -comparisons; // unsuccessful search (return negative value to differentiate from successful search)
// }

// int main() {
//     node** hashTable = (node**)malloc(MAX * sizeof(node*));
//     memset(hashTable, 0, MAX * sizeof(node*));
//     int n, i, key, comparisons;
    
//     // input keys into hash table
//     printf("Enter the number of keys to insert: ");
//     scanf("%d", &n);
//     printf("Enter the keys:\n");
//     for (i = 0; i < n; i++) {
//         scanf("%d", &key);
//         insert(key, hashTable);
//     }
    
//     // search for keys in hash table
//     printf("Enter the number of keys to search for: ");
//     scanf("%d", &n);
//     printf("Enter the keys:\n");
//     for (i = 0; i < n; i++) {
//         scanf("%d", &key);
//         comparisons = search(key, hashTable);
//         if (comparisons > 0) {
//             printf("Key %d found with %d comparisons.\n", key, comparisons);
//         } else {
//             printf("Key %d not found with %d comparisons.\n", key, -comparisons);
//         }
//     }
    
//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
# define Max 100
typedef struct node{
    int key;
    struct node * next;
}node;

node * createNewNode(int key){
    node * temp = (node*)malloc(sizeof(node));
    temp->key = key;
    temp->next = NULL;
    return temp;
}

void insertNode(int key ,  node ** hashTable){
    int index = key % 100;
    node * temp = createNewNode(key);
    temp->next = hashTable[index];
    hashTable[index] = temp;
}

int find(int key , node** hashTable){
    int index = key % Max;
    int comparison = 0;
    node * temp;
    temp = hashTable[index];
    while (temp->next != NULL)
    {
        comparison++;
        if(temp->key == key){
            return comparison;
        }
        temp = temp->next;
    }
    return -1*comparison;
    
}


int main(){
    node ** hashTable = (node**)malloc(Max*sizeof(node*));
    int key;
    int i,n;
    printf("enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the nodes:");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&key);
        insertNode(key, hashTable);
    }
    printf("Enter the seach key: ");
    scanf("%d",&key);
    int comparison  = find(key, hashTable);
    if(comparison>0){
        printf("key found with %d comparison.",comparison);
    }else{
        printf("key not found with %d comparison.",comparison);

    }
    

}