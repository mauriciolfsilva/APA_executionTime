#include <stdio.h>

#ifndef MYLIB_H
#define MYLIB_H
    int * newArray(int n, int seed_offset);
    int * callFunction(int *array, int idFunction, int size, double *seg_CPU_total_inicial, double *seg_sistema_total_inicial, double *seg_CPU_total_final, double *seg_sistema_total_final);
    void writeArray(int * array, int array_length, FILE *file);
    void writeSummarize(const char*  method, int array_length, double tempo_cpu_total, FILE * file);
#endif