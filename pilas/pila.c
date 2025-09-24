#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Pilas* crear_pila(){
    Pilas* pila = (Pilas*)malloc(sizeof(Pilas));
    pila->tope = NULL;
    pila->longui = 0;
    return pila;
}

Nodo* crear_nodo(int info){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = info;
    nodo->next = NULL;
    return nodo;
}

// pone el elemento en la cima de la pila

void apilar(Pilas* pila,int valor){
    Nodo* nodo = crear_nodo(valor);

    nodo->next=pila->tope;
    pila->tope=nodo;
    pila->longui++;

}

// quita el elemento que esta en el tope pero no lo devuelve

void desapilar(Pilas* pila){
    Nodo* aux;

    if(pila->tope != NULL){

        aux=pila->tope;
        pila->tope=pila->tope->next;
        free(aux);
        pila->longui--;

    }
}

//invertir pila,se necesitas 2 pilas y ambas pilas tiene que estar creadas

void inver_pila(Pilas* pila1,Pilas* pila2){
    int aux;

    while(!es_vacia_pila(pila1)){

        aux = octen_tope(pila1);
        desapilar(pila1);
        apilar(pila2,aux );

    }

}

// devuelve la longuitu de la pila

int longui_pila(Pilas* pila){

    return pila->longui;
}

// verifica de es vacia la pila

bool es_vacia_pila(Pilas* pila){
    bool es;

    if(pila->tope==NULL){

        es=true;

    }else {

        es=false;

    }

    return es;
}

// devuelve el tope de la pila mas no lo elimina

int octen_tope(Pilas* pila){
    int tope = -1;

    if (pila->tope != NULL) {

        tope=pila->tope->dato;

    }

    return tope;

}

//elimina todos los elemento de la pila

void elimi_pila(Pilas* pila){

    while (pila->tope != NULL) {

        desapilar(pila);

    }

}
