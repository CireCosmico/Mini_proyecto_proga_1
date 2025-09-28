#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gestor_usuarios.h"

void mostrar_menu() {
    printf("\n=== SISTEMA DE GESTIÓN DE USUARIOS ===\n");
    printf("1. Cargar usuarios desde archivo\n");
    printf("2. Mostrar todos los usuarios\n");
    printf("3. Buscar usuario por cédula\n");
    printf("4. Verificar si usuario existe\n");
    printf("5. Salir\n");
    printf("Seleccione una opción: ");
}

void probar_carga_usuarios(GestorUsuarios* gestor) {
    printf("\n--- CARGAR USUARIOS ---\n");
    char filename[100];
    printf("Ingrese el nombre del archivo (o presione Enter para 'Usuarios.txt'): ");
    getchar(); // Limpiar buffer
    fgets(filename, sizeof(filename), stdin);
    
    // Eliminar salto de línea
    if (filename[strlen(filename)-1] == '\n') {
        filename[strlen(filename)-1] = '\0';
    }
    
    // Si no se ingresó nada, usar archivo por defecto
    if (strlen(filename) == 0) {
        strcpy(filename, "Usuarios.txt");
    }
    
    int cargados = cargar_usuarios_desde_archivo(gestor, filename);
    if (cargados > 0) {
        printf("✓ Se cargaron %d usuarios exitosamente\n", cargados);
    } else {
        printf("✗ No se pudieron cargar usuarios del archivo '%s'\n", filename);
        printf("Creando usuarios de ejemplo...\n");
        
        // Crear algunos usuarios de ejemplo
        insertar_final(gestor->lista_usuarios, crear_usuario("12345678", "Maria", "Goncalves"));
        insertar_final(gestor->lista_usuarios, crear_usuario("16735596", "Angel", "Landaeta"));
        insertar_final(gestor->lista_usuarios, crear_usuario("21857646", "Jose", "Cardenas"));
        insertar_final(gestor->lista_usuarios, crear_usuario("87654321", "Ana", "Perez"));
        
        printf("✓ Se crearon 4 usuarios de ejemplo\n");
    }
}

void probar_mostrar_usuarios(GestorUsuarios* gestor) {
    printf("\n--- MOSTRAR TODOS LOS USUARIOS ---\n");
    if (longitud_lista(gestor->lista_usuarios) == 0) {
        printf("No hay usuarios cargados. Use la opción 1 primero.\n");
    } else {
        mostrar_todos_usuarios(gestor);
    }
}

void probar_buscar_usuario(GestorUsuarios* gestor) {
    printf("\n--- BUSCAR USUARIO POR CÉDULA ---\n");
    if (longitud_lista(gestor->lista_usuarios) == 0) {
        printf("No hay usuarios cargados. Use la opción 1 primero.\n");
        return;
    }
    
    char cedula[20];
    printf("Ingrese la cédula a buscar: ");
    scanf("%19s", cedula);
    
    Usuario* encontrado = buscar_usuario_por_cedula(gestor, cedula);
    if (encontrado) {
        printf("✓ USUARIO ENCONTRADO:\n");
        printf("   Cédula: %s\n", usuario_obtener_cedula(encontrado));
        printf("   Nombre: %s\n", usuario_obtener_nombre(encontrado));
        printf("   Apellido: %s\n", usuario_obtener_apellido(encontrado));
    } else {
        printf("✗ Usuario con cédula '%s' no encontrado\n", cedula);
    }
}

void probar_verificar_existencia(GestorUsuarios* gestor) {
    printf("\n--- VERIFICAR EXISTENCIA DE USUARIO ---\n");
    if (longitud_lista(gestor->lista_usuarios) == 0) {
        printf("No hay usuarios cargados. Use la opción 1 primero.\n");
        return;
    }
    
    char cedula[20];
    printf("Ingrese la cédula a verificar: ");
    scanf("%19s", cedula);
    
    if (usuario_existe(gestor, cedula)) {
        printf("✓ El usuario con cédula '%s' SÍ está registrado\n", cedula);
    } else {
        printf("✗ El usuario con cédula '%s' NO está registrado\n", cedula);
    }
}

void crear_archivo_ejemplo() {
    printf("Creando archivo 'Usuarios.txt' de ejemplo...\n");
    FILE* archivo = fopen("Usuarios.txt", "w");
    if (archivo) {
        fprintf(archivo, "12345678 Maria Goncalves\n");
        fprintf(archivo, "16735596 Angel Landaeta\n");
        fprintf(archivo, "21857646 Jose Cardenas\n");
        fprintf(archivo, "87654321 Ana Perez\n");
        fclose(archivo);
        printf("✓ Archivo 'Usuarios.txt' creado exitosamente\n");
    } else {
        printf("✗ No se pudo crear el archivo de ejemplo\n");
    }
}

int main() {
    printf("=== PRUEBA INDEPENDIENTE - MÓDULO DE USUARIOS ===\n");
    printf("Este programa prueba solo la funcionalidad de usuarios\n");
    printf("sin depender del proyecto completo.\n");
    
    // Crear archivo de ejemplo si no existe
    FILE* test = fopen("Usuarios.txt", "r");
    if (!test) {
        crear_archivo_ejemplo();
    } else {
        fclose(test);
    }
    
    // Crear gestor de usuarios
    GestorUsuarios* gestor = crear_gestor_usuarios();
    if (!gestor) {
        printf("Error: No se pudo crear el gestor de usuarios\n");
        return 1;
    }
    
    int opcion;
    do {
        mostrar_menu();
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                probar_carga_usuarios(gestor);
                break;
            case 2:
                probar_mostrar_usuarios(gestor);
                break;
            case 3:
                probar_buscar_usuario(gestor);
                break;
            case 4:
                probar_verificar_existencia(gestor);
                break;
            case 5:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }
    } while(opcion != 5);
    
    // Liberar recursos
    liberar_gestor_usuarios(gestor);
    printf("Recursos liberados. ¡Hasta luego!\n");
    
    return 0;
}