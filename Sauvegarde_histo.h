#ifndef SAUVEGARDE_H__
#define SAUVEGARDE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pile.h"

#define TAILLE_MAX_FICHIER 300
#define TAILLE_PLATEAU 11
#define TAILLE_MAX 9


void afficher_plateau(int matrice[TAILLE_PLATEAU][TAILLE_PLATEAU],FILE *fichier);
void sauvegarde(char name_save[],pile *historique);

void chargement (pile *p,char name_save[]);


#endif
