#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

listas* crear_lista() {
    listas* lista = (listas*)malloc(sizeof(listas));
    lista->cabeza = NULL;
    lista->longitud = 0;
    return lista;
}

Nodo* crear_nodo(void* info) {
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = info;
    nodo->next = NULL;
    return nodo;
}

void liberar_lista(listas* lista) {
    while (!lista_vacia(lista)) {
        eliminar_inicio(lista); // El usuario debe liberar los datos
    }
    free(lista);
}

void insertar_inicio(listas* lista, void* valor) {
    Nodo* nodo = crear_nodo(valor);
    nodo->next = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++;
}

void insertar_final(listas* lista, void* valor) {
    Nodo* nodo = crear_nodo(valor);
    
    if (lista->cabeza == NULL) {
        lista->cabeza = nodo;
    } else {
        Nodo* aux = lista->cabeza;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = nodo;
    }
    lista->longitud++;
}

void* eliminar_inicio(listas* lista) {
    if (lista->cabeza == NULL) return NULL;
    
    Nodo* temp = lista->cabeza;
    void* dato = temp->dato;
    lista->cabeza = lista->cabeza->next;
    lista->longitud--;
    free(temp);
    return dato;
}

bool lista_vacia(listas* lista) {
    return lista->cabeza == NULL;
}

int longitud_lista(listas* lista) {
    return lista->longitud;
}

void* obtener_elemento(listas* lista, int pos) {
    if (pos < 1 || pos > lista->longitud) return NULL;
    
    Nodo* aux = lista->cabeza;
    for (int i = 1; i < pos; i++) {
        aux = aux->next;
    }
    return aux->dato;
}

int buscar_elemento(listas* lista, void* dato, bool (*comparar)(void*, void*)) {
    Nodo* aux = lista->cabeza;
    int posicion = 1;
    
    while (aux != NULL) {
        if (comparar(aux->dato, dato)) {
            return posicion;
        }
        aux = aux->next;
        posicion++;
    }
    return -1;
}

void mostrar_lista(listas* lista, void (*imprimir)(void*)) {
    Nodo* aux = lista->cabeza;
    int contador = 1;
    
    while (aux != NULL) {
        printf("%d. ", contador);
        imprimir(aux->dato);
        aux = aux->next;
        contador++;
    }
    
    if (contador == 1) {
        printf("La lista está vacía\n");
    }
}