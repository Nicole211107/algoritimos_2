#include <stdio.h>

float raizquadrada(float n){
    float chute = n;
    float outro = 1;
    int i = 0;

    while(i < 10){
        chute = (chute + n / chute) / 2;
        i++;
    }
    return chute;
}

struct ponto{
    float x;
    float y;
};

struct retangulo{
    struct ponto superior_esquerdo;
    struct ponto inferior_direito;
};

int main(){
    struct retangulo r;
    scanf("%f", &r.superior_esquerdo.x);
    scanf("%f", &r.superior_esquerdo.y);
    scanf("%f", &r.inferior_direito.x);
    scanf("%f", &r.inferior_direito.y);
    float largura;
    float altura;
    largura = r.inferior_direito.x - r.superior_esquerdo.x;
    altura = r.superior_esquerdo.y - r.inferior_direito.y;
    if(largura < 0){
        largura = largura * -1;
    }
    if(altura < 0){
        altura = altura * -1;
    }

    float area = largura * altura;
    float diagonal;
    diagonal = raizquadrada(largura*largura + altura*altura);
    float perimetro;
    perimetro = 2 * (largura + altura);
    printf("area:%f\n", area);
    printf("diagonal:%f\n", diagonal);
    printf("perimetro:%f\n", perimetro);
}
