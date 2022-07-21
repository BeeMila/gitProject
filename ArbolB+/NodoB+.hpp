#include "Vector/Vector.hpp"
#include "ResultadoB+.hpp"

#include <iostream>
using namespace std;
#pragma once
   
template <typename T>     
class NodoBmas{
    private:

        Vector<T> datos;
        Vector<NodoBmas<T>*> hijos;
        bool esHoja;

    public:

        /**
         * Un constructor para la clase NodoBmas.
         * 
         * @param orden El orden del árbol B+.
         * @param esHoja Este es un valor booleano que nos dice si el nodo es un nodo hoja o no.
         */
        NodoBmas(int orden, bool esHoja) : datos(orden-1), hijos(orden), esHoja(esHoja){};

        ~NodoBmas(){}

        /**
         * Retorna el valor de esHoja.
         * 
         * @return un valor booleano.
         */
        bool getEsHoja(){
            return this->esHoja;
        }

        /**
         * Devuelve verdadero si el nodo no es un nodo hoja.
         * 
         * @return El valor devuelto es un valor booleano.
         */
        bool esIntermedio(){
            return !getEsHoja();
        }

        /**
         * Comprueba si la pila está vacía.
         * 
         * @return un valor booleano.
         */
        bool estaVacio(){
            return this->datos.estVacio();
        }

        /**
         * Devuelve el número de elementos de la lista.
         */
        int cantidadDatos(){
            this->datos.elementos();
        }

        /**
         * Devuelve el número de hijos del nodo.
         */
        int cantidadHijos(){
            this->hijos.elementos();
        }

        //Retorna una instancia de resultado, que almacena un indice 
        //util para poder encontrar el lugar en donde insertarlo
        Resultado buscadorNodo(T v){
            return Resultado(datos.buscarOrdenado(v))
        }

        Vector<T> &getDatos(){
            return this->datos;
        }

        Vector<NodoBmas<T>*> &getHijos(){
            return this->hijos;
        }

        int insertarOrdenado(T dato){
            Resultado resultado(this->buscadorNodo(dato));
            
            if(resultado.datoEncotrado()){
                throw std::out_of_range("Elemento repetido");
            }

            datos.insertar(dato, resultado.getPosInsercion());

            return resultado.getPosInsercion();
        }

};