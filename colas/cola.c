#include "cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Colas* crear_cola(){

    Colas* cola = (Colas*)malloc(sizeof(Colas));
    cola->primero = NULL;
    cola->ultimo = NULL;
    cola->longui = 0;
    return cola;

}

Nodo* crear_nodo(int info){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = info;
    nodo->next = NULL;
    return nodo;
}

// pone el elemento al fianl de la cola

void encolar(Colas* cola,int valor){
    Nodo* nodo =crear_nodo(valor);

    if(cola->primero == NULL){

        cola->primero = nodo;
        cola->ultimo = nodo;
        cola->longui++;

    }else {

        cola->ultimo->next=nodo;
        cola->ultimo = nodo;
        cola->longui++;

    }

}

// quita el primer elemento de la cola mas no devuelve el elemento

void desencolar(Colas* cola){
    Nodo* aux;

    if (!es_vacia_cola(cola)) {

        if (cola->primero == cola->ultimo) {

            free(cola->primero);
            cola->primero = NULL;
            cola->ultimo = NULL;
            cola->longui--;

        }else {

            aux = cola->primero;
            cola->primero = cola->primero->next;
            free(aux);
            cola->longui--;

        }
    }
}

// te da el primer elemento de cola mas no lo quita, si la cola esta vacia devuelve -1

int octe_primaro_cola(Colas* cola){
    int pri = -1;

    if(cola->primero != NULL){

        pri=cola->primero->dato;

    }

    return pri;
}

// te da el primer elenento de la cola y lo quita, si la cola esta vacia devuelve -1

int despacho(Colas* cola){
    int pri = -1;

    if(!es_vacia_cola(cola)){

        pri = octe_primaro_cola(cola);
        desencolar(cola);

    }

    return pri;
}

// devuelve la longuitu de la cola

int longui_cola(Colas* cola){

    return cola->longui;
}

// de dice si es vavia la cola

bool es_vacia_cola(Colas* cola){
    bool es= false;

    if(cola->primero == NULL){

        es = true;

    }

    return es;
}

// elimina todos los elemento de la cola

void elim_cola(Colas* cola){

    while (cola->primero != NULL) {

        desencolar(cola);

    }

}

// invertir cola, se invirte la misma cola

void inver_cola(Colas* cola){

    Nodo* aux;

    aux = cola->ultimo;
    cola->ultimo = cola->primero;
    cola->primero = aux;

}
