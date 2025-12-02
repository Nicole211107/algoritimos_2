#include <stdio.h>
#include <stdlib.h>

struct Cliente {
    int Cod_Cli;
    char Nome[50];
    char Endereco[100];
    char Fone[20];
};

int main() {
    FILE *arquivoClientes;
    arquivoClientes = fopen("Clientes.txt", "a"); 
    if (arquivoClientes == NULL) {
        printf("Erro ao abrir arquivo Clientes.txt\n");
        return 1;
    }

    int nClientes;
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

    fclose(arquivoClientes);
    printf("Clientes cadastrados com sucesso!\n");

    return 0;
}
