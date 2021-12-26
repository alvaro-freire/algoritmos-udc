/**
 * TÍTUL0: ALGORITMOS
 * SUBTÍTUL0: Práctica 4
 * @author Mateo Díaz Allegue @login mateo.diaz
 * @author Álvaro Freire Ares @login alvaro.freirea
 * GRUPO: 4.2
 * DATE: 23 / 11 / 2021
 */

#include "prints.h"

void print_matrix(int **m, int nodos) {
    int i, j;

    printf("\nMATRIZ DE ADYACENCIA:\n");

    for (i = 0; i < nodos; ++i) {
        printf("( ");

        for (j = 0; j < nodos; ++j) {
            if (m[i][j] > 99) {
                printf(" ∞");
            } else {
                printf("%2d", m[i][j]);
            }

            if (j == nodos - 1) {
                printf(" )\n");
            } else {
                printf(", ");
            }
        }
    }

    printf("\n");
}

void print_columns(double exp1, double exp2, double exp3) {
    printf("%8sn%12st(n)%7st(n)/n^%.2f", "", "", "", exp1);
    printf("%7st(n)/n^%.2f%7st(n)/n^%.2f\n", "", exp2, "", exp3);
}

void print_expected(int n_test) {
    if (n_test == 1) {
        printf("EXPECTED:\n");
        printf("Aristas: (0, 1) (1, 2) (0, 3) (3, 4)\n");
        printf("Peso:    10\n");
    } else if (n_test == 2) {
        printf("EXPECTED:\n");
        printf("Aristas: (0, 1) (1, 2) (2, 3)\n");
        printf("Peso:    6\n");
    } else {
        printf("EXPECTED:\n");
        printf("Aristas: (0, 3) (3, 5) (0, 1) (1, 4) (4, 2) (4, 6)\n");
        printf("Peso:    39\n");
    }
}