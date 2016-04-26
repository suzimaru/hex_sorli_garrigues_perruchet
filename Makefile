CC=gcc
OPT= `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf -lm
EXEC=essai

all : $(EXEC)

interface_graphique.o: interface_graphique.c
	$(CC) -o interface_graphique.o -c interface_graphique.c $(OPT)

main.o: simple.c
	$(CC) -o simple.o -c simple.c $(OPT)
pile.o: pile.c
	$(CC) -o pile.o -c pile.c $(OPT)
Sauvegarde_histo.c.o: Sauvegarde_histo.c
	$(CC) -o Sauvegarde_histo.o -c Sauvegarde_histo.c

$(EXEC): simple.o interface_graphique.o Sauvegarde_histo.o pile.o
	$(CC) simple.o interface_graphique.o pile.o Sauvegarde_histo.o $(OPT) -o $(EXEC)


clean:
	rm -rf *.o
