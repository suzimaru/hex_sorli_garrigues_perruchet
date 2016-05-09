#include "jeux.h"

/*Ce module gère l'historique, les règles du jeux, permet de remplir et initialiser le plateau*/

//////////////////////////////////// PLATEAU
///////////////////////////////////////

/*Cette fonction initialise un case*/
Case init_case() {
  Case pion;
  pion.coordonnee_Y = 0;
  pion.coordonnee_X = 0;
  pion.borne = 0;
  pion.joueur = -1;
  return pion;
}

/*Cette fonction initialise toutes les cases du plateau passé en paramètre*/
void init_plateau(Case plateau[11][11]) {
  int i, k;
  for (i = 0; i < 11; i++) {
    for (k = 0; k < 11; k++) {
      plateau[i][k] = init_case();
      plateau[i][k].coordonnee_X = k;
      plateau[i][k].coordonnee_Y = i;
    }
  }
}

/*cette fonction remplie les champs de la structure case par les valeurs
 * correspondantes et initialise les bornes*/
void remplir(int Y, int X, int joueur, Case plateau[11][11]) {
  plateau[Y][X].coordonnee_X = X;
  plateau[Y][X].coordonnee_Y = Y;

  if (joueur == 0) plateau[Y][X].joueur = 0;

  if (joueur == 1) plateau[Y][X].joueur = 1;
  plateau[Y][X].borne = verif_borne(Y, X, joueur);
}

//////////////////////////////////// VERIFICATION
///////////////////////////////////////

/*Cette fonction renvoie vrai si le plateau est plein*/
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

/*Cette fonction initialise les bornes en fonction de son emplacement dans le plateau
la variable x correspond aux colonnes et y aux lignes*/
int verif_borne(int y, int x, int joueur)
// Vérifie si un coup joué est sur une borne
{
  int vrai = 0;
  if (joueur == 0)  // Si joueur 1 les extrémités sont les côté verticaux
  {
    if ((y >= 0 || y <= 10) && (x == 0)) vrai = 1;
    if ((y >= 0 || y <= 10) && (x == 10)) vrai = 2;
  }
  if (joueur == 1)  // SI joueur 2 les extrémités sont les côtés horizontaux.
  {
    if ((x >= 0 || x <= 10) && (y == 0)) vrai = 1;
    if ((x >= 0 || x <= 10) && (y == 10)) vrai = 2;
  }
  return (vrai);
}

//////////////////////////////////// HISTORIQUE
///////////////////////////////////////
/*Cette fonction enregistre les coups d'un joueur dans une pile p. Elle prend en paramètre les coordonnées 
du pion (y et x) et le numéro du  joueur (ici une couleur) et on crée un nouvel élément en l'initialisant
et on l'empile dans la pile*/
void enregistre_coup(pile *p, int Y, int X, int couleur)

{
  element new;
  new.coordonnee_x = X;
  new.coordonnee_y = Y;
  new.joueur = couleur;
  new.borne = verif_borne(Y, X, new.joueur);
  empiler_pile(p, new);
}

//////////////////////////////////// JEUX ////////////////////////////////////
/*cette fonction renvoie le numéro du joueur tiré au sort qui jouera en premier*/
int choix_joueur() {
  srand(time(0));
  return (rand() % 2);
}

/*Cette fonction remplie le plateau en fonction du pion joué à l'aide de ses coordonnées, du numéro du joueur, 
et le coup joué et rajouté dans la pile pour gérer l'historique */
void faire_un_coup(int Y, int X, int joueur, Case plateau[11][11], pile *p)
{
  remplir(Y, X, joueur, plateau);
  enregistre_coup(p, Y, X, joueur);
}


/*Cette fonction renvoie un int booléen si la victoire a été détectée. Elle prend en paramètre le pion joué 
avec ses coordonnées, le numéro du joueur, empile dans l'historique le coup joué et remplit le plateau*/
int jeux(int Y, int X, int joueur, pile *p, Case plateau[11][11]) {
  int end = 1;
  if (joueur == 0)
    joueur = 1;
  else if (joueur == 1)
    joueur = 0;

  faire_un_coup(Y, X, joueur, plateau, p);

  if (victoire(joueur, p, plateau))
    return (end = 0);
  else
    return (end);
}