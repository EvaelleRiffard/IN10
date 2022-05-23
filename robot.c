#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "dico_i.h"
#include "maj_dico.h"
#include "maj_essai.h"
#include "decriptage.h"
#include "maj_dico2.h"
#define VERT "\x1B[32m"
#define BLEU "\x1B[36m"
#define ROUGE "\x1B[31m"
#define RESET "\x1B[0m"

struct lettre {
    char l ; //lettre
    char* c; //couleur
};
struct jeam {
    char** Dico; //dico
    int n;  //taille du dico
};

char* robot(char* mot){
    
    //Dico initial
    char** Dico;
    Dico = dico_i();
    struct jeam Jeam={Dico,5070};

    //mot essayé initialement
    char* essai = "tarie";

    //initialisation compteur pour éviter une boucle infinie
    int stop = 0;
    //initialisation du compteur pour savoir si le mot est vert
    int C;  

    do{struct lettre* L = decriptage(essai, mot);
        C = 0;
        for(int k = 0; k<5; k++){
            struct lettre lettre = L[k];
            if (strcmp(lettre.c, BLEU)==0){
                C +=1;
            }
            if (strcmp(lettre.c, ROUGE)==0){
                C +=1;
            }
        }
        if (C!=0){
            Jeam = maj_dico2(Jeam,L);
            if (Jeam.Dico[0]==NULL){
                printf("merde\n");
            }
            if (Jeam.n==0){
                printf("%s",Jeam.Dico[0]);
                printf("merde2\n");
            }
            essai = maj_essai(essai, Jeam.Dico);
            printf("le mot testé est : %s\n", essai);
            stop +=1;
            printf("%d\n",C);
        }
    }
    while (C != 0 && stop < 6);
    return essai;

}
