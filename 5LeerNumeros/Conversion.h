#ifndef CONVERSION_H
#define CONVERSION_H

//Clase para verificar numero y realizar la conversion
class Conversion{
    private:
        bool numero;
        int flotante = 0;
        int numInt(char*);  //Convertir a entero
        float numFloat(char*); //Convertir a flotante 
    public:
        Conversion(); //Constructor
        ~Conversion(); //Destructor
        void verificar(char); //Metodo para verificar flotante o entero       
        void convertir(char*); //Metodo de ejecucion para convertir numeros
        bool getNumero();
        void setFlotante(int);
        int getFlotante();
};

#endif 