#include <iostream>
using namespace std;

void selection_sort(int arreglo[], int n){
    int minimo=0, c=0;  

    for (int i = 0; i < n-1; i++){  
        minimo = i;  
        for (int j = i+1; j < n; j++)  //recorre para encontrar el menor elemento
            if (arreglo[j] < arreglo[minimo])  
                minimo = j;  

        c=arreglo[minimo];
        arreglo[minimo]=arreglo[i];
        arreglo[i]=c;   
    }  
}

void mostrar(int arreglo[], int n){  
    for (int i = 0; i < n; i++)  
        cout << arreglo[i] << " ";  
    cout<<"\n"; 
}  

int main(){
    int arreglo[]= {2,5,7,8,4,1,0};
    int n = sizeof(arreglo)/sizeof(arreglo[0]);  
    selection_sort(arreglo, n);   
    mostrar(arreglo, n);
    return 0;
}