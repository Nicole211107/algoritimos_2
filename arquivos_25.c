#include <stdio.h>
#include <stdlib.h>

struct Produto {
    int codigo;
    char descricao[100];
    float preco;
};

int main() {
    FILE *arquivo, *arquivoTemp;
    struct Produto produto;
    float precoMin, precoMax, desconto;
    int totalAlterados = 0;
    printf("Digite o preco minimo: ");
    scanf("%f", &precoMin);
    printf("Digite o preco maximo: ");
    scanf("%f", &precoMax);
    printf("Digite o percentual de desconto (ex: 10 para 10%%): ");
    scanf("%f", &desconto);
    arquivo = fopen("PRODUTOS.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir PRODUTOS.txt\n");
        return 1;
    }

    arquivoTemp = fopen("PRODUTOS_TEMP.txt", "w");
    if (arquivoTemp == NULL) {
        printf("Erro ao criar arquivo temporario\n");
        fclose(arquivo);
        return 1;
    }

    while (fscanf(arquivo, "%d,%99[^,],%f\n", &produto.codigo, produto.descricao, &produto.preco) != EOF) {
        if (produto.preco >= precoMin && produto.preco <= precoMax) {
            produto.preco = produto.preco - (produto.preco * desconto / 100);
            totalAlterados++;
        }
        fprintf(arquivoTemp, "%d,%s,%.2f\n", produto.codigo, produto.descricao, produto.preco);
    }

    fclose(arquivo);
    fclose(arquivoTemp);
    remove("PRODUTOS.txt");
    rename("PRODUTOS_TEMP.txt", "PRODUTOS.txt");
    printf("Desconto aplicado com sucesso!\n");
    printf("Produtos alterados: %d\n", totalAlterados);

    return 0;
}
