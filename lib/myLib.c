

void trocar(int *var1, int *var2)
{
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}


int[] bubble_sort(int [] array, int n) {
     int  i, j;
    for (i = 0; i < n-1; i++)    
     
    for (j = 0; j < n-i-1; j++)
        if (array[j] > array[j+1]){
            int temp = *array[j];
            *array[j] = *array[j+1];
            *array[j+1] = temp;
        }
}