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
void registro(Usua* usuari_act,int cantida_pre,int cantida_pre_act,int sin_res);
listas* cargar_usuarios_desde_archivo();
Usua registrar_usuario_teclado();
Usua iniciar_se(listas* us);
void leer_reg(listas* us,Colas* sin);
void mostrar_his(Usua* us_act);

Usua con_mas_pre(listas* us,Usua actu);
void total_de_pre(listas* us,int* cont);
void ver_base_datos(Preg_res* ver);


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
    Colas* conla_sin_res = crear_cola();
    int aux = 0,cantidad_preg_pre = 0;
    Usua us_actual,us_conmas;
    leer_reg(lis_us,conla_sin_res);

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
        printf("​3.​ Ver historial de la seccion actual\n");
        printf("4.​ Deshacer última consulta de la seccion actual​\n");
        printf("5.​ Ver estadísticas​​ generales\n");
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

                    printf("haz elegido la 2, iniciado una consulta con la IA\n\n");
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

                if(sesion){

                    printf("haz elegido la 4 para borrar la ulima pregunta de la seccion actual\n\n");
                    // imprimir ultima pregunta y preguntar si eliminarla

                }else {

                    printf("no haz iniciado seccion, por faver inicia seccion en la opcion 1\n\n");

                }

            break;

            case 5:

                us_conmas = con_mas_pre(lis_us,us_actual);

                total_de_pre(lis_us,&cantidad_preg_pre);
                registro(&us_conmas,cantidad_preg_pre,aux,longui_cola(conla_sin_res));

                //aqui hay que imprimir Estadisticas

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

    }

    us_conmas = con_mas_pre(lis_us,us_actual);

    total_de_pre(lis_us,&cantidad_preg_pre);
    registro(&us_conmas,cantidad_preg_pre,aux,longui_cola(conla_sin_res));

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

            ver_base_datos(&conver_prue);

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

void registro(Usua* usuari_act,int cantida_pre,int cantida_pre_act,int sin_res){

    //aqui hay que hacer mas cosas pero para eso nececito las lista

    FILE* arc_esta;

    arc_esta = fopen("Estadisticas.txt","w");

    if(arc_esta==NULL){
        printf("Errorwww\n");
    }else {

        fprintf(arc_esta,"Total de consultas en todas las seciones: %d\n",cantida_pre);
        fprintf(arc_esta,"Total de consultas en esta seccion: %d\n",cantida_pre_act);
        fprintf(arc_esta,"Consultas sin respuesta: %d\n",sin_res );
        fprintf(arc_esta,"Usuario con mas consultas: %s %s %s (%d consultas)",usuari_act->CI,usuari_act->nombre,usuari_act->apellido,usuari_act->cam_pre );
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

void leer_reg(listas* us,Colas* sin){

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

                    if (strcmp(act_pre.repuesta,"Lo siento, no entiendo tu consulta") == 0) {

                        encolar(sin,act_pre);

                    }

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

Usua con_mas_pre(listas* us,Usua actu){

    Usua mas;
    Nodo_lista* aux;
    bool sesion = false;

    if(strcmp(actu.CI,"p") == 0){
        sesion = true;
    }

    if (sesion) {

        mas = us->cabeza->usuario;
        aux = us->cabeza->next;

    }else {

        mas = actu;
        aux = us->cabeza;

    }

    while (aux != NULL) {

        if(mas.cam_pre < aux->usuario.cam_pre ){

            mas = aux->usuario;

        }

        aux = aux->next;

    }

    return mas;
}


void total_de_pre(listas* us,int* cont){
    Nodo_lista* aux;
    aux = us->cabeza;

    while (aux != NULL) {

        *cont = (*cont) + aux->usuario.cam_pre;
        aux = aux->next;

    }

}

void ver_base_datos(Preg_res* ver){

    FILE* arc_bae;
    Preg_res aux;
    bool ban = false;

    arc_bae = fopen("BaseConocimiento.txt","r");

    if(arc_bae == NULL){

        printf("Errorwww\n");

    }else {

        while (!feof(arc_bae) && !ban) {

            fgets(aux.pregunta, 150 ,arc_bae);
            aux.pregunta[strcspn(aux.pregunta,"\n" )] = 0;
            fgets(aux.repuesta, 150 ,arc_bae);
            aux.repuesta[strcspn(aux.repuesta,"\n" )] = 0;

            if (strcmp(aux.pregunta,ver->pregunta) == 0) {

                ban = true;
                strcpy(ver->repuesta,aux.repuesta);

            }

        }

        if (!ban) {

           strcpy(ver->repuesta,"Lo siento, no entiendo tu consulta");

        }

    }

}
