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
    FILE *clientes, *recebimentos;
    FILE *tempClientes, *tempRecebimentos;
    int cod;
    printf("Digite o codigo do cliente que deseja excluir: ");
    scanf("%d", &cod);
    clientes = fopen("Clientes.txt", "r");
    tempClientes = fopen("TempClientes.txt", "w");
    struct Cliente c;
    while (fscanf(clientes, "%d,%49[^,],%99[^,],%19[^\n]\n",
                  &c.Cod_Cli, c.Nome, c.Endereco, c.Fone) != EOF) {
        if (c.Cod_Cli != cod) {
            fprintf(tempClientes, "%d,%s,%s,%s\n", c.Cod_Cli, c.Nome, c.Endereco, c.Fone);
        }
    }

    fclose(clientes);
    fclose(tempClientes);
    remove("Clientes.txt");
    rename("TempClientes.txt", "Clientes.txt");
    recebimentos = fopen("Recebimentos.txt", "r");
    tempRecebimentos = fopen("TempRecebimentos.txt", "w");
    struct Recebimento r;
    while (fscanf(recebimentos, "%d,%f,%11[^,],%11[^,],%d\n",
                  &r.Num_doc, &r.Valor_doc, r.Data_Emissao, r.Data_Vencimento, &r.Cod_Cli) != EOF) {
        if (r.Cod_Cli != cod) {
            fprintf(tempRecebimentos, "%d,%.2f,%s,%s,%d\n",
                    r.Num_doc, r.Valor_doc, r.Data_Emissao, r.Data_Vencimento, r.Cod_Cli);
        }
    }

    fclose(recebimentos);
    fclose(tempRecebimentos);
    remove("Recebimentos.txt");
    rename("TempRecebimentos.txt", "Recebimentos.txt");
    printf("Cliente e seus recebimentos excluidos com sucesso!\n");

    return 0;
}
