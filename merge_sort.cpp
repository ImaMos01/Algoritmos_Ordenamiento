#include <iostream>
using namespace std;

void merge(int arreglo[], int l, int m, int n){ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  n - m; 

    int L[n1], R[n2]; //creando nuevos arrays izquierda y derecha.

    for (i = 0; i < n1; i++) 
        L[i] = arreglo[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arreglo[m + 1+ j]; 

    i = 0;  
    j = 0;  
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arreglo[k] = L[i]; 
            i++; 
        } 
        else{ 
            arreglo[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < n1){ 
        arreglo[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2){ 
        arreglo[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void merge_sort(int arreglo[], int l, int n){ 
    if (l < n){ 
        int m = l+(n-l)/2;  
        merge_sort(arreglo, l, m); 
        merge_sort(arreglo, m+1, n); 
        merge(arreglo, l, m, n); 
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
    merge_sort(arreglo,0,n-1);  
    mostrar(arreglo, n);  

    return 0;
}