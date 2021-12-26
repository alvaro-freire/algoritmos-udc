/**
 * TÍTUL0: ALGORITMOS
 * SUBTÍTUL0: Práctica 4
 * @author Mateo Díaz Allegue @login mateo.diaz
 * @author Álvaro Freire Ares @login alvaro.freirea
 * GRUPO: 4.2
 * DATE: 23 / 11 / 2021
 */

#include "test.h"
#include "p4.h"

#define K 1000

void prim(matriz m, int nodos, cola *aristas) {
    /* calcular el árbol de recubrimiento mínimo devolviendo
    las aristas del árbol en la cola 'aristas' */
    arista a;
    int i, j, k = 0, min;
    int *masProximo = (int *) malloc(nodos * sizeof(int));
    int *distanciaMinima = (int *) malloc(nodos * sizeof(int));

    crear_cola(aristas);
    distanciaMinima[0] = -1;
    for (i = 1; i < nodos; i++) {
        masProximo[i] = 0;
        distanciaMinima[i] = m[i][0];
    }

    for (i = 1; i < nodos; i++) {
        min = INT_MAX;
        for (j = 1; j < nodos; j++) {
            if (0 <= distanciaMinima[j] && distanciaMinima[j] < min) {
                min = distanciaMinima[j];
                k = j;
            }
        }

        a.x = masProximo[k];
        a.y = k;
        a.peso = m[a.x][a.y];
        insertar(a, aristas);
        distanciaMinima[k] = -1;

        for (j = 1; j < nodos; j++) {
            if (m[j][k] < distanciaMinima[j]) {
                distanciaMinima[j] = m[j][k];
                masProximo[j] = k;
            }
        }
    }

    free(masProximo);
    free(distanciaMinima);
}

double generate_and_sort(matriz m, int n) {
    cola aristas;
    int j;
    double tb, ta;

    /* se generan matrices y se ejecuta *
     * prim un total de K (1000) veces: */

    tb = microsegundos(); /* se mide el tiempo de inicio: */
    for (j = 0; j < K; ++j) {
        inicializar_matriz(m, n);
        prim(m, n, &aristas);
    }
    ta = microsegundos(); /* se mide el tiempo final: */

    return ta - tb;
}

double generate_matrix(matriz m, int n) {
    int j;
    double tb, ta;

    /* se generan K (1000) matrices: */

    tb = microsegundos(); /* se mide el tiempo de inicio: */
    for (j = 0; j < K; ++j) {
        inicializar_matriz(m, n);
    }
    ta = microsegundos(); /* se mide el tiempo final: */

    return ta - tb;
}

double prim_measurer(matriz m, int n) {
    cola aristas;
    double ta, tb;

    /* se calcula el tiempo que se
     * tarda en ejecutar prim: */

    tb = microsegundos();
    prim(m, n, &aristas);
    ta = microsegundos();

    return ta - tb;
}

double lower500(matriz m, int n) {
    double t1, t2;

    /* se calcula el tiempo para generar una
     * matriz y ejecutar prim K (1000) veces: */
    t1 = generate_and_sort(m, n);

    /* se calcula el tiempo para
     * generar K (1000) matrices: */
    t2 = generate_matrix(m, n);

    return (t1 - t2) / K;   /* se devuelve el tiempo final */
}

double cota(int n, double b) {
    /* si el exponente recibido es un -1,
     * la cota se calculará como n² * log(n): */

    if (b == -1) {
        return pow(n, 2) * log(n);
    } else {
        return pow(n, b);
    }
}

int main() {
    test();
    timetest();

    return 0;
}
