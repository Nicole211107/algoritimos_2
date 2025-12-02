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
    int codigoExcluir;
    int encontrado = 0;
    printf("Digite o codigo do produto que deseja excluir: ");
    scanf("%d", &codigoExcluir);
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
        if (produto.codigo != codigoExcluir) {
            fprintf(arquivoTemp, "%d,%s,%.2f\n", produto.codigo, produto.descricao, produto.preco);
        } else {
            encontrado = 1;
        }
    }

    fclose(arquivo);
    fclose(arquivoTemp);
    remove("PRODUTOS.txt");
    rename("PRODUTOS_TEMP.txt", "PRODUTOS.txt");
    if (encontrado) {
        printf("Produto excluido com sucesso!\n");
    } else {
        printf("Produto nao encontrado!\n");
    }

    return 0;
}
