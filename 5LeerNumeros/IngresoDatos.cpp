#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "Conversion.cpp"
#include "IngresoDatos.h"

using namespace std;

//Constructor
IngresoDatos::IngresoDatos(){
    this -> dato = new char[65]; //Creo un array para almacenar mis datos  
}   
//Destructor
IngresoDatos::~IngresoDatos(){
    delete [] dato; //Lo libero
} 

//Metodos privados

void IngresoDatos::imprimirMensaje(string str){
    cout<< str <<endl;
}

//Metodos publicos

//metodo pincipal
void IngresoDatos::leerDatos(string mensaje){
    imprimirMensaje(mensaje);
    char c;  //Creo un caracter, con el que voy a recibir el cada input
	int j = 0; //Iterador para la verifiacion del unico punto
	int i = 0; //Iterador para terminar el bucle, y asignar el valor final como nulo

    for(i; c != 13; i++){
        c=getch(); //Recibo el dato por teclado

        
    }

    dato[i]='\0';

}