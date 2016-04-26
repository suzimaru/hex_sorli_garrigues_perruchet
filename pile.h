#ifndef pile_h
#define pile_h

#include <stdio.h>
#include <stdlib.h>



typedef struct cell_element{
    int coordonnee_x;
    int coordonnee_y;
    int joueur;
}element;





typedef struct Cell_p {
    struct cell_element elt;
    struct Cell_p *next;
} pile;



pile *init();
int estVide(pile *p);
struct cell_element sommet (pile *p);
void empiler_pile(pile *p,struct cell_element New_number);
pile *depiler(pile *p);



#endif
