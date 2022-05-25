#ifndef CONVERSION_H
#define CONVERSION_H

//Clase para verificar numero y realizar la conversion
class Conversion{
    private:
        bool numero;
        int numInt(char*);  //Convertir a entero
        float numFloat(char*); //Convertir a flotante 
    public:
        Conversion(); //Constructor
        ~Conversion(); //Destructor
        void verificar(char c); //Metodo para verificar flotante o entero
        void convertir(char*); //Metodo de ejecucion para convertir numeros
};

#endif 