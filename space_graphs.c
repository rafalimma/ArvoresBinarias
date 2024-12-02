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

int busca_adicionaestacao(const char* nome) {
    // copia o nome da estação para dentro da lista de vetores
    for (int i = 0;i < toralEstacoes; i++) {
        // busca a estação pelo nome
        if (strcmp(estacoes[i], nome) == 0) {
            return i;
        }
    }
    if(toralEstacoes < MAX) {
        strcpy(estacoes[toralEstacoes], nome);
        return toralEstacoes++;
    }
    if (toralEstacoes >= MAX) {
        printf("Erro: número máximo de estações atingido!\n");
        return -1; // Indica falha
    }
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

int rotaBloqueada(const char* origem, const char* destino) {
    const char* rotas_bloqueadas[][2] = {
        {"Elysium", "Idris"},
        {"Idris", "Rethor"},
        {"Rethor", "Croshaw"},
        {"Croshaw", "Nul"}
    };
    for (int i = 0; i < 4; i++) {
        if ((strcmp(origem, rotas_bloqueadas[i][0]) == 0 && strcmp(destino, rotas_bloqueadas[i][1]) == 0) ||
            (strcmp(origem, rotas_bloqueadas[i][1]) == 0 && strcmp(destino, rotas_bloqueadas[i][0]) == 0)) {

            return 1; // Rota bloqueada
            }
    }
    return 0;
}

int Rotas_maisRapidasBloqueadas(const char* origem, const char* destino) {
    const char* rotas_bloqueadas[][2] = {
        {"Oya", "Castra"},
        {"Vega", "Nul"},
    };
    for (int i = 0; i < 2; i++) {
        if ((strcmp(origem, rotas_bloqueadas[i][0]) == 0 && strcmp(destino, rotas_bloqueadas[i][1]) == 0) ||
            (strcmp(origem, rotas_bloqueadas[i][1]) == 0 && strcmp(destino, rotas_bloqueadas[i][0]) == 0)) {

            return 1; // Rota bloqueada
            }
    }
    return 0;
}


graph* AdicionaConexao(graph* grafo, char* origem, char* destino, int peso, int contigencia) {
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
    // função paara bloquear as primeiras rotas, as que ja estão bloqueadas inicialmente
    if (contigencia == 0) {
        if (rotaBloqueada(origem, destino)) {
            printf("Rota bloqueada: %s -> %s\n", origem, destino);
            return grafo; // retorna o grafo para a próxima iteração fazendo com que a rota seja bloqueada
        }
    }
    // função para bloquear rotas mais utilizadas
    if (contigencia == 1) {
        if (Rotas_maisRapidasBloqueadas(origem, destino)) {
            printf("Rota bloqueada: %s -> %s\n", origem, destino);
            return grafo; // retorna o grafo para a próxima iteração fazendo com que a rota seja bloqueada
        }
    }

    //Essa abordagem insere nós no início da lista, o que é eficiente (complexidade O(1))
    strcpy(novonode->nome, destino); // copia o nome de destino (str) para o membro nome
    novonode->peso = peso;
    novonode->proxima = grafo->adjacentes[indiceOrigem];// aponta para o nó que atualente é o primeiro da lista
    grafo->adjacentes[indiceOrigem] = novonode; // novo node vai ser o primeiro elemento da lista

    return grafo;
}

void abrirCSV(const char* arquivo, graph* grafo, int contingencia) {
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
            AdicionaConexao(grafo, origem, destino, peso, contingencia);
        }
    }
    fclose(fp);
}
// procura o menor vertice com a menor distancia até o momento e que não
// tenha sido visitado
int procuraMenorDistancia(int *dist, int *visitado, int NV) {
    int menor = INF, menorIndice = -1;
    for (int i = 0; i < NV; i++) {
        if (!visitado[i] && dist[i] < menor) {
            menor = dist[i];
            menorIndice = i;
        }
    }
    return menorIndice;
}
// ini é o vertice inicial
// ant ordem que precisa ser visitada
// dist distancia do veritice inicial até odestino
// ambos com mesmo tamnaho de numero de vertices do grafo
void MenorCaminhoGrafo(graph* grafo, int ini, int* ant, int* dist) {
    // NV numero de vertices
    int NV = grafo->estacoes;
    int visitados[MAX] = {0};

    //inicializa distancias
    for (int i = 0; i < NV; i++) {
        dist[i] = INF;
        ant[i] = -1;
    }
    dist[ini] = 0;
    for (int i = 0; i < NV - 1; i++) {
        int u = procuraMenorDistancia(dist, visitados, NV);
        if (u == -1) break;
        visitados[u] = 1;
        node* atual = grafo->adjacentes[u];
        while (atual) {
            int v = busca_adicionaestacao(atual->nome);
            if (!visitados[v] && dist[u] != INF && dist[u] + atual->peso < dist[v]) {
                dist[v] = dist[u] + atual->peso;
                ant[v] = u;
            }
            atual = atual->proxima;
        }
    }
}

void imprimeCaminho(int* ant, int destino) {
    if (ant[destino] == -1) {
        printf("%s", estacoes[destino]);
        return;
    }
    imprimeCaminho(ant, ant[destino]);
    printf(" -> %s", estacoes[destino]);
}

void adicionaEstacao(graph* grafo, const char* novaEstacao) {
    if (busca_adicionaestacao(novaEstacao) != -1) {
        printf("Estação '%s' adicionada\n", novaEstacao);
    } else {
        printf("Erro p/ adicionar '%s'.\n", novaEstacao);
    }
}

void adicionanewConexao(graph* grafo, const char* origem, const char* destino, int peso) {
    AdicionaConexao(grafo, (char*)origem, (char*)destino, peso, 0);
}

void liberaGrafo(graph* grafo) {
    for (int i = 0; i < grafo->estacoes; i++) {
        node* atual = grafo->adjacentes[i];
        while (atual) {
            node* temp = atual;
            atual = atual->proxima;
            free(temp);
        }
    }
    free(grafo);
}

int main () {
    int sem_contingencia = 0;
    graph* grafo = InitGraph(MAX);
    abrirCSV("C:/SpaceGraphs/estacoeserotas.csv", grafo, sem_contingencia);

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
    printf("Calculando rota da Terra até Centauri");

    int ant[MAX];
    int dist[MAX];

    int origem = busca_adicionaestacao("Terra");
    int destino = busca_adicionaestacao("Centauri");

    MenorCaminhoGrafo(grafo, origem, ant, dist);
    printf("Menor caminho da Terra ate Centauri é:\n");
    imprimeCaminho(ant, destino);
    printf("\nDistancia total: %d\n", dist[destino]);
    // free(grafo);
    liberaGrafo(grafo);
    printf("Calculando rotas de contingencia...\n");
    graph* grafo_contingencia = InitGraph(MAX);
    int com_contingencia = 1;
    abrirCSV("C:/SpaceGraphs/estacoeserotas.csv", grafo_contingencia, com_contingencia);
    printf("Calculando rota da Terra ate Centauri\n");
    MenorCaminhoGrafo(grafo_contingencia, origem, ant, dist);
    printf("Menor caminho da Terra ate Centauri usando uma contingencia caso rotas principais sejam bloqueadas e: \n");
    imprimeCaminho(ant, destino);
    printf("\nDistancia total percorrida: %d\n", dist[destino]);
    liberaGrafo(grafo);

    printf("Calculando rotas de contingencia caso uma nova estação seja adicionanda ou excluida...\n");
    graph* grafo_adicionando_estacoes = InitGraph(MAX);
    abrirCSV("C:/SpaceGraphs/estacoeserotas.csv", grafo_adicionando_estacoes, sem_contingencia);
    adicionaEstacao(grafo_adicionando_estacoes, "Raff");
    adicionanewConexao(grafo_adicionando_estacoes, "Raff", "Pallas", 4);
    for (int i=0; i<toralEstacoes; i++) {
        //cada indice i contem a lista encadeada de conexões para a estação i
        node* atual =  grafo_adicionando_estacoes->adjacentes[i];
        printf("Estacao:%s\n", estacoes[i]);
        while (atual != NULL) {
            // percorre a lista de conexões da estação i
            printf("  -> %s (peso: %d)\n", atual->nome, atual->peso);
            atual = atual->proxima;
        }
    }
    printf("Calculando rota da Terra ate Centauri\n");
    MenorCaminhoGrafo(grafo_contingencia, origem, ant, dist);
    printf("Menor caminho da Terra ate Centauri porem com 1 nova estacao adicionanda e: \n");
    imprimeCaminho(ant, destino);
    printf("\nDistancia total percorrida: %d\n", dist[destino]);

    liberaGrafo(grafo);


    return 0;
}
