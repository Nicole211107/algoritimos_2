#include <stdio.h>

struct aluno {
    int matricula;
    char nome[30];
    float nota1;
    float nota2;
    float nota3;
};

int main() {

    struct aluno lista[5];
    int i;
    int indice_maior = 0;
    float maior_media = 0;
    for(i = 0; i < 5; i++){

        lista[i].matricula = i + 1;
        printf("\ndigite o nome do aluno: ");
        scanf("%s", lista[i].nome);
        printf("coloca a nota 1: ");
        scanf("%f", &lista[i].nota1);
        printf("coloca a nota 2: ");
        scanf("%f", &lista[i].nota2);
        printf("coloca a nota 3: ");
        scanf("%f", &lista[i].nota3);
        float media = (lista[i].nota1 + lista[i].nota2 + lista[i].nota3) / 3;
        if(i == 0 || media > maior_media){
            maior_media = media;
            indice_maior = i;
        }
    }

    printf("\nquem ficou com a maior media foi %s\n", lista[indice_maior].nome);
    printf("nota 1 = %.2f\n", lista[indice_maior].nota1);
    printf("nota 2 = %.2f\n", lista[indice_maior].nota2);
    printf("nota 3 = %.2f\n", lista[indice_maior].nota3);
    printf("media final = %.2f\n", maior_media);

    return 0;
}
