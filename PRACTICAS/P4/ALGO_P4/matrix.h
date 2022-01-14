#ifndef ALGO_P4_MATRIX_H
#define ALGO_P4_MATRIX_H

#include "queue.h"
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

matriz crear_matriz(int n);

void inicializar_matriz(matriz m, int n);

void liberar_matriz(matriz m, int n);

void inicializar_semilla();

double microsegundos();

#endif //ALGO_P4_MATRIX_H
