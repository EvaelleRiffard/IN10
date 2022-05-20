#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * maj_dico(char* mot, int* COULEURS_M, char** Dico){
    // Le programme récupère en entrée le mot testé à l'itération précédente et son code couleur associé, on va chercher à trouver tous les mots du dico qui ont le même fonctionnement puis tester un des mots de ce dictionnaire mis à jour
    
    int j=1;      
    int k=0;
    char * DicoNew[10140]; //Le dico qui va être mis à jour avec seulement les mots correspondants au bon truc

    while (k<MAX-1){
       int* COULEURS = decriptage(mot, Dico[k])   //On recuperer le code couleur de tous les mots du dico et on garde ceux qui ont celui qui correspond à notre mot
        if (COULEURS_M == COULEURS){
            DicoNew[j]=Dico[k]; //maj du dico
            j=j+1;
        }
    }
    return DicoNew;
}