#include <stdio.h>
#include <stdlib.h>
#include "pile.h"


pile *init(){
   return NULL;
}

int estVide(pile *p){
    return p==NULL;
}



void empiler_pile(pile *p,struct cell_element New_number){
    if (p==NULL) {
        p=(pile*)malloc(sizeof(struct Cell_p));
        p->elt=New_number;
        p->next=NULL;
    }else{
        pile *tmp=(pile*)malloc(sizeof(struct Cell_p));
        tmp->next=p;
        tmp->elt=New_number;
        p=tmp;
    }
}


struct cell_element sommet (pile *p){
    return p->elt;
}


pile *depiler(pile *p){
    pile *tmp;
    if (!estVide(p)) {
        tmp=p;
        p=p->next;
        free(tmp);
    }
    return p;
}


