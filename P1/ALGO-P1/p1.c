/*
 * TÍTUL0: ALGORITMOS
 * SUBTÍTUL0: Práctica 1
 * AUTOR 1: Mateo Díaz Allegue LOGIN 1: mateo.diaz
 * AUTOR 2: Álvaro Freire Ares LOGIN 2: alvaro.freirea
 * GRUPO: 4.2
 * DATE: 25 / 09 / 2021
 */

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdbool.h>

#define K 1000
#define NULL_INT -100

double microsegundos() {
    struct timeval t;

    /* obtiene la hora del sistema en microsegundos */
    if (gettimeofday(&t, NULL) < 0)
        return 0.0;
    return (t.tv_usec + t.tv_sec * 1000000.0);
}


int sumaSubMax1(int v[], int n) {
    int sumaMax = 0, estaSuma, i, j;

    for (i = 0; i < n; i++) {
        estaSuma = 0;
        for (j = i; j < n; j++) {
            estaSuma += v[j];
            if (estaSuma > sumaMax)
                sumaMax = estaSuma;
        }
    }
    return sumaMax;
}

int sumaSubMax2(int v[], int n) {
    int estaSuma = 0, sumaMax = 0, i;

    for (i = 0; i < n; i++) {
        estaSuma += v[i];
        if (estaSuma > sumaMax)
            sumaMax = estaSuma;
        else if (estaSuma < 0)
            estaSuma = 0;
    }
    return sumaMax;
}

void listar_vector(int v[], int n, int n1, int n2) {
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
        printf("%4s%2d%16s%2d\n", "", n1, "", n2);
}

void test1() {
    int v[6][5] = {{-9, 2,  -5, -4, 6},
                   {4,  0,  9,  2,  5},
                   {-2, -1, -9, -7, -1},
                   {9,  -2, 1,  -7, -8},
                   {15, -2, -5, -4, 16},
                   {7,  -5, 6,  7,  -7}};
    int i, r1, r2;

    printf("Secuencias%15sResultado1\tResultado2\n", "");

    for (i = 0; i <= 5; ++i) {
        /* se calculan los resultados de
         * cada algoritmo y se listan: */
        r1 = sumaSubMax1(v[i], 5);
        r2 = sumaSubMax2(v[i], 5);
        listar_vector(v[i], 5, r1, r2);
    }
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

void test2() {
    int i, a, b;
    int v[9];

    printf("\n%43s%s%4s%s\n", "", "sumaSubMax1", "", "sumaSubMax2");

    for (i = 0; i < 10; i++) {
        aleatorio(v, 9);
        listar_vector(v, 9, NULL_INT, NULL_INT);
        a = sumaSubMax1(v, 9);
        b = sumaSubMax2(v, 9);
        printf("%7s%5d%15d\n", "", a, b);
    }
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

void print_test3(int n, double tf, bool lt500, bool algo1) {
    /* se imprimen los datos por pantalla */

    if (algo1) {
        /* ALGORITMO 1: */
        if (lt500) {
            printf("%9d\t*%10.3f\t%9.6f\t%7.6f\t%7.6f\n",
                   n, tf, tf / pow(n, 1.8), tf / pow(n, 2), tf / pow(n, 2.2));
        } else {
            printf("%9d\t%11.3f\t%9.6f\t%7.6f\t%7.6f\n",
                   n, tf, tf / pow(n, 1.8), tf / pow(n, 2), tf / pow(n, 2.2));
        }
    } else {
        /* ALGORITMO 2: */
        if (lt500) {
            printf("%9d\t*%8.3f\t%9.6f\t%7.6f\t%7.6f\n",
                   n, tf, tf / pow(n, 0.8), tf / n, tf / pow(n, 1.2));
        } else {
            printf("%9d\t%11.3f\t%9.6f\t%7.6f\t%7.6f\n",
                   n, tf, tf / pow(n, 0.4), tf / pow(n, 0.6), tf / pow(n, 0.8));
        }
    }
}

void print_head(int algo) {
    if (algo == 1) {
        printf("\nAlgoritmo 1\n");
        printf("\tn%14st(n)%4st(n)/n^1.8", "", "");
        printf("%8st(n)/n²%6st(n)/n^2.2\n", "", "");
    } else {
        printf("\nAlgoritmo 2:\n");
        printf("\tn%12st(n)%6st(n)/n^0.4", "", "");
        printf("%5st(n)/n^0.6%6st(n)/n^0.8\n", "", "");
    }
}

void test3(void (*algo)(int [], int), int n_algo) {
    double tb, ta, tf;
    int v[32000];
    int n = 500, i;
    bool algo1 = n_algo == 1;

    print_head(n_algo);

    for (i = 0; i < 7; i++) {
        /* se genera vector */
        aleatorio(v, n);

        /* se miden tiempos */
        tb = microsegundos();
        (*algo)(v, n);
        ta = microsegundos();
        tf = ta - tb;

        /* si el tiempo final es menor que 500, se
         * calcula K (1000) veces y se hace la media: */
        if (tf < 500) {
            tf = lower500(algo, v, n);
            print_test3(n, tf, true, algo1);
        } else {
            print_test3(n, tf, false, algo1);
        }
        n *= 2;  // se incrementa n
    }
}

int main() {
    inicializar_semilla();
    test1();
    test2();
    test3((void (*)(int *, int)) sumaSubMax1, 1);
    test3((void (*)(int *, int)) sumaSubMax2, 2);

    return 0;
}
