#ifndef CABECERA_H_INCLUDED
#define CABECERA_H_INCLUDED
#include <iostream>

using namespace std;
class Estado {
public:
    int e[3];

    Estado() { //Constructor
        //for(int i=0; i<3; i++) {/
        e[0]=3; //canivales izq
        e[1]=3; //misioneros izq
        e[2]=1; //lado 1=izq 0=derecho
        //}/

    };



    Estado(int c,int m,int b) { //Constructor
        //for(int i=0; i<3; i++) {/
        e[0]=c; //canivales izq
        e[1]=m; //misioneros izq
        e[2]=b; //lado 1=izq 0=derecho
        //}/

    };

    Estado* autoApuntador() {
        return this;
    };


    //funciones miembro
    void printEstado() {
        //cout << "Hello world!" << endl;
        cout <<"-------------------------------------------------"<< endl;
        for(int i=0; i<3; i++) {
            int x=e[i];
            cout << x << "\t";

        }
        cout << "\t";
        for(int i=0; i<3; i++) {

            if(i!=2)
                cout << 3-e[i] << "\t";
            else
                cout << 1-e[i] << "\t";

        }
        cout<<endl;
        cout <<"-------------------------------------------------"<< endl;
    };



    bool sucesor(int accion) {

        switch(accion) {
        case 1:
            //cc
            cruzar(2,0);
            break;
        case 2:
            //mm
            cruzar(0,2);
            break;
        case 3:
            //cm
            cruzar(1,1);
            break;
        case 4:
            //c
            cruzar(1,0);
            break;
        case 5:
            //m
            cruzar(0,1);
            break;

        }

        return(e[0]<=e[1]||e[1]==0)&&(3-e[0]<=3-e[1]||3-e[1]==0)&&(e[0]>=0)&&(e[0]<=3)&&(e[1]>=0)&&(e[1]<=3);

        //return (e[0]<=e[1] || e[1]==0) && (3-e[0]<=3-e[1] || 3-e[1]==0)

    }

    //(e[0]<=e[1]||e[1]==0&&3-e[0]<=3-e[1]||3-e[0]==0)&&(e[0]>=0)&&(e[0]<=3)&&(e[1]>=0)&&(e[1]<=3)
    void cruzar(int c,int m) {

        //cout << c << " " << m << endl;
        if(e[2]==1) {
            e[2]=0;
            e[0]=e[0]-c;
            e[1]=e[1]-m;
        } else {
            e[2]=1;
            e[0]=e[0]+c;
            e[1]=e[1]+m;
        }


    }

    Estado getEstado() {

        return *this;
    }

    bool testObjetivo(){

        return(e[0]==0 && e[1]==0 && e[2]==0);

    }

};


class Nodo {
public:

    Estado estado;
    Nodo *padre;
    Nodo **hijos;
    int fr;//factor de ramificacion
    int n;//profundidad



    Nodo() {
        //estado=Estado();
        padre=NULL;
        hijos=NULL;
        fr=0;
        n=0;


    };

    Nodo(Estado es) {
        estado=es;
        padre=NULL;
        hijos=NULL;
        fr=0;
        n=0;

    };

    Nodo* autoApuntador() {
        return this;
    };

    Nodo(Nodo *pa,Estado *es) {

        padre=pa;
        estado=es->getEstado();


    };

    void imprimirPadres(){

        Nodo *padres[n+1];
        Nodo *p=NULL;
        p=padre->autoApuntador();


        for(int i=0;i<n;i++){
            padres[i]=p;
            //p->estado.printEstado();
            p=p->padre;
        }


        for(int i=n-1;i>=0;i--){
            padres[i]->estado.printEstado();
        }



    }

    void expandirNodo() {//funcion succesor


        int nh=0;
        Estado **mes;
        mes=new Estado*[5];

        for(int i=1; i<=5; i++) {

            Estado *es =(new Estado(estado.e[0],estado.e[1],estado.e[2]));


            if(es->sucesor(i)) {
                mes[nh]=es;
                nh++;
                //es->printEstado();

            }

            es=nullptr;
        }


        fr=nh;

        hijos=new Nodo*[fr];

        if(nh==0) {
            return;
        }

        for(int i=0; i<fr; i++) {
            hijos[i]=new Nodo();
            hijos[i]->padre=this;
            hijos[i]->n=n+1;
            hijos[i]->estado=mes[i]->getEstado();

        }

    };



};


class Frontera {
public:
    Nodo **f;
    int nEf;

    Frontera() {
        f=NULL;
        nEf=0;

    }

    ~Frontera() {
        for(int C=0; C<nEf; C++) {
            f[C]=NULL;
        }
        delete[] f;
        f=NULL;
        nEf=0;


    };

    void nuevoElemento(Nodo *n) {
        Nodo **aux;
        aux=new Nodo*[nEf+1];
        for(int i=0; i<nEf; i++) {
            aux[i]=f[i];
            f[i]=NULL;
        }
        aux[nEf]=n;

        if(nEf>0)
            delete[] f;

        f=NULL;
        f=aux;
        nEf++;

    };

    bool eliminarElemento(Nodo *n) {

        bool resultado=false;
        Nodo **aux;
        aux=new Nodo*[nEf-1];
        int pos =-1;

        for(int i=0; i<nEf; i++) {
            if(n==f[i]) {
                pos=i;
                resultado=true;
                break;
            }
        }

        if(pos!=-1) {
            for(int i=0; i<pos; i++) {
                aux[i]=f[i];
                f[i]==NULL;
            }
            for(int i=pos; i<nEf-1; i++) {
                aux[i]=f[i+1];
                f[i+1]=NULL;
            }

            delete[]f;
            f=NULL;
            f=aux;
            nEf--;
        } else {

            for(int i=0; i<nEf-1; i++) {
                aux[i]==NULL;

            }
            delete[] aux;
            aux=NULL;

        }

        return resultado;


    };

    Nodo* pop(){

        if(f==NULL){
            return NULL;
        }

        Nodo *aux=NULL;
        aux=f[nEf-1];
        eliminarElemento(f[nEf-1]);

        return aux;

    };

    bool pertenece(Nodo *n){

        for(int i=0;i<nEf;i++){
            if(n==f[i]){/////////////////
                return true;
            }
        }
        return false;


    }




};


class Explorados {
public:
    Estado **exp;
    int nEE;

    Explorados() {
        exp=NULL;
        nEE=0;

    }

    ~Explorados() {
        for(int C=0; C<nEE; C++) {
            exp[C]=NULL;
        }
        delete[] exp;
        exp=NULL;
        nEE=0;


    };

    void nuevoElemento(Estado *n) {
        Estado **aux;
        aux=new Estado*[nEE+1];
        for(int i=0; i<nEE; i++) {
            aux[i]=exp[i];
            exp[i]=NULL;
        }
        aux[nEE]=n;

        if(nEE>0)
            delete[] exp;

        exp=NULL;
        exp=aux;
        nEE++;

    };

    bool eliminarElemento(Estado *n) {

        bool resultado=false;
        Estado **aux;
        aux=new Estado*[nEE-1];
        int pos =-1;

         for(int i=0; i<nEE; i++) {
            if(n==exp[i]) {
                pos=i;
                resultado=true;
                break;
            }
        }

         if(pos!=-1) {
             for(int i=0; i<pos; i++) {
                aux[i]=exp[i];
                exp[i]==NULL;
            }
             for(int i=pos; i<nEE-1; i++) {
                aux[i]=exp[i+1];
                exp[i+1]=NULL;
            }

            delete[]exp;
            exp=NULL;
            exp=aux;
            nEE--;
        } else {

             for(int i=0; i<nEE-1; i++) {
                aux[i]==NULL;

            }
            delete[] aux;
            aux=NULL;

        }

        return resultado;


    };

    Estado* pop(){

        if(exp==NULL){
            return NULL;
        }

        Estado *aux=NULL;
        aux=exp[nEE-1];
        eliminarElemento(exp[nEE-1]);

        return aux;

    };

    bool pertenece(Estado *es){

        for(int i=0;i<nEE;i++){
            if(es->e[0]==exp[i]->e[0] && es->e[1]==exp[i]->e[1] && es->e[2]==exp[i]->e[2]){
                return true;
            }
        }
        return false;


    }




};








#endif // CABECERA_H_INCLUDED
