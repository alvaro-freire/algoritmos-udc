#include <stdio.h>

void printarray(int v[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
}

#define TAM 6

int main() {
    int v[TAM] = {3, 2, 6, 1, 7, 4};

    printf("Vector desordenado: \n");

    printarray(v, TAM);

    //

    printf("\nVector ordenado: \n");

    printarray(v, TAM);

    return 0;
}
