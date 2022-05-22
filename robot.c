#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<time.h>
#include "dico_i.h"
#include "maj_dico.h"
#include "maj_essai.h"
#include "decriptage.h"


char* robot(char* mot){
    char** Dico = dico_i();
    char* essai = "tarie";
    int* COULEURS_M = decriptage(essai, mot);
    int C = 0;
    int i = 0;

    do {Dico = maj_dico(mot, COULEURS_M, Dico);
        essai = maj_essai(essai, Dico);
        printf("%s\n", essai);
        COULEURS_M = decriptage(essai, mot);
        C = 0;
        for (int j = 0; j<5; j++){ C += COULEURS_M[j];}
        i = i+1;}
    while (C != 0 && i<10); 

    return essai; 
}
