#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[40];
    float preco;
    int quantidade;
} Produto;

int main() {
    Produto produtos[5];

    for (int i = 0; i <= 5; i++) {
        printf("_____PRODUTO_%d_____", i+1);
        printf("Nome do produto: %s", produtos[i].nome);
        printf("Preco do produto: %f", produtos[i].preco);
        printf("Quantidade em estoque do produto: %d", produtos[i].quantidade);
        printf("______________________________________________________________");
    }

    return 0;
}

void AdicionarProduto(Produto produtos[], int *contador) {
    for(int i = 0; i <= contador; i++) {
        printf("Nome do produto %d: ", i+1);
        scanf("%s", produtos[i].nome);

        printf("Digite o preco do produto %d: ", i+1);
        scanf("%f", &produtos[i].preco);

        printf("Digite a quantidade do produto %d: ", i+1);
        scanf("%d", &produtos[i].quantidade);
    }
}