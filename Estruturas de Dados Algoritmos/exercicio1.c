#include <stdio.h>
#include <stdlib.h>

int main() {
    int vetor[10];
    int valor;

    for (int i=0;i<10; i++) {
        printf("digite um valor: ");
        scanf("%d", &valor);
        vetor[i] = i;
    }
    for (int i=0;i<10; i++) {
        printf("%d\n", vetor[i]);
    }
    return 0;
}