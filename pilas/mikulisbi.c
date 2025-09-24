#include "pila.h"
#include <stdio.h>
#include <stdbool.h>

int main(){
    //prue

    Pilas* pila = crear_pila();
    Pilas* pila2 = crear_pila();

    apilar(pila,5 );

    printf("tope de la pila %d y su  longuitu es de %d \n",octen_tope(pila),longui_pila(pila));

    apilar(pila,7 );

    printf("tope de la pila %d y su  longuitu es de %d \n",octen_tope(pila),longui_pila(pila));

    /*desapilar(pila);

    printf("tope de la pila %d y su  longuitu es de %d  \n",octen_tope(pila),longui_pila(pila));

    if(es_vacia_pila(pila)){
        printf("es vavia \n");
    }else {
        printf("no es vavia \n");
    }

    elimi_pila(pila);

    if(es_vacia_pila(pila)){
        printf("es vavia \n");
    }*/

    inver_pila(pila,pila2 );

    printf("tope de la pila %d y su  longuitu es de %d \n",octen_tope(pila2),longui_pila(pila2));

    return 0;
}
