#include "interface_graphique.h"

//https://github.com/suzimaru/hex_sorli_garrigues_perruchet/tree/master
  /*gcc -o essai simple.c interface_graphique.c `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf*/


//http://www.dafont.com/fr/ site pour différentes polices.
//http://www.corecoding.com/utilities/rgb-or-hex-to-float.php site pour convertir les couleurs hexa->RGB
//http://www.proftnj.com/RGB3.htm site pour les couleurs (hexa+RGB)




int main(int argc, char *argv[])
{
	pile p;
	init(&p);
	affichage();
  return 0;
}
