#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../pilas/pila.h"


listas* crear_lista(){
    listas* lista = (listas*)malloc(sizeof(listas));
    lista->cabeza = NULL;
    lista->longui = 0;
    return lista;
}

Nodo_lista* crear_nodo(Usua info){
    Nodo_lista* nodo_l = (Nodo_lista*)malloc(sizeof(Nodo_lista));
    strcpy(nodo_l->usuario.nombre,info.nombre );
    strcpy(nodo_l->usuario.apellido,info.apellido );
    strcpy(nodo_l->usuario.CI,info.CI );
    nodo_l->usuario.cam_pre = 0;
    nodo_l->usuario.historial = crear_pila();
    nodo_l->next = NULL;
    return nodo_l;
}

//introduce en la lista en la primera posicion

void inset_one(listas* lista,Usua info){

    Nodo_lista* nodo_l = crear_nodo(info);

    nodo_l->next=lista->cabeza;
    lista->cabeza = nodo_l;
    lista->longui++;

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

bool esta_en_lista(listas* lista,Usua dato){

    Nodo_lista* aux;
    bool esta = false;

    aux=lista->cabeza;

    while (aux != NULL) {

        if(strcmp(dato.CI,aux->usuario.CI) == 0){

            if (strcmp(dato.nombre,aux->usuario.nombre) == 0) {

                if (strcmp(dato.nombre,aux->usuario.nombre) == 0) {

                    esta = true;

                    aux = NULL;  // Esto rompe el bucle

                }

            }


        }else {

            aux=aux->next;

        }

    }

    return esta;

}



//imprime toda la lista por pantalla

void impri_lista(listas* lista){
    Nodo_lista* aux;
    int cont=1;

    aux=lista->cabeza;

    while (aux!=NULL) {

        printf("posicion %d CI %s nombre %s apellido %s ",cont,aux->usuario.CI,aux->usuario.nombre,aux->usuario.apellido);
        cont++;
        aux=aux->next;

    }
}


