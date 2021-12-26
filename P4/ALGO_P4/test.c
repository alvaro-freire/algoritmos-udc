/**
 * TÍTUL0: ALGORITMOS
 * SUBTÍTUL0: Práctica 4
 * @author Mateo Díaz Allegue @login mateo.diaz
 * @author Álvaro Freire Ares @login alvaro.freirea
 * GRUPO: 4.2
 * DATE: 23 / 11 / 2021
 */

#include "test.h"
#include "prints.h"
#include "p4.h"

#define EXP2 2.09   // exponente de la cota ajustada
#define N 15        // tamaño inicial de la matriz (NxN)
#define EJEC 10     // número de tablas a mostrar

void timetest() {
    int i;

    printf("\nMEDICIÓN DE TIEMPOS:\n");

    /* primera ejecución no válida */
    printf("\n** MEDICIÓN NO VÁLIDA (primera ejecución propensa a errores) **\n\n");
    calc_times_test(EXP2 - 0.2, EXP2, EXP2 + 0.2);

    for (i = 1; i <= EJEC; i++) {
        printf("\nTabla %d:\n", i);
        calc_times_test(EXP2 - 0.2, EXP2, EXP2 + 0.2);
    }
}

void test() {
    printf("\nTEST ALGORITMO DE PRIM:\n");

    printf("\nEjemplo 1:\n");
    test1();

    printf("\nEjemplo 2:\n");
    test2();

    printf("\nEjemplo 3:\n");
    test3();
}

void calc_times_test(double exp1, double exp2, double exp3) {
    matriz m;
    int nodos;
    char c;
    double tf, v1, v2, v3;

    print_columns(exp1, exp2, exp3);

    for (nodos = N; nodos < TAM_MAX; nodos *= 2) {
        m = crear_matriz(nodos);

        /* se inicializa la matriz: */
        inicializar_matriz(m, nodos);

        /* se mide el tiempo de una ejecución */
        tf = prim_measurer(m, nodos);

        /* se comprueba si la medición fue < 500 ms: */
        if (tf < 500) {
            tf = lower500(m, nodos);
            c = '*';
        } else {
            c = ' ';
        }

        /* se calculan los valores para la tabla: */
        v1 = tf / cota(nodos, exp1);
        v2 = tf / cota(nodos, exp2);
        v3 = tf / cota(nodos, exp3);

        /* se imprime la fila con los valores: */
        printf("%9d%4s%c%11.3f%3s%15.6f%3s%15.6f%3s%15.6f\n",
               nodos, "", c, tf, "", v1, "", v2, "", v3);

        liberar_matriz(m, nodos);
    }
}

void test1() {
    int nodos = 5;
    cola aristas;
    matriz m = crear_matriz(nodos);

    m[0][0] = 0; m[0][1] = 1; m[0][2] = 8; m[0][3] = 4; m[0][4] = 7;
    m[1][0] = 1; m[1][1] = 0; m[1][2] = 2; m[1][3] = 6; m[1][4] = 5;
    m[2][0] = 8; m[2][1] = 2; m[2][2] = 0; m[2][3] = 9; m[2][4] = 5;
    m[3][0] = 4; m[3][1] = 6; m[3][2] = 9; m[3][3] = 0; m[3][4] = 3;
    m[4][0] = 7; m[4][1] = 5; m[4][2] = 5; m[4][3] = 3; m[4][4] = 0;

    test_aux(m, nodos, aristas, 1);
}

void test2() {
    int nodos = 4;
    cola aristas;
    matriz m = crear_matriz(nodos);

    m[0][0] = 0; m[0][1] = 1; m[0][2] = 4; m[0][3] = 7;
    m[1][0] = 1; m[1][1] = 0; m[1][2] = 2; m[1][3] = 8;
    m[2][0] = 4; m[2][1] = 2; m[2][2] = 0; m[2][3] = 3;
    m[3][0] = 7; m[3][1] = 8; m[3][2] = 3; m[3][3] = 0;

    test_aux(m, nodos, aristas, 2);
}

void test3() {
    int nodos = 7;
    cola aristas;
    matriz m = crear_matriz(nodos);

    m[0][0] = 0; m[0][1] = 7; m[0][2] = INT_MAX; m[0][3] = 5;
        m[0][4] = INT_MAX; m[0][5] = INT_MAX; m[0][6] = INT_MAX;

    m[1][0] = 7; m[1][1] = 0; m[1][2] = 8; m[1][3] = 9;
        m[1][4] = 7; m[1][5] = INT_MAX; m[1][6] = INT_MAX;

    m[2][0] = INT_MAX; m[2][1] = 8; m[2][2] = 0; m[2][3] = INT_MAX;
        m[2][4] = 5; m[2][5] = INT_MAX; m[2][6] = INT_MAX;

    m[3][0] = 5; m[3][1] = 9; m[3][2] = INT_MAX; m[3][3] = 0;
        m[3][4] = 15; m[3][5] = 6; m[3][6] = INT_MAX;

    m[4][0] = INT_MAX; m[4][1] = 7; m[4][2] = 5; m[4][3] = 15;
        m[4][4] = 0; m[4][5] = 8; m[4][6] = 9;

    m[5][0] = INT_MAX; m[5][1] = INT_MAX; m[5][2] = INT_MAX; m[5][3] = 6;
        m[5][4] = 8; m[5][5] = 0; m[5][6] = 11;

    m[6][0] = INT_MAX; m[6][1] = INT_MAX; m[6][2] = INT_MAX; m[6][3] = INT_MAX;
        m[6][4] = 9; m[6][5] = 11; m[6][6] = 0;

    test_aux(m, nodos, aristas, 3);
}

void test_aux(matriz m, int nodos, cola aristas, int n_test) {
    print_matrix(m, nodos); /* se muestra la matriz de adyacencia */

    prim(m, nodos, &aristas);   /* se ejecuta el algoritmo */

    print_expected(n_test); /* se muestra el árbol de recubrimiento esperado */

    mostrar_cola(aristas);  /* se muestra el árbol obtenido */

    liberar_matriz(m, nodos);
}