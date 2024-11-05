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

graph* createGraph(int amigoss) {
    graph* g = (graph*)malloc(sizeof(graph));
    g->amigoss = amigoss; // aqui será um vertice

    g->adjacentes = (node*)malloc(sizeof(node));
    // for no adjacentes pra inicializar cada posição

}
