#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<time.h>

/*void Tempo_CPU_Sistema(double *seg_CPU_total, double *seg_sistema_total)
{
  long seg_CPU, seg_sistema, mseg_CPU, mseg_sistema;
  struct rusage ptempo;

  getrusage(0,&ptempo);

  seg_CPU = ptempo.ru_utime.tv_sec;
  mseg_CPU = ptempo.ru_utime.tv_usec;
  seg_sistema = ptempo.ru_stime.tv_sec;
  mseg_sistema = ptempo.ru_stime.tv_usec;

 *seg_CPU_total     = (seg_CPU + 0.000001 * mseg_CPU);
 *seg_sistema_total = (seg_sistema + 0.000001 * mseg_sistema);
}*/

int * newArray(int n) {
    static int* array; 
    array = malloc(sizeof(int) * n);

    srand(time(NULL));
    for(int i = 0; i < n; i++){
        array[i] = rand() % n;
    }
    return array;
}

int * callFunction(int *array, int idFunction, int size, double *seg_CPU_total_inicial, double *seg_sistema_total_inicial, double *seg_CPU_total_final, double *seg_sistema_total_final ){
    int *customArray = malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
        customArray[i] = array[i];
    }
    switch (idFunction)
    {
    case 1:
        /* bubblesort */
        return NULL;
        break;
    case 2:
        /* insertionsort */
        return NULL;
        break;
    case 3:
        /* heapsort */
        return NULL;
        break;
    case 4:
        /* boxsort */
        return NULL;
        break;
    
    default:
        return NULL;
        break;
    }
}