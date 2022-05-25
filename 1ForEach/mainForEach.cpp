#include <iostream>
using namespace std;

int main(){

    int* array = new int[10];
    
    // Funcion relleno de 1 a i
    for (int i=0; i < 10; i++){
        array[i] = i+1;
    }

    //Funcion imprimir
    for(int i = 0; i<10; i++){
        cout<< array[i] << " ";
    }    
    return 0;
}