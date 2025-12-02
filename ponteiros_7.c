#include <stdio.h>

int acontece(char *a, char *c) {
    int n = 0;
    int m = 0;
    while(*(a + n) != '\0') {
        m = 0;
        while(*(c + m) != '\0' && *(a + n + m) == *(c + m)) {
            m++;
        }

        if(*(c + m) == '\0') {
            return 1;
        }

        n++;
    }

    return 0;
}

int main() {
    char primeira[100];
    char segunda[100];
    printf("digita a primeira string: ");
    scanf("%99s", primeira);
    printf("digita a segunda string: ");
    scanf("%99s", segunda);
    if(acontece(primeira, segunda) == 1) {
        printf("a segunda aparece dentro da primeira\n");
    } else {
        printf("a segunda nao aparece dentro da primeira\n");
    }

    return 0;
}
