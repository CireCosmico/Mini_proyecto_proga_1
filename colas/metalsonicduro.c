#include "cola.h"
#include <stdio.h>
#include <stdbool.h>

int main(){

    Colas* cola = crear_cola();

    encolar(cola,5 );
    encolar(cola,8 );
    encolar(cola,10 );

    printf("primero de la cola %d y su longuitu es de %d \n",octe_primaro_cola(cola),longui_cola(cola));

    /*desencolar(cola);

    printf("primero de la cola %d y su longuitu es de %d \n",octe_primaro_cola(cola),longui_cola(cola));

    desencolar(cola);

    printf("primero de la cola %d y su longuitu es de %d \n",octe_primaro_cola(cola),longui_cola(cola));


    desencolar(cola);

    if(es_vacia_cola(cola)){

        printf("es vacia\n");

    }else {

        printf("no es vacia\n");

    }*/

    inver_cola(cola);

    printf("primero de la cola %d y su longuitu es de %d \n",octe_primaro_cola(cola),longui_cola(cola));

    return 0;
}
