#ifndef CABECERA_H_INCLUDED
#define CABECERA_H_INCLUDED
#include <iostream>

using namespace std;
class Estado {
public:
    //Matriz que se usara para representar los estados del 8 puzle
    int e[3][3];
    int costo;

    Estado() { //Constructor inicializa el puzzle en el orden que deberia estar
        //el costo se inicializa en cero
        costo =0;
        //Fila Superior
        e[0][0]=0;
        e[0][1]=1;
        e[0][2]=2;

        //Fila Intermedia
        e[1][0]=3;
        e[1][1]=4;
        e[1][2]=5;

        //Fila Inferior
        e[2][0]=6;
        e[2][1]=7;
        e[2][2]=8;
    };
    Estado* autoApuntador() {
        return this;
    };

    //FUNCIONES
    //Imprimir estado
    void printEstado() {
    int filas = (sizeof(e)/sizeof(e[0]));
    int columnas = (sizeof(e[0])/sizeof(e[0][0]));
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout<< "[" <<e[i][j]<<"] ";
        }

    cout<<endl;
    }
    cout<<"Costo actual= "<< costo<<endl;
    };
    //METODO PASO SIGUIENTE
    bool pasoSiguiente(int accion) {
    //variable que almacena la posicion f = fila c= columna
    int f,c;

    //primero determinamos la posición en la que se encuentra el espacio vacio
    int filas = (sizeof(e)/sizeof(e[0]));
    int columnas = (sizeof(e[0])/sizeof(e[0][0]));
        for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            if(e[i][j]==0){
                f=i;
                c=j;
            }
        }
    }
    cout<<"posicion actual vacia ----> "<<f<<" "<<c<<"\n"<<endl;
        switch(accion) {
        case 1://ARRIBA
            if((f==0 && c==0)||(f==0 && c==1)||(f==0 && c==2)){
            cout<< "No se puede realizar accion"<< endl;
            return false;
            break;
            }if(f==1 && c==0){
                pasar(f,c,0,0);
                costo++;
                break;
            }if(f==1 && c==1){
                pasar(f,c,0,1);
                costo++;
                break;
            }if(f==1 && c==2){
                pasar(f,c,0,2);
                costo++;
                break;
            }if(f==2 && c==0){
                pasar(f,c,1,0);
                costo++;
                break;
            }if(f==2 && c==1){
                pasar(f,c,1,1);
                costo++;
                break;
            }if(f==2 && c==2){
                pasar(f,c,1,2);
                costo++;
                break;
            }
            break;
        case 2: //ABAJO
            if((f==2 && c==0)||(f==2 && c==1)||(f==2 && c==2)){
            cout<< "No se puede realizar accion" << endl;
            return false;
            break;
            }if(f==1 && c==0){
                pasar(f,c,2,0);
                costo++;
                break;
            }if(f==1 && c==1){
                pasar(f,c,2,1);
                costo++;
                break;
            }if(f==1 && c==2){
                pasar(f,c,2,2);
                costo++;
                break;
            }if(f==0 && c==0){
                pasar(f,c,1,0);
                costo++;
                break;
            }if(f==0 && c==1){
                pasar(f,c,1,1);
                costo++;
                break;
            }if(f==0 && c==2){
                pasar(f,c,1,2);
                costo++;
                break;
            }
            break;
        case 3: //IZQUIERDA
            if((f==0 && c==0)||(f==1 && c==0)||(f==2 && c==0)){
            cout<< "No se puede realizar accion"<< endl;
            return false;
            break;
            }if(f==0 && c==1){
                pasar(f,c,0,0);
                costo++;
                break;
            }if(f==1 && c==1){
                pasar(f,c,1,0);
                costo++;
                break;
            }if(f==2 && c==1){
                pasar(f,c,2,0);
                costo++;
                break;
            }if(f==0 && c==2){
                pasar(f,c,0,1);
                costo++;
                break;
            }if(f==1 && c==2){
                pasar(f,c,1,1);
                costo++;
                break;
            }if(f==2 && c==2){
                pasar(f,c,2,1);
                costo++;
                break;
            }
            break;
        case 4: //derecha
            if((f==0 && c==2)||(f==1 && c==2)||(f==2 && c==2)){
            cout<< "No se puede realizar accion"<< endl;
            return false;
            break;
            }if(f==0 && c==1){
                pasar(f,c,0,2);
                costo++;
                break;
            }if(f==1 && c==1){
                pasar(f,c,1,2);
                costo++;
                break;
            }if(f==2 && c==1){
                pasar(f,c,2,2);
                costo++;
                break;
            }if(f==0 && c==0){
                pasar(f,c,0,1);
                costo++;
                break;
            }if(f==1 && c==0){
                pasar(f,c,1,1);
                costo++;
                break;
            }if(f==2 && c==0){
                pasar(f,c,2,1);
                costo++;
                break;
            }
            break;
        }
        return true;
    }
    //FUNCION PASAR (INTERCAMNBIO)
    void pasar(int f,int c,int nf,int nc) {
        //f y c = fila y columna actual   && nf y nc = siguiente fila y columna a realizar el cambio.
        cout<<"pasa ----> "<<f<<" "<<c<<"\n"<<"pasa ----> "<<nf<<" "<<nc<<"\n"<<endl;
        int aux;
        aux= e[nf][nc];
        e[nf][nc]=e[f][c];
        e[f][c]=aux;
    }
    Estado getEstado() {
        return *this;
    }
    bool testObjetivo(){
        return(e[0][0]==0 && e[1][0]==1 && e[1][0]==2  && e[1][0]==3 && e[1][0]==4 && e[1][0]==5 && e[1][0]==6 && e[1][0]==7 && e[1][0]==8);
    }
};

/*
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


            if(es->pasoSiguiente(i)) {
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
        }  {

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
        }  {

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
*/





#endif // CABECERA_H_INCLUDED
