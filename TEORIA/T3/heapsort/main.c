#include <stdio.h>
#include "heap.h"

void heapsort(int v[], int n) {
    int i, tam;
    Monticulo m;

    Inicializar_Monticulo(&m);
    Crear_Monticulo(v, n, &m);
    tam = m.tamano_monticulo;

    for (i = 0; i < tam; i++) {
        v[tam - i - 1] = EliminarMax(&m);
    }
}

int main() {
    int i;
    int v[9] = {53, 17, 78, 9, 45, 65, 12, 14, 99};

    printf("Vector desordenado: \n");

    for (i = 0; i < 9; i++) {
        printf("%d, ", v[i]);
    }

    heapsort(v, 9);

    printf("\nVector ordenado: \n");

    for (i = 0; i < 9; i++) {
        printf("%d, ", v[i]);
    }

    return 0;
}
