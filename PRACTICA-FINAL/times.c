/*
 * TÍTUL0: ALGORITMOS
 * SUBTÍTUL0: PRUEBA FINAL
 * AUTOR 2: Álvaro Freire Ares LOGIN 2: alvaro.freirea
 * GRUPO: 4.2
 * DATE: 12 / 01 / 2022
 */

#include <stdio.h>
#include "times.h"
#include "auxiliars.h"

#define K 1000

double microsegundos() {
    struct timeval t;

    /* obtiene la hora del sistema en microsegundos */
    if (gettimeofday(&t, NULL) < 0)
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}

double time_measurer(int v[], int n, void (*alg)(int [], int)) {
    double ta, tb;

    /* se calcula el tiempo que se
     * tarda en ordenar un vector: */

    tb = microsegundos();
    (*alg)(v, n);
    ta = microsegundos();

    return ta - tb;
}

double generate_and_sort(void (*algo)(int [], int), int v[], int n) {
    double ta, tb;
    int i;

    tb = microsegundos();
    for (i = 0; i < K; ++i) {
        aleatorio(v, n);
        (*algo)(v, n);
    }
    ta = microsegundos();

    return ta - tb;
}

double generate(int v[], int n) {
    double ta, tb;
    int i;

    tb = microsegundos();
    for (i = 0; i < K; ++i) {
        aleatorio(v, n);
    }
    ta = microsegundos();

    return ta - tb;
}

double lower500(void (*algo)(int [], int), int v[], int n) {
    double t1, t2;

    /* se calcula el tiempo para generar un vector
     * y ejecutar el algoritmo K (1000) veces: */
    t1 = generate_and_sort(algo, v, n);

    /* se calcula el tiempo para
     * generar K (1000) vectores: */
    t2 = generate(v, n);

    return (t1 - t2) / K;   /* se devuelve el tiempo final */
}
