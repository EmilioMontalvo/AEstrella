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

    estado.estadoAleatorio();
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
/*//Pruebas Expansion Nodo
    Nodo n;
    n.expandirNodo();

    for(int i=0;i<n.fr;i++){
        n.hijos[i]->estado.printEstado();
    }

    n.hijos[0]->expandirNodo();

    for(int i=0;i<n.hijos[0]->fr;i++){
        n.hijos[0]->hijos[i]->estado.printEstado();
    }*/
/*
    //pruebas lista/*
    Nodo n1;
    Nodo n2;
    Nodo n3;

    Lista l;

    l.nuevoElemento(n1.autoApuntador());
    l.nuevoElemento(n1.autoApuntador());
    l.nuevoElemento(n1.autoApuntador());

    for(int i=0;i<l.nEl;i++){
        l.f[i]->estado.printEstado();
    }
    cout<<"---------"<<endl;

    l.extraer();

    for(int i=0;i<l.nEl;i++){
        l.f[i]->estado.printEstado();
    }
*/

    return 0;
}
