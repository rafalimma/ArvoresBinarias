#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node* proximo;
}

Node* CriarNo(int valor) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->valor = valor;
    newnode->proximo = NULL;
    return newnode;
}

Node* Inserir(struct Node** head, int valor) {
    Node* newnode = CriarNo(valor);
    newnode->proximo = head*;
    *head = newnode;
}

int main() {
    int arr[];
    for(int i)
    printf("Digite um valor: ");
    scanf("%d", n);
    Node* head = NULL;
    Inserir(&head, n)
}