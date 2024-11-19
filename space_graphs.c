//
// Created by rafae on 15/11/2024.
//

#include "space_graphs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 90 // número máximo de vertices estações

// INSTRUÇÕES
// 1. implementar a estrutura de grafos para implementar a rede de estações
// 2. encontrar o caminho mais curto usando um algoritmo específico
// 3. em caso de falahas encontrar alterantivas entre as rotas

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

graph* AdicionaConexao(graph* grafo, int origem, char* destino, int peso) {
    node* novonode = (node*)malloc(sizeof(node));
    if (!novonode) {
        printf("Erro ao alocar memória\n");
        return grafo; // Retorna o grafo inalterado em caso de erro
    }
    strcpy(novonode->nome[origem], destino);
    novonode->peso = peso;
    grafo->adjacentes[origem] = novonode;

    return grafo;
}

void abrirCSV(const char* arquivo, graph* grafo) {
    FILE* fp = fopen(arquivo, "r");
    char linha[256];
    // fgets lê cada linha do CSV
    while (fgets(linha, sizeof(linha), fp)) {
        // desconsidera nova linha
        linha[strcspn(linha, "\n")] = '\0';
        // strtok divide os dados por linha
        char* origem_str = strtok(linha, ",");
        char* destino = strtok(NULL, ",");
        char* peso_str = strtok(NULL, ",");

        if (origem_str && destino && peso_str) {
            // converte peso str em numero
            // ASCII to integer
            int peso = atoi(peso_str);
            // cria um índice para a origem (usando a primeira letra dela)
            int origem = origem_str[0] % MAX;// por exemplo 'v' = 86 | 86%90 = 86
            AdicionaConexao(grafo, origem, destino, peso);
        } else {
            printf("Erro ao abrir o arquivo\n");
        }
    }
    fclose(fp);
}


int main () {
    graph* grafo = InitGraph(MAX);
    abrirCSV("estacoeserotas.csv", grafo);
    for (int i=0; i<MAX; i++) {
        node* atual =  grafo->adjacentes[i];
        printf("Estacao %d:\n", i);
        while (atual != NULL) {
            printf("  -> %s (peso: %d)\n", atual->nome, atual->peso);
            atual = atual->proxima;
        }
    }
    free(grafo);
    return 0;
}
