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
    float valorMinimo, valorMaximo;
    printf("Digite o valor minimo: ");
    scanf("%f", &valorMinimo);
    printf("Digite o valor maximo: ");
    scanf("%f", &valorMaximo);
    arquivoRecebimentos = fopen("Recebimentos.txt", "r");
    if (arquivoRecebimentos == NULL) {
        printf("Erro ao abrir Recebimentos.txt\n");
        return 1;
    }

    printf("\nRecebimentos com valor entre %.2f e %.2f:\n", valorMinimo, valorMaximo);
    while (fscanf(arquivoRecebimentos, "%d,%f,%11[^,],%11[^,],%d\n",
                  &recebimento.NumeroDocumento,
                  &recebimento.ValorDocumento,
                  recebimento.DataEmissao,
                  recebimento.DataVencimento,
                  &recebimento.CodigoCliente) != EOF) {
        if (recebimento.ValorDocumento >= valorMinimo && recebimento.ValorDocumento <= valorMaximo) {
            arquivoClientes = fopen("Clientes.txt", "r");
            if (arquivoClientes == NULL) {
                printf("Erro ao abrir Clientes.txt\n");
                fclose(arquivoRecebimentos);
                return 1;
            }

            int clienteEncontrado = 0;
            while (fscanf(arquivoClientes, "%d,%49[^,],%99[^,],%19[^\n]\n",
                          &cliente.CodigoCliente,
                          cliente.Nome,
                          cliente.Endereco,
                          cliente.Fone) != EOF) {
                if (cliente.CodigoCliente == recebimento.CodigoCliente) {
                    printf("Documento: %d | Cliente: %s | Valor: %.2f | Emissao: %s | Vencimento: %s\n",
                           recebimento.NumeroDocumento,
                           cliente.Nome,
                           recebimento.ValorDocumento,
                           recebimento.DataEmissao,
                           recebimento.DataVencimento);
                    clienteEncontrado = 1;
                    break;
                }
            }

            fclose(arquivoClientes);
            if (!clienteEncontrado) {
                printf("Documento: %d | Cliente: NAO ENCONTRADO | Valor: %.2f | Emissao: %s | Vencimento: %s\n",
                       recebimento.NumeroDocumento,
                       recebimento.ValorDocumento,
                       recebimento.DataEmissao,
                       recebimento.DataVencimento);
            }
        }
    }

    fclose(arquivoRecebimentos);

    return 0;
}
