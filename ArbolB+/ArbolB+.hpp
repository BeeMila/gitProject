#include <iostream>
#include "NodoB+.hpp"
#include "CaminoB+.hpp"
using namespace std;
#pragma once
   
template <typename T>   
class ArbolBmas{
    private:
        int orden;
        NodoBmas<T>* raiz;
        NodoBmas<T>* primeraHoja;

        /**
         * Devuelve el número mínimo de hijos que puede tener un nodo.
         * 
         * @return El número mínimo de hijos que puede tener un nodo.
         */
        int hijosMin(){
            return this->orden/2;
        }

        /**
         * Devuelve el número máximo de hijos que puede tener un nodo.
         * 
         * @return El número máximo de hijos que puede tener un nodo.
         */
        int hijosMax(){
            return this->orden;
        }

        /**
         * Devuelve el número mínimo de elementos de datos que se pueden almacenar en un nodo.
         * 
         * @return El número de hijos menos 1.
         */
        int datosMin(){
            return hijosMin()-1;
        }

       /**
        * Devuelve el número máximo de elementos de datos que se pueden almacenar en un nodo.
        * 
        * @return El número máximo de hijos que puede tener un nodo.
        */
        int datosMax(){
            return hijosMax()-1;
        }

        /**
         * Esta función devuelve la posición del valor de la mediana en la matriz
         * 
         * @return La posición del valor mediano.
         */
        int getPosMedia(){
            return datosMax()/2;
        }

        /**
         * Marca si un nodo se encuentra a su mínima capacidad
         * 
         * @param nodo el nodo a comprobar
         * 
         * @return su veracidad
         */
        bool alMinimo(NodoBmas<T>* nodo){
            return nodo->cantidadDatos() == datosMin();
        }

        /**
         * 
         * Marca si un nodo se encuentra a su máxima capacidad
         * 
         * @param nodo el nodo a comprobar
         * 
         * @return su veracidad
         */
        bool alMaximo(NodoBmas<T>* nodo){
            return nodo->cantidadDatos() == datosMax();
        }

        /**
         * Comprueba si el nodo tiene menos del número mínimo de datos.
         * 
         * @param nodo el nodo que se está comprobando
         * 
         * @return un valor booleano.
         */
        bool underflow(NodoBmas<T>* nodo){
            return nodo->cantidadDatos() < datosMin();
        }

        /**
         * Comprueba si el nodo tiene más del número máximo de datos.
         * 
         * @param nodo el nodo que se está comprobando para el desbordamiento
         * 
         * @return un valor booleano.
         */
        bool overflow(NodoBmas<T>* nodo){
            return nodo->cantidadDatos() > datosMax();
        }

       /**
        * Crea un nuevo nodo.
        * 
        * @param esHoja verdadero si el nodo es una hoja, falso en caso contrario
        * 
        * @return Un puntero a un objeto NodoBmas.
        */
        NodoBmas<T>* crearNodo(bool esHoja){
            return new NodoBmas(orden, esHoja);
        } 

        void getCamino(T dato, NodoBmas<T>* nodoActual, Camino<T> &camino){
            
            
        }

    public:
    
    /**
     * Crea un nuevo árbol B+ con el orden dado.
     * 
     * @param orden El orden del árbol.
     */
    ArbolBmas(int orden) : orden{orden}, raiz{crearNodo(true)}, primeraHoja{raiz}{}

    ~ArbolBmas(){}


};