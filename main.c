#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "tda/usuario.h"
#include "tda/pre_res.h"

void menu();
int comsulta(Usua* usuari_act);
void guar_histori(Usua* usuari_act,Preg_res conver_act );
void registro(Usua* usuari_act,int cantida_pre,int sin_res);

int main(){

    menu();

    return 0;
}

void menu(){

    // no tocar aun que usted no lo crea esto funciana si
    char no_usar[50];
    fgets(no_usar, 70 , stdin);

    Usua usua_prueba;
    int cantidad_preg_pre = 2;
    int aux;

    strcpy(usua_prueba.CI,"3000000");
    strcpy(usua_prueba.nombre,"miku");
    strcpy(usua_prueba.apellido,"jimenez");
    usua_prueba.cam_pre = 0;

    int op;
    bool sesion = true;

    while (op != 7) {

        aux = 0;

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

                // abria que ver si es usuario ya esta registrado y registrar la cantida de preguntas que hace el usuario resistradado
                printf("haz iniciado una consulta con la IA\n\n");
                aux = comsulta(&usua_prueba);
                usua_prueba.cam_pre = usua_prueba.cam_pre + aux;
                cantidad_preg_pre = cantidad_preg_pre + aux;

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

                printf("haz salido del programa... \n");

            break;

            default:

                printf("la opcion no es valida porfavor vuelva a intentar\n\n");

            break;
        }

        registro(&usua_prueba,cantidad_preg_pre,0);

    }

}

int comsulta(Usua* usuari_act){

    Preg_res conver_prue;
    bool salir = false;
    int cant_pre = 0;

    // hay que ver el formato de la pregunta

    printf("haz las prugutas que quieras, para salir del chat escribe exit \n\n");

    while (!salir) {

        fgets(conver_prue.pregunta, 70 , stdin);
        conver_prue.pregunta[strcspn(conver_prue.pregunta,"\n" )] = 0;

        if(strcmp(conver_prue.pregunta,"exit") != 0){

            strcpy(conver_prue.repuesta,"no, soy rewirt");

            // aqui deberia una funcion que vea si la respuesta esta en la base de dato

            printf("\nIA: %s\n\n",conver_prue.repuesta);

            cant_pre++;

            guar_histori(usuari_act,conver_prue );

        }else {

            salir = true;
            printf("haz salido del chat\n\n");

        }
    }

    return cant_pre;
}

void guar_histori(Usua* usuari_act,Preg_res conver_act ){

    FILE *arc_coner;

    arc_coner = fopen("Conversaciones.txt","a");

    if(arc_coner==NULL){
        printf("Error\n");
    }else {

        fprintf(arc_coner,"%s %s %s \n",usuari_act->CI,usuari_act->nombre,usuari_act->apellido );
        fprintf(arc_coner,"%s \n",conver_act.pregunta );
        fprintf(arc_coner,"%s \n",conver_act.repuesta );

    }

    fclose(arc_coner);
}

void registro(Usua* usuari_act,int cantida_pre,int sin_res){

    //aqui hay que hacer mas cosas pero para eso nececito las lista

    FILE* arc_esta;

    arc_esta = fopen("Estadisticas.txt","w");

    if(arc_esta==NULL){
        printf("Errorwww\n");
    }else {

        fprintf(arc_esta,"Total de consultas: %d\n",cantida_pre);
        fprintf(arc_esta,"Consultas sin respuesta: %d\n",sin_res );
        fprintf(arc_esta,"Usuario con más consultas: %s %s %s (%d consultas)",usuari_act->CI,usuari_act->nombre,usuari_act->apellido,usuari_act->cam_pre );
    }

    fclose(arc_esta);

}
