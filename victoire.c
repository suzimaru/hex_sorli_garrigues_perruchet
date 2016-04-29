#include "victoire.h"

int nb_touche(
    Case plateau[11][11], int x,
    int y)  // Compte le nombre de case adjacente d'une case du plateau donnée
{
  int touche = 0;

  int k = y;
  int i;
  for (i = x; i <= x + 1; i++) {
    if (plateau[i][k].joueur == plateau[x][y].joueur) touche++;
  }

  for (i = x - 1; i <= x + 1; i++)

  {
    if (plateau[i][k].joueur == plateau[x][y].joueur) touche++;
  }

  k = y + 1;
  for (i = x - 1; i <= x; i++) {
    if (plateau[i][k].joueur == plateau[x][y].joueur) touche++;
  }

  return (touche - 1);  //*(-1) Durant l'éxécution, le pion se compte lui même.
}

Case trouver_case(Case plateau[11][11], int lvl_ligne, int lvl_colonne, int x,
                  int y)  // Au premier lancement lvl_ligne = lvl_colonne = 0
{
  Case new_case;
  new_case.coordonnee_Y = 0;
  new_case.coordonnee_X = 0;
  new_case.borne = 0;
  new_case.joueur = -1;

  if (lvl_ligne == 0) {
    if (lvl_colonne ==
        1)  // Le programme recherche case par case s'il y a une case adjacente
    {
      if (plateau[x][y - 1].joueur == plateau[x][y].joueur)
        new_case = plateau[x][y - 1];
    }
    if (lvl_colonne == 2) {
      if (plateau[x + 1][y - 1].joueur == plateau[x][y].joueur)
        new_case = plateau[x][y - 1];
    }
  }
  if (lvl_ligne == 1) {
    if (lvl_colonne == 0) {
      if (plateau[x - 1][y].joueur == plateau[x][y].joueur)
        new_case = plateau[x - 1][y];
    }

    if (lvl_colonne == 2) {
      if (plateau[x + 1][y].joueur == plateau[x][y].joueur)
        new_case = plateau[x + 1][y];
    }
  }

  if (lvl_ligne == 2) {
    if (lvl_colonne == 0) {
      if (plateau[x - 1][y + 1].joueur == plateau[x][y].joueur)
        new_case = plateau[x - 1][y + 1];
    }

    if (lvl_colonne == 1) {
      if (plateau[x][y + 1].joueur == plateau[x][y].joueur)
        new_case = plateau[x][y + 1];
    }
  }

  return (new_case);
}

int deplacement_plateau(Case plateau[11][11], int x, int y, int borne) {
  int lvl_colonne, lvl_ligne = 0;

  Case pion_adjacent;
  pion_adjacent.coordonnee_Y = 0;
  pion_adjacent.coordonnee_X = 0;
  pion_adjacent.borne = 0;
  pion_adjacent.joueur = -1;
  int nb_adjacent;
  int end = 0;
  int fin = 0;

  if (borne == 1) {
    while (pion_adjacent.borne != 2 || end == 1) {
      nb_adjacent = nb_touche(plateau, x, y);

      for (lvl_ligne = 0; lvl_ligne <= 2; lvl_ligne++) {
        // nb_adjacent = 0;

        for (lvl_colonne = 0; lvl_colonne <= 2; lvl_colonne++) {
          pion_adjacent = trouver_case(plateau, lvl_ligne, lvl_colonne, x, y);
          if (pion_adjacent.joueur != -1)
            deplacement_plateau(plateau, pion_adjacent.coordonnee_X,
                                pion_adjacent.coordonnee_Y,
                                pion_adjacent.borne);
          else
            fin++;
        }
      }

      if (nb_adjacent < fin) end = 1;
    }
  }

  if (borne == 2) {
    while (pion_adjacent.borne != 1 || end == 1) {
      nb_adjacent = nb_touche(plateau, x, y);

      for (lvl_ligne = 0; lvl_ligne <= 2; lvl_ligne++) {
        // nb_adjacent = 0;

        for (lvl_colonne = 0; lvl_colonne <= 2; lvl_colonne++) {
          pion_adjacent = trouver_case(plateau, lvl_ligne, lvl_colonne, x, y);
          if (pion_adjacent.joueur != -1)
            deplacement_plateau(plateau, pion_adjacent.coordonnee_X,
                                pion_adjacent.coordonnee_Y,
                                pion_adjacent.borne);
          else
            fin++;
        }
      }

      if (nb_adjacent < fin) end = 1;
    }
  }

  return (pion_adjacent.borne);
}

int borne_oppose(pile *p, int joueur) {
  int vrai = 0;
  int borne = 0;

  while (p != NULL) {
    // if (p->elt.joueur != joueur )
    // 	p->elt = p->next;

    p->elt.borne = borne;
    if (borne == 1) {
      if (p->next->next->elt.borne == 2) return (vrai = 1);
    }

    if (borne == 2) {
      if (p->next->next->elt.borne == 2) return (vrai = 1);
    }

    p = p->next;
    p = p->next;
  }

  return (vrai);
}

int victoire(int joueur, pile *p, Case plateau[11][11]) {
  int fin = 0;

  int borne_op;
  if (p->elt.borne == 0) return (fin);



  fin = borne_oppose(p, joueur);
  if (!fin)
     return (fin);

  else {
    int borne = p->elt.borne;
    int x = p->elt.coordonnee_x;
    int y = p->elt.coordonnee_y;


    borne_op = deplacement_plateau(plateau, x, y, borne);

    if (borne == 1 && borne_op == 2) fin = 1;

    if (borne == 2 && borne_op == 1) fin = 1;
  }



  return (fin);
}
