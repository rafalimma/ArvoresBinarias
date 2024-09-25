#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node {
    int index;
    char nome[100];
    struct Node* left;
    struct Node* right;
} Node;

Node* CriarNo(int index, char* nome) {
    Node* novoNo = (Node*)malloc(sizeof(Node));
    novoNo->index = index;
    strcpy(novoNo->nome, nome); // usado para copiar a string nome para o campo nome do nó
    novoNo->right = NULL;
    novoNo->left = NULL;
    return novoNo;
}

void MostrarArquivo(Node* root) {
    if (root != NULL) {
        MostrarArquivo(root->left);
        printf("Indice: %d, Nome: %s\n", root->index, root->nome);
        MostrarArquivo(root->right);
    }
}

Node* InsereArquivo(Node* root, char* nome, int index) { // aqui node é o nó atual onde o novo nó será inserido ou comparado
    if (root == NULL) {
        return CriarNo(index, nome);
    }
    if (index > root->index) {
        root->right = InsereArquivo(root->right, nome, index);
    }
    if (index < root->index) {
        root->left = InsereArquivo(root->left, nome, index);
    }

    return root;
}

// escolhi esse formato pois permite buscar os indices com base na regra
// da arvore binaria em si em que é possível percorrer os galhos com base
// nos valores dos indices maiores a direita e menores a esquerda.
Node* BuscarIndice(Node* root, int index) {
    if (root == NULL || root->index == index) {
        return root; // retorna a propria raiz se o arquivo for encontrado
    }
    if (index < root->index) { // faz a comparação
        return BuscarIndice(root->left, index);
    } else {
        return BuscarIndice(root->right, index);
    }
}

int main() {
    int opcao;
    int indice_busca;
    Node* root = NULL;

    while(1) {
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
                printf("Buscar arquivo pelo indice: ");
                scanf("%d", &indice_busca);
                Node* encontrado = BuscarIndice(root, indice_busca);
                if (encontrado != NULL) {
                    printf("Arquivo encontrado: Indice: %d, Nome: %s\n", encontrado->index, encontrado->nome);
                } else {
                    printf("Arquivo nao encontrado.\n");
                }
                break;
            case 2:
                printf("Inserir Arquivo\n");
                char nome[100];
                int index;

                printf("Digite um indice para o arquivo: ");
                scanf("%d", &index);
                printf("Digite o nome do arquivo: ");
                scanf(" %[^\n]", nome);

                root = InsereArquivo(root, nome, index);
                printf("___ARQUIVO_INSERIDO___\n\n");
                MostrarArquivo(root);
                break;
            case 3:
                printf("Deletar arquivo");
            case 4:
                printf("Saindo do Programa.");
                break;
            default:
                printf("Opcao invalida");
        }
    }
}
