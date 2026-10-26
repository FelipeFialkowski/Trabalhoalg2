# Compilador e flags
CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11 -MMD -MP

# Diretorio dos objetos
OBJ_DIR = obj

# Arquivos do projeto
SRCS    = main.c funcoes.c SortFuncoes.c
OBJS    = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS    = $(OBJS:.o=.d)
EXEC    = programa

# Regra principal
all: $(EXEC)

# Liga os objetos para gerar o executavel
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compila cada .c em um .o dentro de obj/
# (o "|" cria obj/ so se nao existir, sem forcar recompilacao)
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Cria o diretorio de objetos
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Executa o programa
run: $(EXEC)
	./$(EXEC)

# Limpeza de arquivos gerados
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

# Inclui as dependencias de headers geradas pelo -MMD
-include $(DEPS)

.PHONY: all run clean