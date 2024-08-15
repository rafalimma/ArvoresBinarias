#include <stdio.h>
#include <stdlib.h>


typedef struct Aluno{

    char nome[20];
    int idade;

}Aluno;

int main() {
    
    int vetor[3] = {10, 20, 30};
    Aluno aluno[100];
    Aluno alunorafa = {"Rafa", 18};
    aluno[2] = alunorafa;

    for (int i = 0;i < 3; i++) {
        printf("%d \n", vetor[i]);
    }

    printf("\n");
    Aluno aluno1 = {"Rafael Lima", 18};

    printf("Nome: %s \n", aluno1.nome);
    printf("Idade: %d \n", aluno1.idade);
    return 0;
}
