
#include "pile.h"


pile *init(){
   return NULL;
}

int estVide(pile *p){
    return p==NULL;
}



void empiler_pile(pile **p,element New_number){
    if (p==NULL) {
        *p=(pile*)malloc(sizeof(pile));
        (*p)->elt=New_number;
        (*p)->next=NULL;
        printf("YO ! \n");
  printf("elt  %d %d %d \n",(*p)->elt.coordonnee_x,(*p)->elt.coordonnee_y,(*p)->elt.borne );
    }else{
        pile *tmp=(pile*)malloc(sizeof(pile));
        tmp->next=*p;
        tmp->elt=New_number;
        *p=tmp;
    }
      printf("elt2  %d %d %d \n",(*p)->elt.coordonnee_x,(*p)->elt.coordonnee_y,(*p)->elt.borne );

}


element sommet (pile *p){
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