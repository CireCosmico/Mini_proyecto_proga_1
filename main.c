#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "tda/usuario.h"
#include "tda/pre_res.h"
#include "listas/lista.h"
#include "pilas/pila.h"
#include "colas/cola.h"

void menu();
int comsulta(Usua* usuari_act,Colas* sin,Pilas* ultima);
void guar_histori(Usua* usuari_act,Pilas* ultima);
void registro(Usua* usuari_act,int cantida_pre,int cantida_pre_act,int sin_res);
listas* cargar_usuarios_desde_archivo();
Usua registrar_usuario_teclado();
Usua* iniciar_se(listas* us);
void leer_reg(listas* us,Colas* sin);
void mostrar_his(Usua* us_act);

Usua con_mas_pre(listas* us);
int total_de_pre(listas* us);
void ver_base_datos(Preg_res* ver);
void amini_base(Colas* sin);
void act_base(Preg_res poner);
void eliminar_ul(Usua* us,Pilas* ultima);
void ver_esta();


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
    Pilas* ultima = crear_pila();
    Colas* conla_sin_res = crear_cola();
    int aux = 0,cantidad_preg_pre = 0;
    Usua* us_actual = (Usua*)malloc(sizeof(Usua));;
    Usua us_conmas;
    leer_reg(lis_us,conla_sin_res);

    strcpy(us_actual->CI,"p");

    int op;
    bool sesion = false;

    while (op != 7) {

        aux = 0;

        if(strcmp(us_actual->CI,"p") != 0){
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
        printf("4.​ Deshacer última consulta de la seccion actual​ y si haz echo preguntas hoy\n");
        printf("5.​ Ver estadísticas​​ generales\n");
        printf("​6.​ Administrador: ver cola de preguntas sin respuesta y actualizar la base de conocimiento.​\n");
        printf("​7.​ Salir.\n");

        scanf("%d",&op);

        switch (op) {

            case 1:

                printf("haz elegido la 1 para iniciar seccion\n\n");
                guar_histori(us_actual,ultima );
                free(us_actual);
                us_actual = iniciar_se(lis_us);

            break;

            case 2:

                if(sesion){

                    printf("haz elegido la 2, iniciado una consulta con la IA\n\n");
                    aux = comsulta(us_actual,conla_sin_res,ultima);
                    us_actual->cam_pre = us_actual->cam_pre + aux;

                }else {

                    printf("no haz iniciado seccion, por faver inicia seccion en la opcion 1\n\n");

                }


            break;

            case 3:

                if(sesion){

                    printf("haz elegido la 3 para ver el historial de la cuenta actual\n\n");
                    mostrar_his(us_actual);

                }else {

                    printf("no haz iniciado seccion, por faver inicia seccion en la opcion 1\n\n");

                }



            break;

            case 4:

                if(sesion){

                    printf("haz elegido la 4 para borrar la ulima pregunta de la seccion actual\n\n");
                    // imprimir ultima pregunta y preguntar si eliminarla
                    eliminar_ul(us_actual,ultima);

                }else {

                    printf("no haz iniciado seccion, por faver inicia seccion en la opcion 1\n\n");

                }

            break;

            case 5:

                us_conmas = con_mas_pre(lis_us);

                cantidad_preg_pre = total_de_pre(lis_us);
                registro(&us_conmas,cantidad_preg_pre,aux,longui_cola(conla_sin_res));

                ver_esta();
                //aqui hay que imprimir Estadisticas

            break;

            case 6:

                printf("haz elegido la 6 para Administrar la base de datos\n\n");
                amini_base(conla_sin_res);

            break;

            case 7:

                printf("haz salido del programa... \n");

            break;

            default:

                printf("la opcion no es valida porfavor vuelva a intentar\n\n");

            break;
        }

    }

    us_conmas = con_mas_pre(lis_us);

    cantidad_preg_pre = total_de_pre(lis_us);
    registro(&us_conmas,cantidad_preg_pre,aux,longui_cola(conla_sin_res));

    guar_histori(us_actual,ultima );

}

int comsulta(Usua* usuari_act,Colas* sin,Pilas* ultima){

    Preg_res conver_prue;
    bool salir = false;
    int cant_pre = 0;

    // hay que ver el formato de la pregunta

    printf("haz las prugutas que quieras, para salir del chat escribe exit \n\n");

    // no tocar
    fgets(conver_prue.pregunta, 70 , stdin);

    while (!salir) {

        printf("Tu: ");
        fgets(conver_prue.pregunta, 70 , stdin);
        conver_prue.pregunta[strcspn(conver_prue.pregunta,"\n" )] = 0;

        if(strcmp(conver_prue.pregunta,"exit") != 0){

            ver_base_datos(&conver_prue);

            printf("\nIA: %s\n\n",conver_prue.repuesta);
            apilar(usuari_act->historial,conver_prue );
            apilar(ultima,conver_prue );

            if (strcmp(conver_prue.repuesta,"Lo siento, no entiendo tu consulta") == 0) {

                encolar(sin,conver_prue );

            }

            cant_pre++;

        }else {

            salir = true;
            printf("haz salido del chat\n\n");

        }
    }

    return cant_pre;
}

void guar_histori(Usua* usuari_act,Pilas* ultima ){

    FILE *arc_coner;
    Preg_res conver_act;
    Pilas* aux = crear_pila();

    inver_pila(ultima,aux);

    arc_coner = fopen("Conversaciones.txt","a");

    while (!es_vacia_pila(aux)) {

        if(arc_coner==NULL){
            printf("Error\n");
        }else {

            conver_act = octen_tope(aux);

            fprintf(arc_coner,"%s %s %s\n",usuari_act->CI,usuari_act->nombre,usuari_act->apellido );
            fprintf(arc_coner,"%s\n",conver_act.pregunta );
            fprintf(arc_coner,"%s\n",conver_act.repuesta );

            desapilar(aux);

        }

    }

    fclose(arc_coner);
}

void registro(Usua* usuari_act,int cantida_pre,int cantida_pre_act,int sin_res){

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

Usua* iniciar_se(listas* us){
    Usua act;
    Usua* veri;
    bool esta = false;

    do {

        printf("por faver incresas los datos\n");

        act = registrar_usuario_teclado();

        veri = buscar_usuario(us,act );

        if(strcmp(veri->CI,"no") != 0){

            printf("\nusuario en contrado, volviendo al menu\n\n");
            esta = true;

        }else {

            printf("\nusuario no entrado por favor increce los datos bien\n\n");

        }

    }while (!esta);



    return veri;
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

        aux = us->cabeza;
        poner = false;

        while (fscanf(arc_c,"%s",actual_us.CI) == !feof(arc_c)) {



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

                        ver_base_datos(&act_pre);

                        if (strcmp(act_pre.repuesta,"Lo siento, no entiendo tu consulta") == 0) {

                            encolar(sin,act_pre);

                        }

                    }

                    poner = true;

                }else {

                    aux = aux->next;

                }
            }

            aux = us->cabeza;
            poner = false;

        }

    }

    fclose(arc_c);

}

void mostrar_his(Usua* us_act){

    Pilas* aux = crear_pila();
    Preg_res impri;

    printf("---historial---\n\n");

    inver_pila(us_act->historial,aux );

    while (!es_vacia_pila(aux)) {

        impri = octen_tope(aux);
        desapilar(aux);
        printf("Tu: %s\n",impri.pregunta);
        printf("IA: %s\n\n",impri.repuesta);
        apilar(us_act->historial,impri );

    }
}

Usua con_mas_pre(listas* us){

    Usua mas;
    Nodo_lista* aux;

        mas = us->cabeza->usuario;
        aux = us->cabeza->next;

    while (aux != NULL) {

        if(mas.cam_pre < aux->usuario.cam_pre ){

            mas = aux->usuario;

        }

        aux = aux->next;

    }

    return mas;
}

int total_de_pre(listas* us){
    Nodo_lista* aux;
    aux = us->cabeza;
    int cont = 0;

    while (aux != NULL) {

        cont = cont + aux->usuario.cam_pre;
        aux = aux->next;

    }

    return cont;
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

    fclose(arc_bae);

}

void amini_base(Colas* sin){

    Preg_res aux;
    char yn[5];
    bool bany;

    printf("---Administrador---\n\n");
    fgets(aux.repuesta, 70 , stdin);
    bany =false;

    if (es_vacia_cola(sin)) {

        printf("no hay preguntas sin respuestas\n");
        printf("saliendo de Administrador de repuestas...\n\n");

    }

    while (!es_vacia_cola(sin) && !bany) {



        aux = octe_primaro_cola(sin);

        printf("hay en total %d preguntas sin respuesta en el sistema\n\n",longui_cola(sin));

        printf("la primera de todas es: %s \n\n",aux.pregunta);

        printf("si desea reponder la, solo tienes que escribir la y se guardara en el sistema\n");
        printf("si no quieres reporder la escribe exit\n\n");

        printf("R:");
        fgets(aux.repuesta, 70 , stdin);
        aux.repuesta[strcspn(aux.repuesta,"\n" )] = 0;

        if(strcmp(aux.repuesta,"exit") != 0){

            while (!bany) {

                printf("\n|%s|\n\n",aux.repuesta);
                printf("si esa es la repuesta decea para esa pregunta: %s \n",aux.pregunta);
                printf("escriba Yes para si y No para no\n");
                scanf("%s",yn);

                if (strcmp(yn,"Yes") == 0) {

                    printf("ok, repuesta guardad\n");
                    act_base(aux);
                    bany = true;
                    desencolar(sin);

                }else if (strcmp(yn,"No") == 0) {

                    printf("ok, repuesta descartada\n");
                    bany = true;

                }else {

                    printf("solo puedes escribir Yes o No\n");

                }

            }

            if (es_vacia_cola(sin)) {

                printf("ya no hay mas preguntas\n");

            }

        }else {

            bany = true;

        }

        printf("saliendo de Administrador de repuestas...\n\n");

    }

}

void act_base(Preg_res poner){

    FILE *arc_base;

    arc_base = fopen("BaseConocimiento.txt","a");

    if(arc_base==NULL){
        printf("Error\n");
    }else {

        fprintf(arc_base,"%s\n",poner.pregunta);
        fprintf(arc_base,"%s\n",poner.repuesta);
    }

    fclose(arc_base);

}

void eliminar_ul(Usua* us,Pilas* ultima){

    Preg_res ult = octen_tope(us->historial);
    bool yes = false,val = false;
    char aux[70];

    fgets(aux, 70 , stdin);

    if (!es_vacia_pila(ultima)) {

        do {

            printf("---eliminar ultima pregunta---\n\n");

            printf("su ultima pregunta fue: %s\n",ult.pregunta);
            printf("con la repuesta: %s\n\n",ult.repuesta);

            printf("escriba Yes para eliminarla o escriba exit para no eliminarla y salir de la opccion\n\n");

            printf("Op:");

            fgets(aux, 70 , stdin);
            aux[strcspn(aux,"\n" )] = 0;

            if(strcmp(aux,"exit") == 0){

                val = true;

            }else if (strcmp(aux,"Yes") == 0) {

                val = true;
                yes = true;

            }else {

                printf("opcion no validad, vuelve a eligir\n\n");

            }

            if (yes) {

                desapilar(ultima);
                desapilar(us->historial);
                printf("la consulta a sido elimansada, saliendo de la opcion...\n\n");

            }else {

                printf("la consulta no a sido elimansada, saliendo de la opcion...\n\n");

            }

        }while (!val);


    }else {

        printf("no hay nada que eliminar, saliendo de la opcion...\n\n");

    }

}

void ver_esta(){

    FILE* arc_esta;
    char aux[150];

    arc_esta = fopen("Estadisticas.txt","r");

    if(arc_esta==NULL){
        printf("Errorwww\n");
    }else {

        printf("\n---las estadísticas son la siguientes---\n\n");

        while (!feof(arc_esta)) {

            fgets(aux, 150 , arc_esta);
            aux[strcspn(aux,"\n" )] = 0;
            printf("%s\n",aux);

        }

        printf("\n");

    }

    printf("saliendo de la opcion\n\n");

    fclose(arc_esta);

}
