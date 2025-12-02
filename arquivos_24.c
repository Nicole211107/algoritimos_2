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
    int removidos = 0;
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
        if (produto.preco <= 200.0) {
            fprintf(arquivoTemp, "%d,%s,%.2f\n", produto.codigo, produto.descricao, produto.preco);
        } else {
            removidos++;
        }
    }

    fclose(arquivo);
    fclose(arquivoTemp);
    remove("PRODUTOS.txt");
    rename("PRODUTOS_TEMP.txt", "PRODUTOS.txt");
    printf("Produtos com preco superior a R$ 200,00 foram excluidos.\n");
    printf("Total de produtos removidos: %d\n", removidos);

    return 0;
}
