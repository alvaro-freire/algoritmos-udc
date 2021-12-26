/**
 * TÍTUL0: ALGORITMOS
 * SUBTÍTUL0: Práctica 2
 * AUTOR 1: Mateo Díaz Allegue LOGIN 1: mateo.diaz
 * AUTOR 2: Álvaro Freire Ares LOGIN 2: alvaro.freirea
 * GRUPO: 4.2
 * DATE: 05 / 10 / 2021
 */

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>

#define K 1000
#define MAX_SIZE 512000

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

void ord_sel(int v[], int n) {
    int minj, minx;
    int i, j;

    for (i = 0; i < n - 1; i++) {
        minj = i;
        minx = v[i];
        for (j = i + 1; j < n; j++) {
            if (v[j] < minx) {
                minj = j;
                minx = v[j];
            }
        }
        v[minj] = v[i];
        v[i] = minx;
    }
}

void ord_shell(int v[], int n) {
    int incremento = n;
    int i, j, tmp;
    bool seguir;

    do {
        incremento /= 2;
        for (i = incremento; i < n; i++) {
            tmp = v[i];
            j = i;
            seguir = true;
            while (j - incremento >= 0 && seguir) {
                if (tmp < v[j - incremento]) {
                    v[j] = v[j - incremento];
                    j = j - incremento;
                } else {
                    seguir = false;
                }
            }
            v[j] = tmp;
        }
    } while (incremento > 0);
}

bool ordenado(const int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            return false;
        }
    }
    return true;
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

void ascendente(int v[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        v[i] = i;
    }
}

void descendente(int v[], int n) {
    int aux = n - 1;
    int i;

    for (i = 0; i < n; i++) {
        v[i] = aux;
        aux--;
    }
}

double time_measurer(int v[], int n, void (*ord)(int [], int)) {
    double ta, tb;

    tb = microsegundos();
    (*ord)(v, n);
    ta = microsegundos();

    return ta - tb;
}

double generate_and_sort(int v[], int n, void (*ini)(int [], int), void (*ord)(int [], int)) {
    double tb, ta;
    int j;

    tb = microsegundos();
    for (j = 0; j < K; ++j) {
        (*ini)(v, n);
        (*ord)(v, n);
    }
    ta = microsegundos();

    return ta - tb;
}

double generate_vectors(int v[], int n, void (*ini)(int [], int)) {
    double tb, ta;
    int j;

    tb = microsegundos();
    for (j = 0; j < K; ++j) {
        (*ini)(v, n);
    }
    ta = microsegundos();

    return ta - tb;
}

double lower500(int v[], int n, void (*ini)(int [], int), void (*ord)(int [], int)) {
    double t1, t2;

    /* se calcula el tiempo para generar un vector
     * y ejecutar el algoritmo K (1000) veces: */
    t1 = generate_and_sort(v, n, *ini, *ord);

    /* se calcula el tiempo para
     * generar K (1000) vectores: */
    t2 = generate_vectors(v, n, *ini);

    return (t1 - t2) / K;   /* se devuelve el tiempo final */
}

void print_test(int v[], void (*ini)(int [], int), void (*ord)(int [], int), float cSup, float cAj, float cInf) {
    int n;
    double tf = 0;

    printf("\tn%14st(n)%4st(n)/n^%.2f", "", "", cSup);
    printf("%4st(n)/n^%.2f%5st(n)/n^%.2f\n", "", cAj, "", cInf);

    for (n = 500; n <= 512000 && tf < 500000; n *= 2) {
        (*ini)(v, n);

        tf = time_measurer(v, n, *ord);

        /* si el tiempo final es menor que 500, se
         * calcula K (1000) veces y se hace la media: */
        if (tf < 500) {
            tf = lower500(v, n, *ini, *ord);
            printf("%9d\t*%10.3f\t %9.6f\t %7.6f\t %7.6f\n", n, tf,
                   tf / pow(n, cSup), tf / pow(n, cAj), tf / pow(n, cInf));
        } else {
            printf("%9d\t%11.3f\t %9.6f\t %7.6f\t %7.6f\n", n, tf,
                   tf / pow(n, cSup), tf / pow(n, cAj), tf / pow(n, cInf));
        }
    }
}

void test(void (*ord)(int [], int)) {
    int v[17];

    printf("\nInicialización aleatoria:\n");
    aleatorio(v, 17);
    listar_vector(v, 17);
    (*ord)(v, 17);
    listar_vector(v, 17);

    printf("\nInicialización descendente:\n");
    descendente(v, 11);
    listar_vector(v, 11);
    (*ord)(v, 11);
    listar_vector(v, 11);

    printf("\nInicialización ascendente:\n");
    ascendente(v, 11);
    listar_vector(v, 11);
    (*ord)(v, 11);
    listar_vector(v, 11);
}

void timetest_seleccion() {
    int v[MAX_SIZE];
    int n = 500;

    /* ORDENACIÓN POR SELECCIÓN */

    /*  (a) el vector está ordenado en orden ascendente */
    printf("\nVector inicialmente en orden ascendente:\n");
    ascendente(v, n);
    printf("Ordenación por selección:\n");
    print_test(v, ascendente, ord_sel, (float) 1.7, (float) 2, (float) 2.2);

    /*  (b) el vector está ordenado en orden descendente */
    printf("\nVector inicialmente en orden descendente:\n");
    descendente(v, n);
    printf("Ordenación por selección:\n");
    print_test(v, descendente, ord_sel, (float) 1.8, 2, (float) 2.2);

    /*  (c) el vector está ordenado en orden aleatorio */
    printf("\nVector inicialmente en orden aleatorio:\n");
    aleatorio(v, n);
    printf("Ordenación por selección:\n");
    print_test(v, aleatorio, ord_sel, (float) 1.9, (float) 2, (float) 2.1);
}

void timetest_shell() {
    int v[MAX_SIZE];
    int n = 500;

    /* ORDENACIÓN POR SHELL */

    /*  (a) el vector está ordenado en orden ascendente */
    printf("\nVector inicialmente en orden ascendente:\n");
    ascendente(v, n);
    printf("Ordenación shell:\n");
    print_test(v, ascendente, ord_shell, (float) 1.05, (float) 1.12, (float) 1.3);

    /*  (b) el vector está ordenado en orden descendente */
    printf("\nVector inicialmente en orden descendente:\n");
    descendente(v, n);
    printf("Ordenación shell:\n");
    print_test(v, descendente, ord_shell, (float) 1, (float) 1.12, (float) 1.3);

    /*  (c) el vector está ordenado en orden aleatorio */
    printf("\nVector inicialmente en orden aleatorio:\n");
    aleatorio(v, n);
    printf("Ordenación shell:\n");
    print_test(v, aleatorio, ord_shell, (float) 1.05, (float) 1.2, (float) 1.4);
}

int main() {
    printf("ORDENACIÓN POR SELECCIÓN:\n");
    test(ord_sel);

    printf("\nORDENACIÓN SHELL:\n");
    test(ord_shell);

    timetest_seleccion();
    timetest_shell();

    return 0;
}