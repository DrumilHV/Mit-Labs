#include <stdio.h>
#include <stdlib.h>

// node structure for binary tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

// function to create a new node
node* newNode(int data) {
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// function to insert a node into the binary tree
node* insert(node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// function to get the height of a binary tree
int height(node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

// function to get the balance factor of a node
int balanceFactor(node* root) {
    if (root == NULL) {
        return 0;
    }
    return height(root->left) - height(root->right);
}

// function to print the balance factor of every node in the binary tree
void printBalanceFactors(node* root) {
    if (root == NULL) {
        return;
    }
    printf("Node %d: balance factor = %d\n", root->data, balanceFactor(root));
    printBalanceFactors(root->left);
    printBalanceFactors(root->right);
}

int main() {
    node* root = NULL;
    int n, i, data;
    
    // input nodes into binary tree
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);
    printf("Enter the nodes:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }
    
    // print balance factors of all nodes in binary tree
    printBalanceFactors(root);
    
    return 0;
}
