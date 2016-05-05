#include <stdio.h>
#include <stdbool.h>
#include "pile.h"
#include <stdlib.h>

void init (pile *p)
{
  p->top=NULL;
}

bool estVide (pile *p)
{
  return (p->top== NULL);
}


bool pile_Pleine (pile *p)
{
  return false;
}

void affiche_pile (pile *p)
{
  if (!estVide(p))
  {
    Cell *c=p->top;
    while (c!=NULL)
    {
     
      c=c->next;
    }
  }
}

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
  printf("empiler++\n");
}

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

