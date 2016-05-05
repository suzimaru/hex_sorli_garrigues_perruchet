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
#include "jeux.h"
#include "victoire.h"
#include "pile.h"
#include "Sauvegarde_histo.h"
//#include "Sauvegarde_histo.h"

  // sudo apt-get install libsdl1.2-dev libsdl-mixer1.2-dev libsdl-image1.2-dev libsdl-ttf2.0-dev


#define WINHI 600 // window height
#define WINWI 800 // window width

typedef struct { int h, w; } Dimensions;

typedef struct { int x, y; } Clic;

SDL_Surface *ecran, *texte1, *texte_menu, *texte_auteur, *jouer, *charger,
    *quitter, *image_fond, *HvsH, *HvsIA1, *HvsIA2, *IAvsIA, *retour,
    *niveau_premier_IA, *niveau_deuxieme_IA, *niveau, *PLATEAU, *pion_bleu, *pion_rouge,
    *sauvegarder, *undo, *enum_save, *pion_annule, *arriere, *info_joueur, *info_coup, *cacheur, *info_pion, *cacheur2 ;

SDL_Rect position_fond, posTexte1, posTexte_menu, posTexte_auteur, posJouer,
    posCharger, posQuitter, posHvsH, posHvsIA1, posHvsIA2, posIAvsIA, posretour,
    posNiveau, pos1IA, pos2IA, posPlateau, pos_Pion, 
    posUndo, pos_enum_save, posSauvegarder, pos_Arriere, pos_info_joueur, pos_info_coup, pos_cacheur, pos_info_pion, pos_cacheur2;

Dimensions fenetre; // main window

int souris_Dessus(Clic c, int menu, int borneInfX, int borneInfY, int borneSupX,
                  int borneSupY);
int clic_Valide(Clic c, int borneInfX, int borneInfY, int borneSupX,
                int borneSupY);
void affichage();
void clean(int menu);
void affichage_menu(int menu);
void Jouer (int *nb_joueur, int *nb_pions, Clic c, int *lig, int *col, int *annule, Case plateau[11][11]);
void Charge_plateau(int *nb_pions, Clic c,Case plateau[11][11],int lig,int col, int *nb_joueur);
#endif
