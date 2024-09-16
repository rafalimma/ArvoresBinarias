#include <stdlib.h>
#include <stdio.h>
#define MAX 100

// int main() {
//     int vet[5];
//     int valor;
//     int soma = 0;

//     for (int i=0;i <= 5; i++) {
//         printf("digite o elemento %d do vetor: ", i + 1);
//         scanf("%d", &valor);
//         vet[i] = valor;
//     }
//     for (int i=0;i<=5; i++) {
//         printf("O elemento %d do vetor e %d\n", i+1, vet[i]);
//     }

//     for (int i=0;i<=5; i++) {
//         soma += vet[i];
//     }
//     printf("_____________\n");
//     printf("A soma dos valores e: %d", soma);

//     return 0;
// }

typedef struct {
    int items[MAX];
    int topo;
} Pilha;

void inicializaPilha(Pilha* pilha){
    pilha->topo = -1;
}

int EstaVazia(Pilha* pilha) {
    return pilha->topo == -1;
}

int Topo(Pilha* pilha) {
    if (EstaVazia(pilha)) {
        printf("Pilha vazia\n");
        return -10;
    }
    return pilha->items[pilha->topo];
}

int pop(Pilha* pilha) {
    if (EstaVazia(pilha)) {
        printf("Pilha vazia\n");
        return -10;
    }
    int item = pilha->items[pilha->topo];
    pilha->topo--;
    return item;
}

int Push(Pilha* pilha, int item) {
    if (EstaVazia(pilha)) {
        printf("A pilha esta vazia");
        return -10;
    }
    pilha->topo++; // somando o topo
    pilha->items[pilha->topo] = item;
    return item;
}



int main() {
    Pilha pilha1;
    int valor = 40;

    inicializaPilha(&pilha1);

    if(EstaVazia(&pilha1)) {
        printf("A pilha esta vazia");
    } else {
        printf("A pilha nao esta vazia");
    }

    int topo_pilha = Topo(&pilha1);
    printf("%d", topo_pilha);
    int push = Push(&pilha1, valor);
    printf("%d", push);
}

