#include <stdio.h>
#include "lib/myLib.h"
#define N_LENGTH 10000 

int main(){
    int N = 0;
    
    double s_CPU_inicial, s_total_inicial, s_CPU_final, s_total_final;
    const char methods[4][50] = {"Bubble","Selection","Heap","Box"};

    for(int i = 0; i < 10; i++){
        N += N_LENGTH;
        int *randomArray = newArray(N);
        for(int id = 1; id <= 4; id++){
            int *sortedArray = callFunction(randomArray, id, N, &s_CPU_inicial, &s_total_inicial, &s_CPU_final, &s_total_final);
            printf("Metodo: %s \n Tamanho: %d \n", methods[id-1], N);
            printf ("Tempo de CPU total = %f\n", s_CPU_final - s_CPU_inicial);
            printf("=========================||================\n");
        }
    }
    return 0;
} 