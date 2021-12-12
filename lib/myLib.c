#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <time.h>

void Tempo_CPU_Sistema(double *seg_CPU_total, double *seg_sistema_total)
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
}


void trocar(int *var1, int *var2)
{
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}


void bubble_sort(int array[], int n) {
     int  i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (array[j] > array[j+1]){
                trocar(&array[j], &array[j+1]);
            }
        }
    }    
}

void selection_sort (int array[],int n) {
  int i, j, minino, auxiliar;
  
  for (i = 0; i < (n - 1); i++) {
    minino = i;
    for (j = i+1; j < n; j++) {
      if (array[j] < array[minino]) {
        minino = j;
      }
    }
    if (i != minino) {
      trocar(&array[i], &array[minino]);
    }
  }
}



void heapify(int array[], int n, int i)
{
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
    int maior = i;

    if (direita < n && array[direita] > array[maior])
        maior = direita;
 
    if (esquerda < n && array[esquerda] > array[maior])
        maior = esquerda;
 
 
    if (maior != i) {
        trocar(&array[i], &array[maior]);
 
        heapify(array, n, maior);
    }
}
void heap_sort(int array[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);
 
    for (int i = n - 1; i > 0; i--) {
        trocar(&array[0], &array[i]);
 
        heapify(array, i, 0);
    }
}

void box_sort(int array[], int n) {
    int *box = malloc(sizeof(int) * n);
    int pos = 0;
    for(int i = 0; i < n; i++){
        box[array[i]] += 1;
    }
    for(int i = 0; i < n; i++){
        while(box[i] > 0){
            box[i] -= 1;
            array[pos] = i;
            pos += 1;
        }
    }
    free(box);
}


int * newArray(int n, int seed_offset) {
    static int* array; 
    array = malloc(sizeof(int) * n);

    srand(time(NULL) + seed_offset);
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
        Tempo_CPU_Sistema(seg_CPU_total_inicial, seg_sistema_total_inicial);
        bubble_sort(customArray, size);
        Tempo_CPU_Sistema(seg_CPU_total_final, seg_sistema_total_final);
        return customArray;
        break;
    case 2:
        Tempo_CPU_Sistema(seg_CPU_total_inicial, seg_sistema_total_inicial);
        selection_sort(customArray, size);
        Tempo_CPU_Sistema(seg_CPU_total_final, seg_sistema_total_final);
        return customArray;
        break;
    case 3:
        Tempo_CPU_Sistema(seg_CPU_total_inicial, seg_sistema_total_inicial);
        heap_sort(customArray, size);
        Tempo_CPU_Sistema(seg_CPU_total_final, seg_sistema_total_final);
        return customArray;
        break;
    case 4:
        Tempo_CPU_Sistema(seg_CPU_total_inicial, seg_sistema_total_inicial);
        box_sort(customArray, size);
        Tempo_CPU_Sistema(seg_CPU_total_final, seg_sistema_total_final);
        return customArray;
        break;
    
    default:
        return NULL;
        break;
    }
}



void writeArray(int * array, int array_length, FILE * file) {
   if(file == NULL)
   {
      printf("Error, could not create file!");   
      exit(1);             
   }

    fprintf(file,"%d|",array_length);

    int i = 0;
   for(i = 0; i < array_length - 1; i++){
        fprintf(file,"%d;",array[i]);
   }
   fprintf(file,"%d",array[i]);
   fprintf(file,"\n");

   //array_length|array[0];array[1;array[2]
}

void writeSummarize(const char * method, int array_length, double  tempo_cpu_total, FILE * file) {
   if(file == NULL)
   {
      printf("Error, could not create file!");   
      exit(1);             
   }

    fprintf(file,"%s;%d;%f",method, array_length, tempo_cpu_total);
   fprintf(file,"\n");

   //array_length|array[0];array[1;array[2]
}
