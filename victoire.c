#include "victoire.h"

int nb_touche(
    Case plateau[11][11], int x,
    int y)  // Compte le nombre de case adjacente d'une case du plateau donnée
{
  int touche = 0;

  int k = y;
  int i;
  for (i = x; i <= x + 1; i++) {
    if (plateau[k][i].joueur == plateau[y][x].joueur) touche++;
  }

  for (i = x - 1; i <= x + 1; i++)

  {
    if (plateau[k][i].joueur == plateau[y][x].joueur) touche++;
  }

  k = y + 1;
  for (i = x - 1; i <= x; i++) {
    if (plateau[k][i].joueur == plateau[y][x].joueur) touche++;
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
      if (plateau[y-1][x].joueur == plateau[y][x].joueur)
        new_case = plateau[x][y - 1];
    }
    if (lvl_colonne == 2) {
      if (plateau[y-1][x+1].joueur == plateau[y][x].joueur)
        new_case = plateau[y-1][x];
    }
  }
  if (lvl_ligne == 1) {
    if (lvl_colonne == 0) {
      if (plateau[y][x-1].joueur == plateau[y][x].joueur)
        new_case = plateau[y][x-1];
    }

    if (lvl_colonne == 2) {
      if (plateau[y][x + 1].joueur == plateau[y][x].joueur)
        new_case = plateau[y][x + 1];
    }
  }

  if (lvl_ligne == 2) {
    if (lvl_colonne == 0) {
      if (plateau[y+1][x - 1].joueur == plateau[y][x].joueur)
        new_case = plateau[y+1][x - 1];
    }

    if (lvl_colonne == 1) {
      if (plateau[y+1][x].joueur == plateau[y][x].joueur)
        new_case = plateau[y+1][x];
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

int borne_oppose(pile **p, int joueur) {
  int vrai = 0;
  int borne = 0;
  int vide = 0;
    // if (p->elt.joueur != joueur )
    pile **p_aux = p;
    int borne_next = 0;
    borne = (*p_aux)->top->elt.borne;                
    printf("valeur borne = %d \n", borne );

    if (borne == 1 ){

  while ((*p_aux)->top->next != NULL && borne_next!=2)         
  
    {

      borne_next = (*p_aux)->top->elt.borne;
      depiler(*p_aux);
      borne_next = (*p_aux)->top->elt.borne;


    }
  }
 
  if (borne == 2 ){
    while((*p_aux)->top->next != NULL && borne_next!=1)
    {

      borne_next = (*p_aux)->top->elt.borne;
      depiler(*p_aux);
      vide = estVide(*p_aux);
      
      printf("vide %d \n", vide );

      borne_next = (*p_aux)->top->elt.borne;
      printf("borne suivante : %d\n",borne_next );
    }


  }

 
   

  return (vrai);
}

int victoire(int joueur, pile *p, Case plateau[11][11]) {
  int fin = 0;
  printf("Debut victoire\n");

  int borne_op;

  // printf("borne sommet = %d\n", p->elt.borne );
  
  // int nb_element_pile = nb_element(p);
  // printf("nombre d'élément dans la pile : %d\n", nb_element_pile );

  if (p->top->elt.borne == 0)  { 
    printf("continue\n"); 
    return (fin); }


  fin = borne_oppose(&p, joueur);
  if (!fin)
     return (fin);

  else {
    int borne = p->top->elt.borne;
    int x = p->top->elt.coordonnee_x;
    int y = p->top->elt.coordonnee_y;


    borne_op = deplacement_plateau(plateau, x, y, borne);

    if (borne == 1 && borne_op == 2) fin = 1;

    if (borne == 2 && borne_op == 1) fin = 1;
  }



  return (fin);
}
