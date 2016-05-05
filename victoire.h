#ifndef VIC_H__
#define VIC_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "pile.h"


typedef struct Pion_s
{

	int borne;
	int joueur;					// joueur = -1 => case vide | joueur = 0 => joueur1 | joueur = 1 => joueur2
 	int coordonnee_X;
	int coordonnee_Y;

} Case;


int nb_touche( Case plateau[11][11] ,int x,int y);
Case trouver_case( Case plateau[11][11] ,int lvl_ligne, int lvl_colonne,int x,int y) ;
int deplacement_plateau(Case plateau[11][11] ,int x,int y,int borne);
int borne_oppose(pile **p,int joueur);
int victoire(int joueur,pile *p,Case plateau[11][11]);



#endif


