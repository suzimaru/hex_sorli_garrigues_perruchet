#ifndef SAUVEGARDE_H__
#define SAUVEGARDE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pile.h"

#define TAILLE_MAX_FICHIER 500
#define TAILLE_PLATEAU 11
#define TAILLE_MAX 9


int plateau[TAILLE_PLATEAU][TAILLE_PLATEAU];

void afficher_plateau(int matrice[TAILLE_PLATEAU][TAILLE_PLATEAU],FILE *fichier);
void sauvegarde_fichier(char name_save[],pile *historique);

void chargement (int *joueur,int plateau[TAILLE_PLATEAU][TAILLE_PLATEAU],char name_save[],int *x,int *y);


#endif
