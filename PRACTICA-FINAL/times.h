/*
 * TÍTUL0: ALGORITMOS
 * SUBTÍTUL0: PRUEBA FINAL
 * AUTOR 2: Álvaro Freire Ares LOGIN 2: alvaro.freirea
 * GRUPO: 4.2
 * DATE: 12 / 01 / 2022
 */

#ifndef ALGO_P1_TIMES_H
#define ALGO_P1_TIMES_H

#include <sys/time.h>

double microsegundos();

double time_measurer(int v[], int n, void (*alg)(int [], int));

double generate_and_sort(void (*algo)(int [], int), int v[], int n);

double generate(int v[], int n);

double lower500(void (*algo)(int [], int), int v[], int n);

#endif //ALGO_P1_TIMES_H
