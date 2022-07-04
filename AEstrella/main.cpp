#include <iostream>
#include "cabecera.h"

//Busca el mejor nodo de primero es el mejor del menor valor
Nodo* RBFS(Nodo *node,int f_limit,int * f_cost){

    //Estado llama al test objetivo
    if(node->estado.testObjetivo()){
        return node;
    }

    //El nodo escapande
    node->expandirNodo();

    if(node->fr==0){//Si el nodo factor de ramificaciones es igual a cero retorn null
        return NULL;
    }
    Nodo *s=NULL;//Nodo vacio
    Nodo *best=NULL;//Mejor nodo vacio
    Nodo *result=NULL;//Resultado del nodo vacio

    //Incrementa si el factor de ramifacacion es menor
    for(int i=0;i<node->fr;i++){
        s=node->hijos[i];//Almacena el nodo hijo
        s->f=max(s->g+s->h,node->f);//Escojer le maximo valor de nodos en la frontera


    }
    //Mientras el mejor nodos del valor menor
    while(true){
        best=node->menorFValue();
        if(best->f>f_limit){//el mejor nodo en mayor al limete de frontera retorna null
            *f_cost=best->f;

            return NULL;
        }

        //Almacena el nodo del segundo mejor valor
        int alternative=node->segundoMenorFValue();
        //Ejecojer el mejor valor
        result=RBFS(best,min(f_limit,alternative),&best->f);

        if(result!=NULL){//Si el resultado del mejor valor es diferente de null retorna el valor
            return result;
        }
    }
}


//Busca el camino mas corto desde sus estado incial
Nodo * busquedaAEstrella(Nodo *n){
    int x=0;
    return RBFS(n,999,&x);//Retorn el mejor valor

}

//Codigo principal
int main() {

    Nodo n;//Variable de tipo nodo

    //Mientras el nodo sea diferente llamar al metodo existe solucion
    while(!n.estado.existeSolucion()) {
        n.estado.estadoAleatorio();//asigan el valor de manra aleatorio

    }
    //Imprime las ejecuciones desde el estado inical
    cout<<"Estado inicial:"<<endl;
    n.estado.printEstado();

    //Busca la soluciones que apunta hacia si mismo
    if(n.estado.existeSolucion()) {
        Nodo *sol;

        //LLama al metodo para buscar el mejor valor desde estado incial
        sol=busquedaAEstrella(n.autoApuntador());

        if(sol==NULL) {//si la solucion es diferente de null imprime
            cout<<"No se encontro la solucion"<<endl;
        } else {//Si no, imprime los pasos, la solucion y el numero de pasos

            cout<<"Pasos:"<<endl;
            sol->imprimirPadres();

            cout<<"Solucion:"<<endl;
            sol->estado.printEstado();

            cout<<"Numero de Pasos:"<<endl;
            cout<<sol->n<<endl;
        }

    } else {// Si no imprime las solucion no alzanda

        cout<<"El estado no alcanzara la solucion"<<endl;
    }

    return 0;
}
