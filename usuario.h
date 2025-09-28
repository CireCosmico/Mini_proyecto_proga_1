#ifndef USUARIO_H
#define USUARIO_H
#include <stdbool.h>
#define MAX_CEDULA 20
#define MAX_NOMBRE 50
#define MAX_APELLIDO 50

typedef struct {
    char cedula[MAX_CEDULA];
    char nombre[MAX_NOMBRE];
    char apellido[MAX_APELLIDO];
} Usuario;

// Constructor y destructor
Usuario* crear_usuario(const char* cedula, const char* nombre, const char* apellido);
void liberar_usuario(Usuario* usuario);

// Primitivas de consulta
const char* usuario_obtener_cedula(const Usuario* usuario);
const char* usuario_obtener_nombre(const Usuario* usuario);
const char* usuario_obtener_apellido(const Usuario* usuario);

// Primitivas de comparación
bool usuario_comparar_por_cedula(void* usuario1, void* usuario2);

// Primitivas de impresión
void usuario_imprimir(void* usuario);

#endif // USUARIO_H