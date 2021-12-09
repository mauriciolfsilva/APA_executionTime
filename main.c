#include <stdio.h>
#include "lib/myLib.h"

int main(){
    int *myarray = newArray(5);
    for(int i = 0; i < 5; i++){
        printf("%d : %d \n", i, myarray[i]);
    }
    return 0;
} 