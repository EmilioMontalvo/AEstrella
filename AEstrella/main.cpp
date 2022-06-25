#include <iostream>
#include "cabecera.h"

int main()
{
    /*
    cout << "Hello" << endl;
    cout<<"Prueba Chris"<<endl;
    cout<<"Prueba Stalin"<<endl;*/

    Estado estado;


    estado.printEstado();
    int val1 = estado.funcionDistanciaManhattan();

    cout<< endl;
    cout<< endl;
    estado.pasoSiguiente(4);
    estado.printEstado();
    estado.pasoSiguiente(4);
    estado.printEstado();
    estado.pasoSiguiente(2);
    estado.printEstado();
    estado.pasoSiguiente(3);
    estado.printEstado();
    estado.pasoSiguiente(4);
    estado.printEstado();
    estado.pasoSiguiente(3);
    estado.printEstado();
    estado.pasoSiguiente(1);
    estado.printEstado();
    estado.pasoSiguiente(4);
    estado.printEstado();
    estado.pasoSiguiente(4);
    estado.printEstado();
    estado.pasoSiguiente(2);
    estado.printEstado();
    estado.pasoSiguiente(3);
    estado.printEstado();
    estado.pasoSiguiente(3);
    estado.printEstado();


    cout<<estado.existeSolucion()<<endl;
    int val2 = estado.funcionDistanciaManhattan();

    cout<<"valor antes: "<<val1<<" || valor despues: "<<val2;
    return 0;
}
