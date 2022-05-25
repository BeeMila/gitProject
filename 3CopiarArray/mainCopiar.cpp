#include <iostream>
using namespace std;

int* copiar(int* array, int n){
    int* nuevo = new int[n];

    for(int i = 0; i< n; i++){
        nuevo[i] = array[i];
    }

    return nuevo;
}    

int main(){

    int* array = new int[10];

    int cont = 10;
    for (int i=0; i < 10; i++){
        array[i] = cont;
        cont--;
    }

    int * nuevo = copiar(array,10);

    for(int i = 0; i<10; i++){
        cout<< nuevo[i] << " ";
    } 

    if(array == nuevo){
        cout<< "a";
    }

    delete[] array;
    delete[] nuevo;
    return 0;
}