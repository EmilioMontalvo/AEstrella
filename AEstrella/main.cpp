#include <iostream>
#include "cabecera.h"

int main()
{
    cout << "Hello" << endl;
    cout<<"Prueba Chris"<<endl;
    cout<<"Prueba Stalin"<<endl;

    Estado estado;
    estado.printEstado();
    estado.pasoSiguiente(1);
    return 0;
}
