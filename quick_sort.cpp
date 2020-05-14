#include <iostream>
using namespace std;

int partition (int arreglo[], int bajo, int alto)  {  
    int c=0;
    int pivote = arreglo[alto]; // pivote 
    int i = (bajo - 1); //tome el indice menor  

    for (int j = bajo; j <= alto - 1; j++){  
        if (arreglo[j] < pivote){  //si es menor que el pivote
            i++; // incrementa el indice menor
            c=arreglo[i];
            arreglo[i]=arreglo[j];
            arreglo[j]=c;   
        }  
    }  
    c=arreglo[i+1];
    arreglo[i+1]=arreglo[alto];
    arreglo[alto]=c; 
    return (i + 1);  
}  

void quick_sort(int arreglo[], int bajo, int alto)  
{  
    if (bajo < alto){  

        int par = partition(arreglo, bajo, alto);  //pivote

        quick_sort(arreglo, bajo, par - 1); //izquierda
        quick_sort(arreglo, par + 1, alto);  //derecha
    }  
} 

void mostrar(int arreglo[], int n){  
    for (int i = 0; i < n; i++)  
        cout << arreglo[i] << " ";  
    cout<<"\n"; 
}  

int main(){
    int arreglo[] = {42, 12, 0, 2, 8, 7 };  
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    quick_sort(arreglo,0, n-1);  
    mostrar(arreglo, n);  

    return 0;
}