#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cliente {
    int Cod_Cli;
    char Nome[50];
    char Endereco[100];
    char Fone[20];
};

struct Recebimento {
    int Num_doc;
    float Valor_doc;
    char Data_Emissao[12];
    char Data_Vencimento[12];
    int Cod_Cli;
};

int main() {
    FILE *arquivoClientes;
    FILE *arquivoRecebimentos;
    arquivoRecebimentos = fopen("Recebimentos.txt", "a");
    if (arquivoRecebimentos == NULL) {
        printf("Erro ao abrir arquivo Recebimentos.txt\n");
        return 1;
    }

    int nRecebimentos;
    printf("Quantos recebimentos deseja cadastrar? ");
    scanf("%d", &nRecebimentos);
    for (int i = 0; i < nRecebimentos; i++) {
        struct Recebimento r;
        int existe = 0;
        printf("Digite o numero do documento: ");
        scanf("%d", &r.Num_doc);
        printf("Digite o valor: ");
        scanf("%f", &r.Valor_doc);
        printf("Digite a data de emissao (dd/mm/aaaa): ");
        scanf(" %[^\n]", r.Data_Emissao);
        printf("Digite a data de vencimento (dd/mm/aaaa): ");
        scanf(" %[^\n]", r.Data_Vencimento);
        printf("Digite o codigo do cliente: ");
        scanf("%d", &r.Cod_Cli);
        arquivoClientes = fopen("Clientes.txt", "r");
        if (arquivoClientes == NULL) {
            printf("Erro ao abrir arquivo Clientes.txt\n");
            fclose(arquivoRecebimentos);
            return 1;
        }

        struct Cliente c;
        while (fscanf(arquivoClientes, "%d,%49[^,],%99[^,],%19[^\n]\n", 
                      &c.Cod_Cli, c.Nome, c.Endereco, c.Fone) != EOF) {
            if (c.Cod_Cli == r.Cod_Cli) {
                existe = 1;
                break;
            }
        }
        fclose(arquivoClientes);
        if (existe) {
            fprintf(arquivoRecebimentos, "%d,%.2f,%s,%s,%d\n",
                    r.Num_doc, r.Valor_doc, r.Data_Emissao, r.Data_Vencimento, r.Cod_Cli);
            printf("Recebimento cadastrado com sucesso!\n");
        } else {
            printf("Cliente nao cadastrado! Recebimento nao incluido.\n");
        }
    }

    fclose(arquivoRecebimentos);
    return 0;
}
