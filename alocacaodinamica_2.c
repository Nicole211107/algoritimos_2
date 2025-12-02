#include <stdio.h>
#include <stdlib.h>

struct nicole {
    int matricula;
    char nome[50];
    float notas[3];
};

int main() {
    struct nicole *p;  
    p = (struct nicole*) malloc(sizeof(struct nicole));
    if (p == NULL) {
        printf("Erro na alocacao\n");
        return 1;
    }

    printf("Tamanho da estrutura nicole: %zu bytes\n", sizeof(struct nicole));

    return 0;
}
