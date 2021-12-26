/**
 * TÍTUL0: ALGORITMOS
 * SUBTÍTUL0: Práctica 4
 * @author Mateo Díaz Allegue @login mateo.diaz
 * @author Álvaro Freire Ares @login alvaro.freirea
 * GRUPO: 4.2
 * DATE: 23 / 11 / 2021
 */

#include <math.h>
#include <stdlib.h>

#include "test.h"
#include "matrix.h"

#ifndef ALGO_P4_P4_H
#define ALGO_P4_P4_H

void prim(matriz m, int nodos, cola *aristas);

double cota(int n, double b);

double lower500(matriz m, int n);

double prim_measurer(matriz m, int n);

#endif //ALGO_P4_P4_H
