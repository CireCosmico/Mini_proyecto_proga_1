#include "lista.h"
#include <stdio.h>
#include <stdbool.h>

int main(){

    listas* lista = crear_lista();
    listas* listab = crear_lista();

    inset_one(lista,5 );

    //printf("el valor de mi lista %d de longuitu %d \n",lista->cabeza->dato,lista->longui);
    inset_one(lista,7 );

    //printf("el valor de mi lista %d de longuitu %d \n",lista->cabeza->dato,lista->longui);

    //vacia_one(lista);
    //printf("el valor de mi lista %d de longuitu %d \n",lista->cabeza->dato,lista->longui);
    //vaciar_one(lista);

    elimi_lista(lista);

    bool a=es_vacia_lista(lista);
    if(a){
        printf("es vacia\n");
    }else {
        printf("no es vacia\n");
    }

    inset_one(lista, 8);

    //printf("longitu de lista %d \n",lon_lista(lista));

    //impri_lista(lista);

    //inset_ulti(lista,10);

    //printf("\n\n");

    //impri_lista(lista);

    //vaciar_one(lista);
    //vaciar_one(lista);
    //vaciar_one(lista);

    //printf("longitu de lista %d \n",lon_lista(lista));

    //printf("el elemento 7 esta en posicion: %d \n\n",esta_en_lista(lista,7 ));

    inset_ulti(lista,10 );

    //printf("que hay en la ps 3 en la lista %d \n",oten_ele_lista(lista,3 ));

    inset_posi(lista,12 ,5);

    impri_lista(lista);

    //printf("\n\n");

    vaciar_posi(lista, 5);

    //spaw_lis(lista,2 ,5 );

    //impri_lista(lista);

    printf("\n\n");

    impri_lista(lista);

    //listab = voltear_lista(lista,listab );

    //impri_lista(listab);

    //printf("longitu de lista %d \n",lon_lista(listab));


   return 0;
}
