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
    int codigoCliente;
    int clienteEncontrado = 0; 
    printf("Digite o codigo do cliente: ");
    scanf("%d", &codigoCliente);
    arquivoClientes = fopen("Clientes.txt", "r");
    arquivoRecebimentos = fopen("Recebimentos.txt", "r");
    if (arquivoClientes == NULL || arquivoRecebimentos == NULL) {
        printf("Erro ao abrir arquivos\n");
        return 1;
    }

    char nomeCliente[50];
    while (fscanf(arquivoClientes, "%d,%49[^,],%99[^,],%19[^\n]\n",
                  &cliente.CodigoCliente, cliente.Nome, cliente.Endereco, cliente.Fone) != EOF) {
        if (cliente.CodigoCliente == codigoCliente) {
            strcpy(nomeCliente, cliente.Nome);
            clienteEncontrado = 1;
            break;
        }
    }

    if (clienteEncontrado == 0) {
        printf("Cliente nao encontrado!\n");
        fclose(arquivoClientes);
        fclose(arquivoRecebimentos);
        return 0;
    }

    printf("\nRecebimentos do cliente %s:\n", nomeCliente);
    while (fscanf(arquivoRecebimentos, "%d,%f,%11[^,],%11[^,],%d\n",
                  &recebimento.NumeroDocumento,
                  &recebimento.ValorDocumento,
                  recebimento.DataEmissao,
                  recebimento.DataVencimento,
                  &recebimento.CodigoCliente) != EOF) {
        if (recebimento.CodigoCliente == codigoCliente) {
            printf("Documento: %d | Valor: %.2f | Emissao: %s | Vencimento: %s\n",
                   recebimento.NumeroDocumento,
                   recebimento.ValorDocumento,
                   recebimento.DataEmissao,
                   recebimento.DataVencimento);
        }
    }

    fclose(arquivoClientes);
    fclose(arquivoRecebimentos);

    return 0;
}
