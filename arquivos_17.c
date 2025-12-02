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
    arquivo = fopen("PRODUTOS.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir PRODUTOS.txt\n");
        return 1;
    }

    printf("Produtos com preco superior a R$ 500,00:\n");
    while (fscanf(arquivo, "%d,%99[^,],%f\n",
                  &produto.codigo,
                  produto.descricao,
                  &produto.preco) != EOF) {
        if (produto.preco > 500.0) {
            printf("Codigo: %d | Descricao: %s | Preco: %.2f\n",
                   produto.codigo, produto.descricao, produto.preco);
        }
    }

    fclose(arquivo);

    return 0;
}
