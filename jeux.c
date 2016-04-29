
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
      plateau[i][k].coordonnee_X = i;
      plateau[i][k].coordonnee_Y = k;
    }
  }
}

void remplir(int X, int Y, int joueur, Case plateau[11][11])

{
  plateau[X][Y].coordonnee_X = X;
  plateau[X][Y].coordonnee_Y = Y;

  if (joueur == 0) plateau[X][Y].joueur = 0;

  if (joueur == 1) plateau[X][Y].joueur = 1;
}

//////////////////////////////////// VERIFICATION
///////////////////////////////////////

int plein(int X, int Y, Case plateau[11][11]) {
  int vrai = 0;

  if (plateau[X][Y].joueur != -1) vrai = 1;

  return (vrai);
}

// rajouter fonction plateau plein

int verif_borne(int x, int y,
                int joueur)  // Vérifie si un coup joué est sur une borne

{
  int vrai = 0;

  if (joueur == 0)  // Si joueur 1 les extrémités sont les côté verticaux
  {
    if (y <= 0 && y >= 10 && (x == 0)) vrai = 1;

    if (y <= 0 && y >= 10 && (x == 10)) vrai = 2;
  }

  if (joueur == 1)  // SI joueur 2 les extrémités sont les côtés horizontaux.
  {
    if (x <= 0 && x >= 10 && (y == 0)) vrai = 1;

    if (x <= 0 && x >= 10 && (y == 1)) vrai = 2;
  }

  return (vrai);
}

//////////////////////////////////// HISTORIQUE
///////////////////////////////////////


// element Conversion_elt( int X, int Y, int joueur)  // Met les coordonnée dans la structure element

// {
//   element new;

//   new.coordonnee_x = X;
//   new.coordonnee_y = Y;
//   // printf("%d %d %d %d\n",new.coordonnee_x,new.coordonnee_y,new.joueur,new.borne);
//   new.joueur = joueur;
//   // printf("%d %d %d %d\n",new.coordonnee_x,new.coordonnee_y,new.joueur,new.borne);
//   new.borne = verif_borne(X, Y, new.joueur);
//   printf("%d %d %d %d\n",new.coordonnee_x,new.coordonnee_y,new.joueur,new.borne);

//   return (new);
// }

pile *enregistre_coup(pile *p, int X, int Y, int couleur)

{
   element new; //= Conversion_elt( X, Y, couleur);
  new.coordonnee_x = X;
  new.coordonnee_y = Y;
  new.joueur = couleur;
  new.borne = verif_borne(X, Y, new.joueur);

  empiler_pile(&p, new);
 
  return p;
}

//////////////////////////////////// JEUX ////////////////////////////////////

int choix_joueur() {
  return (rand() % 2);  // choisis un chiffre au hasard
}

void faire_un_coup(int X, int Y, int joueur, Case plateau[11][11], pile *p)

{
  int vrai = plein(X, Y, plateau);
  if (!vrai)  // Vérifie que la case est vide
  {
    remplir(X, Y, joueur, plateau);
    enregistre_coup(p, X, Y, joueur);
  }
}

int jeux(int X, int Y, int joueur, pile *p, Case plateau[11][11])

{
  int end = 0;

  faire_un_coup(X, Y, joueur, plateau, p);

  if (victoire(joueur, p, plateau))
    return (end = 1);
  else  // Si aucun joueur n'as gagné la partie la fonction se rappelle

    return 0;
}


