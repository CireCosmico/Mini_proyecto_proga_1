# Makefile para prueba específica de usuarios
CC = gcc
CFLAGS = -Wall -std=c99
OBJS = main_prueba_usuarios.o lista.o usuario.o gestor_usuarios.o

# Archivos de cabecera
HEADERS = lista.h usuario.h gestor_usuarios.h

# Objetivo principal
prueba_usuarios: $(OBJS)
	$(CC) $(CFLAGS) -o prueba_usuarios $(OBJS)

# Dependencias de los objetos
main_prueba_usuarios.o: main_prueba_usuarios.c $(HEADERS)
	$(CC) $(CFLAGS) -c main_prueba_usuarios.c

lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -c lista.c

usuario.o: usuario.c usuario.h
	$(CC) $(CFLAGS) -c usuario.c

gestor_usuarios.o: gestor_usuarios.c gestor_usuarios.h
	$(CC) $(CFLAGS) -c gestor_usuarios.c

# Limpiar archivos compilados
clean:
	rm -f *.o prueba_usuarios

# Ejecutar prueba
run: prueba_usuarios
	./prueba_usuarios

.PHONY: clean run