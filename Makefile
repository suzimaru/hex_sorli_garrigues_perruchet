CC=gcc
OPT= `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf
EXEC=essai

all : $(EXEC)

interface_graphique.o: interface_graphique.c
	$(CC) -o interface_graphique.o -c interface_graphique.c $(OPT)

main.o: simple.c
	$(CC) -o simple.o -c simple.c $(OPT)

$(EXEC): simple.o interface_graphique.o
	$(CC) simple.o interface_graphique.o $(OPT) -o $(EXEC)


clean:
	rm -rf *.o
