#include "ArbolB+/ArbolB+.hpp"
#include <iostream>
#include <string.h>

using namespace std;

int main(){

    ArbolBmas<int> arbol(5);
    arbol.insertarEnOrden(2);
    arbol.insertarEnOrden(1);
    
    for(int i = 4; i < 100; i++){
        arbol.insertarEnOrden(i);
    }

    arbol.imprimir();


    return 0;
}