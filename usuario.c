#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

Usuario* crear_usuario(const char* cedula, const char* nombre, const char* apellido) {
    Usuario* usuario = (Usuario*)malloc(sizeof(Usuario));
    if (usuario) {
        strncpy(usuario->cedula, cedula, MAX_CEDULA - 1);
        strncpy(usuario->nombre, nombre, MAX_NOMBRE - 1);
        strncpy(usuario->apellido, apellido, MAX_APELLIDO - 1);
        
        // Asegurar terminación nula
        usuario->cedula[MAX_CEDULA - 1] = '\0';
        usuario->nombre[MAX_NOMBRE - 1] = '\0';
        usuario->apellido[MAX_APELLIDO - 1] = '\0';
    }
    return usuario;
}

void liberar_usuario(Usuario* usuario) {
    free(usuario);
}

const char* usuario_obtener_cedula(const Usuario* usuario) {
    return usuario->cedula;
}

const char* usuario_obtener_nombre(const Usuario* usuario) {
    return usuario->nombre;
}

const char* usuario_obtener_apellido(const Usuario* usuario) {
    return usuario->apellido;
}

bool usuario_comparar_por_cedula(void* usuario1, void* usuario2) {
    Usuario* u1 = (Usuario*)usuario1;
    Usuario* u2 = (Usuario*)usuario2;
    return strcmp(u1->cedula, u2->cedula) == 0;
}

void usuario_imprimir(void* usuario) {
    Usuario* u = (Usuario*)usuario;
    printf("Cédula: %s, Nombre: %s, Apellido: %s\n", 
           u->cedula, u->nombre, u->apellido);
}