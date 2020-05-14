#include <iostream>
using namespace std;

void insertion_Sort(int arreglo[], int n)  {  
    int key=0, i, j;  
    for (i = 1; i < n; i++){  
        key = arreglo[i];  
        j = i - 1;  
        
        while (j >= 0 && arreglo[j] > key){  
            arreglo[j + 1] = arreglo[j];  //si el elemnto que le sigue es mayor, intercambian.
            j = j - 1;  
        }  
        arreglo[j + 1] = key;  
    }  
}  

void mostrar(int arreglo[], int n){  
    for (int i = 0; i < n; i++)  
        cout << arreglo[i] << " ";  
    cout<<"\n"; 
}  

int main(){  
    int arreglo[] = {12, 11, 13, 5, 6, 8 };  
    int n = sizeof(arreglo) / sizeof(arreglo[0]);

    insertion_Sort(arreglo, n);  
    mostrar(arreglo, n);  
    return 0;  
}  