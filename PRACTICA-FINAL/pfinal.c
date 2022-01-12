/*
 * TÍTUL0: ALGORITMOS
 * SUBTÍTUL0: PRUEBA FINAL
 * AUTOR 2: Álvaro Freire Ares LOGIN 2: alvaro.freirea
 * GRUPO: 4.2
 * DATE: 12 / 01 / 2022
 */

#include "test.h"
#include "auxiliars.h"

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

int sumaSubMaxAux(int v[], int izq, int der) {
    int centro, sumDer, sumIzq, sumBordeDer, sumBordeIzq, sumAux, i, j;

    if (izq == der) {
        return v[izq] > 0 ? v[izq] : 0;
    } else {
        centro = (izq + der) / 2;
        sumDer = sumaSubMaxAux(v, centro + 1, der);
        sumIzq = sumaSubMaxAux(v, izq, centro);
        sumBordeDer = 0;
        sumAux = 0;

        for (i = centro + 1; i <= der; i++) {
            sumAux += v[i];

            if (sumAux > sumBordeDer) {
                sumBordeDer = sumAux;
            }
        }

        sumBordeIzq = 0;
        sumAux = 0;

        for (j = centro; j >= izq; j--) {
            sumAux += v[j];

            if (sumAux > sumBordeIzq) {
                sumBordeIzq = sumAux;
            }
        }

        return max(max(sumIzq, sumDer), sumBordeIzq + sumBordeDer);
    }
}

int sumaSubMax3(int v[], int n) {
    return sumaSubMaxAux(v, 0, n - 1);
}

int main() {
    int i;

    inicializar_semilla();
    test1();
    test2();

    /* bucle para imprimir varias tablas: */
    for (i = 0; i < 3; i++) {
        test3((void (*)(int *, int)) sumaSubMax3);
    }

    return 0;
}
