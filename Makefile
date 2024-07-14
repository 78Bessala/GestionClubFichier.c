# Compilateur et options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Fichiers objets
OBJ = main.o Membres.o Taches.o Ressources.o Stat.o

# Nom de l'exécutable
EXEC = Tp_inf132

# Règle par défaut
all: $(EXEC)

# Règle pour créer l'exécutable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJ)

# Règles pour créer les fichiers objets
main.o: main.c Tp_inf132.h
	$(CC) $(CFLAGS) -c main.c

Membres.o: Membres.c Tp_inf132.h
	$(CC) $(CFLAGS) -c Membres.c

Taches.o: Taches.c Tp_inf132.h
	$(CC) $(CFLAGS) -c Taches.c

Ressources.o: Ressources.c Tp_inf132.h
	$(CC) $(CFLAGS) -c Ressources.c

Stat.o: Stat.c Tp_inf132.h
	$(CC) $(CFLAGS) -c Stat.c

# Règle pour nettoyer les fichiers générés
clean:
	rm -f *.o $(EXEC)