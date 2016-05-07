#ifndef JEU_H__
#define JEU_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "pile.h"
#include "victoire.h"
#include <time.h>


Case init_case();

void init_plateau(Case plateau[11][11]);


void remplir(int X,int Y,int joueur,Case plateau[11][11] );
int plein(int X,int Y,Case  plateau[11][11] );
int plateau_plein (Case plateau[11][11]);

int verif_borne(int y, int x,int couleur);					// Vérifie si un coup joué est sur une borne

element Conversion_elt (int Y,int X,int couleur) ;		// Met les coordonnée dans la structure element
void enregistre_coup(pile *p,int Y,int X,int couleur);

int choix_joueur();
void faire_un_coup(int Y,int X,int joueur,Case plateau[11][11],pile **p);
int jeux(int Y,int X, int joueur ,pile *p,Case plateau[11][11]);




#endif