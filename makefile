# Makefile para proyecto de IA Interactiva
# Compilador y opciones
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LDFLAGS = 

# Nombre del programa
PROGRAM = ia_interactiva

# Archivos fuente
MAIN_SRC = main.c
LISTA_SRC = listas/lista.c
PILA_SRC = pilas/pila.c
COLA_SRC = colas/cola.c

# Archivos objeto
MAIN_OBJ = main.o
LISTA_OBJ = listas/lista.o
PILA_OBJ = pilas/pila.o
COLA_OBJ = colas/cola.o

OBJS = $(MAIN_OBJ) $(LISTA_OBJ) $(PILA_OBJ) $(COLA_OBJ)

# Archivos de cabecera
USER_HEADER = tda/usuario.h
PRE_RES_HEADER = tda/pre_res.h
ESTAD_HEADER = tda/estadisticas.h
LISTA_HEADER = listas/lista.h
PILA_HEADER = pilas/pila.h
COLA_HEADER = colas/cola.h

HEADERS = $(USER_HEADER) $(PRE_RES_HEADER) $(ESTAD_HEADER) $(LISTA_HEADER) $(PILA_HEADER) $(COLA_HEADER)

# Regla principal - compilar todo
all: $(PROGRAM)

# Enlazar el programa final
$(PROGRAM): $(OBJS)
	$(CC) $(OBJS) -o $(PROGRAM) $(LDFLAGS)

# Compilar main
$(MAIN_OBJ): $(MAIN_SRC) $(HEADERS)
	$(CC) $(CFLAGS) -c $(MAIN_SRC) -o $(MAIN_OBJ)

# Compilar lista
$(LISTA_OBJ): $(LISTA_SRC) $(LISTA_HEADER) $(USER_HEADER) $(PILA_HEADER)
	$(CC) $(CFLAGS) -c $(LISTA_SRC) -o $(LISTA_OBJ)

# Compilar pila
$(PILA_OBJ): $(PILA_SRC) $(PILA_HEADER) $(PRE_RES_HEADER)
	$(CC) $(CFLAGS) -c $(PILA_SRC) -o $(PILA_OBJ)

# Compilar cola
$(COLA_OBJ): $(COLA_SRC) $(COLA_HEADER) $(PRE_RES_HEADER)
	$(CC) $(CFLAGS) -c $(COLA_SRC) -o $(COLA_OBJ)

# Limpiar archivos compilados
clean:
	rm -f $(PROGRAM) $(OBJS)

# Ejecutar el programa
run: $(PROGRAM)
	./$(PROGRAM)

# Recompilar desde cero
rebuild: clean all

# Para decirle a make que estas son reglas, no archivos
.PHONY: all clean run rebuild