#include <iostream>
#include "NodoB+.hpp"
#include "CaminoB+.hpp"
using namespace std;
#pragma once
   
template <typename T>   
class ArbolBmas{
    private:
        int orden;
        int cantidadDatos{0};
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
            return new NodoBmas<T>(orden, esHoja);
        } 

        void getCamino(T dato, NodoBmas<T>* nodoActual, Camino<T> &camino){
            
            Resultado resultado(nodoActual->buscadorNodo(dato));
            camino.agregarNodo(nodoActual);

            int sigPos = (resultado.datoEncontrado() ? (resultado.getPosBusqueda() + (nodoActual->getEsHoja() ? 0 : 1)) : resultado.getPosInsercion());
            
            camino.agregarIndice(sigPos);

            if(nodoActual->getEsHoja()){

                if(resultado.datoEncontrado())
                    camino.marcarDatos();

            }else{
                getCamino(dato, nodoActual->getHijos()[sigPos], camino);
            }
        }

        void insertarEnHoja(T dato, NodoBmas<T> * nodo, Camino<T>& camino){

            if(!(alMaximo(nodo))){
                nodo->insertarOrdenado(dato);
                return;
            }

            // Hay overflow en el nodo actual
            // En el array temporal, copio todas las claves existentes más la que voy a ingresar

            NodoBmas<T>* nuevoHermano = this->crearNodo(true);
            nodo->setSiguiente(nuevoHermano);

            Vector<T>* buffer = crearBuffer(nodo->getDatos(), dato);

            int posMedia{buffer->longitud()/2};
            nodo->getDatos().setDatos(*(buffer->getSubVector(0,posMedia)));
            nuevoHermano->getDatos().setDatos(*(buffer->getSubVector(posMedia, buffer->longitud())));
            insertarEnPadre((*buffer)[posMedia], camino.siguienteNodo(), camino, nodo, nuevoHermano);

        }

        void insertarEnPadre(T dato, NodoBmas<T> * padre, Camino<T>& camino, NodoBmas<T>* hermanoIz, NodoBmas<T>* hermanoDer){

            if(padre == nullptr){ //overflow
                this->crearRaiz(dato, hermanoIz, hermanoDer);
                return;
            }

            if(!(alMaximo(padre))){
                padre->insertarOrdenado(dato, hermanoDer);
                return;
            }

            NodoBmas<T> *nuevoHermano = this->crearNodo(false);
            Vector<T>* buffer = crearBuffer(padre->getDatos(), dato);
            Resultado resultado(buffer->buscarOrdenado(dato));

            int posMedia{buffer->longitud()/2};
            T clavePadre{(*buffer)[posMedia]};
            padre->getDatos().setDatos(*(buffer->getSubVector(0,posMedia)));
            nuevoHermano->getDatos().setDatos(*(buffer->getSubVector(posMedia+1, buffer->longitud())));

            Vector<NodoBmas<T>*> &hijosPadre = padre->getHijos();   
            int posInsertar{resultado.getPosBusqueda()+1};
            
            Vector<NodoBmas<T>*> *parteIzquierda = hijosPadre.getSubVector(0,posInsertar);
            Vector<NodoBmas<T>*> *parteDerecha = hijosPadre.getSubVector(posInsertar, hijosPadre.longitud());

            Vector<NodoBmas<T>*> bufferHijos(hijosPadre.longitud()+1);
            bufferHijos.unirVectores(*parteIzquierda);
            bufferHijos.insertarFinal(hermanoDer);
            bufferHijos.unirVectores(*parteDerecha);

            //Reciclo variable
            posMedia = bufferHijos.longitud()/2 + (bufferHijos.longitud() % 2 == 0 ? 0 : 1);

            padre->getHijos().setDatos(*(bufferHijos.getSubVector(0,posMedia)));
            nuevoHermano->getHijos().setDatos(*(bufferHijos.getSubVector(posMedia, bufferHijos.longitud())));

            insertarEnPadre(clavePadre, camino.siguienteNodo(), camino, padre, nuevoHermano);

        }

        void crearRaiz(T dato, NodoBmas<T>* hermanoIz, NodoBmas<T>* hermanoDer){

            this->raiz = crearNodo(false);
            raiz->insertarOrdenado(dato);
            raiz->getHijos().insertarFinal(hermanoIz);
            raiz->getHijos().insertarFinal(hermanoDer);

        }

        void reemplazarRaiz(NodoBmas<T>* raiz){
            this->raiz = raiz;
        }

        Vector<T>* crearBuffer(Vector<T> &datos, T dato){
            Vector<T> *aux = new Vector<T>(datos.longitud()+1);
            aux->unirVectores(datos);
            aux->insertarOrdenado(dato);

            return aux;
        }

        void borrarEnHoja(T dato, NodoBmas<T>* actual, Camino<T> &camino){
            


        }

        bool borrarClave(T ingr, Camino<T> &camino){

            // Si la clave no existe, no hago nada
            if(!camino.getEncontreDato()){
                return false;
            }

            this.borrarEnHoja(ingr, camino.siguienteNodo(), camino);
			--this.numDatos;
			return true;

        }

        NodoBmas<T>* getHermano(NodoBmas<T>* padre, int posHijo){
            return padre->getHermanoIzq(posHijo);
        }


    public:
    
    /**
     * Crea un nuevo árbol B+ con el orden dado.
     * 
     * @param orden El orden del árbol.
     */
    ArbolBmas(int orden) : orden{orden}, raiz{crearNodo(true)}, primeraHoja{raiz}{}

    ~ArbolBmas(){}

    int getCantidadDatos(){
        return this->cantidadDatos;
    }

    
    bool insertarEnOrden(T ingresar){

        Camino<T> camino;
        this->getCamino(ingresar, raiz, camino);

        if(camino.getEncontreDato()){
            return false;
        }

        this->insertarEnHoja(ingresar, camino.siguienteNodo(), camino);
        cantidadDatos++;
        return true;

    }

    bool borrarClave(T ingr){
        Camino<T> camino;
        this->getCamino(ingresar, raiz, camino);
        
        // Si la clave no existe, no hago nada
        if(!camino.getEncontreDato()){
            return false;
        }

        this -> borrarEnHoja(ingr, camino.siguienteNodo(), camino);
        --(this -> cantidadDatos);
        return true;
    }

    void imprimir(){

        NodoBmas<T>* it = primeraHoja;

        while(it != nullptr){

            cout << " [ ";
            it->getDatos().imprimir();
            cout << " ] ";

            it = it->getSiguiente();
        }


    }    

};
