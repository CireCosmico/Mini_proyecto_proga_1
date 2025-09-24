#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


listas* crear_lista(){
    listas* lista = (listas*)malloc(sizeof(listas));
    lista->cabeza = NULL;
    lista->longui = 0;
    return lista;
}

Nodo* crear_nodo(int info){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = info;
    nodo->next = NULL;
    return nodo;
}

//introduce en la lista en la primera posicion

void inset_one(listas* lista,int valor){

    Nodo* nodo = crear_nodo(valor);

    nodo->next=lista->cabeza;
    lista->cabeza = nodo;
    lista->longui++;

}

//introduce en la lista en la ultima posicion

void inset_ulti(listas* lista,int valor){
    Nodo* nodo = crear_nodo(valor);
    Nodo* aux = lista->cabeza;

    if (lista->cabeza==NULL) {

        inset_one(lista,valor );

    }else {

        while (aux->next!=NULL) {

            aux=aux->next;

        }

        aux->next=nodo;
        lista->longui++;

    }

}

//introduce en la lista en la posicion elejida

void inset_posi(listas* lista,int valor, int pos){
    Nodo* nodo = crear_nodo(valor);
    Nodo* aux;
    int i;

    aux=lista->cabeza;

    if(lista->cabeza == NULL){

        inset_one(lista,valor );

    }else if(pos <= lista->longui+1 && pos>0){

        if(pos==1){

            inset_one(lista,valor );

        }else if(pos == lista->longui+1){

            inset_ulti(lista,valor );

        }else {

            for(i=1;i<pos-1;i++){

                aux=aux->next;
            }

            nodo->next=aux->next;
            aux->next=nodo;
            lista->longui++;

        }

    }else if(pos >= lista->longui+2){

        inset_ulti(lista,valor);

    }
}

// intercambia 2 posiciones en la lista, util para el metodo de ordenamiento

void spaw_lis(listas* lista,int pos1,int pos2){
    int A,B,i;
    Nodo* aux;

    if( pos1 >= 1 && pos2 >= 1 && pos1 <= lista->longui && pos2 <= lista->longui){

        A = oten_ele_lista(lista,pos1 );
        B = oten_ele_lista(lista,pos2 );

        aux=lista->cabeza;

        for(i=1;i<pos1;i++){
            aux=aux->next;
        }

        aux->dato=B;
        aux=lista->cabeza;

        for(i=1;i<pos2;i++){
            aux=aux->next;
        }

        aux->dato=A;

    }
}

//veltea la lista A y la copia en B, sin destruir la lista A, (si quieres asegurar que la lista B este vacia solo usa el elimi_lista)

listas* voltear_lista(listas* Orlista,listas* Inlista){
    Nodo* aux;
    aux=Orlista->cabeza;

    while (aux!=NULL) {

        inset_one(Inlista,aux->dato );
        aux=aux->next;

    }

    return Inlista;

}

// borra en la primera posicion en la lista

void vaciar_one(listas* lista){
    Nodo* aux;

    if(lista->cabeza != NULL){

        aux=lista->cabeza;
        lista->cabeza=lista->cabeza->next;
        lista->longui--;
        free(aux);

    }
}

// borra en la ultima posicion en la lista

void vaciar_ulti(listas* lista){
    Nodo* aux;

    aux=lista->cabeza;

    if(lista->cabeza != NULL){

        if(lista->cabeza->next != NULL){

            while (aux->next->next != NULL) {

                aux=aux->next;

            }

            free(aux->next);
            aux->next=NULL;
            lista->longui--;

        }else {

            free(lista->cabeza);
            lista->cabeza = NULL;
            lista->longui--;

        }
    }
}

// borra en la posicion elgida de la lista

void vaciar_posi(listas* lista,int pos){

    if(pos <= lista->longui && pos > 0){

        if(pos == 1){

            vaciar_one(lista);

        }else if(pos == lista->longui){

            vaciar_ulti(lista);

        }else {

            Nodo* aux,*aux2;
            int i;

            aux = lista->cabeza;

            for(i = 1;i < pos-1;i++){

                aux=aux->next;

            }

            aux2=aux->next;
            aux->next=aux2->next;
            free(aux2);
            lista->longui--;

        }

    }else if(pos > lista->longui){

        vaciar_one(lista);

    }

}

// verifica si es vacia la lista

bool es_vacia_lista(listas* lista){
    bool es;
    if(lista->cabeza == NULL){

        es=true;

    }else {

        es=false;

    }

    return es;
}

//te dice la longuitu de la lista

int lon_lista(listas* lista){

    return lista->longui;
}

//te dice si un elemento esta en la lista devolviendo posicion y si no esta devuelve -1

int esta_en_lista(listas* lista,int dato){
    int esta = -1,cont = 0;
    Nodo* aux;

    aux=lista->cabeza;

    while (aux != NULL) {

        cont++;

        if(dato == aux->dato){

            esta = cont;

            aux = NULL;  // Esto rompe el bucle

        }else {

            aux=aux->next;

        }

    }

    return esta;

}

//dada una posicion devuelve el elemento de se posicion, si la posicion es invalida devuelve -1

int oten_ele_lista(listas* lista,int pos){
    int dato = -1,i;
    Nodo* aux;

    aux=lista->cabeza;

    if(pos <= lista->longui && pos > 0){

        for(i=1;i<pos;i++){

            aux=aux->next;

        }

        dato=aux->dato;

    }

    return dato;

}

//imprime toda la lista por pantalla

void impri_lista(listas* lista){
    Nodo* aux;
    int cont=1;

    aux=lista->cabeza;

    while (aux!=NULL) {

        printf("posicion %d tiene el valor: %d\n",cont,aux->dato);
        cont++;
        aux=aux->next;

    }
}

//elimina todos los elemento de la lista

void elimi_lista(listas* lista){

    while (lista->cabeza != NULL) {

        vaciar_one(lista);

    }

}

void ordena(listas* lista){
    int i,j, mini ,lon = lon_lista(lista);

    for(i = 0; i <= lon-1;i++){

        mini = i;
        int elemento_mini = oten_ele_lista(lista, i );

        for (j = i+1; j <= lon ; j++ ) {
            int elemento_compa = oten_ele_lista(lista, j );

            if(elemento_compa < elemento_mini){

                elemento_compa = elemento_mini;

                mini = j;

            }
        }

        if(i != mini){

            spaw_lis(lista,i ,mini );

        }

    }

}



/*void alfavetordena(listas* lista){
    int i,j, mini ,lon = lon_lista(lista);

    for(i = 0; i <= lon-1;i++){

        mini = i;
        cancion mini_nodo = oten_ele_lista(lista, i );

        for (j = i+1; j <= lon ; j++ ) {
            cancion con_nodo = oten_ele_lista(lista, j );

            if(strcmp(con_nodo.titu,mini_nodo.titu ) < 0){

                strcpy(mini_nodo.titu,con_nodo.titu );
                strcpy(mini_nodo.art,con_nodo.art );
                mini_nodo.dura = con_nodo.dura;

                mini = j;

            }
        }

        if(i != mini){

            spaw_lis(lista,i ,mini );

        }

    }

}*/
