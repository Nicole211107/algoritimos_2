#include <stdio.h>
#include <stdlib.h>

struct Cadastro {
    char nome[50];
    int idade;
    char endereco[50];
};

struct Cadastro* fazer(int n) {
    struct Cadastro *x;
    int i;
    x = (struct Cadastro*) malloc(n * sizeof(struct Cadastro));
    if (x == NULL) {
        printf("erro na alocacao\n");
    }

    for (i = 0; i < n; i++) {
        printf("nome: ");
        scanf(" %49[^\n]", x[i].nome);
        printf("idade: ");
        scanf("%d", &x[i].idade);
        printf("endereco: ");
        scanf(" %49[^\n]", x[i].endereco);
    }

    return x;
}

int main() {

    int n;
    struct Cadastro *p;
    printf("quantos cadastros quer: ");
    scanf("%d", &n);
    p = fazer(n);
    printf("\nmostrando:\n");
    for (int i = 0; i < n; i++) {
        printf("\nnome: %s\n", p[i].nome);
        printf("idade: %d\n", p[i].idade);
        printf("endereco: %s\n", p[i].endereco);
    }

    return 0;
}
