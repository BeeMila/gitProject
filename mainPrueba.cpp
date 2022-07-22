#include "ArbolB+/ArbolB+.hpp"
#include <iostream>
#include <string.h>

using namespace std;

int main(){

    ArbolBmas<int> arbol(6);
    arbol.insertarEnOrden(2);
    arbol.insertarEnOrden(1);
    
    for(int i = 4; i < 20; i++){
        arbol.insertarEnOrden(i);
    }


    arbol.borrarClave(10);
    arbol.borrarClave(100);

    arbol.imprimirNiveles();
    return 0;
}