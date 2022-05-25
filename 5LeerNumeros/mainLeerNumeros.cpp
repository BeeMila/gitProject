#include <iostream>
using namespace std;

#include "IngresoDatos.cpp"

int main(){

    IngresoDatos *a = new IngresoDatos();
    a -> funcionPrincipal("Ingrese sus numeritos");
    a ->~IngresoDatos();

    return 0;
}