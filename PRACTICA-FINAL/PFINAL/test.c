/*
 * TÍTUL0: ALGORITMOS
 * SUBTÍTUL0: PRUEBA FINAL
 * AUTOR 2: Álvaro Freire Ares LOGIN 2: alvaro.freirea
 * GRUPO: 4.2
 * DATE: 12 / 01 / 2022
 */

#include <stdio.h>
#include "test.h"
#include "times.h"
#include "auxiliars.h"
#include "pfinal.h"

#define NULL_INT -100


void test1() {
    int i, r1, r2, r3;
    int v[6][5] = {{-9, 2,  -5, -4, 6},
                   {4,  0,  9,  2,  5},
                   {-2, -1, -9, -7, -1},
                   {9,  -2, 1,  -7, -8},
                   {15, -2, -5, -4, 16},
                   {7,  -5, 6,  7,  -7}};

    printf("Secuencias%15sResultado1\tResultado2\tResultado3\n", "");

    for (i = 0; i <= 5; ++i) {
        /* se calculan los resultados de
         * cada algoritmo y se listan: */
        r1 = sumaSubMax1(v[i], 5);
        r2 = sumaSubMax2(v[i], 5);
        r3 = sumaSubMax3(v[i], 5);
        listar_vector(v[i], 5, r1, r2, r3);
    }
}

void test2() {
    int i, a, b, c;
    int v[9];

    printf("\n%43s%s%4s%s%4s%4s\n", "", "sumaSubMax1", "", "sumaSubMax2", "", "sumaSubMax3");

    for (i = 0; i < 10; i++) {
        aleatorio(v, 9);
        listar_vector(v, 9, NULL_INT, NULL_INT, NULL_INT);
        a = sumaSubMax1(v, 9);
        b = sumaSubMax2(v, 9);
        c = sumaSubMax3(v, 9);
        printf("%7s%5d%15d%15d\n", "", a, b, c);
    }
}

void test3(void (*algo)(int [], int)) {
    double tf;
    int v[32000];
    int n = 500, i;

    printf("\nAlgoritmo 3:\n");
    printf("\tn%12st(n)%6st(n)/n^0.9", "", "");
    printf("%4st(n)/n^1.05%6st(n)/n^1.2\n", "", "");

    for (i = 0; i < 7; i++) {
        /* se genera vector */
        aleatorio(v, n);

        /* se miden tiempos */
        tf = time_measurer(v, n, algo);

        /* si el tiempo final es menor que 500, se
         * calcula K (1000) veces y se hace la media: */
        if (tf < 500) {
            tf = lower500(algo, v, n);
            print_test3(n, tf, true);
        } else {
            print_test3(n, tf, false);
        }
        n *= 2;  // se incrementa n
    }
}