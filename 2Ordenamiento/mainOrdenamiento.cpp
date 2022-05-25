#include <iostream>
using namespace std;

void ordenarAscendente (int* array, int n){
  for (int i = 0; i < n-1; i++) {
    int min = i;

    for (int j = i + 1; j < n; j++) {
      if (array[j] < array[min]) {
        min = j;
      }
    }
    if (min != i) {
      int temp = array[min];
      array[min] = array[i];
      array[i] = temp;
    }
  }
}

void invertir(int* array, int n){
    for(int i = 0; i < n/2; i++){
        int var = array[i];
        array[i] = array[n-i-1];
        array[n-i-1] = var;
    }
}

void ordenarDescendente(int* array, int n){
    ordenarAscendente(array, n);
    invertir(array, n);

}
int main(){

    int* array = new int[10];
    
    // Funcion relleno de 1 a i
    int cont = 10;
    for (int i=0; i < 10; i++){
        array[i] = cont;
        cont--;
    }

    for(int i = 0; i<10; i++){
        cout<< array[i] << " ";
    }  

    cout<< endl;

    ordenarAscendente(array, 10);

    for(int i = 0; i<10; i++){
        cout<< array[i] << " ";
    }  

    cout<< endl;

    ordenarDescendente(array,10);

    for(int i = 0; i<10; i++){
        cout<< array[i] << " ";
    }  

    delete[] array;

    return 0;
}
