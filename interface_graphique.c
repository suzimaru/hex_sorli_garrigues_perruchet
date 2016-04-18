#include "interface_graphique.h"

int clic_Valide(Clic c, int borneInfX, int borneInfY, int borneSupX,
                int borneSupY) {
  return ((c.x >= borneInfX && c.x <= borneSupX) &&
          (c.y >= borneInfY && c.y <= borneSupY));
}
int souris_Dessus(Clic c, int menu, int borneInfX, int borneInfY, int borneSupX,
                  int borneSupY) {}

void affichage_menu(int menu) {
  switch (menu) {
  case (1): {
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
        TTF_OpenFont("hacked/hacked.ttf", 22); // police du menu
    TTF_Font *fontMenu =
        TTF_OpenFont("hacked/hacked.ttf", 40); // police du menu

    SDL_Color fontPurple = {0, 51, 102}; // couleur du menu
                                         // texte du petit rectangle

    texte_auteur = TTF_RenderText_Blended(
        fontAuteur, "Garrigues, Perruchet, Sorli 2016", fontPurple);

    TTF_SetFontStyle(fontMenu, TTF_STYLE_BOLD);
    texte_menu = TTF_RenderText_Blended(fontMenu, "MENU", fontPurple);
    texte1 = TTF_RenderText_Blended(fontMenu, "Jeu HEX", fontPurple);
    TTF_SetFontStyle(fontMenu, TTF_STYLE_NORMAL);

    jouer = TTF_RenderText_Blended(fontMenu, "Jouer", fontPurple);
    charger = TTF_RenderText_Blended(fontMenu, "Charger", fontPurple);
    quitter = TTF_RenderText_Blended(fontMenu, "Quitter", fontPurple);

    SDL_BlitSurface(image_fond, NULL, ecran,
                    &position_fond); // coller l'image de fond
    SDL_BlitSurface(jouer, NULL, ecran, &posJouer);
    SDL_BlitSurface(charger, NULL, ecran, &posCharger);
    SDL_BlitSurface(quitter, NULL, ecran, &posQuitter);
    SDL_BlitSurface(
        texte1, NULL, ecran,
        &posTexte1); // celle la après pour qu'elle ne soit pas écrasée
    SDL_BlitSurface(texte_menu, NULL, ecran, &posTexte_menu);
    SDL_BlitSurface(texte_auteur, NULL, ecran, &posTexte_auteur);
    SDL_Flip(ecran);
    break;
  }
  case (2): {
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
        TTF_OpenFont("hacked/hacked.ttf", 22); // police du menu
    TTF_Font *fontMenu =
        TTF_OpenFont("hacked/hacked.ttf", 40); // police du menu

    SDL_Color fontPurple = {0, 51, 102}; // couleur du menu
    texte1 = TTF_RenderText_Blended(fontMenu, "Jeu HEX",
                                    fontPurple); // texte du petit rectangle
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

    SDL_BlitSurface(image_fond, NULL, ecran,
                    &position_fond); // coller l'image de fond
    SDL_BlitSurface(HvsH, NULL, ecran, &posHvsH);
    SDL_BlitSurface(IAvsIA, NULL, ecran, &posIAvsIA);
    SDL_BlitSurface(HvsIA1, NULL, ecran, &posHvsIA1);
    SDL_BlitSurface(quitter, NULL, ecran, &posQuitter);
    SDL_BlitSurface(
        HvsIA2, NULL, ecran,
        &posHvsIA2); // celle la après pour qu'elle ne soit pas écrasée
    SDL_BlitSurface(texte_menu, NULL, ecran, &posTexte_menu);
    SDL_BlitSurface(texte_auteur, NULL, ecran, &posTexte_auteur);
    SDL_BlitSurface(retour, NULL, ecran, &posretour);
    SDL_Flip(ecran);
    break;
  }
  case (3): {

    posNiveau.x = 140;
    posNiveau.y = 65;

    pos1IA.x = 165;
    pos1IA.y = 220;

    pos2IA.x = 165;
    pos2IA.y = 350;

    posretour.x = 165;
    posretour.y = 475;

    TTF_Font *fontAuteur =
        TTF_OpenFont("hacked/hacked.ttf", 22); // police du menu
    TTF_Font *fontMenu =
        TTF_OpenFont("hacked/hacked.ttf", 40); // police du menu
    SDL_Color fontPurple = {0, 51, 102};       // couleur du menu

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

    break;
  }
  case (4): {
    posPlateau.x = 15;
    posPlateau.y = 140;

    position_fond.x = 0;
    position_fond.y = 0;

    plateau = IMG_Load("Images/hex.png");
    SDL_BlitSurface(image_fond, NULL, ecran, &position_fond);
    SDL_BlitSurface(plateau, NULL, ecran, &posPlateau);
    SDL_Flip(ecran);
    break;
  }
  }
}

void clean(int menu) {
  TTF_Font *fontAuteur =
      TTF_OpenFont("hacked/hacked.ttf", 22);                  // police du menu
  TTF_Font *fontMenu = TTF_OpenFont("hacked/hacked.ttf", 40); // police du menu

  switch (menu) {
  case (1): {
    SDL_FreeSurface(ecran);
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
    SDL_FreeSurface(ecran);

    break;
  }
  case (3): {
    SDL_FreeSurface(niveau);
    SDL_FreeSurface(niveau_deuxieme_IA);
    SDL_FreeSurface(niveau_premier_IA);
    SDL_FreeSurface(retour);
    SDL_FreeSurface(ecran);

    break;
  }
  }
  TTF_CloseFont(fontMenu);
  TTF_CloseFont(fontAuteur);
}

void affichage() {

  ////////////////////////////////////// DECLARATION
  //////////////////////////////////////////////

  Uint32 initflags =
      SDL_INIT_VIDEO; //| SDL_DOUBLEBUF;  /* See documentation for details */

  fenetre.h = WINHI; // en pixels
  fenetre.w = WINWI;

  Uint8 video_bpp = 32;              // 32 bits de couleur
  Uint32 videoflags = SDL_HWSURFACE; // utiliser la mémoire vidéo
  // Uint32 vert, rouge;                // des variables pour des couleurs

  bool continuer;  // pour la boucle principale des évènements
  SDL_Event event; // aussi

  ///////////////////////////////////////// INITIALISATION
  /////////////////////////////////////////

  /* Initialize the SDL library */
  if (SDL_Init(initflags) < 0) {
    fprintf(stderr, "N'arrive pas à initialiser la SDL : %s\n", SDL_GetError());
    exit(1);
  }

  /* Set video mode */
  ecran = SDL_SetVideoMode(fenetre.w, fenetre.h, video_bpp,
                           videoflags); // surface principale

  if (ecran == NULL) {
    fprintf(stderr, "N'arrive pas a` etablir mode video%dx%dx%d : %s\n",
            fenetre.w, fenetre.h, video_bpp, SDL_GetError());
    SDL_Quit();
    exit(2);
  }

  /////////////////////////////////// IMAGE DE FOND
  ////////////////////////////////////////////////////

  image_fond = IMG_Load("Images/image_fond.png");

  // voir pour l'icone de la fenêtre
  SDL_WM_SetCaption("Jeu de Hex", NULL); // titre de la fenêtre

  TTF_Init();
int nb_pions = 0;
int nb_joueur = 0;
  /////////////////////////////////////// BOUCLE PRINCIPALE EVENT
  ///////////////////////////////////////////:

  continuer = true;
  SDLKey key_pressed;
  affichage_menu(1);
  int menu = 1;
  while (continuer) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_MOUSEMOTION: {
        // METTER ICI LE SURLIGNAGE
        //  while ()
        printf("Ça bouge\n");

      } break;
      case SDL_MOUSEBUTTONDOWN: {
        if (event.button.button == SDL_BUTTON_LEFT) {
          Clic c;
          c.x = event.motion.x;
          c.y = event.motion.y;
          printf("X=%d Y=%d\n", c.x,
                 c.y); // on récupère les coordonnées du clic

          // if ((clicX>=400  && clicX<=600) && (clicY>=180 && clicY<=250))
          switch (menu) {
          ////////////////////////////////////// MENU PRINCIPAL
          ////////////////////////////////////////////////
          case (1): {
            if (clic_Valide(c, 330, 240, 450, 295)) {
              // Jouer
              clean(menu);
              ++menu;
              affichage_menu(menu);
              break;
            } else if (clic_Valide(c, 330, 450, 460, 485)) {
              // Quitter
              continuer = false;
              clean(menu);
              break;
            } else if (clic_Valide(c, 315, 340, 470, 385)) {
              // Charger
              printf("charger\n");
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
              --menu;
              affichage_menu(menu);
            } else if (clic_Valide(c, 325, 80, 450, 120)) {
              // IA VS IA
              printf("menu =%d\n", menu);
              clean(menu);
              ++menu;
              affichage_menu(menu);
            } else if (clic_Valide(c, 250, 150, 550, 190)) {
              // H VS H
              printf("Humain vs Humain\n");
              // H VS IA2
              clean(menu);
              menu = menu + 2;
              affichage_menu(menu);
            } else if (clic_Valide(c, 275, 225, 500, 265)) {
              // H VS IA1
              printf("Humain vs IA1\n");
            } else if (clic_Valide(c, 280, 300, 500, 330)) {
              // H VS IA2
              printf("Humain vs IA2\n");
            }
            break;
          }
          /////////////////////////////////// TROISIEME MENU
          //////////////////////////////////////////
          case (3): {
            if (clic_Valide(c, 160, 470, 285, 515)) {
              // RETOUR
              clean(menu);
              --menu;
              affichage_menu(menu);
            }
            break;
          }
          case (4): {
            
            pion_bleu = IMG_Load("Images/pion_bleu.png");
            pion_rouge = IMG_Load("Images/pion_rouge.png");

            pos_Pion_Bleu.x=52;
            pos_Pion_Bleu.y=188;

            pos_Pion_Rouge.x=82;
            pos_Pion_Rouge.y=188;

            if (clic_Valide(c, 50, 190, 75, 210)) {
                            printf("joueur=%d\n",nb_joueur);
              if (!nb_joueur)
              {
                SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion_Bleu);
                SDL_Flip(ecran);
              }
              else
              {
                SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion_Rouge);
                SDL_Flip(ecran);
              }
              nb_joueur = (nb_joueur + 1) % 2;
                            printf("joueur=%d\n",nb_joueur);

              nb_pions++;
            }
            if (clic_Valide(c, 80, 190, 110, 210))
            {

              if (!nb_joueur)
              {
                SDL_BlitSurface(pion_bleu, NULL, ecran, &pos_Pion_Bleu);
                SDL_Flip(ecran);
              }
              else
              {
                SDL_BlitSurface(pion_rouge, NULL, ecran, &pos_Pion_Rouge);
                SDL_Flip(ecran);
              }
              nb_joueur = (nb_joueur + 1) % 2;
              nb_pions++;
            }
          }
          }
        }
      }
      case SDL_KEYDOWN:
        key_pressed = event.key.keysym.sym; // on récupère la touche
        switch (key_pressed) {
        case SDLK_ESCAPE: /* Esc keypress quits the app... */
          continuer = false;
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

  TTF_Quit();
  SDL_Quit();
  }
