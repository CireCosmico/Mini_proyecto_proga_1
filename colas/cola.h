#ifndef COLA_H
#define COLA_H

#include <stdlib.h>
#include <stdbool.h>
#include "../tda/pre_res.h"

/*recuerda que cuabo tengo que modificar el Nodo no le ponga cosas adentro, solo crea un nuevo struct y ese ponlo adentro
 e jem: cancion con el nombre de la cancion del autor y la duracion y eso es valor que estara adentro del Nodo (No como puntero, si no como valor)*
 cuando devuelva devuelve que este adentro del nodo no el nodo por eso es iportante crear el tipo de dato, lo puedes hacer por valor o puntero
 es preferible devolver punteros ya que si encuantra el elemnto que delvuelva NULL como no entontado*/

typedef struct Nodo_cola{

    Preg_res sin_res;
    struct Nodo_cola* next;

} Nodo_cola;

typedef struct Colas{

    Nodo_cola* primero;
    Nodo_cola* ultimo;
    int longui;

} Colas;

Colas* crear_cola();
Nodo_cola* crear_nodo_c(Preg_res info);
void encolar(Colas* cola,Preg_res valor);
void desencolar(Colas* cola);
Preg_res octe_primaro_cola(Colas* cola);
Preg_res despacho(Colas* cola);
int longui_cola(Colas* cola);
bool es_vacia_cola(Colas* cola);
void elim_cola(Colas* cola);
void inver_cola(Colas* cola);

#endif
