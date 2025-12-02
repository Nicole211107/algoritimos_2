#include <stdio.h>

struct Ponto {
    float x;
    float y;
};

struct Retangulo {
    struct Ponto superior_esquerdo;
    struct Ponto inferior_direito;
};

int ponto_dentro(struct Retangulo retangulo, struct Ponto ponto) {
    float valor_minimo_x = retangulo.superior_esquerdo.x;
    float valor_maximo_x = retangulo.inferior_direito.x;
    float valor_minimo_y = retangulo.inferior_direito.y;
    float valor_maximo_y = retangulo.superior_esquerdo.y;
    if (ponto.x >= valor_minimo_x && ponto.x <= valor_maximo_x &&
        ponto.y >= valor_minimo_y && ponto.y <= valor_maximo_y) {
        return 1;
    }
    return 0;
}

int main() {

    struct Retangulo retangulo;
    struct Ponto ponto;
    printf("X do superior esquerdo: ");
    scanf("%f", &retangulo.superior_esquerdo.x);
    printf("Y do superior esquerdo: ");
    scanf("%f", &retangulo.superior_esquerdo.y);
    printf("X do inferior direito: ");
    scanf("%f", &retangulo.inferior_direito.x);
    printf("Y do inferior direito: ");
    scanf("%f", &retangulo.inferior_direito.y);
    printf("X do ponto: ");
    scanf("%f", &ponto.x);
    printf("Y do ponto: ");
    scanf("%f", &ponto.y);
    if (ponto_dentro(retangulo, ponto) == 1) {
        printf("o ponto ta dentro\n");
    } else {
        printf("o ponto nao ta dentro\n");
    }
    return 0;
}

