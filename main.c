#include <stdio.h>
#include <stdlib.h>
#define MAX 6
// Para implementar uma matriz de adjacência em C, vamos usar um array bidimensional
// (ou uma "tabela" de números) onde cada posição [i][j]
// indica se a pessoa i é amiga da pessoa j. Se i e j são amigos, colocamos "1"; caso contrário, colocamos "0".

typedef struct Grafo {
    int amigos[MAX];
    int adhjacencia[MAX][MAX];
} Grafo;

Grafo* InitGrafo(int n_amigos) {
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    g->amigos = n_amigos;
    for (int i=0;i<MAX;i++) {

    }
}

int main(void)
{
    printf("Hello, World!\n");
    return 0;
}
