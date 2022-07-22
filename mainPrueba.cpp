#include "ArbolB+/ArbolB+.hpp"
#include <iostream>
#include <string.h>

using namespace std;

int main(){

    ArbolBmas<int> arbol(5);
    arbol.insertarEnOrden(2);
    arbol.insertarEnOrden(1);
    
    for(int i = 4; i < 40; i++){
        arbol.insertarEnOrden(i);
    }

    arbol.imprimir();
    arbol.borrarClave(10);
    arbol.borrarClave(100);
    arbol.imprimirNiveles();


    return 0;
}