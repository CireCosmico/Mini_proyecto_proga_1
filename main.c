#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "tda/usuario.h"

void menu();
void comsulta();
void guar_histori(Usua usuari_act, );

int main(){

    menu();

    return 0;
}

void menu(){

    int op;
    bool sesion = false;

    while (op != 7) {

        printf("---IA interactiva---\n\n");

        if(sesion){

            printf("no as iniciado sesion en niguna cuenta por favor inicia sesion antes de realizar una consulta\n\n");

        }else {

            printf("ya as inicido sesion, pero si quieres cambiar de cuenta tienes que volver a iniciar sesion\n\n");

        }

        printf("1.​ Iniciar sesión​\n");
        printf("2.​ Realizar consulta​\n");
        printf("​3.​ Ver historial\n");
        printf("4.​ Deshacer última consulta​\n");
        printf("5.​ Ver estadísticas​​\n");
        printf("​6.​ Administrador: ver cola de preguntas sin respuesta y actualizar la base de conocimiento.​\n");
        printf("​7.​ Salir.\n");

        scanf("%d",&op);

        switch (op) {

            case 1:
            break;

            case 2:

                printf("as iniciado una consulta");
                comsulta();

            break;

            case 3:

            break;

            case 4:

            break;

            case 5:

            break;

            case 6:


            break;

            case 7:

                printf("as salido del programa \n");

            break;

            default:

                printf("la opcion no es valida porfavor vuelva a intentar\n\n");

            break;



        }

    }

}

void comsulta(){

    Usua usua_prueba;
    char pre_pru[100],res_prue[100];

    strcpy(usua_prueba.CI,"3000000");
    strcpy(usua_prueba.nombre,"miku");
    strcpy(usua_prueba.apellido,"jimenez");
    strcpy(pre_pru,"eres sonic");
    strcpy(res_prue,"no soy rewirt");

    // aqui deberia una funcion para la conversacion que la imprima y que haga mas cosas




}
