# Makefile pour le projet de calcul de somme de matrice

CC = gcc
CFLAGS = -Wall -g -pthread
SRCS = main.c matrix.c calculator.c
OBJS = $(SRCS:.c=.o)
TARGET = tp3p55


all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
