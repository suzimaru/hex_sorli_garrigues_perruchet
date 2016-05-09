#include <stdio.h>
#include <stdbool.h>
#include "pile.h"
#include <stdlib.h>
/*Auteur SORLI Suzanne*/


/*Cette fonction initialise une pile*/
void init (pile *p)
{
  p->top=NULL;
}

/*Cette fonction renvoie un booléen, true si la pile est vide, false sinon*/
bool estVide (pile *p)
{
  return (p->top== NULL);
}

/*Cette fonction renvoie un booléen, true si la pile est pleine, false sinon*/
bool pile_Pleine (pile *p)
{
  return false;
}

/*Cette fonction affiche tous les éléments de la pile*/
void affiche_pile (pile *p)
{
  if (!estVide(p))
  {
    Cell *c=p->top;
    while (c!=NULL)
    {
     printf("joueur:%d x:%d y:%d, borne=%d\n",c->elt.joueur,c->elt.coordonnee_x,c->elt.coordonnee_y,c->elt.borne);
      c=c->next;
    }
  }
}

/*Cette fonction empile l'élément e dans la pile p*/
void empiler_pile (pile *p, element e)
{
  if (!pile_Pleine(p))
  { 
    Cell *c;
    c=(Cell*)malloc(sizeof(c));
    c->elt=e;
    c->next=p->top;
    p->top=c;
  }
}

/*Cette fonction dépile la pile, elle renvoie l'élément dépilé*/
element depiler(pile *p)
{ 
  element e_depile;
  e_depile.coordonnee_x=0;
  e_depile.coordonnee_y=0;
  e_depile.joueur=-1;
  e_depile.borne=0;
  if (!estVide(p))
  {
    Cell *cellule_depilee=p->top; 
    e_depile=cellule_depilee->elt;
    p->top=cellule_depilee->next;
    free(cellule_depilee);
  }
    return e_depile;
}

/*Cette fonction renvoie l'élément qui est au sommet de la pile*/
element sommet (pile *p)
{
  element som;
  som.coordonnee_x=0;
  som.coordonnee_y=0;
  som.joueur=-1;
  som.borne=0;
  if (!estVide(p))
  {
    Cell *c=p->top;
    som=c->elt;
  }
  return som;
}

