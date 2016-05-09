#include "victoire.h"

// Ce programme vérifie tout d'abord s'il y a bien un pion à chaque borne, puis pars de la dernière case joué pour aller à sa borne opposé,
// tout en vérifiant le chemin parcourus.

Case tab_case[121];               // Tableau qui contient toute les cases que l'on à traversé durant la partie

Case tab_adjacente[121];          // Tableau qui contiens toutes les cases que l'on à traversé qui ont au moins 3 pions pion adjacent.

void remplir_tab(Case tab_case[]) {
  int i;
  for (i = 0; i <= 121; i++) {
    tab_case[i].coordonnee_Y = -1;
    tab_case[i].coordonnee_X = -1;
    tab_case[i].borne = 0;
    tab_case[i].joueur = -1;
  }
}

int lire_tab(int y, int x, Case plateau[11][11]) {
  int i;
  int vrai = 0;
  for (i = 0; i < 70 && (tab_case[i].joueur != 0 || tab_case[i].joueur != 1);
       i++) {
    if (tab_case[i].coordonnee_X == plateau[y][x].coordonnee_X &&
        tab_case[i].coordonnee_Y == plateau[y][x].coordonnee_Y)
      vrai = 1;
  }
  return (vrai);
}

void afficher_tab(int i, Case tab_case[]) {
  for (i = 0; i < 70 && (tab_case[i].joueur != 0 || tab_case[i].joueur != 1);
       i++) {
  }
}

int nb_touche(Case plateau[11][11], int y, int x)
// Compte le nombre de case adjacente de même couleur d'une case du plateau donnée
{
  int touche = 0;

  if (y == 0) {
    // en haut à gauche
    if (x == 0) {
      if (plateau[y][x].joueur == plateau[y + 1][x].joueur) {
        touche++;
      }
      if (plateau[y][x].joueur == plateau[y][x + 1].joueur) touche++;
    }
    // en haut à droite
    else if (x == 10) {
      if (plateau[y][x].joueur == plateau[y][x - 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y + 1][x - 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y + 1][x].joueur) touche++;
    }
    // ligne du haut
    else {
      if (plateau[y][x].joueur == plateau[y][x - 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y][x + 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y + 1][x].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y + 1][x - 1].joueur) touche++;
    }
  } else if (y == 10) {
    // en bas à gauche
    if (x == 0) {
      if (plateau[y][x].joueur == plateau[y - 1][x].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y - 1][x + 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y][x + 1].joueur) touche++;
    }
    // en bas à droite
    else if (x == 10) {
      if (plateau[y][x].joueur == plateau[y - 1][x].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y][x - 1].joueur) touche++;
    }
    // ligne du bas
    else {
      if (plateau[y][x].joueur == plateau[y][x - 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y][x + 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y - 1][x].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y - 1][x + 1].joueur) touche++;
    }
  } else {
    // cote de gauche
    if (x == 0) {
      if (plateau[y][x].joueur == plateau[y - 1][x].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y - 1][x + 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y][x + 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y + 1][x].joueur) touche++;
    }

    // cote de droite
    else if (x == 10) {
      if (plateau[y][x].joueur == plateau[y - 1][x].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y][x - 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y + 1][x - 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y + 1][x].joueur) touche++;
    }

    // tous les autres cas
    else {
      if (plateau[y][x].joueur == plateau[y - 1][x].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y - 1][x + 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y][x + 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y][x - 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y + 1][x].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y + 1][x - 1].joueur) touche++;
    }
  }
  return touche;
}

Case trouver_case(Case plateau[11][11], int lvl_ligne, int lvl_colonne, int y,int x)  
// Au premier lancement lvl_ligne = lvl_colonne = 0
// Cherche une case adjacente et la renvois en faisant un "cercle" autour de la case testé
{
  Case new_case;
  new_case.coordonnee_Y = -1;
  new_case.coordonnee_X = -1;
  new_case.borne = 0;
  new_case.joueur = -1;



  if (lvl_ligne == 0) {
    if (lvl_colonne == 1 && !lire_tab(y - 1, x, plateau))  
    // Le programme recherche case par case s'il y a une case adjacente
    {
      if (plateau[y - 1][x].joueur == plateau[y][x].joueur)

      {
        new_case = plateau[y - 1][x];
    
      }
    }
    if (lvl_colonne == 2 && !lire_tab(y - 1, x + 1, plateau)) {
      if (plateau[y - 1][x + 1].joueur == plateau[y][x].joueur) 
        new_case = plateau[y - 1][x + 1];     
    }
  }

  if (lvl_ligne == 1) {
    if (lvl_colonne == 0 && !lire_tab(y, x - 1, plateau)) {
    
      if (plateau[y][x - 1].joueur == plateau[y][x].joueur)     
        new_case = plateau[y][x - 1];  
    }

    if (lvl_colonne == 2 && !lire_tab(y, x + 1, plateau)) {
      if (plateau[y][x + 1].joueur == plateau[y][x].joueur)    
        new_case = plateau[y][x + 1];    
    }
  }

  if (lvl_ligne == 2) {
    if (lvl_colonne == 0 && !lire_tab(y + 1, x - 1, plateau)) {     
      if (plateau[y + 1][x - 1].joueur == plateau[y][x].joueur)    
        new_case = plateau[y + 1][x - 1];    
    }

    if (lvl_colonne == 1 && !lire_tab(y + 1, x, plateau)) {
      if (plateau[y + 1][x].joueur == plateau[y][x].joueur)     
        new_case = plateau[y + 1][x];       
    }
  }
 
  return (new_case);
}
int k = 0;
Case parcourir_case(Case plateau[11][11], int y, int x, int borne_up,int joueur_up, int *end, int *i){

//Parcour le plateau en commencant par le dernier pion joué.

  int lvl_ligne, lvl_colonne;
  Case pion_adjacent;
  pion_adjacent.coordonnee_Y = 0;
  pion_adjacent.coordonnee_X = 0;
  pion_adjacent.borne = 0;
  pion_adjacent.joueur = -1;
  int sortie = 0;

  int nb_case_adjacente = nb_touche(plateau, y, x); 


  for (lvl_ligne = 0;lvl_ligne <= 2 && *end != 50 && sortie != 1 && nb_case_adjacente != 0;lvl_ligne++) { // On rentre dans la boucle si le pion testé 
    for (lvl_colonne = 0; lvl_colonne <= 2 && *end != 50 && sortie != 1;lvl_colonne++) {                  // possède au moins une case adjacente, et si le 
      pion_adjacent = trouver_case(plateau, lvl_ligne, lvl_colonne, y, x);                                // compteur n'est pas arrivé au max.
      if (pion_adjacent.coordonnee_X != -1 &&  pion_adjacent.coordonnee_Y != -1) {
        tab_case[*i] = pion_adjacent;                                                                     // On remplit le plateau des cases traversé.
        *i = *i + 1;
      }
      if (pion_adjacent.borne == borne_up) sortie = 1;                                                    // On a trouvé la borne recherché, la fonction va se terminer.
      if (nb_touche(plateau, pion_adjacent.coordonnee_Y,  pion_adjacent.coordonnee_X) >= 3 &&pion_adjacent.joueur != -1) {
        tab_adjacente[k] = pion_adjacent;                                                                 // On remplit le plateau expliqué plus haut.
        k++;
      }
      if (pion_adjacent.joueur == joueur_up && pion_adjacent.borne != borne_up && *end != 50 && sortie != 1) {
        *end = *end + 1;
        return (parcourir_case(plateau, pion_adjacent.coordonnee_Y,  pion_adjacent.coordonnee_X, borne_up, joueur_up,end, i));
      }
    }
  }


  if (pion_adjacent.joueur == -1 && tab_adjacente[k - 1].joueur != -1 && sortie != 1) {
    k--;
    return (parcourir_case(plateau, tab_adjacente[k].coordonnee_Y, tab_adjacente[k].coordonnee_X, borne_up, joueur_up,end, i));
  }


  return (pion_adjacent);
}

int deplacement_plateau(Case plateau[11][11], int y, int x, int borne) {
  //Fonction qui renvois la borne que l'on recherche
  int sortie = 1;

  Case pion_adjacent;
  pion_adjacent.coordonnee_Y = 0;
  pion_adjacent.coordonnee_X = 0;
  pion_adjacent.borne = 0;
  pion_adjacent.joueur = -1;
  Case pion_precedent;
  pion_precedent.coordonnee_Y = -1;
  pion_precedent.coordonnee_X = -1;
  pion_precedent.borne = 0;
  pion_precedent.joueur = -1;
  
  int borne_up;

  int joueur_up = plateau[y][x].joueur;
  int i = 0;
  int end = 0;


  if (borne == 1) {                                                 // Le pion de départ à pour borne 1 on recherche donc un pion avec une borne
    borne_up = 2;                                                   // de valeur 2.

    tab_case[0].coordonnee_Y = plateau[y][x].coordonnee_Y;
    tab_case[0].coordonnee_X = plateau[y][x].coordonnee_X;
    tab_case[0].joueur = plateau[y][x].joueur;
    tab_case[0].borne = plateau[y][x].borne;

    i++;

    pion_adjacent = parcourir_case(plateau, plateau[y][x].coordonnee_Y, plateau[y][x].coordonnee_X, borne_up,joueur_up, &end, &i);
    sortie = nb_touche(plateau, pion_adjacent.coordonnee_X,pion_adjacent.coordonnee_Y);
  }

  if (borne == 2) {
    borne_up = 1;

    tab_case[0].coordonnee_Y = plateau[y][x].coordonnee_Y;
    tab_case[0].coordonnee_X = plateau[y][x].coordonnee_X;
    tab_case[0].joueur = plateau[y][x].joueur;
    tab_case[0].borne = plateau[y][x].borne;

    i++;

    pion_adjacent = parcourir_case(plateau, plateau[y][x].coordonnee_Y, plateau[y][x].coordonnee_X, borne_up,plateau[y][x].joueur, &end, &i);
    sortie = nb_touche(plateau, pion_adjacent.coordonnee_X,pion_adjacent.coordonnee_Y);
  }

  return (pion_adjacent.borne);
}

int borne_oppose(pile *p, int joueur) {
  //Fonction qui vérifie si il y a bien un pion de chaque côté du plateau et de la même couleur.
  int vrai = 0;
  int borne = 0;
  pile *p_aux = p;
  Cell *sommet = p->top;
  int borne_next = 0;
  int sortie = 0;
  borne = p_aux->top->elt.borne;

  if (borne == 1) {
    while (p_aux->top->next != NULL && borne_next != 2 && sortie == 0) {
      p_aux->top = p_aux->top->next;
      if (p_aux->top->next != NULL) {
        p_aux->top = p_aux->top->next;
        borne_next = p_aux->top->elt.borne;
      } else
        sortie = 1;
      if (borne_next == 2) vrai = 1;
    }
  }
  if (borne == 2) {
    while (p_aux->top->next != NULL && borne_next != 2 && sortie == 0) {
      p_aux->top = p_aux->top->next;
      if (p_aux->top->next != NULL) {
        p_aux->top = p_aux->top->next;
        borne_next = p_aux->top->elt.borne;
      } else
        sortie = 1;
      if (borne_next == 1) vrai = 1;
    }
  }

  p->top = sommet;

  return (vrai);
}



int victoire(int joueur, pile *p, Case plateau[11][11]) {
  // Appelle toute les autres fonctions, et renvois un int pour définir si on continue ou on arrête la partie.
  int fin = 0;

  int borne_op;
  remplir_tab(tab_case);
  remplir_tab(tab_adjacente);


  fin = borne_oppose(p, joueur);

  if (!fin)
    return (fin);



  else if (p->top->elt.borne!=0) {
    fin = 0;

    int borne = p->top->elt.borne;
    int x = p->top->elt.coordonnee_x;
    int y = p->top->elt.coordonnee_y;


    borne_op = deplacement_plateau(plateau, y, x, borne);

    if (borne == 1 && borne_op == 2) fin = 1;

    if (borne == 2 && borne_op == 1) fin = 1;
  }

 
  return (fin);
}
