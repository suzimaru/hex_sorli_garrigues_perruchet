#include "Sauvegarde_histo.h"




void afficher_plateau(int matrice[TAILLE_PLATEAU][TAILLE_PLATEAU],FILE *fichier){
	int i,j;
	for(i=0;i<TAILLE_PLATEAU;i++){
		for(j=0;j<TAILLE_PLATEAU;j++){
			if (matrice[i][j]==-1){ //la case est vide
				fprintf(fichier,". ");	
			}else if (matrice[i][j]==1){ //la case est rouge
				fprintf(fichier,"R ");
			}else if (matrice[i][j]==0){ //la case est bleue
				fprintf(fichier,"B ");
			}else{
				printf("Ce caractere n'est pas compatible avec le plateau\n");
				exit(1);
			}
		}
		fprintf(fichier,"\n");
	}
}


void sauvegarde_fichier(char name_save[],pile *historique){

	int plateau[TAILLE_PLATEAU][TAILLE_PLATEAU];
	int i=1;
	int j;
	pile *paux=historique;
	Cell *psave=historique->top;
	int position_endgame=291,position_endhex=301,position_game,position_endboard,position_board;
	struct cell_element elt;


	//ouvrir un fichier

	char nom_fichier[20];
	sprintf(nom_fichier,"save/%s.txt",name_save);
	FILE* fichier=NULL;
	fichier=fopen(nom_fichier,"w");

	if (fichier ==	NULL){
		printf("Impossible d'ouvrir ce fichier de sauvegarde\n");
	}
	
	//initialisation du fichier de sauvegarde
	while(i<TAILLE_MAX_FICHIER){
		if(i==1){
			fprintf(fichier,"\\Hex\n");	//fichier commence par le mot \hex
		}else if(i==3){
			fprintf(fichier,"\\Board\n");//description du plateau de jeu par le mot \board
			position_board=i;
		}else if(i==258){
			fprintf(fichier,"\\Endboard\n");//fin de la description du plateau de jeu \endboard
			position_endboard=i;
		}else if(i==260){
			fprintf(fichier,"\\Game\n");//historique de jeu dans la section \game
			position_game=i;
		}else{
			fprintf(fichier,"\n");
		}
		i++;
	}


	

	/* initialisation du plateau */
	
	for(i=0;i<TAILLE_PLATEAU;i++){
		for(j=0;j<TAILLE_PLATEAU;j++){
			plateau[i][j]=-1;
		}
	}
	
	
	fseek(fichier,position_game+24,SEEK_SET);

	while (paux->top!=NULL){
		
		elt=paux->top->elt;
		plateau[elt.coordonnee_y][elt.coordonnee_x]=elt.joueur;
		fprintf(fichier,"\\play %d %d %d\n",elt.joueur,elt.coordonnee_y+1,elt.coordonnee_x+1);
		paux->top=paux->top->next;
		position_endgame += 14;
		position_endhex += 14;		
	}
	fprintf(fichier,"\\Endgame\n");
	fprintf(fichier,"\\Endhex\n");

	historique->top=psave;
	

	fseek(fichier,position_board+11,SEEK_SET);
	afficher_plateau(plateau,fichier);
	

	//fermer le fichier

	fclose(fichier);
}









void chargement(pile *p,int *joueur,int plateau[TAILLE_PLATEAU][TAILLE_PLATEAU],char name_save[],int *x,int *y){
	
	int i,j;
	char pion;
	element coup;
	char fin_game[20]="\\Endgame\n";
	char position_courante[20];
	/*Ouvrir le fichier de sauvegarde*/

	char nom_fichier[20];
	sprintf(nom_fichier,"save/%s.txt",name_save);
	FILE* fichier=NULL;
	fichier=fopen(nom_fichier,"r");

	if (fichier ==	NULL){
		printf("Impossible d'ouvrir ce fichier de sauvegarde\n");
	}


	fseek(fichier,14,SEEK_SET);

	for(i=0;i<TAILLE_PLATEAU;i++){
		for(j=0;j<TAILLE_PLATEAU;j++){
			fscanf(fichier,"%c ",&pion);
			if(pion=='B'){
				plateau[i][j]=0;
			}else if(pion=='R'){
				plateau[i][j]=1;
			}else{
				plateau[i][j]=-1;
			}
		}
	}


	/*Parcourir le fichier pour trouver le debut de l'historique*/
	fseek(fichier,278,SEEK_SET);
	fgets(position_courante,20,fichier);
	while (strcmp(position_courante,fin_game)!=0 && feof(fichier)==0){
		printf("charger : boucle ");
		fscanf(fichier,"\\play %d %d %d",&coup.joueur,&coup.coordonnee_y,&coup.coordonnee_x);
		coup.coordonnee_x=coup.coordonnee_x-1;
		coup.coordonnee_y=coup.coordonnee_y-1;
		printf("y %d x %d\n",coup.coordonnee_y,coup.coordonnee_x);
		empiler_pile(p,coup);
		printf("\\play %d %d %d\n",p->top->elt.joueur,p->top->elt.coordonnee_y-1,p->top->elt.coordonnee_x-1);
		fgets(position_courante,20,fichier);
		printf("%s",position_courante);
	}
	
	depiler(p);
	depiler(p);
	depiler(p);
	
	

// Il faudra return le dernier pion joué (ligne, colonne, numero du joueur)
// si vous testez avec la sauvegarde 2 (j'ai rentré les coordonnées à la main pour le dernier coup jouer) ça affiche les
// bonnes infos 
// quand on charge ça remplit pas la pile donc quand on sauvegarde une partie qu'on a changé aupréalablement, y a que les données 
// qui ont été rentrées APRÈS la sauvegarde qui sont sauvegardées du coup ça marche pas vraiment faudrait que tu rajoutes une pile 
// dans ta fonction chargement je pense
	coup=sommet(p);

	*joueur=coup.joueur;
	*x=coup.coordonnee_x;
	*y=coup.coordonnee_y;


	fclose(fichier);

	
}

