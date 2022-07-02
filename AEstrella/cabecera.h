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
        //llama el metodo aleatorio
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
        //Dependiendo de la variable accion que se recibe
        switch(accion) {
        case 1://ARRIBA
            if((f==0 && c==0)||(f==0 && c==1)||(f==0 && c==2)) { //Si el espacio vacio esta en los limite de arriba
                //cout<< "No se puede realizar accion"<< endl;
                return false;
                break;
            }
            //A continuacion va analizando todos los posibles casillerros donde esta el espacio en blanco
            if(f==1 && c==0) { //Si el espacio vacio esta en la pos [1,0]
                pasar(f,c,0,0); //Mover el espacio vacio actual hacia arriba -> [0,0]

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
            if(f==2 && c==0) { //Si el espacio vacio esta en la pos [fila 2, columna 0]
                pasar(f,c,1,0); //Mover el espacio vacio actual hacia arriba -> [1,0]

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
            if((f==2 && c==0)||(f==2 && c==1)||(f==2 && c==2)) { //Cuando el espacio vacio esta en los limites inferiores
                //cout<< "No se puede realizar accion" << endl;
                return false;
                break;
            }
            if(f==1 && c==0) { //Si el espacio vacio esta en la pos [fila 1, columna 0]
                pasar(f,c,2,0); //Mover el espacio vacio actual hacia abajo -> [2,0]

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
            if((f==0 && c==0)||(f==1 && c==0)||(f==2 && c==0)) { //Cuando el espacio vacio esta en los limites de la izquierda del tablero
                //cout<< "No se puede realizar accion"<< endl;
                return false;
                break;
            }
            if(f==0 && c==1) { //Si el espacio vacio esta en la pos [fila 0, columna 1]
                pasar(f,c,0,0); //Mover el espacio vacio actual hacia la izquierda -> [0,0]

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
            if((f==0 && c==2)||(f==1 && c==2)||(f==2 && c==2)) { //Cuando el espacio vacio esta en los limites de la derecha del tablero
                //cout<< "No se puede realizar accion"<< endl;
                return false;
                break;
            }
            if(f==0 && c==1) { //Si el espacio vacio esta en la pos [fila 0, columna 1]
                pasar(f,c,0,2); //Mover el espacio vacio actual hacia la derecha -> [0,2]

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
        //A continuacion se guarda el numero de la casilla a donde se va mover el espacio vacio
        int aux;
        aux= e[nf][nc];
        e[nf][nc]=e[f][c]; //Se le asigna el espacio vacio  a la nueva casilla
        e[f][c]=aux; //Cambia
    }
    Estado getEstado() {
        return *this;
    }

    //Funcion para determinar si el estado actual cumple con las condiciones del estado objetivo (tablero ordenado ascend.)
    //Retorna True si se cumplle la condicion del estado final || Retorna Falso si el estado actual no es el estado final
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

    //Funcion que devuelve True si el estado inicial alcanzara un estado solucion
    //Si el #de inversiones es par existe solucion, caso contrario no existe solucion
    bool existeSolucion() {

        int inversiones=0;
        int aux[9];
        int c=0;

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                //Se va almacenar los numeros del tablero en un vector de 1 dimension en el orden en que este el estado actual
                aux[c]=e[i][j];

                c++;
            }
        }


        for(int i=0; i<9; i++) {
            for(int j=i+1; j<9; j++) {
                //Ejm: [1,2,3,4,_,6,7,5,8] -> Se puede invertir el [6,5], [7,5]
                //Se cuenta como una inversion cuando el numero actual (i) es mayor que el siguiente (i+1) y  son distintos del espacio vacio
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
    //Metodo que devuelve el valor numerico de la distancia Manhattan en el estado actual
    //La distancia Manhattan es la suma de las ditancias de cada casilla actual que conforman el tablero para llegar a su casilla final o solucion
    int funcionDistanciaManhattan() {
        int distanciaTotal=0;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                //Recorre la matriz del estado actual e[][] y va sumando la distancia individual de cada casilla
                distanciaTotal+= calcularDistanciaManhattan(e[i][j],i,j);
            }
        }
        return distanciaTotal;
    };
    //Funcion que recibe el valor numerico de la casilla y su posicion actual en el tablero
    int calcularDistanciaManhattan(int num, int posi, int posj) { //1 al 8
        int aux1, aux2, distancia;
        //Dependiendo del valor numerico de la casilla actual, para determinar la casilla solucion o final
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
