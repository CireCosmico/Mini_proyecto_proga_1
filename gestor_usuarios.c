#include "gestor_usuarios.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

GestorUsuarios* crear_gestor_usuarios() {
    GestorUsuarios* gestor = (GestorUsuarios*)malloc(sizeof(GestorUsuarios));
    if (gestor) {
        gestor->lista_usuarios = crear_lista();
    }
    return gestor;
}

void liberar_gestor_usuarios(GestorUsuarios* gestor) {
    if (gestor) {
        // Liberar cada usuario individualmente
        while (!lista_vacia(gestor->lista_usuarios)) {
            Usuario* usuario = (Usuario*)eliminar_inicio(gestor->lista_usuarios);
            liberar_usuario(usuario);
        }
        free(gestor->lista_usuarios);
        free(gestor);
    }
}

int cargar_usuarios_desde_archivo(GestorUsuarios* gestor, const char* filename) {
    FILE* archivo = fopen(filename, "r");
    if (!archivo) {
        printf("Error: No se pudo abrir el archivo %s\n", filename);
        return 0;
    }
    
    char cedula[MAX_CEDULA], nombre[MAX_NOMBRE], apellido[MAX_APELLIDO];
    int usuarios_cargados = 0;
    
    while (fscanf(archivo, "%19s %49s %49s", cedula, nombre, apellido) == 3) {
        Usuario* usuario = crear_usuario(cedula, nombre, apellido);
        if (usuario) {
            insertar_final(gestor->lista_usuarios, usuario);
            usuarios_cargados++;
        }
    }
    
    fclose(archivo);
    printf("Usuarios cargados: %d\n", usuarios_cargados);
    return usuarios_cargados;
}

Usuario* buscar_usuario_por_cedula(GestorUsuarios* gestor, const char* cedula) {
    // Crear usuario temporal para búsqueda
    Usuario usuario_temp;
    strncpy(usuario_temp.cedula, cedula, MAX_CEDULA - 1);
    usuario_temp.cedula[MAX_CEDULA - 1] = '\0';
    
    int posicion = buscar_elemento(gestor->lista_usuarios, &usuario_temp, usuario_comparar_por_cedula);
    if (posicion != -1) {
        return (Usuario*)obtener_elemento(gestor->lista_usuarios, posicion);
    }
    return NULL;
}

bool usuario_existe(GestorUsuarios* gestor, const char* cedula) {
    return buscar_usuario_por_cedula(gestor, cedula) != NULL;
}

void mostrar_todos_usuarios(GestorUsuarios* gestor) {
    printf("=== USUARIOS REGISTRADOS ===\n");
    mostrar_lista(gestor->lista_usuarios, usuario_imprimir);
}