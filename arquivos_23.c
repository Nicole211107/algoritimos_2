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
    char letra;
    float precoMin, precoMax;
    printf("Digite a letra inicial do produto: ");
    scanf(" %c", &letra);
    printf("Digite o preco minimo: ");
    scanf("%f", &precoMin);
    printf("Digite o preco maximo: ");
    scanf("%f", &precoMax);
    arquivo = fopen("PRODUTOS.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir PRODUTOS.txt\n");
        return 1;
    }

    printf("\nProdutos que comecam com '%c' e preco entre %.2f e %.2f:\n", letra, precoMin, precoMax);
    while (fscanf(arquivo, "%d,%99[^,],%f\n",
                  &produto.codigo,
                  produto.descricao,
                  &produto.preco) != EOF) {
        if ((produto.descricao[0] == letra || produto.descricao[0] == letra + 32) &&
            produto.preco >= precoMin && produto.preco <= precoMax) {
            printf("Codigo: %d | Descricao: %s | Preco: %.2f\n",
                   produto.codigo, produto.descricao, produto.preco);
        }
    }

    fclose(arquivo);

    return 0;
}
