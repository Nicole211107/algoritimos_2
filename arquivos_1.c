#include <stdio.h>
#include <stdlib.h>

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
    arquivoClientes = fopen("Clientes.txt", "w");
    if (arquivoClientes == NULL) {
        printf("Erro ao criar arquivo Clientes.txt\n");
        return 1;
    }

    arquivoRecebimentos = fopen("Recebimentos.txt", "w");
    if (arquivoRecebimentos == NULL) {
        printf("Erro ao criar arquivo Recebimentos.txt\n");
        return 1;
    }

    int nClientes, nRecebimentos;
    printf("Quantos clientes deseja cadastrar? ");
    scanf("%d", &nClientes);
    for (int i = 0; i < nClientes; i++) {
        struct Cliente c;
        printf("Digite o codigo do cliente: ");
        scanf("%d", &c.Cod_Cli);
        printf("Digite o nome: ");
        scanf(" %[^\n]", c.Nome);
        printf("Digite o endereco: ");
        scanf(" %[^\n]", c.Endereco);
        printf("Digite o telefone: ");
        scanf(" %[^\n]", c.Fone);
        fprintf(arquivoClientes, "%d,%s,%s,%s\n", c.Cod_Cli, c.Nome, c.Endereco, c.Fone);
    }

    printf("Quantos recebimentos deseja cadastrar? ");
    scanf("%d", &nRecebimentos);
    for (int i = 0; i < nRecebimentos; i++) {
        struct Recebimento r;
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
        fprintf(arquivoRecebimentos, "%d,%.2f,%s,%s,%d\n", r.Num_doc, r.Valor_doc, r.Data_Emissao, r.Data_Vencimento, r.Cod_Cli);
    }

    fclose(arquivoClientes);
    fclose(arquivoRecebimentos);
    printf("Arquivos criados com sucesso!\n");

    return 0;
}
