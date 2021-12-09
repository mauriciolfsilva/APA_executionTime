#include <stdio.h>
#include "lib/myLib.h"
#define N_LENGTH 20 

int main(){
    int N = 0;
    
    double s_CPU_inicial, s_total_inicial, s_CPU_final, s_total_final;
    const char methods[4][50] = {"Bubble","Selection","Heap","Box"};

    for(int i = 0; i < 1; i++){
        N += N_LENGTH;
        int *randomArray = newArray(N);
        for(int id = 1; id <= 4; id++){
            int *sortedArray = callFunction(randomArray, id, N, &s_CPU_inicial, &s_total_inicial, &s_CPU_final, &s_total_final);
            // printf ("Tempo de CPU total = %f\n", s_CPU_final - s_CPU_inicial);
            if(sortedArray){
                printf("Metodo %s \n", methods[id-1]);
                printf("=========================||================\n");
                for(int j = 0; j < N; j++){
                    printf("%d \n", sortedArray[j]);
                }
            }
        }
    }
    return 0;
} 