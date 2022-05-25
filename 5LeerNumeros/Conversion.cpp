#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "Conversion.h"

using namespace std;

//Constructor
Conversion::Conversion(){}
//Destructor
Conversion::~Conversion(){}

//Metodos privados
int Conversion::numInt(char* dato){
    return atoi(dato); //String a int

}

float Conversion::numFloat(char* dato){
    return std::stof(dato); //String a float
}

//Metodos publicos
void Conversion::verificar(char c){
    if (c == 46){ // 46 codigo ASCII del punto (.)
        this -> numero = true; //Asigno verdadero si es un flotante, pues tiene punto
    } else{
        this -> numero = false; //Asigno falso si es un entero. Pues no posee punto
    }
}

void Conversion::convertir(char* dato){
    if(this-> numero){
        cout << "\nSu numero es "<< numInt(dato) << " y es un entero" <<endl; //Imprimo entero
    }else{
        cout << "\nSu numero es "<< numFloat(dato) << " y es un flotante" <<endl; //Imprimo flotante
    }
}