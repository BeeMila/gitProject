#ifndef INGRESODATOS_H
#define INGRESODATOS_H
#include <string>
using namespace std;
#include "Conversion.h"

class IngresoDatos{
    private:
        char* dato; //Arreglo donde guardare la insercion de mis numeros
        Conversion conversion; //Instancia de conversion para determinar y transformar enteros y flotantes
        void imprimirMensaje(string);

    public:
        IngresoDatos();   //Constructor
        ~IngresoDatos();       //Destructor

        //metodo pincipal
        void leerDatos(string);

        //Sub metodos
        char *agregoChars(char *dato);
        bool unicoPunto(char c);

        //Metodos de retorno
        int devolverInt(char *dato);
        float devolverFloat(char *dato);
};

#endif  