#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<time.h>
#include "dico_i.h"
#include "maj_dico.h"
#include "maj_essai.h"
#include "decriptage.h"
#define MAX 10140

 

char* robot(char* mot){
    char** Dico = dico_i();
    char* essai = "tarie";
    int* COULEURS_M = decriptage(essai, mot);
    int C = 0;
    int i = 0;

    do {Dico = maj_dico(mot, COULEURS_M, DICO);
        essai = maj_essai(essai, Dico);
        printf("%s\n", essai);
        COULEURS_M = decriptage(essai, mot);
        C = 0;
        for (int i = 0; i<5; ++i){ C += COULEURS_M[i];}
        i = i+1}
    while (i<1000 && C != 0); 

    return essai; 
}
