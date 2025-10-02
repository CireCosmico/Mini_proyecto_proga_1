#ifndef GESTOR_USUARIOS_H
#define GESTOR_USUARIOS_H

#include "usuario.h"
#include "lista.h"

typedef struct {
    listas* lista_usuarios;
} GestorUsuarios;

// Constructor y destructor
GestorUsuarios* crear_gestor_usuarios();
void liberar_gestor_usuarios(GestorUsuarios* gestor);

// Primitivas principales (según MiniProyecto)
int cargar_usuarios_desde_archivo(GestorUsuarios* gestor, const char* filename);
Usuario* buscar_usuario_por_cedula(GestorUsuarios* gestor, const char* cedula);
bool usuario_existe(GestorUsuarios* gestor, const char* cedula);

// Primitivas de utilidad
void mostrar_todos_usuarios(GestorUsuarios* gestor);

#endif // GESTOR_USUARIOS_H