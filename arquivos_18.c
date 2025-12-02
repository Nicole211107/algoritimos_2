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
    FILE *arquivoTemp;
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

    while (fscanf(arquivo, "%d,%99[^,],%f\n",
                  &produto.codigo,
                  produto.descricao,
                  &produto.preco) != EOF) {
        produto.preco = produto.preco * 1.15;
        fprintf(arquivoTemp, "%d,%s,%.2f\n", produto.codigo, produto.descricao, produto.preco);
    }

    fclose(arquivo);
    fclose(arquivoTemp);
    remove("PRODUTOS.txt");
    rename("PRODUTOS_TEMP.txt", "PRODUTOS.txt");
    printf("Todos os precos foram atualizados em 15%% com sucesso!\n");

    return 0;
}
