#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main() {

    image ima;
    loadImage("lena.pgm", &ima);
    recordImage("exLenaInitial.pgm", &ima);

    int seuil;
    printf("Rentrer le seuil de niveau de gris souhaité (entre 0 et 255 compris) : ");
    scanf("%d",&seuil);
    binarisation(seuil, &ima);
    recordImage("exLenaBinarise.pgm", &ima);

    inverse(&ima);
    recordImage("exLenaInverse.pgm", &ima);

    image ima2;
    loadImage("lena.pgm", &ima2); 
    erosion(&ima2);
    recordImage("exLenaErode.pgm", &ima2);

    image ima3;
    loadImage("lena.pgm", &ima3); 
    dilatation(&ima3);
    recordImage("exLenaDilate.pgm", &ima3);

    freemat(&ima);
    freemat(&ima2);
    freemat(&ima3);
    return 0;

}