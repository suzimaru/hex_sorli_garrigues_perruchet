#include "interface_graphique.h"

/* Auteur SORLI Suzanne
Ce module est l'interface graphique, il gère tous les menus, tous les affichages de pion, et appelle les fonctionnalités
correspondantes (dans les autres modules).
Ce module nécéssite les différentes fonctionnalités appelées dans pendant exécution*/

int nb_joueur;
/////////////////////////////////////////////////////////////////

int nb_pions = 0;

/*Cette fonction vérifie si l'endroit du clic correspond à l'emplacement indiqué dans les paramètres.
Clic c étant le clic, borneinfX et borneInfY étant les coordonnées du point en haut à gauche du rectangle
BorneSupX et BorneSupY étant les coordonnées du point en bas à droite du rectangle
Il renvoie un int booléen si le clic est dans le rectangle ou non.*/
int clic_Valide(Clic c, int borneInfX, int borneInfY, int borneSupX,
                int borneSupY) {
  return ((c.x >= borneInfX && c.x <= borneSupX) &&
          (c.y >= borneInfY && c.y <= borneSupY));
}


/*Cette fonction affiche le menu correspondant au numéro du menu associé.
int menu est le numéro du menu*/
void affichage_menu(int menu) {
  switch (menu) {
    case (1): {
      //Menu principal
      posTexte1.x = 315;
      posTexte1.y = 60;

      posJouer.x = 340;
      posJouer.y = 250;

      posCharger.x = 325;
      posCharger.y = 345;

      posQuitter.x = 335;
      posQuitter.y = 445;

      position_fond.x = 0;
      position_fond.y = 0;

      posTexte_menu.x = 340;
      posTexte_menu.y = 150;

      posTexte_auteur.x = 255;
      posTexte_auteur.y = 540;

      TTF_Font *fontAuteur =
          TTF_OpenFont("hacked/hacked.ttf", 22); 
      TTF_Font *fontMenu =
          TTF_OpenFont("hacked/hacked.ttf", 40); 

      SDL_Color fontPurple = {0, 51, 102};  

      texte_auteur = TTF_RenderText_Blended(
          fontAuteur, "Garrigues, Perruchet, Sorli 2016", fontPurple);

      TTF_SetFontStyle(fontMenu, TTF_STYLE_BOLD);
      texte_menu = TTF_RenderText_Blended(fontMenu, "MENU", fontPurple);
      texte1 = TTF_RenderText_Blended(fontMenu, "Jeu HEX", fontPurple);
      TTF_SetFontStyle(fontMenu, TTF_STYLE_NORMAL);

      jouer = TTF_RenderText_Blended(fontMenu, "Jouer", fontPurple);
      charger = TTF_RenderText_Blended(fontMenu, "Charger", fontPurple);
      quitter = TTF_RenderText_Blended(fontMenu, "Quitter", fontPurple);

      SDL_BlitSurface(image_fond, NULL, ecran, &position_fond);
      SDL_BlitSurface(jouer, NULL, ecran, &posJouer);
      SDL_BlitSurface(charger, NULL, ecran, &posCharger);
      SDL_BlitSurface(quitter, NULL, ecran, &posQuitter);
      SDL_BlitSurface(
          texte1, NULL, ecran,
          &posTexte1); 
      SDL_BlitSurface(texte_menu, NULL, ecran, &posTexte_menu);
      SDL_BlitSurface(texte_auteur, NULL, ecran, &posTexte_auteur);

      SDL_Flip(ecran);

      TTF_CloseFont(fontMenu);
      TTF_CloseFont(fontAuteur);
      break;
    }
    case (2): {
      //Menu secondaire
      posQuitter.x = 335;
      posQuitter.y = 435;

      position_fond.x = 0;
      position_fond.y = 0;

      posTexte_menu.x = 345;
      posTexte_menu.y = 15;

      posTexte_auteur.x = 255;
      posTexte_auteur.y = 540;

      posHvsH.x = 260;
      posHvsH.y = 155;

      posHvsIA1.x = 285;
      posHvsIA1.y = 225;

      posHvsIA2.x = 285;
      posHvsIA2.y = 295;

      posIAvsIA.x = 335;
      posIAvsIA.y = 85;

      posretour.x = 340;
      posretour.y = 365;

      TTF_Font *fontAuteur =
          TTF_OpenFont("hacked/hacked.ttf", 22);  
      TTF_Font *fontMenu =
          TTF_OpenFont("hacked/hacked.ttf", 40); 

      SDL_Color fontPurple = {0, 51, 102};  
      texte1 = TTF_RenderText_Blended(fontMenu, "Jeu HEX",
                                      fontPurple);  
      HvsH = TTF_RenderText_Blended(fontMenu, "Humain VS Humain", fontPurple);
      HvsIA1 = TTF_RenderText_Blended(fontMenu, "Humain VS IA1", fontPurple);
      HvsIA2 = TTF_RenderText_Blended(fontMenu, "Humain VS IA2", fontPurple);
      IAvsIA = TTF_RenderText_Blended(fontMenu, "IA VS IA", fontPurple);
      retour = TTF_RenderText_Blended(fontMenu, "Retour", fontPurple);

      texte_auteur = TTF_RenderText_Blended(
          fontAuteur, "Garrigues, Perruchet, Sorli 2016", fontPurple);

      TTF_SetFontStyle(fontMenu, TTF_STYLE_BOLD);
      texte_menu = TTF_RenderText_Blended(fontMenu, "MENU", fontPurple);
      TTF_SetFontStyle(fontMenu, TTF_STYLE_NORMAL);

      jouer = TTF_RenderText_Blended(fontMenu, "Jouer", fontPurple);
      charger = TTF_RenderText_Blended(fontMenu, "Charger", fontPurple);
      quitter = TTF_RenderText_Blended(fontMenu, "Quitter", fontPurple);

      SDL_BlitSurface(image_fond, NULL, ecran, &position_fond);
      SDL_BlitSurface(HvsH, NULL, ecran, &posHvsH);
      SDL_BlitSurface(IAvsIA, NULL, ecran, &posIAvsIA);
      SDL_BlitSurface(HvsIA1, NULL, ecran, &posHvsIA1);
      SDL_BlitSurface(quitter, NULL, ecran, &posQuitter);
      SDL_BlitSurface(HvsIA2, NULL, ecran, &posHvsIA2);
      SDL_BlitSurface(texte_menu, NULL, ecran, &posTexte_menu);
      SDL_BlitSurface(texte_auteur, NULL, ecran, &posTexte_auteur);
      SDL_BlitSurface(retour, NULL, ecran, &posretour);
      SDL_Flip(ecran);

      TTF_CloseFont(fontMenu);
      TTF_CloseFont(fontAuteur);
      break;
    }
    case (3): {
      //Menu du choix du niveau de l'IA
      posNiveau.x = 140;
      posNiveau.y = 65;

      pos1IA.x = 165;
      pos1IA.y = 220;

      pos2IA.x = 165;
      pos2IA.y = 350;

      posretour.x = 165;
      posretour.y = 475;

      TTF_Font *fontMenu =
          TTF_OpenFont("hacked/hacked.ttf", 40); 
      SDL_Color fontPurple = {0, 51, 102};       

      niveau = TTF_RenderText_Blended(fontMenu, "Quel est le niveau des IA ?",
                                      fontPurple);
      niveau_premier_IA = TTF_RenderText_Blended(
          fontMenu, "Premiere IA :          1          2", fontPurple);
      niveau_deuxieme_IA = TTF_RenderText_Blended(
          fontMenu, "Deuxieme IA :          1          2", fontPurple);
      retour = TTF_RenderText_Blended(fontMenu, "Retour", fontPurple);

      SDL_BlitSurface(image_fond, NULL, ecran, &position_fond);
      SDL_BlitSurface(niveau, NULL, ecran, &posNiveau);
      SDL_BlitSurface(niveau_premier_IA, NULL, ecran, &pos1IA);
      SDL_BlitSurface(niveau_deuxieme_IA, NULL, ecran, &pos2IA);
      SDL_BlitSurface(retour, NULL, ecran, &posretour);
      SDL_Flip(ecran);

      TTF_CloseFont(fontMenu);

      break;
    }
    case (4): {
      //Fenetre de jeu avec le plateau et les fonctionnalités associées
      posPlateau.x = 15;
      posPlateau.y = 140;

      position_fond.x = 0;
      position_fond.y = 0;

      Uint32 couleur_cacheur = SDL_MapRGB(ecran->format, 204, 204, 255);
      pos_cacheur.x = 15;
      pos_cacheur.y = 75;

      pos_cacheur2.x = 15;
      pos_cacheur2.y = 465;
      cacheur = SDL_CreateRGBSurface(SDL_HWSURFACE, 235, 40, 32, 0, 0, 0, 0);
      cacheur2 = SDL_CreateRGBSurface(SDL_HWSURFACE, 600, 60, 32, 0, 0, 0, 0);
      SDL_FillRect(cacheur2, NULL, couleur_cacheur);
      SDL_FillRect(cacheur, NULL, couleur_cacheur);
      pion_annule = IMG_Load("Images/Undon.png");
      PLATEAU = IMG_Load("Images/plateau.png");
      TTF_Font *fontMenu = TTF_OpenFont("hacked/hacked.ttf", 40);
      SDL_Color fontPurple = {0, 51, 102};
      quitter = TTF_RenderText_Blended(fontMenu, "Quitter", fontPurple);
      sauvegarder = TTF_RenderText_Blended(fontMenu, "Sauvegarder", fontPurple);
      undo = TTF_RenderText_Blended(fontMenu, "Undo", fontPurple);
      abandon = TTF_RenderText_Blended(fontMenu, "Abandon", fontPurple);
      retour = TTF_RenderText_Blended(fontMenu, "retour", fontPurple);
      SDL_BlitSurface(image_fond, NULL, ecran, &position_fond);

      SDL_BlitSurface(PLATEAU, NULL, ecran, &posPlateau);

      posSauvegarder.x = 545;
      posSauvegarder.y = 80;

      posUndo.x = 545;
      posUndo.y = 160;

      posQuitter.x = 545;
      posQuitter.y = 400;

      posretour.x = 545;
      posretour.y = 320;

      pos_abandon.x = 545;
      pos_abandon.y = 240;

      if (nb_joueur == 0)
        info_joueur =
            TTF_RenderText_Blended(fontMenu, "Joueur Bleu", fontPurple);
      else
        info_joueur =
            TTF_RenderText_Blended(fontMenu, "Joueur Rouge", fontPurple);

      pos_info_joueur.x = 15;
      pos_info_joueur.y = 75;

      pos_info_coup.x = 15;
      pos_info_coup.y = 475;
      SDL_BlitSurface(cacheur, NULL, ecran, &pos_cacheur);
      SDL_BlitSurface(info_joueur, NULL, ecran, &pos_info_joueur);
      SDL_BlitSurface(sauvegarder, NULL, ecran, &posSauvegarder);
      SDL_BlitSurface(undo, NULL, ecran, &posUndo);
      SDL_BlitSurface(quitter, NULL, ecran, &posQuitter);
      SDL_BlitSurface(retour, NULL, ecran, &posretour);
      SDL_BlitSurface(abandon, NULL, ecran, &pos_abandon);
      SDL_BlitSurface(cacheur2, NULL, ecran, &pos_cacheur2);
      SDL_Flip(ecran);

      TTF_CloseFont(fontMenu);
      break;
    }
    case (5): {
      //Sous menu pour le choix de la sauvegarde à restaurer
      SDL_BlitSurface(image_fond, NULL, ecran, &position_fond);
      TTF_Font *fontMenu = TTF_OpenFont("hacked/hacked.ttf", 40);
      SDL_Color fontPurple = {0, 51, 102};

      posNiveau.x = 145;
      posNiveau.y = 85;
      niveau = TTF_RenderText_Blended(fontMenu, "Selectionnez une sauvegarde",
                                      fontPurple);
      SDL_BlitSurface(niveau, NULL, ecran, &posNiveau);

      enum_save = TTF_RenderText_Blended(
          fontMenu, "Save 1         Save 2         Save 3", fontPurple);
      pos_enum_save.x = 140;
      pos_enum_save.y = 285;

      posretour.x = 165;
      posretour.y = 475;
      retour = TTF_RenderText_Blended(fontMenu, "Retour", fontPurple);
      SDL_BlitSurface(retour, NULL, ecran, &posretour);

      SDL_BlitSurface(enum_save, NULL, ecran, &pos_enum_save);
      SDL_Flip(ecran);
      TTF_CloseFont(fontMenu);

      break;
    }
    case (6): {
      //Fenetre du score - Victoire
      SDL_BlitSurface(image_fond, NULL, ecran, &position_fond);
      TTF_Font *fontMenu = TTF_OpenFont("hacked/hacked.ttf", 40);
      SDL_Color fontPurple = {0, 51, 102};

      posretour.x = 80;
      posretour.y = 525;
      retour = TTF_RenderText_Blended(fontMenu, "Retour", fontPurple);
      SDL_BlitSurface(retour, NULL, ecran, &posretour);

      pos_victoire.x = 215;
      pos_victoire.y = 20;
      if (nb_joueur == 0)
        vic = TTF_RenderText_Blended(fontMenu, "victoire du joueur rouge !",
                                     fontPurple);
      else
        vic = TTF_RenderText_Blended(fontMenu, "victoire du joueur bleu !",
                                     fontPurple);
      SDL_BlitSurface(vic, NULL, ecran, &pos_victoire);
      SDL_BlitSurface(retour, NULL, ecran, &posretour);

      PLATEAU = IMG_Load("Images/victoire.jpg");
      posPlateau.x = 260;
      posPlateau.y = 70;
      SDL_BlitSurface(PLATEAU, NULL, ecran, &posPlateau);
      SDL_Flip(ecran);
      TTF_CloseFont(fontMenu);
    }
  }
}

/*Cette fonction nettoie les surfaces selon le menu
int menu est le numéro du menu*/
void clean(int menu) {
  switch (menu) {
    case (1): {
      SDL_FreeSurface(texte1);
      SDL_FreeSurface(texte_menu);
      SDL_FreeSurface(texte_auteur);
      SDL_FreeSurface(jouer);
      SDL_FreeSurface(charger);
      SDL_FreeSurface(quitter);

      break;
    }
    case (2): {
      SDL_FreeSurface(HvsH);
      SDL_FreeSurface(texte_menu);
      SDL_FreeSurface(texte_auteur);
      SDL_FreeSurface(IAvsIA);
      SDL_FreeSurface(HvsIA1);
      SDL_FreeSurface(HvsIA2);
      SDL_FreeSurface(quitter);
      SDL_FreeSurface(retour);

      break;
    }
    case (3): {
      SDL_FreeSurface(niveau);
      SDL_FreeSurface(niveau_deuxieme_IA);
      SDL_FreeSurface(niveau_premier_IA);
      SDL_FreeSurface(retour);

      break;
    }
    case (4): {
      SDL_FreeSurface(quitter);
      SDL_FreeSurface(sauvegarder);
      SDL_FreeSurface(undo);
      SDL_FreeSurface(abandon);
      SDL_FreeSurface(retour);

      SDL_FreeSurface(pion_bleu);
      SDL_FreeSurface(pion_rouge);

      SDL_FreeSurface(PLATEAU);
     /* SDL_FreeSurface(info_coup);
      SDL_FreeSurface(info_joueur);*/
      SDL_FreeSurface(pion_annule);

      break;
    }
    case (5): {
      SDL_FreeSurface(retour);
      SDL_FreeSurface(niveau);
      SDL_FreeSurface(enum_save);
      break;
    }
    case (6): {
      SDL_FreeSurface(retour);
      SDL_FreeSurface(PLATEAU);
      SDL_FreeSurface(vic);
    }
  }
}

/*Cette fonction fait jouer le joueur, permet de rajouter les pions en SDL, convertit les clics de la souris en 
int pour la ligne et la colonne, met à jour la pile pour l'historique de la partie, et renvoie un int booléen selon
l'état de la partie (victoire ou non)

nb_joueur est le numéro du joueur, nb_pion est le nombre de pion présents sur le plateau, Clic c est le clic récupéré par le
logiciel pour faire jouer le joueur, lig et col sont les résultats de la conversion du clic en coordonnées d'un pion.
annule est une variable qui sera mis à jour si on joue ou non. Si on a joué il sera possible d'annuler son coup, sinon on met
annule à 0 pour interdir le joueur de Undo. Le plateau va être modifié puisqu'on va rajouter les pions dans l'affichage en 
fonction du plateau que l'on modifie aussi grace à col et lig. p est la pile qui sera aussi modifiée afin de gérer l'historique.*/
int Jouer(int *nb_joueur, int *nb_pions, Clic c, int *lig, int *col,
          int *annule, Case plateau[11][11], pile *p) {
  TTF_Font *fontMenu = TTF_OpenFont("hacked/hacked.ttf", 40);
  SDL_Color fontPurple = {0, 51, 102};
  int vic = 1;
  int ancienne_lig = *lig;
  int ancienne_col = *col;
  int ajouer = 0;
  // LIGNE 0
  if (clic_Valide(c, 30, 165, 361, 181)) {
    *lig = 0;
    *col = (floor((c.x - 32) / 30));
    if (plateau[*lig][*col].joueur == -1) {
      pos_Pion.y = 163;
      pos_Pion.x = 30 * (*col) + 30 + 7;
      if (*nb_joueur == 0) {
        SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 0;
      } else {
        SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 1;
      }
      *nb_joueur = (*nb_joueur + 1) % 2;
      *nb_pions = *nb_pions + 1;
      *annule = 0;
      ajouer = 1;
    } else {
      *lig = ancienne_lig;
      *col = ancienne_col;
    }
  }

  // LIGNE 1
  if (clic_Valide(c, 45, 190, 374, 207)) {
    *lig = 1;
    *col = floor((c.x - 47) / 30);
    if (plateau[*lig][*col].joueur == -1) {
      pos_Pion.y = 188;
      pos_Pion.x = 30 * (*col) + 45 + 7;
      if (*nb_joueur == 0) {
        SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 0;
      } else {
        SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 1;
      }
      *nb_joueur = (*nb_joueur + 1) % 2;
      *nb_pions = *nb_pions + 1;
      *annule = 0;
      ajouer = 1;
    } else {
      *lig = ancienne_lig;
      *col = ancienne_col;
    }
  }

  // LIGNE 2
  if (clic_Valide(c, 60, 215, 389, 233)) {
    *lig = 2;
    *col = floor((c.x - 62) / 30);
    if (plateau[*lig][*col].joueur == -1) {
      pos_Pion.y = 213;
      pos_Pion.x = 30 * (*col) + 60 + 7;
      if (*nb_joueur == 0) {
        SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 0;
      } else {
        SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 1;
      }
      *nb_joueur = (*nb_joueur + 1) % 2;
      *nb_pions = *nb_pions + 1;
      *annule = 0;
      ajouer = 1;
    } else {
      *lig = ancienne_lig;
      *col = ancienne_col;
    }
  }
  // LIGNE 3
  if (clic_Valide(c, 75, 240, 406, 260)) {
    *lig = 3;
    *col = floor((c.x - 77) / 30);
    if (plateau[*lig][*col].joueur == -1) {
      pos_Pion.y = 238;
      pos_Pion.x = 30 * (*col) + 75 + 7;
      if (*nb_joueur == 0) {
        SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 0;
      } else {
        SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 1;
      }
      *nb_joueur = (*nb_joueur + 1) % 2;
      *nb_pions = *nb_pions + 1;
      *annule = 0;
      ajouer = 1;
    } else {
      *lig = ancienne_lig;
      *col = ancienne_col;
    }
  }

  // LIGNE 4
  if (clic_Valide(c, 90, 265, 421, 286)) {
    *lig = 4;
    *col = floor((c.x - 92) / 30);
    if (plateau[*lig][*col].joueur == -1) {
      pos_Pion.y = 263;
      pos_Pion.x = 30 * (*col) + 90 + 7;
      if (*nb_joueur == 0) {
        SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 0;
      } else {
        SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 1;
      }
      *nb_joueur = (*nb_joueur + 1) % 2;
      *nb_pions = *nb_pions + 1;
      *annule = 0;
      ajouer = 1;
    } else {
      *lig = ancienne_lig;
      *col = ancienne_col;
    }
  }

  // LIGNE 5
  if (clic_Valide(c, 105, 290, 435, 310)) {
    *lig = 5;
    *col = floor((c.x - 107) / 30);
    if (plateau[*lig][*col].joueur == -1) {
      pos_Pion.y = 288;
      pos_Pion.x = 30 * (*col) + 105 + 7;
      if (*nb_joueur == 0) {
        SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 0;
      } else {
        SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 1;
      }
      *nb_joueur = (*nb_joueur + 1) % 2;
      *nb_pions = *nb_pions + 1;
      *annule = 0;
      ajouer = 1;
    } else {
      *lig = ancienne_lig;
      *col = ancienne_col;
    }
  }

  // LIGNE 6
  if (clic_Valide(c, 120, 315, 451, 333)) {
    *lig = 6;
    *col = floor((c.x - 122) / 30);
    if (plateau[*lig][*col].joueur == -1) {
      pos_Pion.y = 313;
      pos_Pion.x = 30 * (*col) + 120 + 7;
      if (*nb_joueur == 0) {
        SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 0;
      } else {
        SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 1;
      }
      *nb_joueur = (*nb_joueur + 1) % 2;
      *nb_pions = *nb_pions + 1;
      *annule = 0;
      ajouer = 1;
    } else {
      *lig = ancienne_lig;
      *col = ancienne_col;
    }
  }

  // LIGNE 7
  if (clic_Valide(c, 135, 340, 466, 360)) {
    *lig = 7;
    *col = floor((c.x - 137) / 30);
    if (plateau[*lig][*col].joueur == -1) {
      pos_Pion.y = 338;
      pos_Pion.x = 30 * (*col) + 135 + 7;
      if (*nb_joueur == 0) {
        SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 0;
      } else {
        SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 1;
      }
      *nb_joueur = (*nb_joueur + 1) % 2;
      *nb_pions = *nb_pions + 1;
      *annule = 0;
      ajouer = 1;
    } else {
      *lig = ancienne_lig;
      *col = ancienne_col;
    }
  }

  // LIGNE 8
  if (clic_Valide(c, 150, 365, 481, 385)) {
    *lig = 8;
    *col = floor((c.x - 152) / 30);
    if (plateau[*lig][*col].joueur == -1) {
      pos_Pion.y = 363;
      pos_Pion.x = 30 * (*col) + 150 + 7;
      if (*nb_joueur == 0) {
        SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 0;
      } else {
        SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 1;
      }
      *nb_joueur = (*nb_joueur + 1) % 2;
      *nb_pions = *nb_pions + 1;
      *annule = 0;
      ajouer = 1;
    } else {
      *lig = ancienne_lig;
      *col = ancienne_col;
    }
  }

  // LIGNE 9
  if (clic_Valide(c, 165, 390, 496, 410)) {
    *lig = 9;
    *col = floor((c.x - 167) / 30);
    if (plateau[*lig][*col].joueur == -1) {
      pos_Pion.y = 388;
      pos_Pion.x = 30 * (*col) + 165 + 7;
      if (*nb_joueur == 0) {
        SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 0;
      } else {
        SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 1;
      }
      *nb_joueur = (*nb_joueur + 1) % 2;
      *nb_pions = *nb_pions + 1;
      *annule = 0;
      ajouer = 1;
    } else {
      *lig = ancienne_lig;
      *col = ancienne_col;
    }
  }
  // LIGNE 10
  if (clic_Valide(c, 180, 415, 511, 435)) {
    *lig = 10;
    *col = floor((c.x - 182) / 30);
    if (plateau[*lig][*col].joueur == -1) {
      pos_Pion.y = 413;
      pos_Pion.x = 30 * (*col) + 180 + 7;
      if (*nb_joueur == 0) {
        SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 0;
      } else {
        SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
        SDL_Flip(ecran);
        plateau[*lig][*col].joueur = 1;
      }
      *nb_joueur = (*nb_joueur + 1) % 2;
      *nb_pions = *nb_pions + 1;
      *annule = 0;
      ajouer = 1;
    } else {
      *lig = ancienne_lig;
      *col = ancienne_col;
    }
  }

  if (ajouer) {
    vic = jeux(*lig, *col, *nb_joueur, p, plateau);
    SDL_BlitSurface(cacheur2, NULL, ecran, &pos_cacheur2);
    if (*nb_pions != 0) {
      char char_coup[100] = "";

      // echange des joueurs car on l'incrémente avant
      if (*nb_joueur == 1) {
        sprintf(char_coup, "Le joueur bleu a joue en %d,%d", (*lig) + 1,
                (*col) + 1);
        info_coup = TTF_RenderText_Blended(fontMenu, char_coup, fontPurple);
        SDL_BlitSurface(info_coup, NULL, ecran, &pos_info_coup);
      } else if (*nb_joueur == 0) {
        sprintf(char_coup, "Le joueur rouge a joue en %d,%d", (*lig) + 1,
                (*col) + 1);
        info_coup = TTF_RenderText_Blended(fontMenu, char_coup, fontPurple);
        SDL_BlitSurface(info_coup, NULL, ecran, &pos_info_coup);
      }
    }
    SDL_BlitSurface(cacheur, NULL, ecran, &pos_cacheur);
    if (*nb_joueur == 0)
      info_joueur = TTF_RenderText_Blended(fontMenu, "Joueur Bleu", fontPurple);
    else
      info_joueur =
          TTF_RenderText_Blended(fontMenu, "Joueur Rouge", fontPurple);
    SDL_BlitSurface(info_joueur, NULL, ecran, &pos_info_joueur);
    SDL_BlitSurface(info_coup, NULL, ecran, &pos_info_coup);
    SDL_Flip(ecran);
  }
  return vic;
}

void Charge_plateau(int *nb_pions, Clic c, Case plateau[11][11], int lig,
                    int col, int *nb_joueur) {
  TTF_Font *fontMenu = TTF_OpenFont("hacked/hacked.ttf", 40);
  SDL_Color fontPurple = {0, 51, 102};
  int i, j;
  pion_bleu = IMG_Load("Images/pion_bleu.png");
  pion_rouge = IMG_Load("Images/pion_rouge.png");
  for (i = 0; i < 11; i++) {
    for (j = 0; j < 11; j++) {
      if (plateau[i][j].coordonnee_Y == 0) {
        pos_Pion.y = 163;
        pos_Pion.x = 30 * plateau[i][j].coordonnee_X + 30 + 7;
        if (plateau[i][j].joueur == 0) {
          (*nb_pions) = (*nb_pions + 1);
          SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        } else if (plateau[i][j].joueur == 1) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        }
      } else if (plateau[i][j].coordonnee_Y == 1) {
        pos_Pion.y = 188;
        pos_Pion.x = 30 * plateau[i][j].coordonnee_X + 45 + 7;
        if (plateau[i][j].joueur == 0) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        } else if (plateau[i][j].joueur == 1) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        }
      } else if (plateau[i][j].coordonnee_Y == 2) {
        pos_Pion.y = 213;
        pos_Pion.x = 30 * plateau[i][j].coordonnee_X + 60 + 7;
        if (plateau[i][j].joueur == 0) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        } else if (plateau[i][j].joueur == 1) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        }
      } else if (plateau[i][j].coordonnee_Y == 3) {
        pos_Pion.y = 238;
        pos_Pion.x = 30 * plateau[i][j].coordonnee_X + 75 + 7;
        if (plateau[i][j].joueur == 0) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        } else if (plateau[i][j].joueur == 1) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        }
      } else if (plateau[i][j].coordonnee_Y == 4) {
        pos_Pion.y = 263;
        pos_Pion.x = 30 * plateau[i][j].coordonnee_X + 90 + 7;
        if (plateau[i][j].joueur == 0) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        } else if (plateau[i][j].joueur == 1) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        }
      } else if (plateau[i][j].coordonnee_Y == 5) {
        pos_Pion.y = 288;
        pos_Pion.x = 30 * plateau[i][j].coordonnee_X + 105 + 7;
        if (plateau[i][j].joueur == 0) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        } else if (plateau[i][j].joueur == 1) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        }
      } else if (plateau[i][j].coordonnee_Y == 6) {
        pos_Pion.y = 313;
        pos_Pion.x = 30 * plateau[i][j].coordonnee_X + 120 + 7;
        if (plateau[i][j].joueur == 0) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        } else if (plateau[i][j].joueur == 1) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        }
      } else if (plateau[i][j].coordonnee_Y == 7) {
        pos_Pion.y = 338;
        pos_Pion.x = 30 * plateau[i][j].coordonnee_X + 135 + 7;
        if (plateau[i][j].joueur == 0) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        } else if (plateau[i][j].joueur == 1) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        }
      } else if (plateau[i][j].coordonnee_Y == 8) {
        pos_Pion.y = 363;
        pos_Pion.x = 30 * plateau[i][j].coordonnee_X + 150 + 7;
        if (plateau[i][j].joueur == 0) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        } else if (plateau[i][j].joueur == 1) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        }
      } else if (plateau[i][j].coordonnee_Y == 9) {
        pos_Pion.y = 388;
        pos_Pion.x = 30 * plateau[i][j].coordonnee_X + 165 + 7;
        if (plateau[i][j].joueur == 0) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        } else if (plateau[i][j].joueur == 1) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        }
      } else if (plateau[i][j].coordonnee_Y == 10) {
        pos_Pion.y = 413;
        pos_Pion.x = 30 * plateau[i][j].coordonnee_X + 180 + 7;
        if (plateau[i][j].joueur == 0) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        } else if (plateau[i][j].joueur == 1) {
          *nb_pions = *nb_pions + 1;
          SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion);
          SDL_Flip(ecran);
        }
      }
    }
  }
  SDL_BlitSurface(cacheur, NULL, ecran, &pos_cacheur);
  if (*nb_joueur == 0)
    info_joueur = TTF_RenderText_Blended(fontMenu, "Joueur Rouge", fontPurple);
  else
    info_joueur = TTF_RenderText_Blended(fontMenu, "Joueur Bleu", fontPurple);
  SDL_BlitSurface(info_joueur, NULL, ecran, &pos_info_joueur);
  SDL_BlitSurface(cacheur2, NULL, ecran, &pos_cacheur2);
  if (*nb_pions != 0) {
    char char_coup[100] = "";

    // echange des joueurs car on l'incrémente avant
    if (*nb_joueur == 1) {
      sprintf(char_coup, "Le joueur rouge a joue en %d,%d", lig + 1, col + 1);
      info_coup = TTF_RenderText_Blended(fontMenu, char_coup, fontPurple);
      SDL_BlitSurface(info_coup, NULL, ecran, &pos_info_coup);
    } else if (*nb_joueur == 0) {
      sprintf(char_coup, "Le joueur bleu a joue en %d,%d", lig + 1, col + 1);
      info_coup = TTF_RenderText_Blended(fontMenu, char_coup, fontPurple);
      SDL_BlitSurface(info_coup, NULL, ecran, &pos_info_coup);
    }
    SDL_Flip(ecran);
  }
  *nb_joueur = (*nb_joueur + 1) % 2;
}

/*Ce sous programme gère le logiciel en appelant toutes les fonctionnalités associées.*/
void affichage() {
  ////////////////////////////////////// DECLARATION
  //////////////////////////////////////////////

  Uint32 initflags = SDL_INIT_VIDEO;

  fenetre.h = WINHI;
  fenetre.w = WINWI;

  Uint8 video_bpp = 32;
  Uint32 videoflags = SDL_HWSURFACE;

  bool continuer;
  SDL_Event event;
  nb_joueur = choix_joueur();
  ///////////////////////////////////////// INITIALISATION
  /////////////////////////////////////////

  if (SDL_Init(initflags) < 0) {
    fprintf(stderr, "N'arrive pas à initialiser la SDL : %s\n", SDL_GetError());
    exit(1);
  }

  ecran = SDL_SetVideoMode(fenetre.w, fenetre.h, video_bpp, videoflags);

  if (ecran == NULL) {
    fprintf(stderr, "N'arrive pas a` etablir mode video%dx%dx%d : %s\n",
            fenetre.w, fenetre.h, video_bpp, SDL_GetError());
    SDL_Quit();
    exit(2);
  }

  /////////////////////////////////// IMAGE DE FOND
  ////////////////////////////////////////////////////

  image_fond = IMG_Load("Images/image_fond.png");

  SDL_WM_SetCaption("Jeu de Hex", NULL);

  TTF_Init();
  SDL_BlitSurface(image_fond, NULL, ecran, &position_fond);

  /////////////////////////////////////// BOUCLE PRINCIPALE EVENT
  ///////////////////////////////////////////:
  int annule = 0;
  int sauvegarde = 0;
  int lig = 0, col = 0;
  pile p;
  init(&p);
  Case plateau[11][11];
  init_plateau(plateau);

  continuer = true;
  SDLKey key_pressed;
  affichage_menu(1);
  int menu = 1;
  while (continuer) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_MOUSEBUTTONDOWN: {
          if (event.button.button == SDL_BUTTON_LEFT) {
            Clic c;
            c.x = event.motion.x;
            c.y = event.motion.y;           
            switch (menu) {
              ////////////////////////////////////// MENU PRINCIPAL
              ////////////////////////////////////////////////
              case (1): {
                if (clic_Valide(c, 330, 240, 450, 295)) {
                  // Jouer
                  clean(menu);
                  menu++;
                  affichage_menu(menu);
                  break;
                } else if (clic_Valide(c, 330, 450, 460, 485)) {
                  // Quitter
                  continuer = false;
                  clean(menu);
                  break;
                } else if (clic_Valide(c, 315, 340, 470, 385)) {
                  // Charger
                  clean(menu);
                  menu = 5;
                  affichage_menu(menu);
                  break;
                }
                break;
              }
              /////////////////////////////////// DEUXIEME MENU
              //////////////////////////////////////////
              case (2): {
                if (clic_Valide(c, 330, 450, 460, 485)) {
                  // QUITTER
                  continuer = false;
                  clean(menu);
                  break;
                } else if (clic_Valide(c, 330, 360, 455, 400)) {
                  // RETOUR
                  clean(menu);
                  menu--;
                  affichage_menu(menu);
                  break;
                } else if (clic_Valide(c, 325, 80, 450, 120)) {
                  // IA VS IA
                  clean(menu);
                  menu++;
                  affichage_menu(menu);
                  break;
                } else if (clic_Valide(c, 250, 150, 550, 190)) {
                  // H VS H
                  clean(menu);
                  menu = 4;
                  affichage_menu(menu);
                  break;
                } else if (clic_Valide(c, 275, 225, 500, 265)) {
                  // H VS IA1
                  printf("Humain vs IA1\n");
                  break;
                } else if (clic_Valide(c, 280, 300, 500, 330)) {
                  // H VS IA2
                  printf("Humain vs IA2\n");
                  break;
                }
                break;
              }
              /////////////////////////////////// TROISIEME MENU
              //////////////////////////////////////////
              case (3): {
                if (clic_Valide(c, 160, 470, 285, 515)) {
                  // RETOUR
                  clean(menu);
                  menu=2;
                  affichage_menu(menu);
                }
                break;
              }
              case (4): {
                pion_bleu = IMG_Load("Images/pion_bleu.png");
                pion_rouge = IMG_Load("Images/pion_rouge.png");
                TTF_Font *fontMenu = TTF_OpenFont("hacked/hacked.ttf", 40);
                SDL_Color fontPurple = {0, 51, 102};
                SDL_BlitSurface(cacheur, NULL, ecran, &pos_cacheur);
                if (nb_joueur == 0)
                  info_joueur = TTF_RenderText_Blended(fontMenu, "Joueur Bleu",
                                                       fontPurple);
                else
                  info_joueur = TTF_RenderText_Blended(fontMenu, "Joueur Rouge",
                                                       fontPurple);

                SDL_BlitSurface(info_joueur, NULL, ecran, &pos_info_joueur);
                SDL_Flip(ecran);
                if (clic_Valide(c, 20, 145, 525, 450)) {
                  // PLATEAU

                  int fin = Jouer(&nb_joueur, &nb_pions, c, &lig, &col, &annule,
                                  plateau, &p);
                  if (!fin) {
                    init(&p);
                    init_plateau(plateau);
                    annule = 1;
                    clean(menu);
                    menu = 6;
                    affichage_menu(menu);
                    break;
                  }
                  break;
                }
                if (clic_Valide(c, 540, 235, 720, 275)) {
                  // ABANDON
                  clean(menu);
                  menu = 6;
                  init_plateau(plateau);
                  init(&p);
                  annule = 1;
                  affichage_menu(menu);
                  break;
                }
                if (clic_Valide(c, 540, 315, 660, 360)) {
                  // RETOUR
                  clean(menu);
                  init_plateau(plateau);
                  init(&p);
                  menu = 1;
                  affichage_menu(menu);
                  annule = 1;
                  break;
                }
                if (clic_Valide(c, 540, 395, 670, 445)) {
                  // QUITTER
                  continuer = false;
                  clean(menu);
                  break;
                }
                if (clic_Valide(c, 540, 75, 765, 120)) {
                  // SAUVEGARDER
                  SDL_BlitSurface(cacheur2, NULL, ecran, &pos_cacheur2);
                  enum_save = TTF_RenderText_Blended(
                      fontMenu, "Save 1         Save 2         Save 3",
                      fontPurple);
                  pos_enum_save.x = 15;
                  pos_enum_save.y = 475;
                  SDL_BlitSurface(enum_save, NULL, ecran, &pos_enum_save);
                  SDL_Flip(ecran);
                  sauvegarde++;
                  break;
                }
                char *name_save;
                if (clic_Valide(c, 15, 465, 130, 515) && sauvegarde) {
                  name_save = "save_1";
                  SDL_BlitSurface(cacheur2, NULL, ecran, &pos_cacheur2);
                  enum_save = TTF_RenderText_Blended(fontMenu, "Enregistre !",
                                                     fontPurple);
                  SDL_BlitSurface(enum_save, NULL, ecran, &pos_enum_save);
                  SDL_Flip(ecran);
                  sauvegarde = 0;
                  sauvegarde_fichier(name_save, &p);

                  break;
                } else if (clic_Valide(c, 200, 465, 325, 515) && sauvegarde) {
                  name_save = "save_2";
                  SDL_BlitSurface(cacheur2, NULL, ecran, &pos_cacheur2);
                  enum_save = TTF_RenderText_Blended(fontMenu, "Enregistre !",
                                                     fontPurple);
                  SDL_BlitSurface(enum_save, NULL, ecran, &pos_enum_save);
                  SDL_Flip(ecran);
                  sauvegarde = 0;
                  sauvegarde_fichier(name_save, &p);
                  break;
                } else if (clic_Valide(c, 400, 465, 530, 515) && sauvegarde) {
                  name_save = "save_3";
                  SDL_BlitSurface(cacheur2, NULL, ecran, &pos_cacheur2);
                  enum_save = TTF_RenderText_Blended(fontMenu, "Enregistre !",
                                                     fontPurple);
                  SDL_BlitSurface(enum_save, NULL, ecran, &pos_enum_save);
                  SDL_Flip(ecran);
                  sauvegarde = 0;
                  sauvegarde_fichier(name_save, &p);
                  break;
                }

                if (clic_Valide(c, 540, 155, 645, 200)) {
                  // UNDO
                  if (!annule) {
                    if (nb_pions != 0) {
                      depiler(&p);
                      plateau[lig][col].joueur = -1;
                      SDL_BlitSurface(pion_annule, NULL, ecran, &pos_Pion);
                      nb_joueur = (nb_joueur - 1) % 2;
                      nb_pions--;
                      SDL_BlitSurface(cacheur, NULL, ecran, &pos_cacheur);
                      SDL_BlitSurface(cacheur2, NULL, ecran, &pos_cacheur2);
                      if (nb_joueur == 0) {
                        info_joueur = TTF_RenderText_Blended(
                            fontMenu, "Joueur Bleu", fontPurple);
                        info_coup = TTF_RenderText_Blended(
                            fontMenu, "Le joueur bleu a annule son coup",
                            fontPurple);
                      } else {
                        info_joueur = TTF_RenderText_Blended(
                            fontMenu, "Joueur Rouge", fontPurple);
                        info_coup = TTF_RenderText_Blended(
                            fontMenu, "Le joueur rouge a annule son coup",
                            fontPurple);
                      }
                      SDL_BlitSurface(info_joueur, NULL, ecran,
                                      &pos_info_joueur);
                      SDL_BlitSurface(info_coup, NULL, ecran, &pos_info_coup);

                      SDL_Flip(ecran);
                      annule++;
                      break;
                    }
                  }
                }
                break;
              }
              case (5): {
                char *name_save;
                if (clic_Valide(c, 160, 475, 290, 515)) {
                  clean(menu);
                  menu = 1;
                  affichage_menu(menu);
                  break;
                }

                if (clic_Valide(c, 120, 280, 250, 330)) {
                  name_save = "save_1";
                  int matrice[11][11];
                  int k, n;
                  chargement(&p, &nb_joueur, matrice, name_save, &col, &lig);
                  for (k = 0; k < 11; k++) {
                    for (n = 0; n < 11; n++) {
                      plateau[k][n].coordonnee_Y = k;
                      plateau[k][n].coordonnee_X = n;
                      if (k == 0 || n == 0) {
                        plateau[k][n].borne = 1;
                      } else if (k == 10 || n == 10) {
                        plateau[k][n].borne = 2;
                      } else {
                        plateau[k][n].borne = 0;
                      }
                      plateau[k][n].joueur = matrice[k][n];
                      if (plateau[k][n].joueur != -1) {
                        enregistre_coup(&p, k, n, matrice[k][n]);
                      }
                    }
                  }
                  clean(menu);
                  menu = 4;
                  affichage_menu(menu);
                  Charge_plateau(&nb_pions, c, plateau, lig, col, &nb_joueur);
                  annule = 1;
                  break;
                } else if (clic_Valide(c, 320, 280, 445, 325)) {
                  name_save = "save_2";
                  int matrice[11][11];
                  int k, n;
                  chargement(&p, &nb_joueur, matrice, name_save, &col, &lig);
                  for (k = 0; k < 11; k++) {
                    for (n = 0; n < 11; n++) {
                      plateau[k][n].coordonnee_Y = k;
                      plateau[k][n].coordonnee_X = n;
                      if (k == 0 || n == 0) {
                        plateau[k][n].borne = 1;
                      } else if (k == 10 || n == 10) {
                        plateau[k][n].borne = 2;
                      } else {
                        plateau[k][n].borne = 0;
                      }
                      plateau[k][n].joueur = matrice[k][n];
                      if (plateau[k][n].joueur != -1) {
                        enregistre_coup(&p, k, n, matrice[k][n]);
                      }
                    }
                  }
                  clean(menu);
                  menu = 4;
                  affichage_menu(menu);
                  Charge_plateau(&nb_pions, c, plateau, lig, col, &nb_joueur);
                  annule = 1;
                  break;
                } else if (clic_Valide(c, 520, 280, 645, 325)) {
                  name_save = "save_3";
                  int matrice[11][11];
                  int k, n;
                  chargement(&p, &nb_joueur, matrice, name_save, &col, &lig);
                  for (k = 0; k < 11; k++) {
                    for (n = 0; n < 11; n++) {
                      plateau[k][n].coordonnee_Y = k;
                      plateau[k][n].coordonnee_X = n;
                      if (k == 0 || n == 0) {
                        plateau[k][n].borne = 1;
                      } else if (k == 10 || n == 10) {
                        plateau[k][n].borne = 2;
                      } else {
                        plateau[k][n].borne = 0;
                      }
                      plateau[k][n].joueur = matrice[k][n];
                      if (plateau[k][n].joueur != -1) {
                        enregistre_coup(&p, k, n, matrice[k][n]);
                      }
                    }
                  }
                  clean(menu);
                  menu = 4;
                  affichage_menu(menu);
                  Charge_plateau(&nb_pions, c, plateau, lig, col, &nb_joueur);
                  annule = 1;
                  break;
                }
                break;
              }
              case (6): {
                if (clic_Valide(c, 70, 515, 205, 570)) {
                  //RETOUR
                  clean(menu);
                  menu = 1;
                  init_plateau(plateau);
                  init(&p);
                  affichage_menu(menu);
                  break;
                }
                break;
              }
            }
          }
        }
        case SDL_KEYDOWN:
          key_pressed = event.key.keysym.sym;
          switch (key_pressed) {
            case SDLK_ESCAPE:
              continuer = false;
              break;
            default:
              break;
          }
          break;
        case SDL_QUIT:
          continuer = false;
          break;
        default:
          break;
      }
    }
  }

  /////////////////////////////////////////// QUIT
  /////////////////////////////////////////////
  SDL_FreeSurface(image_fond);
  TTF_Quit();
  SDL_Quit();
  }