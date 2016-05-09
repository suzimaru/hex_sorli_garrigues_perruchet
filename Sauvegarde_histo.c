/*Fichier Sauvegarde_histo.c
Fonction: 	afficher_plateau
			sauvegarde_fichier
			chargement

afficher_plateau:	Prend en parametre:	un tableau d'integer à 2 dimensions,un fichier
					Execution:	Parcours le tableau à 2 dimensions et l'affiche dans le fichier de sauvegarde en remplacant les valeur par les caractères B,R ou .

sauvegarde_fichier	Prend en parametre:	une chaine de caractère(le nom de la sauvegarde) et une pile (historique)
					Execution:	Ouvre un fichier texte du nom de la chaine de charactere en mode ecriture, Initialise le fichier avec les balises \Hex,\board,..
								Ensuite depile l'historique et ecrit une ligne dans le fichier de sauvegarde pour chaque coup joué sous la forme :\play joueur X Y
								place les balises de fin de fichier et ferme le fichier.

chargement			Prend en parametre:	pile *p,int *joueur,int plateau[TAILLE_PLATEAU][TAILLE_PLATEAU],char name_save[],int *x,int *y
					Execution: 	Cette fonction ouvre un fichier de sauvegarde passé en parametre , récupere le plateau de jeu inscrit dans le fichier, ensuite il parcours 
								l'historique pour recuperer chaque coup joué,enfin il renvoi le dernier coup joué,une pile contenant l'historique et un plateau avec les informations
								de position des cases
*/




#include "Sauvegarde_histo.h"




void afficher_plateau(int matrice[TAILLE_PLATEAU][TAILLE_PLATEAU],FILE *fichier){
	int i,j;
	for(i=0;i<TAILLE_PLATEAU;i++){
		for(j=0;j<TAILLE_PLATEAU;j++){
			if (matrice[i][j]==-1){      	//la case est vide
				fprintf(fichier,". ");	
			}else if (matrice[i][j]==1){ 	//la case est rouge
				fprintf(fichier,"R ");
			}else if (matrice[i][j]==0){ 	//la case est bleue
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
		exit(1);
	}
	
	//initialisation du fichier de sauvegarde

	while(i<TAILLE_MAX_FICHIER){
		if(i==1){
			fprintf(fichier,"\\Hex\n");
		}else if(i==3){
			fprintf(fichier,"\\Board\n");
			position_board=i;
		}else if(i==258){
			fprintf(fichier,"\\Endboard\n");
			position_endboard=i;
		}else if(i==260){
			fprintf(fichier,"\\Game\n");
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
	
	/*On positionne le curseur du fichier au debut de l'historique*/
	
	fseek(fichier,position_game+24,SEEK_SET);

	while (paux->top!=NULL){
		/*on parcours la pile et on recupere les données de chaque coup 
		on sort de la boucle lorsque l'on a fini la pile*/

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
	
	int i,j,n=0;
	char pion;
	element coup;
	char fin_game[20]="Endgame\n";
	char position_courante[20];

	/*Ouvrir le fichier de sauvegarde*/

	char nom_fichier[20];
	sprintf(nom_fichier,"save/%s.txt",name_save);
	FILE* fichier=NULL;
	fichier=fopen(nom_fichier,"r");

	if (fichier ==	NULL){
		printf("Impossible d'ouvrir ce fichier de sauvegarde\n");
		exit(1);
	}

	/*récupere le plateau de jeu inscrit dans le fichier*/
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

	/*On parcours l'historique de jeu dans le fichier de sauvegarde et on s'arrete lorsque l'on rencontre 
	l chaine de caractere Endgame */

	while (strcmp(position_courante,fin_game)!=0 && feof(fichier)==0){
		fscanf(fichier,"\\play %d %d %d",&coup.joueur,&coup.coordonnee_y,&coup.coordonnee_x);
		coup.coordonnee_x=coup.coordonnee_x-1;
		coup.coordonnee_y=coup.coordonnee_y-1;
		if (n==0){
			*joueur=coup.joueur;
			*x=coup.coordonnee_x;
			*y=coup.coordonnee_y;
		}
		empiler_pile(p,coup);
		fgets(position_courante,20,fichier);
		n++;
	}

	if(!estVide(p)){
		depiler(p);
	}

	fclose(fichier);

	
}

