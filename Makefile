# Makefile pour le projet de calcul de somme de matrice

# Compilateur
CC = gcc

# Flags de compilation : -Wall pour les warnings, -g pour le debug, -pthread pour la librairie Pthreads
CFLAGS = -Wall -g -pthread

# Fichiers sources
SRCS = main.c matrix.c calculator.c

# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Nom de l'exécutable final
TARGET = tp3p55

# Règle par défaut : construire l'exécutable
all: $(TARGET)

# Règle pour lier les fichiers objets et créer l'exécutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Règle pour compiler les fichiers .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(OBJS) $(TARGET)

# Pour indiquer que 'all' et 'clean' ne sont pas des fichiers
.PHONY: all clean
