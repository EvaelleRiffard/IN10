// permet de savoir si le mot choisi est le bon mot et renvoie si il y a les mêmes lettres et s'ils sont à la bonne place
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Saisie.h"

#define VERT "\x1B[32m"
#define JAUNE "\x1B[33m"
#define ROUGE "\x1B[31m"
#define RESET "\x1B[0m"

struct lettre {
    char l ; //lettre
    char* c; //couleur
};

struct lettre* decriptage(char* essai, char* mot){

    //traiter le cas d'erreur
    while (strcmp(essai, "erreur") == 0){
        printf("\n");
        essai = saisie();
    }

    struct lettre* L = malloc(5 * sizeof(struct lettre));
    for (int i=0; i<5; i++){
        L[i].l = essai[i];
        printf("%c", L[i].l);
        
        //est ce que la lettre est à la bonne place
        if(essai[i] == mot[i]){
            L[i].c = VERT;
        }

        //est ce que la lettre est dans le mot
        else { 
            int k = 0;
            while (k < 5 && essai[i] != mot[k]){
                k += 1;
            }
            //oui il y est
            if (k<5){
                L[i].c = JAUNE;
            }
            //non il n'y est pas
            else{
                L[i].c = ROUGE;
            }
        }
    }
    printf("\n");
    return L;
}