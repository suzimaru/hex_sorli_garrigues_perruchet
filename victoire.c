#include "victoire.h"


Case tab_case[121];

Case tab_adjacente[121];

void remplir_tab(Case tab_case[])
{
  int i;
  for (i=0;i<=121;i++)
  {
  tab_case[i].coordonnee_Y = -1;
  tab_case[i].coordonnee_X = -1;
  tab_case[i].borne = 0;
  tab_case[i].joueur = -1;
  }
}


int lire_tab(int y , int x, Case plateau[11][11] )
{
  int i;
  int vrai=0;
  for (i=0; i <70 && (tab_case[i].joueur!=0 || tab_case[i].joueur!=1);i++ )
  {
    if(tab_case[i].coordonnee_X==plateau[y][x].coordonnee_X && tab_case[i].coordonnee_Y==plateau[y][x].coordonnee_Y)
      vrai=1;
  }
  printf("vrai lire tab : %d \n",vrai );
  return(vrai);
}

void afficher_tab(int i,Case tab_case[])
{
  for (i=0; i <70 && (tab_case[i].joueur!=0 || tab_case[i].joueur!=1);i++ )
  {
      printf("tab_case[%d] x : %d  y :  %d \n",i,tab_case[i].coordonnee_X,tab_case[i].coordonnee_Y  );
  }
}


int nb_touche(Case plateau[11][11], int y, int x)
// Compte le nombre de case adjacente d'une case du plateau donnée
{
  int touche = 0;

  if (y == 0) {
    // en haut à gauche
    if (x == 0) {
      printf("en haut gauche\n");
      if (plateau[y][x].joueur == plateau[y + 1][x].joueur)
      {
        printf("gsg %d  %d\n",y,x);
        touche++;
      }  
      if (plateau[y][x].joueur == plateau[y][x + 1].joueur) touche++;
      printf("%d \n",touche);
    }
    // en haut à droite
    else if (x == 10) {
      printf("en haut droit\n");
      if (plateau[y][x].joueur == plateau[y][x-1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y+1][x - 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y+1][x].joueur) touche++;
      printf("%d \n",touche);
    }
    // ligne du haut
    else {
      printf("ligne haut \n");
      if (plateau[y][x].joueur == plateau[y][x - 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y][x + 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y + 1][x].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y + 1][x - 1].joueur) touche++;
      printf("%d \n",touche);
    }
  } else if (y == 10) {
    // en bas à gauche
    if (x == 0) {
      printf("en bas à gauche\n");
      if (plateau[y][x].joueur == plateau[y - 1][x].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y - 1][x + 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y][x + 1].joueur) touche++;
      printf("%d \n",touche);
    }
    // en bas à droite
    else if (x == 10) {
      printf("en bas droite\n");
      if (plateau[y][x].joueur == plateau[y - 1][x].joueur) touche++;
      printf("%d\n",touche);
      if (plateau[y][x].joueur == plateau[y][x - 1].joueur) touche++;
      printf("%d \n",touche);
    }
    // ligne du bas
    else {
      printf("ligne du bas\n");
      if (plateau[y][x].joueur == plateau[y][x - 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y][x + 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y - 1][x].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y - 1][x + 1].joueur) touche++;
      printf("%d \n",touche);
    }
  } else {
    // cote de gauche
    if (x == 0) {
      printf("cote gauche\n");
      if (plateau[y][x].joueur==plateau[y-1][x].joueur) touche++;
      if (plateau[y][x].joueur==plateau[y-1][x+1].joueur) touche++;
      if (plateau[y][x].joueur==plateau[y][x+1].joueur) touche++;
      if (plateau[y][x].joueur==plateau[y+1][x].joueur) touche++;
      printf("%d \n",touche);
    }

    // cote de droite
    else if (x == 10) {
      printf("cote droit\n");
      if (plateau[y][x].joueur==plateau[y-1][x].joueur) touche++;
      if (plateau[y][x].joueur==plateau[y][x-1].joueur) touche++;
      if (plateau[y][x].joueur==plateau[y+1][x-1].joueur) touche++;
      if (plateau[y][x].joueur==plateau[y+1][x].joueur) touche++;
      printf("%d \n",touche);
    }

    // tous les autres cas
    else {
      printf("autre\n");
      if (plateau[y][x].joueur==plateau[y-1][x].joueur) touche++;
      if (plateau[y][x].joueur==plateau[y-1][x+1].joueur) touche++;
      if (plateau[y][x].joueur==plateau[y][x+1].joueur) touche++;
      if (plateau[y][x].joueur==plateau[y][x-1].joueur) touche++;
      if (plateau[y][x].joueur==plateau[y+1][x].joueur) touche++;
      if (plateau[y][x].joueur==plateau[y+1][x-1].joueur) touche++;
      printf("%d \n",touche);
    }
  }
  return touche; 
}

Case trouver_case(Case plateau[11][11], int lvl_ligne, int lvl_colonne, int y,int x)  // Au premier lancement lvl_ligne = lvl_colonne = 0
{
  Case new_case;
  new_case.coordonnee_Y = -1;
  new_case.coordonnee_X = -1;
  new_case.borne = 0;
  new_case.joueur = -1;


  printf("------> trouver case\n");
 
     printf("niveau ligne : %d niveau colonne : %d \n",lvl_ligne,lvl_colonne );


  if (lvl_ligne == 0 ) {
    if (lvl_colonne ==  1 && !lire_tab(y-1,x,plateau))  // Le programme recherche case par case s'il y a une case adjacente
    {
      // if (plateau[y][x - 1].joueur == plateau[y][x].joueur)
      printf("test1\n");
              if (plateau[y-1][x].joueur == plateau[y][x].joueur)

        {new_case = plateau[y-1][x]; printf(" plateau[y-1][x] coordonnée : y %d x : %d joueur : %d \n",plateau[y-1][x].coordonnee_Y,plateau[y-1][x].coordonnee_X, plateau[y-1][x].joueur ); }
    }
    if (lvl_colonne == 2 && !lire_tab(y-1,x+1,plateau)) {
      printf("test2\n");
            // if (plateau[y + 1][x - 1].joueur == plateau[y][x].joueur)

      if (plateau[y - 1][x + 1].joueur == plateau[y][x].joueur)
        {new_case = plateau[y-1][x + 1]; printf(" plateau[y-1][x + 1]  coordonnée : y %d x : %d joueur : %d \n",plateau[y-1][x + 1].coordonnee_Y,plateau[y-1][x + 1].coordonnee_X, plateau[y-1][x + 1].joueur ); }
    }
  }
  
  if (lvl_ligne == 1 ) {
    if (lvl_colonne == 0 && !lire_tab(y,x-1,plateau)) {
      printf("test3\n");
      // if (plateau[y - 1][x].joueur == plateau[y][x].joueur)
      printf("comparaison joueur : case : %d joueur : %d \n",plateau[y][x-1].joueur,plateau[y][x].joueur );
              if (plateau[y][x-1].joueur == plateau[y][x].joueur)

        {new_case = plateau[y][x-1];printf(" plateau[y][x-1] coordonnée : y %d x : %d joueur : %d \n",plateau[y][x-1].coordonnee_Y,plateau[y][x-1].coordonnee_X, plateau[y][x-1].joueur );  }
    }

    if (lvl_colonne == 2 && !lire_tab(y,x+1,plateau) ) {
      // if (plateau[y + 1][x].joueur == plateau[y][x].joueur)
      printf("test4\n");
              if (plateau[y][x+1].joueur == plateau[y][x].joueur)

        {new_case = plateau[y][x+1];printf(" plateau[y][x+1] coordonnée : y %d x : %d joueur : %d \n",plateau[y][x+1].coordonnee_Y,plateau[y][x+1].coordonnee_X, plateau[y][x+1].joueur ); }
    }
  }

  if (lvl_ligne == 2  ) {
    if (lvl_colonne == 0 && !lire_tab(y+1,x-1,plateau)) {
      // if (plateau[y - 1][x + 1].joueur == plateau[y][x].joueur)
      printf("test5\n");
              if (plateau[y + 1][x - 1].joueur == plateau[y][x].joueur)

        {new_case = plateau[y+1][x - 1];printf(" plateau[y+1][x - 1] coordonnée : y %d x : %d joueur : %d \n",plateau[y+1][x - 1].coordonnee_Y,plateau[y+1][x-1].coordonnee_X, plateau[y+1][x-1].joueur ); }
    }

    if (lvl_colonne == 1 && !lire_tab(y+1,x,plateau)) { 
      // if (plateau[y][x + 1].joueur == plateau[y][x].joueur)
      printf("test6\n");
              if (plateau[y+1][x].joueur == plateau[y][x].joueur)

        {new_case = plateau[y+1][x];printf(" plateau[y+1][x] coordonnée : y %d x : %d joueur : %d \n",plateau[y+1][x].coordonnee_Y,plateau[y+1][x].coordonnee_X, plateau[y+1][x].joueur );}
    }
  }
  printf("new_case : y : %d x : %d borne : %d joueur %d\n",new_case.coordonnee_Y,new_case.coordonnee_X,new_case.borne,new_case.joueur );
  return (new_case);
}
int k=0;
Case parcourir_case (Case plateau[11][11], int y, int x,int borne_up,int joueur_up,int *end,int *i)
{

  
  int lvl_ligne,lvl_colonne;
  Case pion_adjacent;
  pion_adjacent.coordonnee_Y = 0;
  pion_adjacent.coordonnee_X = 0;
  pion_adjacent.borne = 0;
  pion_adjacent.joueur = -1;
  int sortie =0;
  printf("k : %d \n", k);

  int nb_case_adjacente = nb_touche(plateau,y,x);
  printf("Nombre de case adjacente : %d \n",nb_case_adjacente );
   
  printf("-------> parcourir_case\n");
  printf("valeur de i : %d \n",*i );
  // afficher_tab(*i);

    for (lvl_ligne = 0; lvl_ligne <=2 && *end !=50 && sortie != 1 && nb_case_adjacente != 0 ; lvl_ligne++) {

      for (lvl_colonne = 0; lvl_colonne <= 2 && *end != 50 && sortie != 1; lvl_colonne++) {
      
        pion_adjacent = trouver_case(plateau, lvl_ligne, lvl_colonne, y, x);
        if(pion_adjacent.coordonnee_X!=-1 && pion_adjacent.coordonnee_Y!=-1 ) {tab_case[*i] = pion_adjacent; printf("tab_case[%d] = y %d  x  %d  \n",*i ,tab_case[*i].coordonnee_Y,tab_case[*i].coordonnee_X  );  *i=*i+1;}
      
        printf("pion_adjacent y : %d x:%d borne : %d joueur : %d \n",pion_adjacent.coordonnee_Y,pion_adjacent.coordonnee_X,pion_adjacent.borne,pion_adjacent.joueur );
        printf("borne up : %d borne pion : %d finis : %d \n",borne_up,pion_adjacent.borne,*end );
        if (pion_adjacent.borne==borne_up) sortie=1;
        if (nb_touche(plateau,pion_adjacent.coordonnee_Y,pion_adjacent.coordonnee_X)>=3 && pion_adjacent.joueur!=-1) {tab_adjacente[k]=pion_adjacent;printf("tab_adjacente[%d] = y %d x %d \n",k, tab_adjacente[k].coordonnee_Y,tab_adjacente[k].coordonnee_X ); k++; }
        if (pion_adjacent.joueur == joueur_up && pion_adjacent.borne != borne_up && *end !=50 && sortie != 1)
          {         
                  *end=*end+1;

                  // remplir_tab();
return(parcourir_case(plateau, pion_adjacent.coordonnee_Y,
                              pion_adjacent.coordonnee_X,borne_up,joueur_up,end,i));}
        
      }
    }

    printf("pion_adjacent y : %d x:%d borne : %d joueur : %d \n",pion_adjacent.coordonnee_Y,pion_adjacent.coordonnee_X,pion_adjacent.borne,pion_adjacent.joueur );
    printf("k : %d , tab_adjacente[%d] joueur : %d  \n", k,k ,tab_adjacente[k].joueur );
    if(pion_adjacent.joueur==-1 && tab_adjacente[k-1].joueur!=-1 && sortie!=1)
    {
      printf("Yo !\n");
       k--;
      return(parcourir_case(plateau,tab_adjacente[k].coordonnee_Y,tab_adjacente[k].coordonnee_X,borne_up,joueur_up,end,i));
    }
  
      printf("pion_adjacent fin y : %d x:%d borne : %d joueur : %d \n",pion_adjacent.coordonnee_Y,pion_adjacent.coordonnee_X,pion_adjacent.borne,pion_adjacent.joueur );


  return (pion_adjacent);


}



int deplacement_plateau(Case plateau[11][11], int y, int x, int borne) {
  // int lvl_colonne, lvl_ligne = 0;
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
  pion_precedent.joueur=-1;
  // int nb_adjacent;
  // int end = 0;
  // int fin = 0;
  int borne_up;
  printf("------> deplacement\n");


  int joueur_up=plateau[y][x].joueur;
  int i=0;

  if (borne ==1)
  {
    int end = 0;
    borne_up = 2;


        tab_case[0].coordonnee_Y=plateau[y][x].coordonnee_Y;
        tab_case[0].coordonnee_X=plateau[y][x].coordonnee_X;
        tab_case[0].joueur=plateau[y][x].joueur;
        tab_case[0].borne=plateau[y][x].borne;

        i++;


        pion_adjacent=parcourir_case(plateau,plateau[y][x].coordonnee_Y ,plateau[y][x].coordonnee_X ,borne_up,joueur_up,&end,&i);
        sortie=nb_touche(plateau, pion_adjacent.coordonnee_X,pion_adjacent.coordonnee_Y);
     


  }

  if (borne ==2)
  {
    borne_up = 1;
    int end =0;
   

        tab_case[0].coordonnee_Y=plateau[y][x].coordonnee_Y;
        tab_case[0].coordonnee_X=plateau[y][x].coordonnee_X;
        tab_case[0].joueur=plateau[y][x].joueur;
        tab_case[0].borne=plateau[y][x].borne;

        i++;
       

        pion_adjacent=parcourir_case(plateau,plateau[y][x].coordonnee_Y,plateau[y][x].coordonnee_X,borne_up,plateau[y][x].joueur,&end,&i);
        sortie=nb_touche(plateau, pion_adjacent.coordonnee_X,pion_adjacent.coordonnee_Y);




  }


  return (pion_adjacent.borne);
}

int borne_oppose(pile *p, int joueur) {
  int vrai = 0;
  int borne = 0;
  pile *p_aux = p;
  Cell *sommet = p->top;
  int borne_next = 0;
  int sortie=0;
  borne = p_aux->top->elt.borne;                


  if (borne == 1)
  {
    while (p_aux->top->next!=NULL && borne_next!=2 && sortie == 0 )
    {
      p_aux->top = p_aux->top->next;
      if (p_aux->top->next != NULL){

        p_aux->top=p_aux->top->next;
        borne_next = p_aux->top->elt.borne;
     }
     else sortie = 1;
     if(borne_next==2) vrai=1;
   }
  }
  if (borne == 2)
  {
    while (p_aux->top->next!=NULL && borne_next!=2 && sortie == 0 )
    {
      p_aux->top = p_aux->top->next;
      if (p_aux->top->next != NULL){

        p_aux->top=p_aux->top->next;
        borne_next = p_aux->top->elt.borne;
     }
     else sortie = 1;
     if(borne_next==1) vrai=1;

   }
  }

p->top=sommet;

return (vrai);

}


int victoire(int joueur, pile *p, Case plateau[11][11]) {
  int fin = 0;

  int borne_op;
  remplir_tab(tab_case);
  remplir_tab(tab_adjacente);

  

  // if (p->top->elt.borne == 0)  { 
  //   printf("continue jeux\n"); 
  //   return (fin); }


  fin = borne_oppose(p, joueur);
  if (!fin)
     return (fin);

  else {
    fin =0;

    int borne = p->top->elt.borne;
    int x = p->top->elt.coordonnee_x;    
    int y = p->top->elt.coordonnee_y;

    printf("Coordonnée début&joueur   :   y: %d   x : %d joueur : %d  borne : %d  \n", plateau[y][x].coordonnee_Y,plateau[y][x].coordonnee_X,plateau[y][x].joueur,plateau[y][x].borne ); 


    borne_op = deplacement_plateau(plateau, y, x, borne);
    printf("deplacement_plateau finis\n");

    if (borne == 1 && borne_op == 2) fin = 1; 

    if (borne == 2 && borne_op == 1) fin = 1; 
  }
  printf("fin du jeu : %d\n",fin );

  return (fin);
}
