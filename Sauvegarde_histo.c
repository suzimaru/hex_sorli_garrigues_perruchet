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


void sauvegarde(char name_save[],pile *historique){

	int plateau[TAILLE_PLATEAU][TAILLE_PLATEAU];
	int i=1;
	int j;
	int position_endgame,position_endhex,position_game,position_endboard,position_board;

	//ouvrir un fichier

	char nom_fichier[20];
	sprintf(nom_fichier,"%s.txt",name_save);
	FILE* fichier=NULL;
	fichier=fopen(nom_fichier,"w+");

	if (fichier ==	NULL){
		printf("Impossible d'ouvrir ce fichier de sauvegarde\n");
	}
	
	//initialisation du fichier de sauvegarde
	while(i<TAILLE_MAX_FICHIER){
		if(i==1){
			fprintf(fichier,"\\Hex\n");	//fichier commence par le mot \hex
		}else if(i==4){
			fprintf(fichier,"	\\Board\n");//description du plateau de jeu par le mot \board
			position_board=i;
		}else if(i==260){
			fprintf(fichier,"	\\Endboard\n");//fin de la description du plateau de jeu \endboard
			position_endboard=i;
		}else if(i==263){
			fprintf(fichier,"	\\Game\n");//historique de jeu dans la section \game
			position_game=i;
		}else if(i==265){
			fprintf(fichier,"	\\Endgame\n");//on fini la section historique avec un \endgame
			position_endgame=i;
		}else if(i==267){
			fprintf(fichier,"\\Endhex\n");//fichier clos \endhex
			position_endhex=i;
		}else{
			fprintf(fichier,"\n");
		}
		i++;
	}


	fseek(fichier,position_board+12,SEEK_SET);
	

	/* initialisation du plateau */
	
	for(i=0;i<TAILLE_PLATEAU;i++){
		for(j=0;j<TAILLE_PLATEAU;j++){
			plateau[i][j]=0;
		}
	}
	
	afficher_plateau(plateau,fichier);
	

	while (!estVide(historique)){
		fseek(fichier,position_game+12,SEEK_SET);
		fprintf(fichier,"\\play %d %d %d \n",historique->elt.joueur,historique->elt.coordonnee_x,historique->elt.coordonnee_y);
		depiler(historique);
		position_endgame++;
		position_endhex++;		
	}
	
	fseek(fichier,position_endgame,SEEK_SET);
	fprintf(fichier,"	\\Endgame\n");


	fseek(fichier,position_endhex,SEEK_SET);
	fprintf(fichier,"\\Endhex\n");
	

	//fermer le fichier

	fclose(fichier);
}



// char name[6]="save_1";
// pile histo;
// sauvegarde(name,&histo);

