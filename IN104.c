#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Saisie.h"
#include "decriptage.h"
#include "reglejeu.h"
#include "wordle.h"
#include "robot.h"
#include "maj_dico.h"
#include "maj_essai.h"

#include "hasard.h"
#include "dico_i.h"
#include "maj_dico2.h"
struct jeam {
    char** Dico; //dico
    int n;  //taille du dico
};

int main(){
    
    #define VERT "\x1B[32m"
    #define BLEU "\x1B[36m"
    #define ROUGE "\x1B[31m"
    #define RESET "\x1B[0m"

    /*TEST COULEURS
    char* j = "bleu";
    printf("%s%s%s\n", BLEU, j, RESET);
    char* r = "rouge";
    printf("%s%s%s\n", ROUGE, r, RESET);
    char* v = "vert";
    printf("%s%s%s\n", VERT, v, RESET);
    */

    /*
    char* mot = hasard();
    //printf("%s\n", mot);
    wordle(mot);
    // wordle(hasard());
    */
    
    
   /* char* mot = hasard();
    printf("le mot à trouver est : ");
    printf("%s\n", mot);
    char** Dico = dico_i();
    if (Dico==NULL){
        printf("merde\n");
    }
    
    for (int k= 0; k<5070; k++){
            printf("%s\n", Dico[k]);
        }
    
    char* res = robot(mot);
    printf("le mot donné par le robot est : ");
    printf("%s\n", res);
    */
/*
    
    char** Dico;
    Dico = dico_i();
    char * essai;
    essai = "tarie";
    int* COULEURS_M;
    char* mot=hasard();
    for (int i=0;i<5;i++){
        COULEURS_M = decriptage(essai, mot);
        Dico=maj_dico(essai,COULEURS_M,Dico);
        int C=0;
        for (int j=0;j<5;j++){
            C=C+COULEURS_M[j];
        }
        if (C==0){
            printf("Le jeu est résolu en n=%d essais\n",i);
            return 0;
        }
        essai= maj_essai(essai,maj_dico(essai,COULEURS_M,Dico));
        }
    printf("Le robot n'a pas réussi à résoudre le jeu");
    return 0;
    */

    //Dico initial
    char** Dico;
    Dico = dico_i();
    /*
    for (int i=0;i<50;++i) {
        printf("ok : %s\n", Dico[i]);
    }
    */
    struct jeam Jeam={Dico,5070};

    //Definition mot à trouver
    char* mot=hasard();
    printf("%s\n", mot );

    struct lettre* L = decriptage("tarie", mot);

    struct jeam JeamNew = maj_dico2(Jeam,L);
    if (JeamNew.Dico==NULL){
        printf("merde\n");
    }
    if (JeamNew.n==0){
        printf("merde2\n");
    }

    free(L);
    
}    
    