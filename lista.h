#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo {
    void* dato;  // Cambiado a void* para ser genérico
    struct Nodo* next;
} Nodo;

typedef struct listas {
    Nodo* cabeza;
    int longitud;
} listas;

// Constructor y destructor
listas* crear_lista();
Nodo* crear_nodo(void* info);
void liberar_lista(listas* lista);

// Operaciones de inserción
void insertar_inicio(listas* lista, void* valor);
void insertar_final(listas* lista, void* valor);
void insertar_posicion(listas* lista, void* valor, int pos);

// Operaciones de eliminación
void* eliminar_inicio(listas* lista);
void* eliminar_final(listas* lista);
void* eliminar_posicion(listas* lista, int pos);

// Operaciones de consulta
bool lista_vacia(listas* lista);
int longitud_lista(listas* lista);
void* obtener_elemento(listas* lista, int pos);
int buscar_elemento(listas* lista, void* dato, bool (*comparar)(void*, void*));

// Operaciones de utilidad
void intercambiar_elementos(listas* lista, int pos1, int pos2);
void mostrar_lista(listas* lista, void (*imprimir)(void*));

#endif // LISTA_H