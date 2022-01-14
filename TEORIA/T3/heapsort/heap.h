#ifndef HEAPSORT_HEAP_H
#define HEAPSORT_HEAP_H

#pragma once

#include <stdlib.h>
#include <stdbool.h>

#define MAX_TAM 100

typedef struct Monticulo {
    int tamano_monticulo;
    int vector_monticulo[MAX_TAM];
} Monticulo;

void Inicializar_Monticulo(Monticulo *m);

bool Monticulo_Vacio(Monticulo m);

void Flotar(Monticulo *m, int i);

void Insertar(int x, Monticulo *m);

int EliminarMax(Monticulo *m);

void Crear_Monticulo(const int vector_monticulo[MAX_TAM], int n, Monticulo *m);

#endif //HEAPSORT_HEAP_H
