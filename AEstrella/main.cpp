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
/*
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
    estado.printEstado();*/


    //cout<<estado.existeSolucion()<<endl;

    Nodo n;
    n.expandirNodo();

    for(int i=0;i<n.fr;i++){
        n.hijos[i]->estado.printEstado();
    }

    return 0;
}
