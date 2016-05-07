#include "victoire.h"

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
      if (plateau[y][x].joueur == plateau[y - 1][x].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y - 1][x - 1].joueur) touche++;
      if (plateau[y][x].joueur == plateau[y][x - 1].joueur) touche++;
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
      if (plateau[y][x].joueur == plateau[y + 1][x].joueur) touche++;
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

Case trouver_case(Case plateau[11][11], int lvl_ligne, int lvl_colonne, int y,
                  int x)  // Au premier lancement lvl_ligne = lvl_colonne = 0
 {
 Case new_case;
  new_case.coordonnee_Y = 0;
  new_case.coordonnee_X = 0;
  new_case.borne = 0;
  new_case.joueur = -1;

//   printf("------> trouver case\n");
//      printf("coordonnée testé trouvé case  :  Y : %d X: %d \n",y,x );
//      printf("niveau ligne : %d niveau colonne : %d \n",lvl_ligne,lvl_colonne );


//   if (lvl_ligne == 0) {
//     if (lvl_colonne ==
//         1)  // Le programme recherche case par case s'il y a une case adjacente
//     {
//       // if (plateau[y][x - 1].joueur == plateau[y][x].joueur)
//       printf("test1\n");
//               if (plateau[y-1][x].joueur == plateau[y][x].joueur)

//         {new_case = plateau[y-1][x]; printf(" plateau[y-1][x] coordonnée : y %d x : %d joueur : %d \n",plateau[y-1][x].coordonnee_Y,plateau[y-1][x].coordonnee_X, plateau[y-1][x].joueur ); }
//     }
//     if (lvl_colonne == 2) {
//       printf("test2\n");
//             // if (plateau[y + 1][x - 1].joueur == plateau[y][x].joueur)

//       if (plateau[y - 1][x + 1].joueur == plateau[y][x].joueur)
//         {new_case = plateau[y-1][x + 1]; printf(" plateau[y-1][x + 1]  coordonnée : y %d x : %d joueur : %d \n",plateau[y-1][x + 1].coordonnee_Y,plateau[y-1][x + 1].coordonnee_X, plateau[y-1][x + 1].joueur ); }
//     }
//   }
  
//   if (lvl_ligne == 1) {
//     if (lvl_colonne == 0) {
//       printf("test3\n");
//       // if (plateau[y - 1][x].joueur == plateau[y][x].joueur)
//               if (plateau[y][x-1].joueur == plateau[y][x].joueur)

//         {new_case = plateau[y][x-1];printf(" plateau[y][x-1] coordonnée : y %d x : %d joueur : %d \n",plateau[y][x-1].coordonnee_Y,plateau[y][x-1].coordonnee_X, plateau[y][x-1].joueur );  }
//     }

//     if (lvl_colonne == 2) {
//       // if (plateau[y + 1][x].joueur == plateau[y][x].joueur)
//       printf("test4\n");
//               if (plateau[y][x+1].joueur == plateau[y][x].joueur)

//         {new_case = plateau[y][x+1];printf(" plateau[y][x+1] coordonnée : y %d x : %d joueur : %d \n",plateau[y][x+1].coordonnee_Y,plateau[y][x+1].coordonnee_X, plateau[y][x+1].joueur ); }
//     }
//   }

//   if (lvl_ligne == 2) {
//     if (lvl_colonne == 0) {
//       // if (plateau[y - 1][x + 1].joueur == plateau[y][x].joueur)
//       printf("test5\n");
//               if (plateau[y + 1][x - 1].joueur == plateau[y][x].joueur)

//         {new_case = plateau[y+1][x - 1];printf(" plateau[y+1][x - 1] coordonnée : y %d x : %d joueur : %d \n",plateau[y+1][x - 1].coordonnee_Y,plateau[y+1][x-1].coordonnee_X, plateau[y+1][x-1].joueur ); }
//     }

//     if (lvl_colonne == 1) {
//       // if (plateau[y][x + 1].joueur == plateau[y][x].joueur)
//       printf("test6\n");
//               if (plateau[y+1][x].joueur == plateau[y][x].joueur)

//         {new_case = plateau[y+1][x];printf(" plateau[y+1][x] coordonnée : y %d x : %d joueur : %d \n",plateau[y+1][x].coordonnee_Y,plateau[y+1][x].coordonnee_X, plateau[y+1][x].joueur );}
//     }
//   }
//   printf("new_case : y : %d x : %d borne : %d joueur %d\n",new_case.coordonnee_Y,new_case.coordonnee_X,new_case.borne,new_case.joueur );
  return (new_case);
}

Case parcourir_case (Case plateau[11][11], int y, int x,int borne_up,int joueur_up,int *end)
{

  // int nb_adjacent=0;
  // int sortie=1;
  int lvl_ligne,lvl_colonne;
  Case pion_adjacent;
  pion_adjacent.coordonnee_Y = 0;
  pion_adjacent.coordonnee_X = 0;
  pion_adjacent.borne = 0;
  pion_adjacent.joueur = -1;
  int sortie =0;
   printf("coordonnée testé parcourir case :  Y : %d X: %d \n",y,x );
  // int sortie = 0;
  printf("-------> parcourir_case\n");

    printf("joueur testé : %d \n",joueur_up);


  printf("case du plateau : y :%d  x : %d  borne : %d joueur : %d \n",plateau[y][x].coordonnee_Y,plateau[y][x].coordonnee_X,plateau[y][x].borne,plateau[x][y].joueur );



    for (lvl_ligne = 0; lvl_ligne <=2 && *end !=15 ; lvl_ligne++) {
    // nb_adjacent = 0;

      for (lvl_colonne = 0; lvl_colonne <= 2 && *end != 15; lvl_colonne++) {
        printf("borne up : %d \n",borne_up );
        sortie=nb_touche(plateau, x,y);
        printf("nb touche : %d \n",sortie );

        pion_adjacent = trouver_case(plateau, lvl_ligne, lvl_colonne, y, x);
        printf("pion_adjacent y : %d x:%d borne : %d joueur : %d \n",pion_adjacent.coordonnee_Y,pion_adjacent.coordonnee_X,pion_adjacent.borne,pion_adjacent.joueur );
        // if (pion_adjacent.joueur == borne_up) 
        *end=*end+1;
        printf("comparaison joueur : joueur : %d  case test : %d \n",joueur_up,pion_adjacent.joueur );
        printf("borne up : %d borne pion : %d finis : %d \n",borne_up,pion_adjacent.borne,*end );
        if (pion_adjacent.joueur == joueur_up && pion_adjacent.borne != borne_up && *end !=15)
          {          printf("pion_adjacent retourné x : %d y:%d borne : %d joueur : %d \n",pion_adjacent.coordonnee_Y,pion_adjacent.coordonnee_X,pion_adjacent.borne,pion_adjacent.joueur );
return(parcourir_case(plateau, pion_adjacent.coordonnee_X,
                              pion_adjacent.coordonnee_Y,borne_up,joueur_up,end));}
        
      }
    }
  
          printf("pion_adjacent retourné y : %d x:%d borne : %d joueur : %d \n",pion_adjacent.coordonnee_Y,pion_adjacent.coordonnee_X,pion_adjacent.borne,pion_adjacent.joueur );

  return (pion_adjacent);


}



int deplacement_plateau(Case plateau[11][11], int y, int x, int borne) {
  // int lvl_colonne, lvl_ligne = 0;
  int sortie = 1;

  printf("coordonnée testé déplacement plateau :  Y : %d X: %d \n",y,x );

  Case pion_adjacent;
  pion_adjacent.coordonnee_Y = 0;
  pion_adjacent.coordonnee_X = 0;
  pion_adjacent.borne = 0;
  pion_adjacent.joueur = -1;
  // int nb_adjacent;
  // int end = 0;
  // int fin = 0;
  int borne_up;
  printf("------> deplacement\n");

  printf("case du plateau : y :%d  x : %d  borne : %d joueur : %d \n",plateau[y][x].coordonnee_Y,plateau[y][x].coordonnee_X,plateau[y][x].borne,plateau[y][x].joueur );

  

  if (borne ==1)
  {
    int end = 0;
    borne_up = 2;
    // printf("borne 1\n");
    // printf("pion_adjacent borne : %d  sortie : %d\n",pion_adjacent.borne,sortie );


        pion_adjacent=parcourir_case(plateau,y,x,borne_up,plateau[y][x].joueur,&end);
        sortie=nb_touche(plateau, pion_adjacent.coordonnee_Y,pion_adjacent.coordonnee_X);
     


  }

  if (borne ==2)
  {
    borne_up = 1;
    int end =0;
    // printf("borne 2\n");
    //  printf("pion_adjacent borne : %d  sortie : %d\n",pion_adjacent.borne,sortie );

      

        pion_adjacent=parcourir_case(plateau,x,y,borne_up,plateau[x][y].joueur,&end);
        sortie=nb_touche(plateau, pion_adjacent.coordonnee_X,pion_adjacent.coordonnee_Y);




  }

  printf("pion adjacent borne : %d \n",pion_adjacent.borne );

  return (pion_adjacent.borne);
}

int borne_oppose(pile *p, int joueur) {
  int vrai = 0;
  int borne = 0;
  pile *p_aux = p;
  Cell *sommet = p->top;
  // printf("sommet : %d\n",sommet->elt.borne );
  int borne_next = 0;
  int sortie=0;
  borne = p_aux->top->elt.borne;                
  // printf("valeur borne = %d \n", borne);


  if (borne == 1)
  {
    while (p_aux->top->next!=NULL && borne_next!=2 && sortie == 0 )
    {
      // printf("joueur : %d\n",p_aux->top->elt.joueur );
      p_aux->top = p_aux->top->next;
      if (p_aux->top->next != NULL){

        p_aux->top=p_aux->top->next;
        borne_next = p_aux->top->elt.borne;
        // printf("borne suivante : %d\n",borne_next );
     }
     else sortie = 1;
     if(borne_next==2) vrai=1;
   }
  }
  if (borne == 2)
  {
    while (p_aux->top->next!=NULL && borne_next!=2 && sortie == 0 )
    {
      // printf("joueur : %d\n",p_aux->top->elt.joueur );
      p_aux->top = p_aux->top->next;
      if (p_aux->top->next != NULL){

        p_aux->top=p_aux->top->next;
        borne_next = p_aux->top->elt.borne;
        // printf("borne suivante : %d\n",borne_next );
     }
     else sortie = 1;
     if(borne_next==1) vrai=1;

   }
  }
 // printf("borne opposé vrai : %d\n",vrai );

p->top=sommet;
// printf("pile sommet  : %d\n",p->top->elt.borne );

return (vrai);

}


int victoire(int joueur, pile *p, Case plateau[11][11]) {
  int fin = 0;

  int borne_op;

  // printf("borne sommet = %d\n", p->elt.borne );
  
  // int nb_element_pile = nb_element(p);
  // printf("nombre d'élément dans la pile : %d\n", nb_element_pile );

  if (p->top->elt.borne == 0)  { 
    printf("continue jeux\n"); 
    return (fin); }


  fin = borne_oppose(p, joueur);
  if (!fin)
     return (fin);

  else {
    fin =0;

    int borne = p->top->elt.borne;
    int x = p->top->elt.coordonnee_x;    
    int y = p->top->elt.coordonnee_y;

    printf("Coordonnée début :   y: %d   x : %d \n", y,x ); 


    borne_op = deplacement_plateau(plateau, y, x, borne);
    // printf("borne_op = %d || borne = %d \n",borne_op,borne );
    printf("deplacement_plateau finis\n");

    if (borne == 1 && borne_op == 2) fin = 1; 

    if (borne == 2 && borne_op == 1) fin = 1; 
  }
  printf("fin du jeu : %d\n",fin );

  return (fin);
}
