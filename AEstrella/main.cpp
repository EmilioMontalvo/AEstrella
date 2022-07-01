#include <iostream>
#include "cabecera.h"


Nodo* RBFS(Nodo *node,int f_limit,int * f_cost){

    //node->print();

    if(node->estado.testObjetivo()){
        return node;
    }

    node->expandirNodo();

    if(node->fr==0){
        return NULL;
    }
    Nodo *s=NULL;
    Nodo *best=NULL;
    Nodo *result=NULL;

    for(int i=0;i<node->fr;i++){
        s=node->hijos[i];
        s->f=max(s->g+s->h,node->f);


    }
    while(true){
        best=node->menorFValue();
        if(best->f>f_limit){
            *f_cost=best->f;

            return NULL;
        }


        int alternative=node->segundoMenorFValue();
        //best->print();

        result=RBFS(best,min(f_limit,alternative),&best->f);

        if(result!=NULL){

            return result;
        }
    }
}



Nodo * busquedaAEstrella(Nodo *n){
    int x=0;
    return RBFS(n,999,&x);

}


int main() {

    Nodo n;




    while(!n.estado.existeSolucion()) {
        n.estado.estadoAleatorio();


    }
    cout<<"Estado inicial:"<<endl;
    n.estado.printEstado();

    if(n.estado.existeSolucion()) {
        Nodo *sol;


        sol=busquedaAEstrella(n.autoApuntador());

        if(sol==NULL) {
            cout<<"No se encontro la solucion"<<endl;
        } else {

            cout<<"Pasos:"<<endl;
            sol->imprimirPadres();

            cout<<"Solucion:"<<endl;
            sol->estado.printEstado();

            cout<<"Numero de Pasos:"<<endl;
            cout<<sol->n<<endl;
        }

    } else {

        cout<<"El estado no alcanzara la solucion"<<endl;
    }

    return 0;
}
