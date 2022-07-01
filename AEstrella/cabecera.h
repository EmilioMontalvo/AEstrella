#ifndef CABECERA_H_INCLUDED
#define CABECERA_H_INCLUDED
#include <iostream>
#include <time.h>

using namespace std;
class Estado {
public:
    //Matriz que se usara para representar los estados del 8 puzle
    int e[3][3];


    Estado() { //Constructor inicializa el puzzle en el orden que deberia estar
        for(int i=0; i<3; i++) {

            for(int j=0; j<3; j++) {

                e[i][j]=0;

            }

        }

        estadoAleatorio();

    };




    Estado(int es[3][3]) { //Constructor

        for(int i=0; i<3; i++) {

            for(int j=0; j<3; j++) {

                e[i][j]=es[i][j];

            }

        }

    };

    Estado* autoApuntador() {
        return this;
    };



    //FUNCIONES
    //Imprimir estado
    void printEstado() {
        int filas = (sizeof(e)/sizeof(e[0]));
        int columnas = (sizeof(e[0])/sizeof(e[0][0]));
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout<< "[" <<e[i][j]<<"] ";
            }

            cout<<endl;
        }
        cout<<endl;


    };


    //METODO PASO SIGUIENTE
    bool pasoSiguiente(int accion) {
        //variable que almacena la posicion f = fila c= columna
        int f,c;

        //primero determinamos la posición en la que se encuentra el espacio vacio
        int filas = (sizeof(e)/sizeof(e[0]));
        int columnas = (sizeof(e[0])/sizeof(e[0][0]));
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                if(e[i][j]==0) {
                    f=i;
                    c=j;
                }
            }
        }
        //cout<<"posicion actual vacia ----> "<<f<<" "<<c<<"\n"<<endl;
        switch(accion) {
        case 1://ARRIBA
            if((f==0 && c==0)||(f==0 && c==1)||(f==0 && c==2)) {
                //cout<< "No se puede realizar accion"<< endl;
                return false;
                break;
            }
            if(f==1 && c==0) {
                pasar(f,c,0,0);

                break;
            }
            if(f==1 && c==1) {
                pasar(f,c,0,1);

                break;
            }
            if(f==1 && c==2) {
                pasar(f,c,0,2);

                break;
            }
            if(f==2 && c==0) {
                pasar(f,c,1,0);

                break;
            }
            if(f==2 && c==1) {
                pasar(f,c,1,1);

                break;
            }
            if(f==2 && c==2) {
                pasar(f,c,1,2);

                break;
            }
            break;
        case 2: //ABAJO
            if((f==2 && c==0)||(f==2 && c==1)||(f==2 && c==2)) {
                //cout<< "No se puede realizar accion" << endl;
                return false;
                break;
            }
            if(f==1 && c==0) {
                pasar(f,c,2,0);

                break;
            }
            if(f==1 && c==1) {
                pasar(f,c,2,1);

                break;
            }
            if(f==1 && c==2) {
                pasar(f,c,2,2);

                break;
            }
            if(f==0 && c==0) {
                pasar(f,c,1,0);

                break;
            }
            if(f==0 && c==1) {
                pasar(f,c,1,1);

                break;
            }
            if(f==0 && c==2) {
                pasar(f,c,1,2);

                break;
            }
            break;
        case 3: //IZQUIERDA
            if((f==0 && c==0)||(f==1 && c==0)||(f==2 && c==0)) {
                //cout<< "No se puede realizar accion"<< endl;
                return false;
                break;
            }
            if(f==0 && c==1) {
                pasar(f,c,0,0);

                break;
            }
            if(f==1 && c==1) {
                pasar(f,c,1,0);

                break;
            }
            if(f==2 && c==1) {
                pasar(f,c,2,0);

                break;
            }
            if(f==0 && c==2) {
                pasar(f,c,0,1);

                break;
            }
            if(f==1 && c==2) {
                pasar(f,c,1,1);

                break;
            }
            if(f==2 && c==2) {
                pasar(f,c,2,1);

                break;
            }
            break;
        case 4: //derecha
            if((f==0 && c==2)||(f==1 && c==2)||(f==2 && c==2)) {
                //cout<< "No se puede realizar accion"<< endl;
                return false;
                break;
            }
            if(f==0 && c==1) {
                pasar(f,c,0,2);

                break;
            }
            if(f==1 && c==1) {
                pasar(f,c,1,2);

                break;
            }
            if(f==2 && c==1) {
                pasar(f,c,2,2);

                break;
            }
            if(f==0 && c==0) {
                pasar(f,c,0,1);

                break;
            }
            if(f==1 && c==0) {
                pasar(f,c,1,1);

                break;
            }
            if(f==2 && c==0) {
                pasar(f,c,2,1);

                break;
            }
            break;
        }
        return true;
    }
    //FUNCION PASAR (INTERCAMNBIO)
    void pasar(int f,int c,int nf,int nc) {
        //f y c = fila y columna actual   && nf y nc = siguiente fila y columna a realizar el cambio.
        //cout<<"pasa ----> "<<f<<" "<<c<<"\n"<<"pasa ----> "<<nf<<" "<<nc<<"\n"<<endl;
        int aux;
        aux= e[nf][nc];
        e[nf][nc]=e[f][c];
        e[f][c]=aux;
    }
    Estado getEstado() {
        return *this;
    }

    bool testObjetivo() {
        int c=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){

                if(e[i][j]!=c){
                    return false;
                }
                c++;
            }

        }

        return true;
    }


    bool existeSolucion() {

        int inversiones=0;
        int aux[9];
        int c=0;

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {

                aux[c]=e[i][j];

                c++;
            }
        }


        for(int i=0; i<9; i++) {
            for(int j=i+1; j<9; j++) {


                if(aux[i]>aux[j] && aux[i]!=0 && aux[j]!=0 ) {
                    inversiones++;
                }
            }
        }



        return(inversiones%2==0);



    }

    void estadoAleatorio() {

        srand(time(NULL));

        int piezas[]= {0,1,2,3,4,5,6,7,8};
        bool asignado=false;
        int t=0;
        int x=-1;

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {

                while(!asignado) {
                    t=(rand()%9);
                    x=piezas[t];
                    if(x!=-1) {
                        e[i][j]=x;
                        piezas[t]=-1;
                        asignado=true;
                    }
                }
                asignado=false;
            }
        }

    }

    int funcionDistanciaManhattan() {
        int distanciaTotal=0;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                distanciaTotal+= calcularDistanciaManhattan(e[i][j],i,j);
            }
        }
        return distanciaTotal;
    };

    int calcularDistanciaManhattan(int num, int posi, int posj) { //1 al 8
        int aux1, aux2, distancia;
        switch(num) {
        case 0:
            aux1=abs(0-posi);
            aux2=abs(0-posj);
            distancia=aux1+aux2;
            break;
        case 1:
            aux1=abs(0-posi);
            aux2=abs(1-posj);
            distancia=aux1+aux2;
            break;
        case 2:
            aux1=abs(0-posi);
            aux2=abs(2-posj);
            distancia=aux1+aux2;
            break;
        case 3:
            aux1=abs(1-posi);
            aux2=abs(0-posj);
            distancia=aux1+aux2;
            break;
        case 4:
            aux1=abs(1-posi);
            aux2=abs(1-posj);
            distancia=aux1+aux2;
            break;
        case 5:
            aux1=abs(1-posi);
            aux2=abs(2-posj);
            distancia=aux1+aux2;
            break;
        case 6:
            aux1=abs(2-posi);
            aux2=abs(0-posj);
            distancia=aux1+aux2;
            break;
        case 7:
            aux1=abs(2-posi);
            aux2=abs(1-posj);
            distancia=aux1+aux2;
            break;
        case 8:
            aux1=abs(2-posi);
            aux2=abs(2-posj);
            distancia=aux1+aux2;
            break;
        default:
            cout<<"Numero no posible\n";
        }
        return distancia;
    }
};




class Nodo {
public:

    Estado estado;
    Nodo *padre;
    Nodo **hijos;
    int fr;//factor de ramificacion
    int n;//profundidad

    int f;
    int h;
    int g;




    Nodo() {
        //estado=Estado();
        padre=NULL;
        hijos=NULL;
        fr=0;
        n=0;
        f=0;
        h=0;
        g=0;


    };



    Nodo(Estado es) {
        estado=es;
        padre=NULL;
        hijos=NULL;
        fr=0;
        n=0;
        f=0;
        h=0;
        g=0;

    };

    Nodo(Nodo *nod) {
        estado=nod->estado;
        padre=nod->padre;
        hijos=nod->hijos;
        fr=nod->fr;
        n=nod->n;
        f=nod->f;
        h=nod->h;
        g=nod->g;

    };

    Nodo* autoApuntador() {
        return this;
    };

    Nodo(Nodo *pa,Estado *es) {

        padre=pa;
        estado=es->getEstado();


    };

    bool comparar(Nodo *n){

        for(int i=0;i<3;i++){
            for(int j=0;i<3;i++){
                if(estado.e[i]!=n->estado.e[i]){
                    return false;
                }
            }
        }

        if(f!=n->f){
            return false;
        }
        return true;

    }

    void print(){
        estado.printEstado();

        cout<<"f: "<<f<<endl;
        cout<<"h: "<<h<<endl;
        cout<<"g: "<<g<<endl;
        cout<<"n: "<<g<<endl;


    }

    void imprimirPadres() {

        Nodo *padres[n+1];
        Nodo *p=NULL;
        p=padre->autoApuntador();


        for(int i=0; i<n; i++) {
            padres[i]=p;
            //p->estado.printEstado();
            p=p->padre;
        }


        for(int i=n-1; i>=0; i--) {
            padres[i]->estado.printEstado();
        }



    }

    void expandirNodo() {//funcion succesor


        int nh=0;
        Estado **mes;
        mes=new Estado*[4];

        for(int i=1; i<=4; i++) {

            Estado *es =(new Estado(estado.e));


            if(es->pasoSiguiente(i) && es->existeSolucion()) {
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
            hijos[i]->h=hijos[i]->estado.funcionDistanciaManhattan();
            hijos[i]->g=this->g+1;
            hijos[i]->f=hijos[i]->h+hijos[i]->g;


        }

    };

    Nodo * menorFValue() {

        Nodo * menor;
        menor=NULL;
        if(fr==0)return NULL;
        menor=hijos[0];
        for(int i=1; i<fr; i++) {
            if(menor->f > hijos[i]->f) {
                menor=hijos[i];
            }
        }

        return menor;

    }


    int segundoMenorFValue() {

        int primero=menorFValue()->f;
        int segundo=9999;

        for(int i=0; i<fr; i++) {
            int x=hijos[i]->f;
            if( x<segundo && x!=primero) {
                segundo=x;
            }
        }

        return segundo;

    }



};



#endif // CABECERA_H_INCLUDED
