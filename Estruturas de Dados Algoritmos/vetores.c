#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno{
    char nome[20];
    int idade;
    float nota;
};

int main() {
    int vetor[10];
    int i, soma = 0;
    for (int i=0;i<10;i++) {
        printf("informe o %d% numero: ", i+1);
        scanf("%d", &vetor[i]);
    }
    for(int i=0;i<10;i++) {
        i = vetor[i];
        soma += i;
    }
    printf("soma: %d ", soma );
    struct Aluno aluno1 = {"Joao", 20, 9};
    return 0;
}