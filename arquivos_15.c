#include <stdio.h>
#include <stdlib.h>

struct Produto {
    int codigo;
    char descricao[100];
    float preco;
};

int main() {
    FILE *arquivo;
    struct Produto produto;
    arquivo = fopen("PRODUTOS.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }

    fclose(arquivo);
    printf("Arquivo PRODUTOS.txt criado com sucesso!\n");

    return 0;
}
