// Répète 6 fois l'étape de décryptage
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Saisie.h"
#include "decriptage.h"
#include "reglejeu.h"
#include "hasard.h"
#include "robot.h"

void wordle(char* mot){

    reglejeu();

    int i = 0;
    int C = 0;
    do { int* COULEURS = decriptage(saisie(), mot);
        C = 0;
        for (int j = 0; j<5; ++j){ C += COULEURS[i];}
        i = i+1;
        free(COULEURS);}
    while (i<6 && C != 0);

        
}