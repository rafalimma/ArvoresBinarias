//
// Created by rafae on 15/11/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX 100 // número máximo de vertices estações
#define INF INT_MAX

// INSTRUÇÕES
// 1. implementar a estrutura de grafos para implementar a rede de estações
// 2. encontrar o caminho mais curto usando um algoritmo específico
// 3. em caso de falahas encontrar alterantivas entre as rotas

// rotas bloqueadas:
// Elysium - Idris;
// Idris - Rethor;
// Rethor - Croshaw;
// Croshaw - Nul;


// para salvar os nomes das estações
char estacoes[MAX][40];// vetor char
int toralEstacoes = 0; // número total de estaçoes registradas

typedef struct Node {
    char nome[40]; // nome da estação
    // int indentificador;
    int peso;
    struct Node *proxima; // aponta para a próxima estação ligada
} node;

typedef struct Graph {
    int estacoes; // número total de estações
    node* adjacentes[MAX];
} graph;

typedef struct {
    int vertice;
    int distancia;
} heapNode;


int busca_adicionaestacao(const char* nome) {
    // copia o nome da estação para dentro da lista de vetores
    for (int i = 0;i < toralEstacoes; i++) {
        if (strcmp(estacoes[i], nome) == 0) {
            return i;
        }
    }
    if(toralEstacoes < MAX) {
        strcpy(estacoes[toralEstacoes], nome);
        return toralEstacoes++;
    }
    printf("Erro: número máximo de estações atingido!\n");
    return -1; // Indica falha
}

graph* InitGraph(int total_estacoes) {
    graph* space_graph = (graph*)malloc(sizeof(graph));
    space_graph->estacoes = total_estacoes;

    for (int i=0; i<MAX; i++) {
        // inicializa todos os vértices como NULL
        space_graph->adjacentes[i] = NULL;
    }
    return space_graph;
}

graph* AdicionaConexao(graph* grafo, char* origem, char* destino, int peso) {
    int indiceOrigem = busca_adicionaestacao(origem);
    int indiceDestino = busca_adicionaestacao(destino);

    if (indiceDestino == -1 || indiceOrigem == -1) {
        printf("Erro ao adicionar conexão");
        return 0;
    }

    node* novonode = (node*)malloc(sizeof(node));
    if (!novonode) {
        printf("Erro ao alocar memória\n");
        return grafo; // Retorna o grafo inalterado em caso de erro
    }
    //Essa abordagem insere nós no início da lista, o que é eficiente (complexidade O(1))
    strcpy(novonode->nome, destino); // copia o nome de destino (str) para o membro nome
    novonode->peso = peso;
    novonode->proxima = grafo->adjacentes[indiceOrigem];// aponta para o nó que atualente é o primeiro da lista
    grafo->adjacentes[indiceOrigem] = novonode; // novo node vai ser o primeiro elemento da lista

    return grafo;
}
// função que adiciona as estações dos dois lados da conexão
//void AdicionaConexaoBidirecional(graph* grafo, const char* origem, const char* destino, int peso) {
    //AdicionaConexao(grafo, origem, destino, peso);
    //AdicionaConexao(grafo, destino, origem, peso); // Adiciona a conexão na direção oposta
//}

void abrirCSV(const char* arquivo, graph* grafo) {
    FILE* fp = fopen(arquivo, "r");
    if (!fp) {
        printf("Erro ao abrir o arquivo: %s\n", arquivo);
        return;
    }
    char linha[256];
    // fgets lê cada linha do CSV
    while (fgets(linha, sizeof(linha), fp)) {
        // desconsidera nova linha
        linha[strcspn(linha, "\n")] = '\0';
        // strtok divide os dados por linha
        char* origem = strtok(linha, ",");
        char* destino;
        char* peso_str;

        while ((destino = strtok(NULL, ",")) && (peso_str = strtok(NULL, ","))) {
            int peso = atoi(peso_str); // Converte o peso para inteiro
            AdicionaConexao(grafo, origem, destino, peso);
        }
    }
    fclose(fp);
}

int procuraMenorDistancia(float *dist, int *visitado, int NV) {

}
// ant ordem que precisa ser visitada
// dist distancia do veritice inicial até odestino
// ambos com mesmo tamnaho de numero de vertices do grafo
void MenorCaminhoGrafo(graph grafo*, int ini, int *ant, float *dist) {
    int i, cont, NV, ind, *visitado, u;
    cont = NV = grafo->estacoes;
    visitado = (int*)malloc(NV * sizeof(int));
    for (i = 0; i < NV; i++) {
        // inicializando distancias anteriores
        ant[i] = -1;
        dist[i] = -1;
        visitado[i] = 0;
    }
    while(cont > 0) {
        u = procuraMenorDistancia(dist, visitado, NV);
        if (u == -1) {
            break;
            //...........
        }
    }
}

int main () {
    graph* grafo = InitGraph(MAX);
    abrirCSV("C:/SpaceGraphs/estacoeserotas.csv", grafo);
    // itera por todas as estações
    for (int i=0; i<toralEstacoes; i++) {
        //cada indice i contem a lista encadeada de conexões para a estação i
        node* atual =  grafo->adjacentes[i];
        printf("Estacao:%s\n", estacoes[i]);
        while (atual != NULL) {
            // percorre a lista de conexões da estação i
            printf("  -> %s (peso: %d)\n", atual->nome, atual->peso);
            atual = atual->proxima;
        }
    }
    free(grafo);
    return 0;
}
