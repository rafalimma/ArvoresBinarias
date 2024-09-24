#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
    int index;
    struct Node* left;
    struct Node* right;
} Node;

Node* CriarNo(int index, char nome) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->index = index;
    novoNo->nome = nome;
    novoNo->right = NULL;
    novoNo->left = NULL;
    return novoNo;
}

Node* InsereArquivo(Node* root, int index) { // aqui node é o nó atual onde o novo nó será inserido ou comparado
    char nome[100];

    printf("Digite um indice para o arquivo: ");
    scanf("%d", &index);
    printf("Digite o nome do arquivo: ");
    scanf(" %[^\n]", nome);

    if (root == NULL) {
        return CriarNo(index, nome);
    }
    if (index > root->index) {
        root->right = InsereArquivo(root->right, index);
    }
    if (index < root->index) {
        root->left = InsereArquivo(root->left, index);
    }

    return root;
}

int main() {
    char opcao[100];
    int index;
    Node root = NULL;

    printf("__SISTEMA_DE_GERENCIAMENTO_DE_ARQUIVOS__\n");
    printf("Escolha uma opcao:\n ");
    printf("1. Buscar arquivo\n");
    printf("2. Inserir arquivo\n");
    printf("3. Deletar arquivo\n");
    printf("4. Sair\n");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("Buscar Arquivo\n");
            continue;
        case 2:
            printf("Inserir Arquivo\n");
            printf("Insira o indíce do arquivo:");
            scanf("%d", &index);
            InsereArquivo(root, index);
            continue;
            break;
    }
}