/**
 * TÍTUL0: ALGORITMOS
 * SUBTÍTUL0: Práctica 4
 * @author Mateo Díaz Allegue @login mateo.diaz
 * @author Álvaro Freire Ares @login alvaro.freirea
 * GRUPO: 4.2
 * DATE: 23 / 11 / 2021
 */

#include "matrix.h"

matriz crear_matriz(int n) {
    int i;
    matriz aux;

    if ((aux = malloc(n * sizeof(int *))) == NULL) {
        return NULL;
    }

    for (i = 0; i < n; i++) {
        if ((aux[i] = malloc(n * sizeof(int))) == NULL) {
            return NULL;
        }
    }

    return aux;
}

void inicializar_matriz(matriz m, int n) {
/* Crea un grafo completo no dirigido con valores aleatorios entre 1 y n */
    int i, j;

    inicializar_semilla();

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            m[i][j] = rand() % n + 1;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            if (i == j) {
                m[i][j] = 0;
            } else {
                m[i][j] = m[j][i];
            }
        }
    }
}

void liberar_matriz(matriz m, int n) {
    int i;

    for (i = 0; i < n; i++) {
        free(m[i]);
    }

    free(m);
}

void inicializar_semilla() {
/* se establece la semilla de una nueva serie de enteros pseudo-aleatorios */
    srand(time(NULL));
}

double microsegundos() { /* obtiene la hora del sistema en microsegundos */
    struct timeval t;

    if (gettimeofday(&t, NULL) < 0) {
        return 0.0;
    }

    return (t.tv_usec + t.tv_sec * 1000000.0);
}