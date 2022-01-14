/**
 * TÍTUL0: ALGORITMOS
 * SUBTÍTUL0: Práctica 4
 * @author Mateo Díaz Allegue @login mateo.diaz
 * @author Álvaro Freire Ares @login alvaro.freirea
 * GRUPO: 4.2
 * DATE: 23 / 11 / 2021
 */

#include <stdlib.h>
#include "queue.h"

void crear_cola(cola *cola) {
    cola->cabeza = 0;
    cola->final = -1;
    cola->tamano = 0;
}

int cola_vacia(cola cola) {
    return cola.tamano == 0;
}

void insertar(tipo_elemento elemento, cola *cola) {
    if (cola->tamano == TAM_MAX) {
        printf("error: cola llena: %d\n", cola->tamano);
        exit(EXIT_FAILURE);
    }

    cola->tamano++;
    incrementar(&(cola->final));
    cola->vector[cola->final] = elemento;
}

tipo_elemento quitar_primero(cola *cola) {
    tipo_elemento element;

    if (cola_vacia(*cola)) {
        printf("error: cola vacia\n");
        exit(EXIT_FAILURE);
    }

    cola->tamano--;
    element = cola->vector[cola->cabeza];
    incrementar(&(cola->cabeza));
    return element;
}

tipo_elemento primero(cola cola) {
    if (cola_vacia(cola)) {
        printf("error: cola vacia\n");
        exit(EXIT_FAILURE);
    }

    return (cola.vector[cola.cabeza]);
}

void incrementar(int *element) {
    if (++(*element) == TAM_MAX) {
        *element = 0;
    }
}

void mostrar_cola(cola cola) {
    int i, peso = 0;
    arista a;

    printf("\nRESULTADO:\n");

    if (cola_vacia(cola)) {
        printf("Cola vacía\n");
        return;
    }

    printf("Aristas:%s", " ");

    for (i = cola.cabeza; (i - 1) % TAM_MAX != cola.final; i = (i + 1) % TAM_MAX) {
        a = cola.vector[i];
        printf("(%d, %d) ", a.x, a.y);
        peso += a.peso;
    }

    printf("\nPeso:%4s%d\n", "", peso);
}