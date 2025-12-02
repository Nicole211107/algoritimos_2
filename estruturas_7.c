#include <stdio.h>

struct hora{
    int hora;
    int minuto;
    int segundo;
};

int main() {
    struct hora lista[5];
    int i;
    int indice_maior = 0;
    for(i = 0; i < 5; i++){
        printf("\n digite os dados da hora %d\n", i+1);
        printf("coloca a hora: ");
        scanf("%d", &lista[i].hora);
        printf("coloca o minuto: ");
        scanf("%d", &lista[i].minuto);
        printf("coloca o segundo: ");
        scanf("%d", &lista[i].segundo);
    }

      for(i = 1; i < 5; i++){
        if(lista[i].hora > lista[indice_maior].hora){
            indice_maior = i;
        } else if(lista[i].hora == lista[indice_maior].hora){
            if(lista[i].minuto > lista[indice_maior].minuto){
                indice_maior = i;
            } else if(lista[i].minuto == lista[indice_maior].minuto){
                if(lista[i].segundo > lista[indice_maior].segundo){
                    indice_maior = i;
                }
            }
        }
    }

      printf("\na maior hora digitada foi: %02d:%02d:%02d\n");
      lista[indice_maior].hora, 
           lista[indice_maior].minuto, 
           lista[indice_maior].segundo;
           
           return 0;

}