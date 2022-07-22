
//!FUNCION MENU. IMPLEMENTA MENU.H Y OPCIONMENU.H
//!EJEMPLO DE CREACION DE MENU

#define NOMINMAX 1

#include <iostream>
#include <limits>
#include "Menu.cpp"
#include "OpcionMenu.cpp"

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
   
    //!Creo objeto menu. Este manejara las opciones
    Menu menu("Listas - menu");
   
    menu.add_option(MenuOption("1", [&](MenuOptionArguments args) {
       
        do {

            //!Recibo datos de teclado. Me funciona para validar
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            break;
        } while (true);

    }));


    menu.add_option(MenuOption("2", [&](MenuOptionArguments args) {
        //!realizo una accion que no requiere input manual.
    }));


    //!Submenus
    menu.add_option(MenuOption("3", [&](MenuOptionArguments args) {
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
    menu.add_option(MenuOption("salir", [&](MenuOptionArguments args) {
        cout << "\nGracias por usar el programa!" <<endl;
        menu.stop();
    }, false));

    //!MOSTRAR MENU.
    menu.display(); 

    return 0; 
}

