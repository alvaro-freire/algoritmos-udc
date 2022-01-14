#include <stdio.h>

#define UMBRAL 5

void ord_ins(int v[], int izq, int dch) {
    int i, j;
    int x;

    for (i = izq + 1; i <= dch; i++) {
        x = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > x) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

void merge(int v[], int izq, int dch, int centro) {
    int aux_tam = dch - izq + 1;
    int aux[aux_tam];
    int i = izq;
    int j = centro + 1;
    int k = izq;

    while (i <= centro && j <= dch) {
        if (v[i] <= v[j]) {
            aux[izq - k] = v[i];
            i++;
        } else {
            aux[izq - k] = v[j];
            j++;
        }
        k++;
    }

    while (i <= centro) {
        aux[izq - k] = v[j];
        i++;
        k++;
    }

    while (j <= dch) {
        aux[izq - k] = v[j];
        j++;
        k++;
    }

    for (k = izq; k <= dch; k++) {
        v[k] = aux[izq - k];
    }
}

void recursive_mergesort(int v[], int izq, int dch) {
    int centro;

    if (izq + UMBRAL < dch) {
        centro = (izq + dch) / 2;
        recursive_mergesort(v, izq, centro);
        recursive_mergesort(v, centro + 1, dch);
        merge(v, izq, dch, centro);
    } else {
        ord_ins(v, izq, dch);
    }

}

void mergesort(int v[], int n) {
    recursive_mergesort(v, 0, n - 1);
}

void printarray(int v[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\nTamaño: %d\n", i);
}

#define TAM 14

int main() {
    int v[TAM] = {3, 2, 6, 1, 7, 4, 65, 1, 6, 62, 253, 2352, 124, 11};

    printf("Vector desordenado: \n");

    printarray(v, TAM);

    mergesort(v, TAM);

    printf("\nVector ordenado: \n");

    printarray(v, TAM);

    return 0;
}
