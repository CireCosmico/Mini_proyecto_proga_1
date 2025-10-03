#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "tda/usuario.h"
#include "tda/pre_res.h"
#include "listas/lista.h"
#include "pilas/pila.h"
#include "colas/cola.h"

void menu();
int comsulta(Usua* usuari_act);
void guar_histori(Usua* usuari_act,Preg_res conver_act );
void registro(Usua* usuari_act,int cantida_pre,int sin_res);
listas* cargar_usuarios_desde_archivo();
Usua registrar_usuario_teclado();
Usua iniciar_se(listas* us);
void leer_reg(listas* us);
void mostrar_his(Usua* us_act);

int main(){

    menu();

    return 0;
}

// Función para cargar usuarios desde archivo a la lista
listas* cargar_usuarios_desde_archivo(){
    listas* lista = crear_lista();
    FILE* archivo = fopen("Usuarios.txt", "r");
    
    if(archivo == NULL){
        printf("Error: No se pudo abrir el archivo Usuarios.txt\n");
        return lista;
    }
    
    char CI[MAX], nombre[MAX], apellido[MAX];
    
    while(fscanf(archivo, "%s %s %s", CI, nombre, apellido) == 3){
        Usua nuevo_usuario;
        strcpy(nuevo_usuario.CI, CI);
        strcpy(nuevo_usuario.nombre, nombre);
        strcpy(nuevo_usuario.apellido, apellido);
        
        inset_one(lista, nuevo_usuario);
    }
    
    fclose(archivo);
    return lista;
}

// Función para registrar nuevo usuario por teclado
Usua registrar_usuario_teclado(){
    Usua nuevo_usuario;
    
    printf("Ingrese la cedula: ");
    scanf("%s", nuevo_usuario.CI);
    
    printf("Ingrese el nombre: ");
    scanf("%s", nuevo_usuario.nombre);
    
    printf("Ingrese el apellido: ");
    scanf("%s", nuevo_usuario.apellido);
    
    return nuevo_usuario;
}



void menu(){

    // no tocar aun que usted no lo crea esto funciana si

    listas* lis_us = cargar_usuarios_desde_archivo();
    int aux,cantidad_preg_pre;
    Usua us_actual;
    leer_reg(lis_us);

    strcpy(us_actual.CI,"p");

    int op;
    bool sesion = false;

    while (op != 7) {

        aux = 0;

        if(strcmp(us_actual.CI,"p") != 0){
            sesion = true;
        }

        printf("---IA interactiva---\n\n");

        if(sesion){

            printf("ya as inicido sesion, pero si quieres cambiar de cuenta tienes que volver a iniciar sesion\n\n");

        }else {

            printf("no as iniciado sesion en niguna cuenta por favor inicia sesion antes de realizar una consulta\n\n");

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

                printf("haz elegido la 1 para iniciar seccion\n\n");
                us_actual = iniciar_se(lis_us);

            break;

            case 2:

                if(sesion){

                    printf("haz iniciado una consulta con la IA\n\n");
                    aux = comsulta(&us_actual);
                    us_actual.cam_pre = us_actual.cam_pre + aux;
                    cantidad_preg_pre = cantidad_preg_pre + aux;

                }else {

                    printf("no haz iniciado seccion, por faver inicia seccion en la opcion 1\n\n");

                }


            break;

            case 3:

                if(sesion){

                    printf("haz elegido la 3 para ver el historial de la cuenta actual\n\n");
                    mostrar_his(&us_actual);

                }else {

                    printf("no haz iniciado seccion, por faver inicia seccion en la opcion 1\n\n");

                }



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

        registro(&us_actual,cantidad_preg_pre,0);

    }

}

int comsulta(Usua* usuari_act){

    Preg_res conver_prue;
    bool salir = false;
    int cant_pre = 0;

    // hay que ver el formato de la pregunta

    printf("haz las prugutas que quieras, para salir del chat escribe exit \n\n");

    // no tocar
    fgets(conver_prue.pregunta, 70 , stdin);

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

Usua iniciar_se(listas* us){
    Usua act;
    bool esta = false;

    do {

        printf("por faver incresas los datos\n");

        act = registrar_usuario_teclado();

        act = buscar_usuario(us,act );

        if(strcmp(act.CI,"no") != 0){

            printf("\nusuario en contrado\n\n");
            act.cam_pre =
            esta = true;

        }else {

            printf("\nusuario no entrado por favor increce los datos bien\n\n");

        }

    }while (!esta);



    return act;
}

void leer_reg(listas* us){

    FILE* arc_c;
    Usua actual_us;
    Preg_res act_pre;
    Nodo_lista* aux;
    bool poner = false;

    arc_c = fopen("Conversaciones.txt","r");

    if(arc_c==NULL){
        printf("Errorwww\n");
    }else {


        while (fscanf(arc_c,"%s",actual_us.CI) == !feof(arc_c) ) {

            aux = us->cabeza;
            poner = false;

            fscanf(arc_c,"%s",actual_us.nombre);
            fscanf(arc_c,"%s",actual_us.apellido);

            fgets(act_pre.pregunta, 150 ,arc_c);

            fgets(act_pre.pregunta, 150 ,arc_c);
            fgets(act_pre.repuesta, 150 ,arc_c);
            act_pre.pregunta[strcspn(act_pre.pregunta,"\n" )] = 0;
            act_pre.repuesta[strcspn(act_pre.repuesta,"\n" )] = 0;

            while (!poner && aux != NULL) {

                if(strcmp(aux->usuario.CI, actual_us.CI) == 0 &&
                    strcmp(aux->usuario.nombre, actual_us.nombre) == 0 &&
                    strcmp(aux->usuario.apellido, actual_us.apellido) == 0){

                    apilar(aux->usuario.historial,act_pre);
                    aux->usuario.cam_pre++;
                    poner = true;

                }else {

                    aux = aux->next;

                }
            }

        }

    }

}

void mostrar_his(Usua* us_act){

    Pilas* aux = crear_pila();
    Preg_res impri;

    printf("---historial---\n\n");

    inver_pila(us_act->historial,aux );

    while (!es_vacia_pila(aux)) {

        impri = octen_tope(aux);
        desapilar(aux);
        printf("tu: %s\n",impri.pregunta);
        printf("IA: %s\n\n",impri.repuesta);
        apilar(us_act->historial,impri );

    }
}
