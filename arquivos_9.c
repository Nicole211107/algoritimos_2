#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
};

int main() {
    FILE *arquivoClientes, *arquivoRecebimentos;
    struct Cliente cliente;
    struct Recebimento recebimento;
    float valorMinimo;
    int clienteEncontrado;
    printf("Digite o valor minimo para filtrar recebimentos: ");
    scanf("%f", &valorMinimo);
    arquivoClientes = fopen("Clientes.txt", "r");
    arquivoRecebimentos = fopen("Recebimentos.txt", "r");
    if (arquivoClientes == NULL || arquivoRecebimentos == NULL) {
        printf("Erro ao abrir arquivos\n");
        return 1;
    }

    printf("\nRecebimentos com valor acima de %.2f:\n", valorMinimo);
    while (fscanf(arquivoRecebimentos, "%d,%f,%11[^,],%11[^,],%d\n",
                  &recebimento.NumeroDocumento,
                  &recebimento.ValorDocumento,
                  recebimento.DataEmissao,
                  recebimento.DataVencimento,
                  &recebimento.CodigoCliente) != EOF) {
        if (recebimento.ValorDocumento > valorMinimo) {
            rewind(arquivoClientes);
            char nomeCliente[50];
            clienteEncontrado = 0;
            while (fscanf(arquivoClientes, "%d,%49[^,],%99[^,],%19[^\n]\n",
                          &cliente.CodigoCliente,
                          cliente.Nome,
                          cliente.Endereco,
                          cliente.Fone) != EOF) {
                if (cliente.CodigoCliente == recebimento.CodigoCliente) {
                    strcpy(nomeCliente, cliente.Nome);
                    clienteEncontrado = 1;
                    break;
                }
            }

            if (clienteEncontrado) {
                printf("Documento: %d | Cliente: %s | Valor: %.2f | Emissao: %s | Vencimento: %s\n",
                       recebimento.NumeroDocumento,
                       nomeCliente,
                       recebimento.ValorDocumento,
                       recebimento.DataEmissao,
                       recebimento.DataVencimento);
            }
        }
    }

    fclose(arquivoClientes);
    fclose(arquivoRecebimentos);

    return 0;
}
