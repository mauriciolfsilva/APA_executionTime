#include <stdio.h>
#include "lib/myLib.h"
#define N_LENGTH 100 

int main(){
    int N = 0;
    
    double s_CPU_inicial, s_total_inicial, s_CPU_final, s_total_final;

    for(int i = 0; i < 5; i++){
        N += N_LENGTH;
        int *randomArray = newArray(N);
        for(int id = 1; id <= 4; id++){
            callFunction(randomArray, id, N, &s_CPU_inicial, &s_total_inicial, &s_CPU_final, &s_total_final);
            printf ("Tempo de CPU total = %f\n", s_CPU_final - s_CPU_inicial);
        }
    }
    return 0;
} 