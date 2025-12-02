#include <stdio.h>

struct nicole {
    char nome[100];
    char esporte[100];
    int idade;
    float altura;
};

int main() {

    struct nicole atletas[5];
    int n = 0;
    int c;
    int a;
    while(n < 5){
        printf("manda o nome do atleta: \n");
        scanf("%s", atletas[n].nome);
        printf("qual esporte ele pratica: \n");
        scanf("%s", atletas[n].esporte);
        printf("coloca a idade: \n");
        scanf("%d", &atletas[n].idade);
        printf("coloca a altura: \n");
        scanf("%f", &atletas[n].altura);
        n = n + 1;
    }

    n = 0;
    while(n < 4){
        c = n + 1;
        while(c < 5){
            if(atletas[n].idade < atletas[c].idade){
                int idade_temp;
                float altura_temp;
                char temp;
                idade_temp = atletas[n].idade;
                atletas[n].idade = atletas[c].idade;
                atletas[c].idade = idade_temp;
                altura_temp = atletas[n].altura;
                atletas[n].altura = atletas[c].altura;
                atletas[c].altura = altura_temp;
                a = 0;
                while(atletas[n].nome[a] != '\0' || atletas[c].nome[a] != '\0'){
                    temp = atletas[n].nome[a];
                    atletas[n].nome[a] = atletas[c].nome[a];
                    atletas[c].nome[a] = temp;
                    a = a + 1;
                }

                a = 0;
                while(atletas[n].esporte[a] != '\0' || atletas[c].esporte[a] != '\0'){
                    temp = atletas[n].esporte[a];
                    atletas[n].esporte[a] = atletas[c].esporte[a];
                    atletas[c].esporte[a] = temp;
                    a = a + 1;
                }
            }
            c = c + 1;
        }
        n = n + 1;
    }
    n = 0;
    while(n < 5){
        printf("\n%s, idade: %d, esporte: %s, altura: %.2f\n", 
               atletas[n].nome, atletas[n].idade, atletas[n].esporte, atletas[n].altura);
        n = n + 1;
    }
    return 0;
}
