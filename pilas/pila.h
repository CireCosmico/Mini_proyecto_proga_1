#ifndef PILA_H
#define PILA_H

#include <stdlib.h>
#include <stdbool.h>
#include "../tda/pre_res.h"

/*recuerda que cuabo tengo que modificar el Nodo no le ponga cosas adentro, solo crea un nuevo struct y ese ponlo adentro
 e jem: cancion con el nombre de la cancion del autor y la duracion y eso es valor que estara adentro del Nodo (No como puntero, si no como valor)*
 cuando devuelva devuelve que este adentro del nodo no el nodo por eso es iportante crear el tipo de dato, lo puedes hacer por valor o puntero
 es preferible devolver punteros ya que si encuantra el elemnto que delvuelva NULL como no entontado*/

typedef struct Nodo_Pila{

    Preg_res his;
    struct Nodo_Pila* next;

} Nodo_Pila;

typedef struct Pila{

    Nodo_Pila* tope;
    int longui;

} Pilas;

Pilas* crear_pila();
Nodo_Pila* crear_nodo_p(Preg_res valor);
void apilar(Pilas* pila,Preg_res valor);
void desapilar(Pilas* pila);
void inver_pila(Pilas* pila1,Pilas* pila2);
int longui_pila(Pilas* pila);
bool es_vacia_pila(Pilas* pila);
Preg_res octen_tope(Pilas* pila);
void elimi_pila(Pilas* pila);

#endif
