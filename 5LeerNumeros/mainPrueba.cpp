#include <iostream>
using namespace std;

int main(){

    char *cad = new char[10];

    for(int i = 0; i < 10; i++){
        cad[i] = i+1;
    }

    cad[3] = 46;

    for(int i = 0; i < 10; i++){
        cout << cad[i] << "";
    }
    return 0;
}