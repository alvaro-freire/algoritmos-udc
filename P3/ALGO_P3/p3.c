/**
 * TÍTUL0: ALGORITMOS
 * SUBTÍTUL0: Práctica 3
 * @author Mateo Díaz Allegue @login mateo.diaz
 * @author Álvaro Freire Ares @login alvaro.freirea
 * GRUPO: 4.2
 * DATE: 16 / 11 / 2021
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define K 1000
#define VECTOR_SIZE 10
#define MAX_SIZE 512000
#define UMBRAL 1

double microsegundos() { /* obtiene la hora del sistema en microsegundos */
    struct timeval t;

    if (gettimeofday(&t, NULL) < 0)
        return 0.0;

    return (t.tv_usec + t.tv_sec * 1000000.0);
}


void inicializar_semilla() {
/* se establece la semilla de una nueva serie de enteros pseudo-aleatorios */
    srand(time(NULL));
}

void aleatorio(int v[], int n) {
    int i, m = 2 * n + 1;

    inicializar_semilla();

/* se generan números pseudoaleatorio entre -n y +n */
    for (i = 0; i < n; i++) {
        v[i] = (rand() % m) - n;
    }
}

bool ordenado(const int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            return false;
        }
    }
    return true;
}

void ascendente(int v[], int n) {
    for (int i = 0; i < n; i++)
        v[i] = i;
}

void descendente(int v[], int n) {
    int aux = n - 1;
    int i;

    for (i = 0; i < n; i++) {
        v[i] = aux;
        aux--;
    }
}

void listar_vector(int v[], int n) {
    int i;

    /* se lista el vector: */
    printf("[ ");

    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%2d ]", v[i]);
        } else {
            printf("%2d, ", v[i]);
        }
    }

    printf("\nOrdenado? %d\n", ordenado(v, n));
}

void intercambiar(int i, int j, int v[]) {
    int aux;

    /* se intercambian los valores
     * "i" y "j" en el vector "v" */

    aux = v[j];
    v[j] = v[i];
    v[i] = aux;
}

void ord_ins(int v[], int n) {
    int i, j;
    int x;

    for (i = 1; i < n; i++) {
        x = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > x) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

void mediana3(int v[], int i, int j) {
    int k;

    if (i >= j) {
        return;
    }

    k = (i + j) / 2;

    if (v[k] > v[j]) {
        intercambiar(j, k, v);
    }
    if (v[k] > v[i]) {
        intercambiar(i, k, v);
    }
    if (v[i] > v[j]) {
        intercambiar(i, j, v);
    }
}

void ord_aux(int v[], int izq, int der) {
    int i, j, pivote;

    if (izq + UMBRAL <= der) {
        mediana3(v, izq, der);

        pivote = v[izq];
        i = izq;
        j = der;

        do {
            do i++; while (v[i] < pivote);
            do j--; while (v[j] > pivote);
            intercambiar(i, j, v);
        } while (j > i);
        intercambiar(i, j, v);
        intercambiar(izq, j, v);
        ord_aux(v, izq, j - 1);
        ord_aux(v, j + 1, der);
    }
}

void ord_rapida(int v[], int n) {
    ord_aux(v, 0, n - 1);
    if (UMBRAL > 1) {
        ord_ins(v, n);
    }
}

double generate_and_sort(int v[], int n, void (*ini)(int [], int), void (*ord)(int [], int)) {
    double tb, ta;
    int j;

    /* se generan vectores y se ordenan
     * un total de K (1000) veces: */

    tb = microsegundos(); /* se mide el tiempo de inicio: */
    for (j = 0; j < K; ++j) {
        (*ini)(v, n);
        (*ord)(v, n);
    }
    ta = microsegundos(); /* se mide el tiempo final: */

    return ta - tb;
}

double generate_vectors(int v[], int n, void (*ini)(int [], int)) {
    double tb, ta;
    int j;

    /* se generan vectores y un
     * total de K (1000) veces: */

    tb = microsegundos(); /* se mide el tiempo de inicio: */
    for (j = 0; j < K; ++j) {
        (*ini)(v, n);
    }
    ta = microsegundos(); /* se mide el tiempo final: */

    return ta - tb;
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

double lower500(int v[], int n, void (*ini)(int [], int), void (*alg)(int [], int)) {
    double t1, t2;

    /* se calcula el tiempo para generar un vector
     * y ejecutar el algoritmo K (1000) veces: */
    t1 = generate_and_sort(v, n, ini, alg);

    /* se calcula el tiempo para
     * generar K (1000) vectores: */
    t2 = generate_vectors(v, n, ini);

    return (t1 - t2) / K;   /* se devuelve el tiempo final */
}

void test(void (*alg)(int [], int)) {
    int v[VECTOR_SIZE];

    printf("\nOrdenación con inicialización ascendente:\n");
    ascendente(v, VECTOR_SIZE);
    listar_vector(v, VECTOR_SIZE);
    (*alg)(v, VECTOR_SIZE);
    listar_vector(v, VECTOR_SIZE);

    printf("\nOrdenación con inicialización descendente:\n");
    descendente(v, VECTOR_SIZE);
    listar_vector(v, VECTOR_SIZE);
    (*alg)(v, VECTOR_SIZE);
    listar_vector(v, VECTOR_SIZE);

    printf("\nOrdenación con inicialización aleatoria:\n");
    aleatorio(v, VECTOR_SIZE);
    listar_vector(v, VECTOR_SIZE);
    (*alg)(v, VECTOR_SIZE);
    listar_vector(v, VECTOR_SIZE);
}

void print_times_tests(int n, double tf, double cSup, double cAj, double cInf, char aster) {
    /* muestra la información de una fila de datos: */
    printf("%9d%4s%c%11.3f%3s%15.6f%3s%15.6f%3s%15.6f\n",
           n, "", aster, tf, "", tf / cSup, "", tf / cAj, "", tf / cInf);
}

double calculate_cota(int n, double b) {
    /* si el exponente recibido es un -1,
     * la cota se calculará como n * log(n): */

    if (b == -1) {
        return n * log(n);
    } else {
        return pow(n, b);
    }
}

void calc_times_test(void (*ini)(int [], int), void (*alg)(int [], int), double exp1, double exp2,
                     double exp3, double (*cota)(int, double), char *op1, char *op2, char *op3) {
    int v[MAX_SIZE], n;
    double tf = 0;

    printf("%8sn%12st(n)%7st(n)/%s", "", "", "", op1);
    printf("%7st(n)/%s%7st(n)/%s\n", "", op2, "", op3);

    for (n = 500; n <= MAX_SIZE && tf < 500000; n *= 2) {

        /* se inicializa el vector: */
        (*ini)(v, n);

        /* se mide el tiempo de una ejecución */
        tf = time_measurer(v, n, alg);

        /* se comprueba si la medición fue < 500 ms: */
        if (tf < 500) {
            tf = lower500(v, n, ini, alg);
            print_times_tests(n, tf, cota(n, exp1), cota(n, exp2), cota(n, exp3), '*');
        } else {
            print_times_tests(n, tf, cota(n, exp1), cota(n, exp2), cota(n, exp3), ' ');
        }
    }
}

void timetest() {
    printf("\nORDENACIÓN POR INSERCIÓN:\n");

    /*  ** primera ejecución (no válida) ** */
    printf("\n** MEDICIÓN NO VÁLIDA (primera ejecución propensa a errores) **\n\n");
    calc_times_test(ascendente, ord_ins, 0.8, 1, 1.1, calculate_cota,
                    "(n^0.8)", "(n)", "(n^1.1)");

    /*  (a) el vector está ordenado en orden ascendente: */
    printf("\nVector inicialmente en orden ascendente:\n");
    calc_times_test(ascendente, ord_ins, 0.8, 1, 1.1, calculate_cota,
                    "(n^0.8)", "(n)", "(n^1.1)");

    /*  (b) el vector está ordenado en orden descendente: */
    printf("\nVector inicialmente en orden descendente:\n");
    calc_times_test(descendente, ord_ins, 1.9, 2, 2.1, calculate_cota,
                    "(n^1.9)", "(n^2)", "(n^2.1)");

    /*  (c) el vector está ordenado en orden aleatorio: */
    printf("\nVector inicialmente en orden aleatorio:\n");
    calc_times_test(aleatorio, ord_ins, 1.9, 2, 2.1, calculate_cota,
                    "(n^1.9)", "(n^2)", "(n^2.1)");

    printf("\nORDENACIÓN RÁPIDA: ( UMBRAL = %d )\n", UMBRAL);

    /*  (a) el vector está ordenado en orden ascendente: */
    printf("\nVector inicialmente en orden ascendente:\n");
    calc_times_test(ascendente, ord_rapida, 1, 1.09, 1.2, calculate_cota,
                    "(n^1)", "(n^1.09)", "(n^1.2)");

    /*  (b) el vector está ordenado en orden descendente: */
    printf("\nVector inicialmente en orden descendente:\n");
    calc_times_test(descendente, ord_rapida, 1, 1.08, 1.2, calculate_cota,
                    "(n^1)", "(n^1.08)", "(n^1.2)");

    /*  (c) el vector está ordenado en orden aleatorio: */
    printf("\nVector inicialmente en orden aleatorio:\n");
    calc_times_test(aleatorio, ord_rapida, 1, -1, 1.3, calculate_cota,
                    "(n^1)", "(n*log(n))", "(n^1.3)");
}

int main() {
    printf("\n************ TEST DE ALGORITMOS ************\n");

    printf("\nTEST DE ORDENACIÓN POR INSERCIÓN:\n");
    test(ord_ins);

    printf("\nTEST DE ORDENACIÓN RÁPIDA:\n");
    test(ord_rapida);

    printf("\n************ MEDICIÓN DE TIEMPOS ************\n");
    timetest();

    return 0;
}
