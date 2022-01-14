#include <stdio.h>

void mochila1(const int a[], const int b[], int n, int W) {
    int i;
    int peso = 0;
    int x[n];

    for (i = 0; i < n; ++i) {
        x[i] = 0;
    }

    while (peso < W) {
        // i = mejor objeto restante
        if (peso + a[i] <= W) {
            x[i] = 1;
            peso += a[i];
        } else {
            x[i] = (W - peso) / a[i];
            peso = W;
        }
    }

    return x;
}

void printarray(int v[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
}

#define TAM 4

int main() {
    int v[TAM] = {3, 2, 6, 1};

    printf("Vector desordenado: \n");

    printarray(v, TAM);

    int a[2] = {3, 2};
    int b[2] = {6, 1};


    printf("\nVector ordenado: \n");

    printarray(v, TAM);

    return 0;
}
