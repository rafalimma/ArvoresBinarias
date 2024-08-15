// dada uma pilha imprima ela

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100


typedef struct {
    int items[MAX_SIZE];
    int topo;
} PilhaEst;

int cheiaPilha(PilhaEst*pilha) {
    return (pilha->topo==MAX_SIZE-1);
}