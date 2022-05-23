#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decriptage.h"
#define VERT "\x1B[32m"
#define BLEU "\x1B[36m"
//#define JAUNE "\x1B[33m"
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

struct jeam maj_dico2(struct jeam Jeam, struct lettre* L){
    //Dico
    char** Dico = Jeam.Dico;
    
    
    // n = taille du dico
    int n = Jeam.n;

    //création du nouveau dico
    struct jeam JeamNew;
    char** DicoNew = malloc(n * sizeof(char*));
    int d = 0;  //compteur de remplissage du dico
    JeamNew.Dico = DicoNew;

    
    //création de la liste des lettres rouges
    char * rouge = malloc(6 * sizeof(char));
    int c = 0; //compteur de la liste rouge
    for (int k=0; k<5; k++) {
        
        struct lettre lettreR = L[k];
        if (strcmp(lettreR.c,ROUGE)){
            
            rouge[c] = lettreR.l;
            c+=1;
        }
    }
    //printf("yousk2\n");
    int r=0;
    //On rajoute dans le nouveau dico que les mots qui respectent les consignes
    for (int i = 0; i<n-1; i++){
        char * essai = Dico[i];
        int Erreur = 0; //compteur d'erreurs
        r+=1;
        
        for (int j = 0; j<5; j++){
           
            struct lettre lettre_couleur = L[j];
            
            //Consigne 1 : il contient les lettres vertes au bon endroit
            if (essai[j]==lettre_couleur.l && strcmp(lettre_couleur.c,VERT)){
                
                Erreur +=1;
            }
            
            //Consigne 2 : il ne contient pas les lettres bleues au même emplacement
            if (essai[j] == lettre_couleur.l && strcmp(lettre_couleur.c,BLEU)){
                Erreur +=1;
            }
            
            //Consigne 3 : il ne contient pas de lettre rouge
            else {
                for (int k = 0; k<c; k++){
                    if (essai[j] == rouge[k]){
                        Erreur +=1;
                    }
                }
            }
        }
    
        //S'il n'y a pas d'erreur on rajoute le mot dans le dico
        if (Erreur == 0){
            //printf("c'est pas ici que ca merde");
            printf("ok : %s\n", essai);
            DicoNew[d] = malloc(6*sizeof(char));
            for (int k=0;k<5;++k){
                DicoNew[d][k]=essai[k];
            }
            d+=1;
        }
    }
    JeamNew.n = d;
    //printf("yousk2\n");
    return JeamNew;
}