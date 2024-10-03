// vantagens:
// dinamicas, não precisa saber o tamanho dos dados
// insersões e remoções no meio da lista sao faceis
// desvantagens
// ocupam mais memoria
// 2 espaçoes para cada nó

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info; // informaçõao do nó
    struct Node* proximo // ponteiro p/ prox elemento
} Node;

// duplamente encadeada:

typedef struct Node {
    int info;
    struct Node* proximo;
    struct Node* anterior;
} Node;

Node* inicia(Node* nodo, int info) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->info = info;
    node->proximo = NULL;
    node->anterior = NULL;
    return node;
}





int main() {

}