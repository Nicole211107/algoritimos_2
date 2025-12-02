#include <stdio.h>

struct nicole {
    char nome[50];
    int dia;
    int mes;
    int ano;
};

int main() {

    struct nicole pessoa;
    struct nicole mais_velha;
    struct nicole mais_nova;
    int i = 0;
    while(i < 6){
        printf("\n digite o nome da pessoa:");
        scanf("%s", pessoa.nome);
        printf("coloca o dia de nascimento:");
        scanf("%d", &pessoa.dia);
        printf("coloca o mes de nascimento:");
        scanf("%d", &pessoa.mes);
        printf("coloca o ano de nascimento:");
        scanf("%d", &pessoa.ano);
        if(i == 0){
            mais_velha = pessoa;
            mais_nova = pessoa;
        } else {
            if(pessoa.ano < mais_velha.ano){
                mais_velha = pessoa;
            } else if(pessoa.ano == mais_velha.ano){
                if(pessoa.mes < mais_velha.mes){
                    mais_velha = pessoa;
                } else if(pessoa.mes == mais_velha.mes){
                    if(pessoa.dia < mais_velha.dia){
                        mais_velha = pessoa;
                    }
                }
            }

            if(pessoa.ano > mais_nova.ano){
                mais_nova = pessoa;
            } else if(pessoa.ano == mais_nova.ano){
                if(pessoa.mes > mais_nova.mes){
                    mais_nova = pessoa;
                } else if(pessoa.mes == mais_nova.mes){
                    if(pessoa.dia > mais_nova.dia){
                        mais_nova = pessoa;
                    }
                }
            }
        }

        i = i + 1;
    }

    printf("\n a pessoa mais velha é: %s\n", mais_velha.nome);
    printf("a pessoa mais nova é: %s\n", mais_nova.nome);

    return 0;
}
