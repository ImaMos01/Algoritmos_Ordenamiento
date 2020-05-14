#include <iostream>
using namespace std;

int getMax(int array[], int n) { //hallar el mayor número del arreglo
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

void countingSort(int array[], int size, int place) { //se usara en funccion segun el sistema de numeracion decimal
    const int max = 10;
    int output[size];
    int count[max];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;

    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

void radix_sort(int array[], int size) {
    int max = getMax(array, size);

    for (int place = 1; max / place > 0; place *= 10) //aplicar el counting sort segun el sistema de numeracion decimal 
        countingSort(array, size, place);
}


void mostrar(int arreglo[], int n){  
    for (int i = 0; i < n; i++)  
        cout << arreglo[i] << " ";  
    cout<<"\n"; 
}  

int main(){
    int arreglo[] = {42, 12, 100, 20, 8, 327};  
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    radix_sort(arreglo, n);  
    mostrar(arreglo, n);  

    return 0;
}