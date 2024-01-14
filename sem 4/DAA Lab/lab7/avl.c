#include <stdio.h>
#include <stdlib.h>

// node structure for AVL tree
typedef struct node {
    int data;
    int height;
    struct node* left;
    struct node* right;
} node;

// function to create a new node
node* newNode(int data) {
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->height = 1;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// function to get the height of a node
int height(node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

// function to get the balance factor of a node
int balanceFactor(node* root) {
    if (root == NULL) {
        return 0;
    }
    return height(root->left) - height(root->right);
}

// function to perform left rotation on a subtree rooted at x
node* leftRotate(node* x) {
    node* y = x->right;
    node* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    // update heights
    x->height = (height(x->left) > height(x->right) ? height(x->left) : height(x->right)) + 1;
    y->height = (height(y->left) > height(y->right) ? height(y->left) : height(y->right)) + 1;
    
    return y;
}

// function to perform right rotation on a subtree rooted at y
node* rightRotate(node* y) {
    node* x = y->left;
    node* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    // update heights
    y->height = (height(y->left) > height(y->right) ? height(y->left) : height(y->right)) + 1;
    x->height = (height(x->left) > height(x->right) ? height(x->left) : height(x->right)) + 1;
    
    return x;
}

// function to insert a node into the AVL tree
// function to insert a node into the AVL tree
node* insert(node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        return root; // duplicate data not allowed in AVL tree
    }
    
    // update height of current node
    root->height = (height(root->left) > height(root->right) ? height(root->left) : height(root->right)) + 1;
    
    // check balance factor of current node
    int bf = balanceFactor(root);
    
    // left left case
    if (bf > 1 && data < root->left->data) {
        return rightRotate(root);
    }
    
    // right right case
    if (bf < -1 && data > root->right->data) {
        return leftRotate(root);
    }
    
    // left right case
    if (bf > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    // right left case
    if (bf < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}
// function to perform inorder traversal of the AVL tree
void inorder(node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    node* root = NULL;

    // insert some nodes into the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // print the inorder traversal of the AVL tree
    printf("Inorder traversal of the AVL tree:\n");
    inorder(root);

    return 0;
}
