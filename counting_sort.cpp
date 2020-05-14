#include <iostream>
using namespace std;

void counting_sort(int array[], int size){
	int output[10];
	int count[10]; //para los numero de elementos
	int max = array[0];

  	for (int i = 1; i < size; i++){ //encuentra el mayor elemento del arreglo
		if (array[i] > max)
			max = array[i];
	}

	for (int i = 0; i <= max; ++i){ //crea un array con el tamaño del elemento mayor
		count[i] = 0;
	}

	for (int i = 0; i < size; i++){//aumenta en 1 segun el numero de apariciones
		count[array[i]]++;
	}

	for (int i = 1; i <= max; i++){ //hace una suma con el anterior elemento
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; i--) { //coloca los elemento ordenados al arreglo output
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (int i = 0; i < size; i++){//copia los elementos al arreglo original
		array[i] = output[i];
	}
}

void mostrar(int arreglo[], int n){  
    for (int i = 0; i < n; i++)  
        cout << arreglo[i] << " ";  
    cout<<"\n"; 
}  

int main(){
    int arreglo[] = {9, 2, 5, 4, 8, 3};  //por limitaciones de mi pc solo funciona con numeros menores a 25
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    counting_sort(arreglo, n);  
    mostrar(arreglo, n);  

    return 0;
}