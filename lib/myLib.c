

void trocar(int *var1, int *var2)
{
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}


void bubble_sort(int [] array, int n) {
     int  i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (array[j] > array[j+1]){
                trocar(array[j], array[j+1]);
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
      trocar(array[i], array[minimo]);
    }
  }
}


void heap_sort(int array[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);
 
    for (int i = n - 1; i > 0; i--) {
        trocar(array[0], array[i]);
 
        heapify(array, i, 0);
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
        maior = l;
 
 
    if (maior != i) {
        trocar(array[i], array[maior]);
 
        heapify(array, n, maior);
    }
}

