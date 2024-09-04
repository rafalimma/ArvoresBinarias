#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

// inicializa a pilha
void initializeStack(Stack* stack) {
    stack->top = -1 // inicializa o topo com -1, indicando que a pilha
    // esta vazia
}
// verifica se a pilha esta vazia
int isEmpty(Stack* stack) {
    return stack->top == -1
}
// função que verifica se a pilha esta cheia
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
    // retorna true se a pilha estiver cheia
}

// remove um elemento da pilha
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Erro: Pilha vazia\n");
        return -1; // retorna um valor de erro
    }
    return stack->items[(stack->top)]; // Retorna o valor do topo e decremeta
    // o topo
}