#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// node structure for hash table
typedef struct node {
    int key;
    int status; // 0 for empty, 1 for occupied, 2 for deleted
} node;

// function to insert a key into the hash table
int insert(int key, node* hashTable) {
    int index = key % MAX; // calculate hash index
    int i = index;
    int comparisons = 0;
    
    while (hashTable[i].status == 1) {
        comparisons++;
        if (hashTable[i].key == key) {
            return comparisons; // key already exists
        }
        i = (i + 1) % MAX; // linear probing
        if (i == index) {
            return -comparisons; // hash table is full
        }
    }
    
    hashTable[i].key = key;
    hashTable[i].status = 1;
    
    return comparisons; // successful insertion
}

// function to search for a key in the hash table
int search(int key, node* hashTable) {
    int index = key % MAX; // calculate hash index
    int i = index;
    int comparisons = 0;
    
    while (hashTable[i].status != 0) {
        comparisons++;
        if (hashTable[i].key == key && hashTable[i].status == 1) {
            return comparisons; // successful search
        }
        i = (i + 1) % MAX; // linear probing
        if (i == index) {
            break;
        }
    }
    
    return -comparisons; // unsuccessful search (return negative value to differentiate from successful search)
}

int main() {
    node* hashTable = (node*)malloc(MAX * sizeof(node));
    memset(hashTable, 0, MAX * sizeof(node));
    int n, i, key, comparisons;
    
    // input keys into hash table
    printf("Enter the number of keys to insert: ");
    scanf("%d", &n);
    printf("Enter the keys:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        comparisons = insert(key, hashTable);
        if (comparisons > 0) {
            printf("Key %d inserted with %d comparisons.\n", key, comparisons);
        } else {
            printf("Hash table is full, key %d not inserted.\n", key);
        }
    }
    
    // search for keys in hash table
    printf("Enter the number of keys to search for: ");
    scanf("%d", &n);
    printf("Enter the keys:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        comparisons = search(key, hashTable);
        if (comparisons > 0) {
            printf("Key %d found with %d comparisons.\n", key, comparisons);
        } else {
            printf("Key %d not found with %d comparisons.\n", key, -comparisons);
        }
    }
    
    return 0;
}
