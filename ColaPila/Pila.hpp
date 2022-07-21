#pragma once
#include "Nodo.hpp"

using namespace std;
template <typename T>

class Pila{

private:
	Nodo<T>* primero= nullptr;
	Nodo<T>* ultimo= nullptr;
	int longitud{0};

public:

	/**
	 * Crea una nueva pila con una longitud de 0.
	 */
	Pila(){
	}

	~Pila(){
		primero->~Nodo();
		ultimo->~Nodo();
	}

	/**
	 * Comprueba si la lista está vacía.
	 * 
	 * @return un valor booleano.
	 */
	bool estaVacio(){
		return longitud == 0;
	}

	/**
	 * Crea un nuevo nodo y, si la lista está vacía, establece el nuevo nodo como el primer y último nodo.
	 * De lo contrario, establece el nuevo nodo como el último nodo.
	 * 
	 * @param v El valor que se insertará en la pila.
	 */
	void push(T v) {
    	Nodo<T> *nuevo = new Nodo<T>(v);

    	if (primero == nullptr) {
        	primero = ultimo = nuevo;
			
    	}else {    	
			nuevo->setNodo(ultimo);
			ultimo=nuevo;
		}

		longitud++;
	}

	/**
	 * Imprime la lista en orden inverso
	 */
	void mostrar(){

    	Nodo<T> * tmp=this->ultimo;
			while (tmp !=nullptr){
				cout << tmp->getValor()<<" ";
				tmp = tmp->getNodo();
    	}
	}	

	/**
	 * Si la pila está vacía, devuelve un valor vacío. Si la pila tiene un elemento, elimine el elemento y
	 * devuelva su valor. Si la pila tiene más de un elemento, elimine el último elemento y devuelva su
	 * valor
	 * 
	 * @return El valor del nodo que se está eliminando.
	 */
	T pop() {

		if(primero == nullptr){
			cout<<"\n Pila Vacia"<<endl;
			return {};
		}else if(primero == ultimo){
			Nodo<T>  *aux_borrar = ultimo->getNodo();
			T aux{aux_borrar->getValor()};
			primero = ultimo=nullptr;
			aux_borrar->~Nodo();
			longitud--;
			return aux;

		}else{
    		Nodo<T>  *aux_borrar=ultimo;
			T aux{aux_borrar->getValor()}; 
			ultimo=aux_borrar->getNodo();
			aux_borrar->~Nodo();
			longitud--;
			return aux;
        }

    }

	/**
	 * Devuelve el valor del último elemento de la pila.
	 * 
	 * @return El valor del último nodo en la pila.
	 */
	T peek(){

		if(primero == nullptr){
			cout<<"\n Pila Vacia"<<endl;
			return {};
		}else{

			T aux{ultimo->getNodo()->getValor()};
			return aux;

		}

	}

};	
	


