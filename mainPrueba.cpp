#include "ArbolB+/ArbolB+.hpp"
#include <iostream>
#include <string.h>

using namespace std;

int main(){

    ArbolBmas<int> arbol(3);
    arbol.insertarEnOrden(2);
    arbol.insertarEnOrden(1);

    return 0;
}