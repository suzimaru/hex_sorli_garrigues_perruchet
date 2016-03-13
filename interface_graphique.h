#ifndef _INTERFACE_H__
#define _INTERFACE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
 
#include <SDL/SDL.h>
#include <SDL/SDL_keysym.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
 
#define WINHI 600 // window height
#define WINWI 800 // window width
 
SDL_Rect position_fond,posTexte1,posTexte_menu,posTexte_auteur,posJouer, posCharger, posQuitter, posHvsH, posHvsIA1, posHvsIA2, posretour;

typedef struct
{
	int h, w;
}	Dimensions;
 
typedef struct 
{
	int x,y;
}	Clic;
 SDL_Surface *ecran, *texte1, *texte_menu, *texte_auteur, *jouer, *charger, *quitter, *image_fond, *HvsH, *HvsIA1, *HvsIA2, *retour; // quelques surfaces
  Dimensions fenetre; // main window


int clic_Valide (Clic c, int borneInfX, int borneInfY, int borneSupX, int borneSupY);
void affichage (); 
void clean (int menu);
void affichage_menu_principal(int menu);
#endif
