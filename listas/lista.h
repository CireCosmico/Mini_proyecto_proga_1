#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdbool.h>

/*recuerda que cuabo tengo que modificar el Nodo no le ponga cosas adentro, solo crea un nuevo struct y ese ponlo adentro
ejem: cancion con el nombre de la cancion del autor y la duracion y eso es valor que estara adentro del Nodo (No como puntero, si no como valor)
cuando devuelva devuelve que este adentro del nodo no el nodo por eso es iportante crear el tipo de dato, lo puedes hacer por valor o puntero
es preferible devolver punteros ya que si encuantra el elemnto que delvuelva NULL como no entontado aun que si tenes errores en mejor trabajer com varieble*/

typedef struct Nodo{

    int dato;
    struct Nodo* next;
    
} Nodo;

typedef struct listas{

    Nodo* cabeza;
    int longui;

}listas;

listas* crear_lista();
Nodo* crear_nodo(int info);
void inset_one(listas* lista,int valor);
void inset_ulti(listas* lista,int valor);
void inset_posi(listas* lista,int valor, int pos);
void spaw_lis(listas* lista,int pos1,int pos2);
listas* voltear_lista(listas* Orlista,listas* Inlista);
void vaciar_one(listas* lista);
void vaciar_ulti(listas* lista);
void vaciar_posi(listas* lista,int pos);
bool es_vacia_lista(listas* lista);
int lon_lista(listas* lista);
int esta_en_lista(listas* lista,int dato);
int oten_ele_lista(listas* lista,int pos);
void impri_lista(listas* lista);
void elimi_lista(listas* lista);
void ordena(listas* lista);
//void alfavetordena(listas* lista);

#endif
