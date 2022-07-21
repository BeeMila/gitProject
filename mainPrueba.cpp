#include "Vector/Vector.hpp"
#include <iostream>
#include <string.h>

using namespace std;

int main(){

    Vector<string> maty(5);
    maty.insertarFinal("Holitas");
    maty.insertarFinal("mundo");
    maty.imprimir();

    return 0;
}