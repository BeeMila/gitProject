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
char* IngresoDatos::leerDatos(string mensaje){
    imprimirMensaje(mensaje);
    char c;  //Creo un caracter, con el que voy a recibir el cada input
	int j = 0; //Iterador para la verifiacion del unico punto
	int i = 0; //Iterador para terminar el bucle, y asignar el valor final como nulo

    for(i; c != 13; i++){ //Bucle hasta que se presion la tecla ENTER
        c=getch(); //Recibo el dato por teclado

        if(c >= '0' && c <= '9' || c == 46){
            conversion.verificar(c); //Verifico por puntos ingresados
           
            unicoPunto( &j , &i, mensaje, &c); //Funcion de unico punto

        }else if(c == 8){ //Si el input es un back space

			backspace(&i, &j,  &c, mensaje); //Funcion para la tecla backspace
        }    			     
    }

    dato[i]='\0';
    return dato;
}

void IngresoDatos::unicoPunto(int* j, int* i, string mensaje, char* c){
    if(conversion.getNumero()){ //Si el numero es flotante
            conversion.setFlotante(1); //Seteo, pues si tiene un punto, es flotante
            if(*j==0){
                printf("%c", *c); //Imprimo el valor
                dato[*i] = *c;
                ++*j; //Hago que J deje de ser 0, pues no puede haber mas de un solo punto
            }else{ //!El usuario ingreso mas de un punto
        
                system("CLS");
                imprimirMensaje("Ha ingresado mas de un punto. Vuelva a intentarlo");
                imprimirMensaje(mensaje);
                for(int p = 0; p < *i; p++){
                    printf("%c", dato[p]);
                }
                --*i; //Para no avanzar en el contador e imprimir basura
            }
    }else{ //Si el dato no es un punto
            printf("%c", *c);
            dato[*i] = *c;
    }
}

void IngresoDatos::backspace(int* i, int* j, char* c, string mensaje){
    system("CLS"); //Limpio pantalla
    cout<< *i <<endl;
    imprimirMensaje(mensaje);
    for(int p = 0; p < *i-1; p++){
        printf("%c", dato[p]); //Imprimo de nuevo hasta el penultimo
    }

    if(*i != 0){ //Verifico que hay valores
        if(dato[*i-1] == 46){ //Verifico si hubo un punto, para reiniciarlo en la cuenta
            conversion.setFlotante(0);
            *j = 0;
        }
        dato[--*i]='\0'; //Borro valor
        --*i; //Disminuto iterador
    }
}

void IngresoDatos::funcionPrincipal(string mensaje){
    this -> conversion.convertir(leerDatos(mensaje));
}