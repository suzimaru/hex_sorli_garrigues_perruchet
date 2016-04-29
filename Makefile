CC=gcc
OPT= `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -lm -g
EXEC=essai

all : $(EXEC)

interface_graphique.o: interface_graphique.c
	$(CC) -o interface_graphique.o -c interface_graphique.c $(OPT)

main.o: simple.c
	$(CC) -o simple.o -c simple.c $(OPT)

Sauvegarde_histo.o: Sauvegarde_histo.c
	$(CC) -o Sauvegarde_histo.o -c Sauvegarde_histo.c

jeux.o: jeux.c
	$(CC) -o jeux.o -c jeux.c 

victoire.o: victoire.c
	$(CC) -o victoire.o	-c victoire.c 

pile.o: pile.c
	$(CC) -o pile.o	-c pile.c


$(EXEC): simple.o interface_graphique.o jeux.o victoire.o pile.o Sauvegarde_histo.o
	$(CC) simple.o interface_graphique.o jeux.o victoire.o pile.o Sauvegarde_histo.o $(OPT) -o $(EXEC)


clean:
	rm -rf *.o
