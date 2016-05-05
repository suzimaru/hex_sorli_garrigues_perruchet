#ifndef _pile_H__
#define _pile_H__

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct cell_element{
    int coordonnee_x;
    int coordonnee_y;
    int joueur;
    int borne;
}element;

typedef struct Cell_s
{
	element elt;
	struct Cell_s *next;
} Cell;

typedef struct pile_s
{
	Cell *top;
} pile;


void init(pile *p);
bool estVide (pile *p);
bool pile_Pleine (pile *p);
void affiche_pile (pile *p);
void empiler_pile (pile *p, element e);
element depiler(pile *p);
element sommet (pile *p);
void saisir_pile(pile *p);


#endif
