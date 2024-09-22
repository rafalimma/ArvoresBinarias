#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
    int valor;
    struct Node* left;
    struct Node* right;
    int altura; // altura da arvore para ver se esta balanceada
} Node;

Node* novoNode(int valor) { // tipo ponteiro da estrutura Node
    Node* node = (Node*)malloc(sizeof(Node));
    node->valor = valor;
    node->left = NULL;
    node->right = NULL;
    node->altura = 1;
    return node;
} // função aloca memória para o nó e inicializa seus valores iniciais.

int obterAltura(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->altura;
}

Node* InserirnovoNo(Node* node, int valor) {
    if (node == NULL) {
        return novoNode(valor);
    }
    if (valor < node->valor) {
        node->left = InserirnovoNo(node->left, valor);
    } else if (valor > node->valor) {
        node->right = InserirnovoNo(node->right, valor);
    } else {
        return node;
    }

    node->altura = 1 + (obterAltura(node->left) > obterAltura(node->right) ? obterAltura(node->left) : obterAltura(node->right))

    int balance = Equilibrio(node);
    return node;
}

int Equilibrio(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return obterAltura(node->left) - obterAltura(node->right);
}

int main() {
    int vet[6];
    Node* node = NULL;
    for (int i=0;i<6;i++) {
        printf("Digite um valor: ");
        scanf("%d", &vet[i]);
    }
    for (int i=0;i<6;i++) {
        printf("\n%d", vet[i]);
        IserirnovoNo(node, vet[i]);
    }
    return 0;
}

