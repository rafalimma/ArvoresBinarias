// It's pretty straightforward.
// Your goal is to create a function that removes the first and last characters of a string. 
// You're given one parameter, the original string. You don't have
// to worry about strings with less than two characters.

#include <string.h>
#include <stdlib.h>

char* remove_char(char* dst, const char* src)
{
    int tamanho = strlen(src);

    // Copiar da posição 1 até tamanho - 2
    for(int i = 1; i < tamanho - 1; i++){
        dst[i - 1] = src[i];  // Copiar src[i] para dst[i - 1]
    }
    dst[tamanho - 2] = '\0';

    return dst;
}