#include <stdio.h>
#include <stdlib.h>
#define ALFABETO 26

typedef struct Node {
    Node TrieNode* letra[ALFABETO];
    bool fim_palavra;
} Node

Node* Criarno() {
    Node* node = (Node)malloc(sizeof(Node*));
    node->fim_palavra = false;
    // inicializar cada letra
    for(int i=0;i < TAMANHO_ALFABETO; i++) {
        node->letra[i] = NULL;
    }
    return node;
}

Node* Insert() {
    
}