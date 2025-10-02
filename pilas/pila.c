#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

Pilas* crear_pila(){
    Pilas* pila = (Pilas*)malloc(sizeof(Pilas));
    pila->tope = NULL;
    pila->longui = 0;
    return pila;
}

Nodo_Pila* crear_nodo_p(Preg_res valor){
    Nodo_Pila* nodo_p = (Nodo_Pila*)malloc(sizeof(Nodo_Pila));
    strcpy(nodo_p->his.pregunta,valor.pregunta );
    strcpy(nodo_p->his.repuesta,valor.repuesta );
    nodo_p->next = NULL;
    return nodo_p;
}

// pone el elemento en la cima de la pila

void apilar(Pilas* pila,Preg_res valor){
    Nodo_Pila* nodo_p = crear_nodo_p(valor);

    nodo_p->next=pila->tope;
    pila->tope=nodo_p;
    pila->longui++;

}

// quita el elemento que esta en el tope pero no lo devuelve

void desapilar(Pilas* pila){
    Nodo_Pila* aux;

    if(pila->tope != NULL){

        aux=pila->tope;
        pila->tope=pila->tope->next;
        free(aux);
        pila->longui--;

    }
}

//invertir pila,se necesitas 2 pilas y ambas pilas tiene que estar creadas

void inver_pila(Pilas* pila1,Pilas* pila2){
    Preg_res aux;

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

Preg_res octen_tope(Pilas* pila){
    Preg_res tope;

    if (pila->tope != NULL) {

        strcpy(tope.pregunta,pila->tope->his.pregunta);
        strcpy(tope.repuesta,pila->tope->his.repuesta);

    }

    return tope;

}

//elimina todos los elemento de la pila

void elimi_pila(Pilas* pila){

    while (pila->tope != NULL) {

        desapilar(pila);

    }

}
