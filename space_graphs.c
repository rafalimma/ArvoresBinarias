//
// Created by rafae on 15/11/2024.
//

#include "space_graphs.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 90 // número máximo de vertices estações

// INSTRUÇÕES
// 1. implementar a estrutura de grafos para implementar a rede de estações
// 2. encontrar o caminho mais curto usando um algoritmo específico
// 3. em caso de falahas encontrar alterantivas entre as rotas

FILE *arquivo = fopen("estacoeserotas.csv", "r");


typedef struct Node {
    char *nome[40]; // nome da estação
    // int indentificador;
    int peso;
    struct node *proxima; // aponta para a próxima estação ligada
} node;

typedef struct Graph {
    int estacoes; // número total de estações
    node* adjacentes[MAX];
} graph;

graph* InitGraph(int total_estacoes) {
    graph* space_graph = (graph*)malloc(sizeof(graph));
    space_graph->estacoes = total_estacoes;

    for (int i=0; i<MAX; i++) {
        space_graph->adjacentes[i] = NULL;
        space_graph->adjacentes[i]->peso = 0;
    }
    return space_graph;
}

graph* AdicionaConexao()

int main () {
    printf("Hello World\n");
}