#include <stdio.h>
#include <stdlib.h>

// no da fila
typedef struct No {
    char nome_pessoa;
    struct No* next;
} No;

// ponteiros para final e inicio da fila

typedef struct Fila {
    struct No *front, back*
} Fila;

No* CriarNo(char* nome_pessoa) {
    No* novono = (No*)malloc(sizeof(No));
    novono->nome_pessoa = nome_pessoa;
    novono->next = NULL;
    return novono;
}

No* Insert(No* nodo) {
    
}