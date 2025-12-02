#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Cliente {
    int CodigoCliente;
    char Nome[50];
    char Endereco[100];
    char Fone[20];
};

struct Recebimento {
    int NumeroDocumento;
    float ValorDocumento;
    char DataEmissao[12];
    char DataVencimento[12];
    int CodigoCliente;
}

int converterDataParaNumero(char data[]) {
    int dia, mes, ano;
    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);
    return ano * 10000 + mes * 100 + dia;
}

int main() {
    FILE *arquivoClientes, *arquivoRecebimentos;
    struct Cliente cliente;
    struct Recebimento recebimento;
    char dataInicio[12], dataFim[12];
    printf("Digite a data inicial (dd/mm/aaaa): ");
    scanf(" %[^\n]", dataInicio);
    printf("Digite a data final (dd/mm/aaaa): ");
    scanf(" %[^\n]", dataFim);
    int numeroDataInicio = converterDataParaNumero(dataInicio);
    int numeroDataFim = converterDataParaNumero(dataFim);
    arquivoRecebimentos = fopen("Recebimentos.txt", "r");
    arquivoClientes = fopen("Clientes.txt", "r");
    if (arquivoRecebimentos == NULL || arquivoClientes == NULL) {
        printf("Erro ao abrir arquivos\n");
        return 1;
    }

    printf("\nRecebimentos no periodo:\n");
    time_t hoje = time(NULL);
    struct tm *dataHoje = localtime(&hoje);
    int numeroDataHoje = (dataHoje->tm_year + 1900) * 10000 + (dataHoje->tm_mon + 1) * 100 + dataHoje->tm_mday;
    while (fscanf(arquivoRecebimentos, "%d,%f,%11[^,],%11[^,],%d\n",
                  &recebimento.NumeroDocumento,
                  &recebimento.ValorDocumento,
                  recebimento.DataEmissao,
                  recebimento.DataVencimento,
                  &recebimento.CodigoCliente) != EOF) {
        int numeroDataVencimento = converterDataParaNumero(recebimento.DataVencimento);
        if (numeroDataVencimento >= numeroDataInicio && numeroDataVencimento <= numeroDataFim) {
            rewind(arquivoClientes);
            char nomeCliente[50] = "";
            while (fscanf(arquivoClientes, "%d,%49[^,],%99[^,],%19[^\n]\n",
                          &cliente.CodigoCliente,
                          cliente.Nome,
                          cliente.Endereco,
                          cliente.Fone) != EOF) {
                if (cliente.CodigoCliente == recebimento.CodigoCliente) {
                    strcpy(nomeCliente, cliente.Nome);
                    break;
                }
            }

            int diasAtraso = 0;
            if (numeroDataHoje > numeroDataVencimento) {
                diasAtraso = numeroDataHoje - numeroDataVencimento;
                diasAtraso = diasAtraso / 100; 
            }

            printf("Documento: %d | Cliente: %s | Valor: %.2f | Vencimento: %s | Dias de atraso: %d\n",
                   recebimento.NumeroDocumento, nomeCliente, recebimento.ValorDocumento,
                   recebimento.DataVencimento, diasAtraso);
        }
    }

    fclose(arquivoRecebimentos);
    fclose(arquivoClientes);

    return 0;
}
