// Répète 6 fois l'étape de décryptage
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Saisie.h"
#include "decriptage.h"
#include "reglejeu.h"
#include "hasard.h"
#include "robot.h"

struct lettre {
    char l ; //lettre
    char* c; //couleur
};

    #define VERT "\x1B[32m"
    #define BLEU "\x1B[36m"
    #define ROUGE "\x1B[31m"
    #define RESET "\x1B[0m"



void wordle(char* mot){

    reglejeu();

    int i = 0;
    int C = 0;
    
    do {struct lettre* COULEURS = decriptage(saisie(), mot);
        C = 0;
        for(int k = 0; k<5; k++){
            struct lettre coul = COULEURS[k];
            if (strcmp(coul.c, BLEU)==0){
                C +=1;
            }
            if (strcmp(coul.c, ROUGE)==0){
                C +=1;
            }
        }
        i = i+1;
        free(COULEURS);}
    while (i<6 && C != 0);        
}