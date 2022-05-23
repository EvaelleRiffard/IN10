#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<time.h>
#include "dico_i.h"
#include "maj_dico.h"
#include "maj_essai.h"
#include "decriptage.h"


char* robot(char* mot, char** Dico){
    /*
    char** Dico = dico_i();
    char* essai = "tarie";
    int* COULEURS_M = decriptage(essai, mot);
    int C = 0;
    for (int j = 0; j<5; j++){ C += COULEURS_M[j];}
    int i = 0;

    while (C != 0 && i<10){
        Dico = maj_dico(mot, COULEURS_M, Dico);
        //Dico = Dico1;
        size_t n = sizeof(Dico)/(5*sizeof(char));
        for (int k= 0; k<n; k++){
            printf("%d\n", k);
        }
        essai = maj_essai(essai, Dico);
        //essai = essai1;
        printf("le mot essayé est\n");
        printf("%s\n", essai);
        COULEURS_M = decriptage(essai, mot);
        C = 0;
        for (int j = 0; j<5; j++){ C += COULEURS_M[j];}
        i = i+1;
        }
     

    //free(Dico)
    return essai;
    */
    int* COULEURS_M = decriptage(essai, mot);
    return maj_essai(essai,maj_dico(essai,COULEURS_M,Dico));

}
