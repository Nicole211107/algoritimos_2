#include <stdio.h>
#include <stdlib.h>

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

struct Estacao {
    int CodigoEstacao;
    char NomeEstacao[50];
};

int main() {
    FILE *arquivoEstilista, *arquivoRoupa, *arquivoEstacao;
    arquivoEstilista = fopen("Estilista.txt", "w");
    if (arquivoEstilista == NULL) {
        printf("Erro ao criar Estilista.txt\n");
        return 1;
    }

    fclose(arquivoEstilista);
    arquivoRoupa = fopen("Roupa.txt", "w");
    if (arquivoRoupa == NULL) {
        printf("Erro ao criar Roupa.txt\n");
        return 1;
    }
    fclose(arquivoRoupa);
    arquivoEstacao = fopen("Estacao.txt", "w");
    if (arquivoEstacao == NULL) {
        printf("Erro ao criar Estacao.txt\n");
        return 1;
    }
    fclose(arquivoEstacao);
    printf("Arquivos Estilista.txt, Roupa.txt e Estacao.txt criados com sucesso!\n");

    return 0;
}
