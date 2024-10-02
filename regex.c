#include <stdio.h>
#include <regex.h>
#include <stdlib.h>

int main() {
    regex_t regex;
    int reti;
    char msbuf[100];
    const char *pattern = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";
    const char *string = "test@example.com"; // string para teste

    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        printf("Nao foi possivel copiar");
        exit(1);
    }

    
}