#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    int numero;
    char nome[50];
    float nota1;
    float nota2;
};

int main() {
    int opcao;
    FILE *arquivo;
    struct Aluno aluno;

    do {
        printf("\nMenu de opcoes:\n");
        printf("1 - Criar arquivo\n");
        printf("2 - Incluir dados\n");
        printf("3 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            arquivo = fopen("Alunos.txt", "w");
            if (arquivo == NULL) {
                printf("Erro ao criar arquivo!\n");
            } else {
                fclose(arquivo);
                printf("Arquivo criado com sucesso!\n");
            }
        }

        else if (opcao == 2) {
            arquivo = fopen("Alunos.txt", "a");
            if (arquivo == NULL) {
                printf("Erro ao abrir arquivo!\n");
                continue;
            }

            char continuar = 's';
            while (continuar == 's' || continuar == 'S') {
                printf("\nDigite o numero do aluno: ");
                scanf("%d", &aluno.numero);
                printf("Digite o nome do aluno: ");
                scanf(" %[^\n]", aluno.nome);
                printf("Digite a nota1: ");
                scanf("%f", &aluno.nota1);
                printf("Digite a nota2: ");
                scanf("%f", &aluno.nota2);
                fprintf(arquivo, "%d,%s,%.2f,%.2f\n", aluno.numero, aluno.nome, aluno.nota1, aluno.nota2);
                printf("Deseja incluir outro aluno? (s/n): ");
                scanf(" %c", &continuar);
            }

            fclose(arquivo);
            arquivo = fopen("Alunos.txt", "r");
            if (arquivo == NULL) {
                printf("Erro ao abrir arquivo!\n");
                continue;
            }

            printf("\nRegistros cadastrados:\n");
            while (fscanf(arquivo, "%d,%49[^,],%f,%f\n",
                          &aluno.numero, aluno.nome, &aluno.nota1, &aluno.nota2) != EOF) {
                float media = (aluno.nota1 + aluno.nota2) / 2;
                printf("Numero: %d | Nome: %s | Nota1: %.2f | Nota2: %.2f | Media: %.2f\n",
                       aluno.numero, aluno.nome, aluno.nota1, aluno.nota2, media);
            }

            fclose(arquivo);
        }

    } while (opcao != 3);
    printf("\nPrograma finalizado.\n");

    return 0;
}
