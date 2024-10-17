

#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_ALFABETO 26

typedef struct TrieNode {
    struct TrieNode* filhos[TAMANHO_ALFABETO];// ponteiro para cada letra
    bool fimDaPalavra; // indica se é o fim da palavra
};

TrieNode* criarno() {
    TrieNode* novoNo = (TrieNode*)malloc(sizeof(TrieNode));
    novoNo->fimDaPalavra = false; 

    for(int i=0;i < TAMANHO_ALFABETO; i++) {
        novoNo->filhos[i] = NULL;
    }
    return novoNo;
}

void Inserir(TrieNode* root, const char* palavra) {
    TrieNode* atual = root;

    for (int i=0; palavra[i] != '\0'; i++) {
        int index = palavra[i] - 'a';

        if (atual->filhos[index] == NULL) {
            atual->filhos[index] = criarno();
        }
        
    }
}