#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct Livro {
    char nome[100];
    char autor[50];
    int paginas;
} Livro;

void Insert(struct Livro* livros, int* n_livros) {
    int qtd;
    printf("Quantidade de livros que deseja inserir: \n");
    scanf("%d", &qtd);

    getchar();

    for(int i=0;i<qtd;i++) {
        printf("livro %d:\n", i + 1);
        printf("Titulo do livro: ");
        scanf(" %[^\n]", livros[i].nome);
        printf("\nAutor do livro:");
        scanf(" %[^\n]", livros[i].autor);
        printf("\nNumero de paginas do livro:");
        scanf("%d", &livros[i].paginas);
    }
    printf("Livros adicionados!\n");

    for (int i=0;i<qtd;i++) {
        printf("livro %d:\n", i+1);
        printf("%s \n", livros[i].nome);
        printf("%s \n", livros[i].autor);
        printf("%d \n", livros[i].paginas);
    }
    n_livros += qtd;
}

int Buscar(struct Livro* livros, int n_livros) {
    int opc;
    char titulo[100];
    char autor[50];
    
    printf("\nBuscar por: ");
    printf("\n1. titulo          2. autor");
    scanf("%d", &opc);
    switch(opc) {
        case 1:
            printf("\nDigite um titulo para buscar: ");
            scanf("%s", titulo);
            for (int i=0;i<n_livros;i++) {
                if (strcmp(titulo, livros[i].nome) == 0) {
                    printf("\nLivro %d", i + 1);
                    printf("\ntitulo: %s", livros[i].nome);
                    printf("\nAutor: %s", livros[i].autor);
                    printf("\nPaginas: %d", livros[i].paginas);
                    return 0;
                }
            }
            printf("Livro nao encontrado.");
            break;
        case 2:
            printf("\nDigite um autor para buscar: ");
            scanf("%s", autor);
            for (int i=0;i<n_livros;i++) {
                if (strcmp(autor, livros[i].autor) == 0) {
                    printf("\nLivro %d", i + 1);
                    printf("\ntitulo: %s", livros[i].nome);
                    printf("\nAutor: %s", livros[i].autor);
                    printf("\nPaginas: %d", livros[i].paginas);
                    return 0;
                }
            }
            printf("\nLivro nao encontrado.");
            break;
        default:
            printf("Opcao invalida.");
    }
}

int main() {
    int opcao;
    int n_livros = 0;
    Livro livros[MAX];

    while(1) {
        printf("\n___SISTEMA_DE_ARQUIVAMENTO_DE_LIVROS___\n");
        printf("\n");
        printf("Escolha uma opcao:\n ");
        printf("1. Buscar\n");
        printf("2. Inserir\n");
        printf("3. Deletar\n");
        printf("4. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Buscar livro");
                Buscar(livros, n_livros);
                continue;
                break;
            case 2:
                printf("Inserir livro\n");
                Insert(livros, &n_livros);
                continue;
                break;
            case 3:
                printf("Deletar livro");
                break;
            case 4:
                printf("SAIR");
                exit(0);
                break;
            default:
                printf("Digite uma opcao valida");
        }
    break;
    }
    return 0;
}