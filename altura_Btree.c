#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore binária
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Função que calcula a altura da árvore binária
int altura(struct Node* root) {
    // Se a árvore está vazia, a altura é -1 (ou pode ser 0, dependendo da convenção)
    if (root == NULL) {
        return -1;
    }
    
    // Calcula a altura da subárvore esquerda e direita
    int alturaEsquerda = altura(root->left);
    int alturaDireita = altura(root->right);
    
    // A altura da árvore é o maior valor entre a subárvore esquerda e direita + 1
    return (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
}

// Função auxiliar para criar um novo nó
struct Node* novoNo(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função principal
int main() {
    // Criando uma árvore de exemplo
    struct Node* root = novoNo(1);
    root->left = novoNo(2);
    root->right = novoNo(3);
    root->left->left = novoNo(4);
    root->left->right = novoNo(5);

    // Calcula e imprime a altura da árvore
    printf("A altura da árvore é: %d\n", altura(root));
    
    return 0;
}