
#include "jeux.h"

//////////////////////////////////// STRUCTURE
///////////////////////////////////////

//////////////////////////////////// PLATEAU
///////////////////////////////////////

Case init_case() {
  Case pion;
  pion.coordonnee_Y = 0;
  pion.coordonnee_X = 0;
  pion.borne = 0;
  pion.joueur = -1;
  return pion;
}

void init_plateau(Case plateau[11][11]) {
  int i, k;
  for (i = 0; i < 11; i++) {
    for (k = 0; k < 11; k++) {
      plateau[i][k] = init_case();
      plateau[i][k].coordonnee_Y = i;
      plateau[i][k].coordonnee_X = k;
    }
  }
}

void remplir(int X, int Y, int joueur, Case plateau[11][11])

{
  plateau[Y][X].coordonnee_X = X;
  plateau[Y][X].coordonnee_Y = Y;
  printf("y%d x%d \n",Y,X);
  if (joueur == 0) plateau[Y][X].joueur = 0;

  if (joueur == 1) plateau[Y][X].joueur = 1;
  printf("remplir\n");
}

//////////////////////////////////// VERIFICATION
///////////////////////////////////////

int plein(int X, int Y, Case plateau[11][11]) {

  return (plateau[Y][X].joueur !=1);
}

// rajouter fonction plateau plein

int plateau_plein(Case plateau[11][11]) {
  int i, j;
  int nb_case_pleine = 0;

  for (i = 0; i < 11; i++) {
    for (j = 0; j < 11; j++) {
      if (plateau[i][j].joueur != -1) nb_case_pleine++;
    }
  }

  return (nb_case_pleine == 121);
}

int verif_borne(int x, int y,
                int joueur)  // Vérifie si un coup joué est sur une borne

{
  int vrai = 0;

  if (joueur == 1)  // Si joueur 1 les extrémités sont les côté verticaux
  {
    if ((y >= 0 || y <= 10) && (x == 0)) vrai = 1;

    if ((y >= 0 || y <= 10) && (x == 10)) vrai = 2;
  }

  if (joueur == 0)  // SI joueur 2 les extrémités sont les côtés horizontaux.
  {
    if ((x >= 0 || x <= 10) && (y == 0)) vrai = 1;

    if ((x >= 0 || x <= 10) && (y == 10)) vrai = 2;
  }

  return (vrai);
}

//////////////////////////////////// HISTORIQUE
///////////////////////////////////////

void enregistre_coup(pile *p, int X, int Y, int couleur)

{
  element new;  //= Conversion_elt( X, Y, couleur);
  new.coordonnee_x = X;
  new.coordonnee_y = Y;
  new.joueur = couleur;
  new.borne = verif_borne(X, Y, new.joueur);

  empiler_pile(p, new);
}

//////////////////////////////////// JEUX ////////////////////////////////////

int choix_joueur() {
  return (rand() % 2);  // choisis un chiffre au hasard
}

void faire_un_coup(int X, int Y, int joueur, Case plateau[11][11], pile **p)

{
  int vrai = 0;
  printf("plein %d\n", vrai);
  if (vrai == 0)  // Vérifie que la case est vide
  {
    // fonction marche problème d'affichage
    remplir(X, Y, joueur, plateau);
    enregistre_coup(*p, X, Y, joueur);

    // printf("pile vide : %d\n",vide );
  }
}

int jeux(int X, int Y, int joueur, pile *p, Case plateau[11][11]) {
  int end = 0;
  if (!joueur)
  joueur = 1;
  else if (joueur)
  joueur = 0;

  faire_un_coup(X, Y, joueur, plateau, &p);
  printf("coup joué\n");

  printf("Element de la pile joueur :%d  X: %d Y: %d borne: %d \n",
         p->top->elt.joueur, p->top->elt.coordonnee_x, p->top->elt.coordonnee_y,
         p->top->elt.borne);

  /*if (victoire(joueur, p, plateau))
    return (end = 1);
  else
    return (0);*/
  return 0;
}


