#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estacao {
    int CodigoEstacao;
    char NomeEstacao[50];
};

struct Estilista {
    int CodigoEstilista;
    char NomeEstilista[50];
    float Salario;
};

struct Roupa {
    int CodigoRoupa;
    char DescricaoRoupa[100];
    int CodigoEstilista;
    int CodigoEstacao;
    int Ano;
};

int main() {
    FILE *arquivoEstacao, *arquivoEstilista, *arquivoRoupa;
    struct Estacao estacao;
    struct Estilista estilista;
    struct Roupa roupa;
    int opcao, encontrado;

    do {
        printf("\nMenu:\n");
        printf("1 - Cadastrar Estacao\n");
        printf("2 - Cadastrar Estilista\n");
        printf("3 - Cadastrar Roupa\n");
        printf("4 - Mostrar roupas de uma Estacao\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        if (opcao == 1) {
            arquivoEstacao = fopen("Estacao.txt", "a");
            if (arquivoEstacao == NULL) {
                printf("Erro ao abrir Estacao.txt\n");
                continue;
            }
            printf("Codigo da Estacao: ");
            scanf("%d", &estacao.CodigoEstacao);
            printf("Nome da Estacao: ");
            scanf(" %[^\n]", estacao.NomeEstacao);
            fprintf(arquivoEstacao, "%d,%s\n", estacao.CodigoEstacao, estacao.NomeEstacao);
            fclose(arquivoEstacao);
            printf("Estacao cadastrada com sucesso!\n");
        }

        else if (opcao == 2) {
            arquivoEstilista = fopen("Estilista.txt", "a");
            if (arquivoEstilista == NULL) {
                printf("Erro ao abrir Estilista.txt\n");
                continue;
            }
            printf("Codigo do Estilista: ");
            scanf("%d", &estilista.CodigoEstilista);
            printf("Nome do Estilista: ");
            scanf(" %[^\n]", estilista.NomeEstilista);
            printf("Salario do Estilista: ");
            scanf("%f", &estilista.Salario);
            fprintf(arquivoEstilista, "%d,%s,%.2f\n", estilista.CodigoEstilista, estilista.NomeEstilista, estilista.Salario);
            fclose(arquivoEstilista);
            printf("Estilista cadastrado com sucesso!\n");
        }

        else if (opcao == 3) {
            arquivoRoupa = fopen("Roupa.txt", "a");
            if (arquivoRoupa == NULL) {
                printf("Erro ao abrir Roupa.txt\n");
                continue;
            }

            printf("Codigo da Roupa: ");
            scanf("%d", &roupa.CodigoRoupa);
            printf("Descricao da Roupa: ");
            scanf(" %[^\n]", roupa.DescricaoRoupa);
            encontrado = 0;
            int codigoEstilistaTemp;
            arquivoEstilista = fopen("Estilista.txt", "r");
            if (arquivoEstilista == NULL) {
                printf("Erro ao abrir Estilista.txt\n");
                fclose(arquivoRoupa);
                continue;
            }
            printf("Codigo do Estilista: ");
            scanf("%d", &codigoEstilistaTemp);
            while (fscanf(arquivoEstilista, "%d,%49[^,],%f\n",
                          &estilista.CodigoEstilista, estilista.NomeEstilista, &estilista.Salario) != EOF) {
                if (estilista.CodigoEstilista == codigoEstilistaTemp) {
                    encontrado = 1;
                    break;
                }
            }
            fclose(arquivoEstilista);
            if (!encontrado) {
                printf("Estilista nao cadastrado!\n");
                fclose(arquivoRoupa);
                continue;
            }
            roupa.CodigoEstilista = codigoEstilistaTemp;
            encontrado = 0;
            int codigoEstacaoTemp;
            arquivoEstacao = fopen("Estacao.txt", "r");
            if (arquivoEstacao == NULL) {
                printf("Erro ao abrir Estacao.txt\n");
                fclose(arquivoRoupa);
                continue;
            }
            printf("Codigo da Estacao: ");
            scanf("%d", &codigoEstacaoTemp);
            while (fscanf(arquivoEstacao, "%d,%49[^\n]\n", &estacao.CodigoEstacao, estacao.NomeEstacao) != EOF) {
                if (estacao.CodigoEstacao == codigoEstacaoTemp) {
                    encontrado = 1;
                    break;
                }
            }
            fclose(arquivoEstacao);
            if (!encontrado) {
                printf("Estacao nao cadastrada!\n");
                fclose(arquivoRoupa);
                continue;
            }
            roupa.CodigoEstacao = codigoEstacaoTemp;
            printf("Ano da Roupa: ");
            scanf("%d", &roupa.Ano);
            fprintf(arquivoRoupa, "%d,%s,%d,%d,%d\n",
                    roupa.CodigoRoupa, roupa.DescricaoRoupa,
                    roupa.CodigoEstilista, roupa.CodigoEstacao, roupa.Ano);
            fclose(arquivoRoupa);
            printf("Roupa cadastrada com sucesso!\n");
        }

        else if (opcao == 4) {
            int codigoEstacaoRelatorio;
            printf("Digite o codigo da Estacao para o relatorio: ");
            scanf("%d", &codigoEstacaoRelatorio);
            arquivoRoupa = fopen("Roupa.txt", "r");
            if (arquivoRoupa == NULL) {
                printf("Erro ao abrir Roupa.txt\n");
                continue;
            }

            printf("\nRoupas da Estacao %d:\n", codigoEstacaoRelatorio);
            while (fscanf(arquivoRoupa, "%d,%99[^,],%d,%d,%d\n",
                          &roupa.CodigoRoupa,
                          roupa.DescricaoRoupa,
                          &roupa.CodigoEstilista,
                          &roupa.CodigoEstacao,
                          &roupa.Ano) != EOF) {
                if (roupa.CodigoEstacao == codigoEstacaoRelatorio) {
                    arquivoEstilista = fopen("Estilista.txt", "r");
                    if (arquivoEstilista != NULL) {
                        while (fscanf(arquivoEstilista, "%d,%49[^,],%f\n",
                                      &estilista.CodigoEstilista,
                                      estilista.NomeEstilista,
                                      &estilista.Salario) != EOF) {
                            if (estilista.CodigoEstilista == roupa.CodigoEstilista) {
                                printf("Roupa: %s | Ano: %d | Estilista: %s\n",
                                       roupa.DescricaoRoupa,
                                       roupa.Ano,
                                       estilista.NomeEstilista);
                                break;
                            }
                        }
                        fclose(arquivoEstilista);
                    }
                }
            }

            fclose(arquivoRoupa);
        }

    } while (opcao != 0);

    printf("Programa finalizado.\n");
    return 0;
}
