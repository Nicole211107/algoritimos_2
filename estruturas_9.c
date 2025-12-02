#include <stdio.h>

struct nicole {
    char nome[100];
    char esporte[100];
    int idade;
    float altura;
};

int main() {

    struct nicole atleta;
    struct nicole mais_velho;
    struct nicole mais_alto;
    int i = 0;
    while(i < 5){
        printf("manda o nome do atleta: \n");
        scanf("%s", atleta.nome);
        printf("qual esporte ele pratica: \n");
        scanf("%s", atleta.esporte);
        printf("coloca a idade: \n");
        scanf("%d", &atleta.idade);
        printf("coloca a altura: \n");
        scanf("%f", &atleta.altura);
        if(i == 0){
            mais_velho = atleta;
            mais_alto = atleta;
        }

        else{
            if(atleta.idade > mais_velho.idade){
                mais_velho = atleta;
            }

            if(atleta.altura > mais_alto.altura){
                mais_alto = atleta;
            }
        }

        i = i + 1;
    }

    printf("o mais velho é: %s\n", mais_velho.nome);
    printf("idade dele: %d\n", mais_velho.idade);
    printf("o mais alto é: %s\n", mais_alto.nome);
    printf("altura dele: %.2f\n", mais_alto.altura);
    return 0;
}
