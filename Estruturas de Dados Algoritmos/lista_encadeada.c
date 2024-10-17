// vantagens:
// dinamicas, não precisa saber o tamanho dos dados
// insersões e remoções no meio da lista sao faceis
// desvantagens
// ocupam mais memoria
// 2 espaçoes para cada nó

// Imagina uma lista de brinquedos que você tem, onde cada
// brinquedo lembra qual é o próximo brinquedo da fila. 
// Esse tipo de lista é o que chamamos de lista encadeada.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int info; // informaçõao do nó
    struct Node* proximo; // ponteiro p/ proximo nó
} Node;

// função para criar um novo nó:
Node* CriarNo(int valor) {
    Node* novono = (Node*)malloc(sizeof(Node));
    novono->info = valor; // armazena o valor / informação do nó
    novono->proximo = NULL; // aponta null para o proximo elemento, ainda não tem o proximo
    return novono;
}

// função que insere o no no inicio da lista
void InsereNo(struct Node** head, int valor) {
    struct Node* novono = CriarNo(valor); // o prox valor sempre vai estar apontando pra null
    novono->proximo = *head;
    *head = novono; // salvando head com o valor do novo no que sera o atual
}

void PrintLista(Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ->", current->info);
        current = current->proximo;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    InsereNo(&head, 10);
    InsereNo(&head, 30);
    InsereNo(&head, 20);

    PrintLista(head);

    return 0;
}
