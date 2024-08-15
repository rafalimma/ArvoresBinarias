#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    char nome[20];
    float preco;
    int quantidade;
}

void main() {
    int option;

    printf('O que você quer fazer?');
    printf('adicionar[1], listar[2], buscar[3]');
    scanf("%d", &option);

    switch (option) {
        case 1:
         adicionar()   
    }
}