#include <stdio.h>
#include <stdlib.h>
#define MAX 30
// exemplos com amigos
// na lista de adjacencia usamos Nós para representar cada conexão com amigos
// uma lista para cada amigo
// grafo que guarda todas as listas de amigos
typedef struct node {
    int amigo;
    struct node *proximoamigo; // aponta para o próximo amigo que tem conexão
} node;
// se o amigo A é amigo de B e C teremos um node que representa a amizade
// entre A e B e outro node que representa a amizade entre A e C

typedef struct Graph {
    int amigoss; //número total de amigos (vertices)
    node* adjacentes[MAX];// cada ponteiro desse vetor é um vertice do grafo
} graph;

// criando funções que faz a lista funcionar
// função para criar o grafo que tem -> n total de amigos e
// array de listas de amigo para cada amigo

graph* initGraph(int amigoss) {
    graph* g = (graph*)malloc(sizeof(graph)); // aqui eu to alocando a estrutura inteira
    g->amigoss = amigoss; // aqui será um vertice

    for (int i=0; i<amigoss; i++) {
        printf("pondo pa nulo\n");
        g->adjacentes[i]->proximoamigo = NULL; // armazena todos os amigos da pessoa i
    }
    return g;
}

graph* insertGraph(graph* grafoo_amigos, int amigo, int amigoss) {
    if (amigoss > MAX) {
        return  NULL;
    } else {
        for (int i=0; i<amigoss; i++) {
            if (i == amigo) {
                grafoo_amigos->adjacentes[i]->proximoamigo->amigo = amigo; // aqui eu estou criando uma conexão
                return grafoo_amigos;
            }
        }
    }

}

int main() {
    graph* grafoo_amigos = initGraph(10);
    for (int i=0;i<grafoo_amigos->amigoss;i++) {
        printf("Amigo:", i, grafoo_amigos->adjacentes[i]->proximoamigo);
    }
    free(grafoo_amigos);
    return 0;
}
