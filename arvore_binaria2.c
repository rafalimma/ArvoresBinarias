#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int valor;
    struct Node* left;
    struct Node* right;
} Node;

Node* CriarNo(int valor) {
    Node* newnode = (Node*)malloc(sizeof(Node))
    newnode->valor = valor;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode
}

Node insertNode(Node* root, int valor) {
    if (root == NULL) {
        root = criarNo(valor);
    } else if (valor <= root->valor) {
        root->left = insertNode(root->left, valor)
    }
}