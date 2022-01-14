/*
 * TÍTUL0: ALGORITMOS
 * SUBTÍTUL0: PRUEBA FINAL
 * AUTOR 2: Álvaro Freire Ares LOGIN 2: alvaro.freirea
 * GRUPO: 4.2
 * DATE: 12 / 01 / 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "auxiliars.h"

#define NULL_INT -100

int max(int a, int b) {
    return a > b ? a : b;
}

void listar_vector(int v[], int n, int n1, int n2, int n3) {
    int i;
    /* se lista el vector: */

    printf("[ ");
    for (i = 0; i < n; i++) {
        if (i == n - 1)
            printf("%2d ]", v[i]);
        else
            printf("%2d, ", v[i]);
    }

    /* solo se muestra en el test1, no en el test2: */
    if (n1 != NULL_INT && n2 != NULL_INT)
        printf("%4s%2d%16s%2d%16s%2d\n", "", n1, "", n2, "", n3);
}

void inicializar_semilla() {
/* se establece la semilla de una nueva serie de enteros pseudo-aleatorios */
    srand(time(NULL));
}

void aleatorio(int v[], int n) {
    int i, m = 2 * n + 1;

    /* se generan números pseudoaleatorios entre -n y +n */
    for (i = 0; i < n; i++) {
        v[i] = (rand() % m) - n;
    }
}

void print_test3(int n, double tf, bool lt500) {
    double inf = pow(n, 0.9);
    double aj = pow(n, 1.05);
    double sup = pow(n, 1.2);

    /* se imprimen los datos por pantalla */
    if (lt500) {
        printf("%9d\t*%8.3f\t%9.6f\t%7.6f\t%7.6f\n",
               n, tf, tf / inf, tf / aj, tf / sup);
    } else {
        printf("%9d\t%9.3f\t%9.6f\t%7.6f\t%7.6f\n",
               n, tf, tf / inf, tf / aj, tf / sup);
    }
}