# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Ficheiros do projeto
SRCS = main.c funcoes.c
OBJS = $(SRCS:.c=.o)
EXEC = programa

# Regra principal
all: $(EXEC)

# Liga os objetos para gerar o executável
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compila cada ficheiro .c num ficheiro .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza de ficheiros gerados
clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean