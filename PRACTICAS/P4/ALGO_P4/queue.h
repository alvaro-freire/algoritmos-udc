/**
 * TÍTUL0: ALGORITMOS
 * SUBTÍTUL0: Práctica 4
 * @author Mateo Díaz Allegue @login mateo.diaz
 * @author Álvaro Freire Ares @login alvaro.freirea
 * GRUPO: 4.2
 * DATE: 23 / 11 / 2021
 */

#ifndef ALGO_P4_QUEUE_H
#define ALGO_P4_QUEUE_H

#include <stdio.h>
#include <limits.h>

#define TAM_MAX 1600

typedef int **matriz;
typedef struct {
    int x;
    int y;
    int peso;
} arista;

typedef arista tipo_elemento;
typedef struct {
    int cabeza;
    int final;
    int tamano;
    tipo_elemento vector[TAM_MAX];
} cola;

void crear_cola(cola *cola);

int cola_vacia(cola cola);

void insertar(tipo_elemento elemento, cola *cola);

tipo_elemento quitar_primero(cola *cola);

tipo_elemento primero(cola cola);

void incrementar(int *x);

void mostrar_cola(cola cola);

#endif //ALGO_P4_QUEUE_H
