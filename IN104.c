#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Saisie.h"
#include "decriptage.h"
#include "reglejeu.h"
#include "wordle.h"
#include "hasard.h"
#include "robot.h"
#include "maj_essai.h"
#include "dico_i.h"
#include "maj_dico2.h"
struct lettre {
    char l ; //lettre
    char* c; //couleur
};
struct jeam {
    char** Dico; //dico
    int n;  //taille du dico
};

int main(){
    
    #define VERT "\x1B[32m"
    #define BLEU "\x1B[36m"
    #define ROUGE "\x1B[31m"
    #define RESET "\x1B[0m"


    printf("ESSAI PARTIE 1 \n");
    char* mot1 = hasard();
    printf("%s\n", mot1);
    wordle(mot1);

    //Pour jouer tout seul :
    //wordle(hasard());

    printf("ESSAI PARTIE 2 \n");
    char* mot2 = hasard();
    printf("%s\n", mot2 );
    char* mot_f = robot(mot2);
    printf("le mot à trouver est : %s \n", mot_f);
    
    
}    
    