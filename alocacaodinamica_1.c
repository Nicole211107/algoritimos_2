#include <stdio.h>
#include <stdlib.h>

int main(){
    char *n = (char*) malloc(1);
    int *g = (int*) malloc(1);
    float *c = (float*) malloc(1);
    double *j = (double*) malloc(1);
    printf("tamanho do char: %lu bytes\n", sizeof(char));
    printf("tamanho do int: %lu bytes\n", sizeof(int));
    printf("tamanho do float: %lu bytes\n", sizeof(float));
    printf("tamanho do double: %lu bytes\n", sizeof(double));

    return 0;
}
