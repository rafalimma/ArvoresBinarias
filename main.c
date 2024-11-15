#include <stdio.h>
#include <stdlib.h>
#define MAX 6
// Para implementar uma matriz de adjacência em C, vamos usar um array bidimensional
// (ou uma "tabela" de números) onde cada posição [i][j]
// indica se a pessoa i é amiga da pessoa j. Se i e j são amigos, colocamos "1"; caso contrário, colocamos "0".

typedef struct Grafo {
    int amigos;
    int adjacencia[MAX][MAX];
} Grafo;

Grafo* InitGrafo(int n_amigos) {
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    g->amigos = n_amigos;
    for (int i=0;i<MAX;i++) {
        for (int j=0;j<MAX;j++) {
            g->adjacencia[i][j] = 0;
        }
    }
    return g;
}

void InsertAmizade(Grafo* g, int amigo1, int amigo2) {
    g->adjacencia[amigo1][amigo2] = 1;
    g->adjacencia[amigo2][amigo1] = 1;
}

int main() {
    Grafo* grafoo_amigos = InitGrafo(MAX);
    InsertAmizade(grafoo_amigos, 0, 2);
    InsertAmizade(grafoo_amigos, 1, 3);
    InsertAmizade(grafoo_amigos, 4, 5);

    free(grafoo_amigos);
    return 0;
}

