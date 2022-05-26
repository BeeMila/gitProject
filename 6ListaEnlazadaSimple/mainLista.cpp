#include "Lista.cpp"

int main(){


    ListaEnlazada *l = new ListaEnlazada();
    l ->agregarFinal(5);
    l ->agregarFinal(10);
    l ->agregarFinal(15);
    l ->agregarFinal(20);
    l ->agregarFinal(25);


    l -> imprimirCabeza();

    return 0;
}