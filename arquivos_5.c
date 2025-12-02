#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cliente {
    int Cod_Cli;
    char Nome[50];
    char Endereco[100];
    char Fone[20];
};

int main() {
    FILE *clientes, *tempClientes;
    struct Cliente c;
    int cod, encontrado = 0;
    printf("Digite o codigo do cliente que deseja alterar: ");
    scanf("%d", &cod);
    clientes = fopen("Clientes.txt", "r");
    if (clientes == NULL) {
        printf("Erro ao abrir Clientes.txt\n");
        return 1;
    }
    tempClientes = fopen("TempClientes.txt", "w");
    if (tempClientes == NULL) {
        printf("Erro ao criar arquivo temporario\n");
        fclose(clientes);
        return 1;
    }

    while (fscanf(clientes, "%d,%49[^,],%99[^,],%19[^\n]\n",
                  &c.Cod_Cli, c.Nome, c.Endereco, c.Fone) != EOF) {
        if (c.Cod_Cli == cod) {
            printf("Digite o novo nome: ");
            scanf(" %[^\n]", c.Nome);
            printf("Digite o novo endereco: ");
            scanf(" %[^\n]", c.Endereco);
            printf("Digite o novo telefone: ");
            scanf(" %[^\n]", c.Fone);
            encontrado = 1;
        }
        fprintf(tempClientes, "%d,%s,%s,%s\n", c.Cod_Cli, c.Nome, c.Endereco, c.Fone);
    }

    fclose(clientes);
    fclose(tempClientes);
    remove("Clientes.txt");
    rename("TempClientes.txt", "Clientes.txt");
    if (encontrado)
        printf("Cliente alterado com sucesso!\n");
    else
        printf("Cliente nao encontrado!\n");

    return 0;
}
