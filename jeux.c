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
      plateau[i][k].coordonnee_X = k;
      plateau[i][k].coordonnee_Y = i;
    }
  }
}

void remplir(int Y, int X, int joueur, Case plateau[11][11])

{
 
  plateau[Y][X].coordonnee_X = X;
  plateau[Y][X].coordonnee_Y = Y;

  if (joueur == 0) plateau[Y][X].joueur = 0;

  if (joueur == 1) plateau[Y][X].joueur = 1;
  plateau[Y][X].borne = verif_borne(Y,X,joueur);
    printf("case du plateau : y :%d  x : %d  borne : %d joueur : %d \n",plateau[Y][X].coordonnee_Y,plateau[Y][X].coordonnee_X,plateau[Y][X].borne,plateau[Y][X].joueur );

}

//////////////////////////////////// VERIFICATION
///////////////////////////////////////

int plein(int Y, int X, Case plateau[11][11]) {
  int vrai = 0;

  if (plateau[Y][X].joueur != -1) vrai = 1;

  return (vrai);
}

// rajouter fonction plateau plein

int plateau_plein (Case plateau[11][11])
{

  int i,j;
  int nb_case_pleine = 0;
  int vrai = 0;

  for(i=0;i<11;i++)
  {
    for(j=0;j<11;j++)
    {
      if (plateau[i][j].joueur!=-1)
        nb_case_pleine++;
    }
  }

  if(nb_case_pleine == 121)
    vrai = 1;

  return(vrai);

}

int verif_borne(int y, int x, int joueur)  // Vérifie si un coup joué est sur une borne

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
 
  // printf("borne = %d \n",vrai );
  // printf("sortie borne\n");
  return (vrai);
}

//////////////////////////////////// HISTORIQUE
///////////////////////////////////////



void enregistre_coup(pile *p, int Y, int X, int couleur)

{
  element new; //= Conversion_elt( X, Y, couleur);
  new.coordonnee_x = X;
  new.coordonnee_y = Y;
  new.joueur = couleur;
  new.borne = verif_borne(Y, X, new.joueur);

 
  printf("enregistrer y %d x %d\n",Y,X);
  empiler_pile(p, new);


}

//////////////////////////////////// JEUX ////////////////////////////////////

int choix_joueur() {
  return (rand() % 2);  // choisis un chiffre au hasard
}

void faire_un_coup(int Y, int X, int joueur, Case plateau[11][11], pile *p)

{
  int vrai = 0;
  if (vrai==0)  // Vérifie que la case est vide
  {
                    // fonction marche problème d'affichage
    remplir(Y, X, joueur, plateau);
    enregistre_coup(p, Y, X, joueur);

    // printf("pile vide : %d\n",vide );

  }
}

int jeux(int Y, int X, int joueur, pile *p, Case plateau[11][11])
{
  int end = 1;
  if (joueur == 0) joueur =1;
  else if (joueur == 1) joueur = 0;
 
  faire_un_coup(Y, X, joueur, plateau, p);
  // printf("coup joué\n");

      printf("Coordonnée jeu    :   y: %d   x : %d joueur : %d  borne : %d  \n", plateau[Y][X].coordonnee_Y,plateau[Y][X].coordonnee_X,plateau[Y][X].joueur,plateau[Y][X].borne );


 

  if (victoire(joueur, p, plateau))
    return (end = 0);
  else 
    return (end);
}