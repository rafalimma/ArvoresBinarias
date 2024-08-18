#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// estrutura de um nó da arvore binária (isso é um nó)
typedef struct Node {
    int valor; // cada nó tem um valor e pode ter filhos
    struct Node* esquerda; // para a esquerda -> menores
    struct Node* direita; // para a direita -> maiores
} Node; // esse é o alias para o struct Node

// retorna um ponteiro do tipo Node* que será o ponteiro para o
// novo nó criado
// "->" acessa o membro da estrutura
Node* criarNo(int valor) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNode->direita = NULL;
    return novoNode;
}

// função que cria um novo nó na arvore:
Node* insertNode(Node* root, int valor) {
    if (root == NULL) {
        root = 
    }
}