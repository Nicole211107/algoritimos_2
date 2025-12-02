#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Recebimento {
    int NumeroDocumento;
    float ValorDocumento;
    char DataEmissao[12];
    char DataVencimento[12];
    int CodigoCliente;
};

int main() {
    FILE *arquivoRecebimentos;
    FILE *arquivoTempRecebimentos;
    struct Recebimento recebimento;
    int numeroDocumento, codigoCliente;
    int encontrado = 0;
    printf("Digite o numero do documento: ");
    scanf("%d", &numeroDocumento);
    printf("Digite o codigo do cliente: ");
    scanf("%d", &codigoCliente);
    arquivoRecebimentos = fopen("Recebimentos.txt", "r");
    if (arquivoRecebimentos == NULL) {
        printf("Erro ao abrir Recebimentos.txt\n");
        return 1;
    }

    arquivoTempRecebimentos = fopen("TempRecebimentos.txt", "w");
    if (arquivoTempRecebimentos == NULL) {
        printf("Erro ao criar arquivo temporario\n");
        fclose(arquivoRecebimentos);
        return 1;
    }

    while (fscanf(arquivoRecebimentos, "%d,%f,%11[^,],%11[^,],%d\n",
                  &recebimento.NumeroDocumento,
                  &recebimento.ValorDocumento,
                  recebimento.DataEmissao,
                  recebimento.DataVencimento,
                  &recebimento.CodigoCliente) != EOF) {

        if (recebimento.NumeroDocumento == numeroDocumento && recebimento.CodigoCliente == codigoCliente) {
            printf("Digite o novo valor do documento: ");
            scanf("%f", &recebimento.ValorDocumento);
            printf("Digite a nova data de emissao (dd/mm/aaaa): ");
            scanf(" %[^\n]", recebimento.DataEmissao);
            printf("Digite a nova data de vencimento (dd/mm/aaaa): ");
            scanf(" %[^\n]", recebimento.DataVencimento);
            encontrado = 1;
        }

        fprintf(arquivoTempRecebimentos, "%d,%.2f,%s,%s,%d\n",
                recebimento.NumeroDocumento,
                recebimento.ValorDocumento,
                recebimento.DataEmissao,
                recebimento.DataVencimento,
                recebimento.CodigoCliente);
    }

    fclose(arquivoRecebimentos);
    fclose(arquivoTempRecebimentos);
    remove("Recebimentos.txt");
    rename("TempRecebimentos.txt", "Recebimentos.txt");
    if (encontrado)
        printf("Recebimento alterado com sucesso!\n");
    else
        printf("Recebimento nao encontrado!\n");

    return 0;
}
