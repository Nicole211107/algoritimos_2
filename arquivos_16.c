#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    int codigo;
    char descricao[100];
    float preco;
};

int main() {
    FILE *arquivo;
    struct Produto produto;
    char continuar = 's';

    do {
        arquivo = fopen("PRODUTOS.txt", "r");
        if (arquivo == NULL) {
            printf("Erro ao abrir PRODUTOS.txt\n");
            return 1;
        }

        int codigoExiste = 0;
        printf("Digite o codigo do produto: ");
        scanf("%d", &produto.codigo);
        struct Produto produtoTemp;
        while (fscanf(arquivo, "%d,%99[^,],%f\n",
                      &produtoTemp.codigo,
                      produtoTemp.descricao,
                      &produtoTemp.preco) != EOF) {
            if (produtoTemp.codigo == produto.codigo) {
                codigoExiste = 1;
                break;
            }
        }
        fclose(arquivo);
        if (codigoExiste) {
            printf("Codigo ja cadastrado! Tente outro.\n");
        } else {
            printf("Digite a descricao do produto: ");
            scanf(" %[^\n]", produto.descricao);
            printf("Digite o preco do produto: ");
            scanf("%f", &produto.preco);
            arquivo = fopen("PRODUTOS.txt", "a");
            if (arquivo == NULL) {
                printf("Erro ao abrir PRODUTOS.txt\n");
                return 1;
            }

            fprintf(arquivo, "%d,%s,%.2f\n", produto.codigo, produto.descricao, produto.preco);
            fclose(arquivo);
            printf("Produto cadastrado com sucesso!\n");
        }

        printf("Deseja cadastrar outro produto? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
    arquivo = fopen("PRODUTOS.txt", "r");
    if (arquivo != NULL) {
        printf("\nProdutos cadastrados:\n");
        while (fscanf(arquivo, "%d,%99[^,],%f\n",
                      &produto.codigo,
                      produto.descricao,
                      &produto.preco) != EOF) {
            printf("Codigo: %d | Descricao: %s | Preco: %.2f\n",
                   produto.codigo, produto.descricao, produto.preco);
        }
        fclose(arquivo);
    }

    return 0;
}
