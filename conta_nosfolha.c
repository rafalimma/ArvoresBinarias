#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} node;

Node* Novono(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int ContarFolhas(Node* root) {
    if (root == NULL) {
        return 0;
    }

    // verificação se o no não tem filhos
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    
    return ContarFolhas(root -> left) + ContarFolhas(root->right);
}