#include <stdio.h>
#include <stdlib.h>
// Recursão : um programa em que uma função chama a si mesma
// para resolver um problema
//

// função recursiva para calcular um fatorial de um numero

int Fatorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * Fatorial(n - 1);
    }
}

int Fib(int n) {
    if (n == 1 || n == 0) {
        return n;
    } else {
        return Fib(n-2) + Fib(n - 1);
    }
}

int Potencia(int n, int x) {
    if (x == 0) {
        return 1;
    } else{
        return n * Potencia(n, x - 1);
    }
}

int Soma(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + Soma(n - 1);
    }
}


int main() {
    printf("fatorial de 7: %d \n", Fatorial(7));
    printf("Fibonachi de 6: %d \n", Fib(6));
    printf("Potencia de 3 elevado a 2: %d \n", Potencia(3, 2));
    printf("soma de 4 ate o inicio: %d \n", Soma(4));
    return 0;
}