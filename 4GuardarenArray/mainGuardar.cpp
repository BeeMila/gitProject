#include <iostream>
using namespace std;

int main(){

    int size = 0;
    std::cout << "Escriba la longitud de su coso: " << std::endl;
    std::cin >> size;
    int* array = new int[size];
    std::cout << "Escriba los valores de su coso: " << std::endl;
    
    for(int i = 0; i<size; i++){
        std::cin >> array[i];
    }

    for(int i = 0; i<size; i++){
        cout<< array[i] << " ";
    } 

    delete[] array;
    return 0;
}