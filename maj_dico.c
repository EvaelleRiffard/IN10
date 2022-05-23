#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decriptage.h"
#include "comp.h"
#define MAX 10140

char** maj_dico(char* essai, int* COULEURS_M, char** Dico){
    // Le programme récupère en entrée le mot testé à l'itération précédente et son code couleur associé, on va chercher à trouver tous les mots du dico qui ont le même fonctionnement puis tester un des mots de ce dictionnaire mis à jour
    /*
    int j=0;      
    int k=0;
   // char* DicoNew[10140]; //Le dico qui va être mis à jour avec seulement les mots correspondants au bon truc
    char ** DicoNew=malloc(sizeof(char *)*10140);
    while (k<MAX-1){
        int* COULEURS = decriptage(essai, Dico[k]);   //On recuperer le code couleur de tous les mots du dico et on garde ceux qui ont celui qui correspond à notre mot
        if (comp(COULEURS_M, 5, COULEURS, 5) == 0){
            DicoNew[j]=Dico[k]; //maj du dico
            j=j+1;
        }
        k=k+1;

    }
    free(Dico);
    return DicoNew;*/
    char** DicoNew=malloc(sizeof(char *)*10140);
    int k=0;
    for (int i=0; i<5;i++){
        if (COULEURS_M[i]==0){
            for (int j=0;j<MAX-1;j++){
                if (Dico[j][i]==essai[i]){
                    DicoNew[k]=Dico[i];
                    k=k+1;
                }
            }
        }
    }
    return DicoNew;
}