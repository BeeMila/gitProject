#define NOMINMAX 1

#include <iostream>
#include <limits>
#include "Menu/Menu.cpp"
#include "Menu/OpcionMenu.cpp"
#include "IngresoDatos/Conversion.h"
#include "IngresoDatos/IngresoDatos.h"
#include "ArbolB+/ArbolB+.hpp"

#include <iostream>

using namespace std;

int ingresoD(){

	IngresoDatos *i = new IngresoDatos();
	cout << "\n";
	int num = i->funcionPrincipalEnteros("Ingrese el numero: ");

	return num;
}

void ingresarInternos(ArbolBmas<int> &arbol){

	cout<<"\n";
	
	for (int i = 0; i < 10; i++){

		int num{ingresoD()};

		if(num == -10101010){
			i = 10;
		}else{
			arbol.insertarEnOrden(num);
            cout << " ~~~ Valor insertado ~~" <<endl;
		}
	}

	cout<<"\n";
}

int main(int argc, char **argv) {
    
    
    Menu menu("\n \t Arbol B+ \t \n");
    ArbolBmas<int> arbol(4);

    menu.add_option(MenuOption("\t ~~ 1. Agregar datos", [&](MenuOptionArguments args) {
       
        ingresarInternos(arbol);
        system("pause");

    }));


    menu.add_option(MenuOption("\t ~~ 2. Eliminar", [&](MenuOptionArguments args) {
        
        int numEliminar{ingresoD()};
        if (arbol.borrarClave(numEliminar)){
            cout << "\n ~~ El dato fue borrado ~~ " <<endl;
        }else{
            cout << " ~~\n El dato no fue encontrado ~~ " <<endl;
        }
        system("pause");

    }));

    menu.add_option(MenuOption("\t ~~ 3. Verificar la existencia de un dato en el arbol", [&](MenuOptionArguments args) {
        
        int numBuscar{ingresoD()};
        if(arbol.buscar(numBuscar)){
            cout << "\n ~~ El dato si se encuentra en el arbol ~~ " <<endl;
        }else{
            cout << "\n ~~ El dato no se encuentro en el arbol ~~ " <<endl;
        }

    }));


    menu.add_option(MenuOption("\t ~~ 4. Imprimir", [&](MenuOptionArguments args) {
        
        system("CLS");
        Menu menuInterno("Submenu");

        
        menuInterno.add_option(MenuOption("\t ~~ 1. Mostrar nodos", [&](MenuOptionArguments args) {
            arbol.imprimir();
            system("pause");
        }));
        
        menuInterno.add_option(MenuOption("\t ~~ 2. Mostrar por niveles", [&](MenuOptionArguments args) {
            arbol.imprimirNiveles();
            system("pause");
        }));

        menuInterno.add_option(MenuOption("\n \t ~~ 3. Regresar a menu principal", [&](MenuOptionArguments args) {
            menuInterno.stop();
        }, false));

        menuInterno.display();

    }));

    //!Submenus
    menu.add_option(MenuOption("\t ~~ 4. Encriptar", [&](MenuOptionArguments args) {
        system("CLS");
        Menu menuInterno("Submenu");

        
        menuInterno.add_option(MenuOption("1...", [&](MenuOptionArguments args) {
        }));
        

        menuInterno.add_option(MenuOption("\nRegresar a menu principal", [&](MenuOptionArguments args) {
            menuInterno.stop();
        }, false));

        menuInterno.display();
    }));

    //!Funcion salida del menu
    menu.add_option(MenuOption("\t ~~ 5. Salir", [&](MenuOptionArguments args) {
        cout << "\nGracias por usar el programa!" <<endl;
        menu.stop();
    }, false));

    //!MOSTRAR MENU.
    menu.display(); 

    return 0; 
}

