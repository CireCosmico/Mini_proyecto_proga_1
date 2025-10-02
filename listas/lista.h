#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdbool.h>
#include "../tda/usuario.h"

/*recuerda que cuabo tengo que modificar el Nodo no le ponga cosas adentro, solo crea un nuevo struct y ese ponlo adentro
ejem: cancion con el nombre de la cancion del autor y la duracion y eso es valor que estara adentro del Nodo (No como puntero, si no como valor)
cuando devuelva devuelve que este adentro del nodo no el nodo por eso es iportante crear el tipo de dato, lo puedes hacer por valor o puntero
es preferible devolver punteros ya que si encuantra el elemnto que delvuelva NULL como no entontado aun que si tenes errores en mejor trabajer com varieble*/

typedef struct Nodo_lista{

    Usua usuario;
    struct Nodo_lista* next;
    
} Nodo_lista;

typedef struct listas{

    Nodo_lista* cabeza;
    int longui;

}listas;

listas* crear_lista();
Nodo_lista* crear_nodo_l(Usua info);
void inset_one(listas* lista,Usua info);

bool es_vacia_lista(listas* lista);
int lon_lista(listas* lista);
bool esta_en_lista(listas* lista,Usua dato);

void impri_lista(listas* lista);
void elimi_lista(listas* lista);
Usua* buscar_usuario(listas* lista, char* CI, char* nombre, char* apellido);
void elimi_lista(listas* lista);

#endif
