# Nome do executável
EXEC = tp2

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c99

# Arquivos fonte
SRCS = main.c ProgA.c ProgD.c uteis.c

# Arquivos objeto (compilados)
OBJS = $(SRCS:.c=.o)

# Arquivos cabeçalho
HDRS = estrategias.h uteis.h

# Regra principal (default) para compilar o executável
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Regra para compilar arquivos .c em .o
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos compilados
clean:
	rm -f $(OBJS) $(EXEC)

# Regra de 'phony' para evitar conflitos com arquivos com nomes similares
.PHONY: clean