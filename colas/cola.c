#include "cola.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../tda/pre_res.h"

Colas* crear_cola(){

    Colas* cola = (Colas*)malloc(sizeof(Colas));
    cola->primero = NULL;
    cola->ultimo = NULL;
    cola->longui = 0;
    return cola;

}

Nodo_cola* crear_nodo_c(Preg_res info){
    Nodo_cola* nodo_c = (Nodo_cola*)malloc(sizeof(Nodo_cola));
    strcpy(nodo_c->sin_res.pregunta,info.pregunta);
    strcpy(nodo_c->sin_res.repuesta,info.repuesta);
    nodo_c->next = NULL;
    return nodo_c;
}

// pone el elemento al fianl de la cola

void encolar(Colas* cola,Preg_res valor){
    Nodo_cola* nodo_c =crear_nodo_c(valor);

    if(cola->primero == NULL){

        cola->primero = nodo_c;
        cola->ultimo = nodo_c;
        cola->longui++;

    }else {

        cola->ultimo->next=nodo_c;
        cola->ultimo = nodo_c;
        cola->longui++;

    }

}

// quita el primer elemento de la cola mas no devuelve el elemento

void desencolar(Colas* cola){
    Nodo_cola* aux;

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

Preg_res octe_primaro_cola(Colas* cola){
    Preg_res pri;

    if(cola->primero != NULL){

        pri = cola->primero->sin_res;

    }

    return pri;
}

// te da el primer elenento de la cola y lo quita, si la cola esta vacia devuelve -1

Preg_res despacho(Colas* cola){
    Preg_res pri;

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

    Nodo_cola* aux;

    aux = cola->ultimo;
    cola->ultimo = cola->primero;
    cola->primero = aux;

}
