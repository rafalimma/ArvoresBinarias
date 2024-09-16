#include <stdlib.h>
#include <stdio.h>
#define MAX 100

// : Escreva um programa que leia uma sequência de
//números e os armazene em uma pilha.

typedef struct {
    int items;
    int topo;
} Pilha;

void InicializaPilha(Pilha* pilha) {
    pilha->topo = -1;
}


void ArmazenarPilha(int arr[], int size){
    printf("Armazenando os valores do vetor em uma Pilha...\n");
    for (int i=0;i <= 5;i++) {
        pilha->topo++;
        pilha->items[pilha->topo] = arr[i];
    }
}

int main() {
    Pilha pilha0;

    int valor;
    int vet[5];

    for(int i=0;i <= 5; i++) {
        printf("Digite um numero: ");
        scanf("%d\n", &valor);
        vet[i] = valor;
    }
    printf('Inicializando a pilha...');
    InicializaPilha(pilha0);
    ArmazenarPilha(vet, 5);

}