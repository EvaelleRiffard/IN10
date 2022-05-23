#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decriptage.h"
#define VERT "\x1B[32m"
#define BLEU "\x1B[36m"
#define ROUGE "\x1B[31m"
#define RESET "\x1B[0m"

struct lettre {
    char l ; //lettre
    char* c; //couleur
};

//Cette structure contient le dictionnaire et sa taille, son nom n'est pas intuitif mais c'est parce que cela fait référence à l'expression "j'en ai marre" 
//En effet nous avons créé cette structure afin de sortir d'une boucle sans fin de segmentation fault qui nous a fortement miné le moral
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
    

    
    //création de la liste des lettres rouges
    char * rouge = malloc(6 * sizeof(char));
    int c = 0; //compteur de la liste rouge
    for (int k=0; k<5; k++) {
        struct lettre lettreR = L[k];
        if (strcmp(lettreR.c,ROUGE)==0){
            rouge[c] = lettreR.l;
            c+=1;
        }
    }

    
    
    //On rajoute dans le nouveau dico que les mots qui respectent les consignes
    for (int i = 0; i<n; i++){
        char * essai = Dico[i];
        int Erreur = 0; //compteur d'erreurs
        
        for (int j = 0; j<5; j++){
           
            struct lettre lettre_couleur = L[j];
            
            //Consigne 1 : il contient les lettres vertes au bon endroit
            if (essai[j]!=lettre_couleur.l && strcmp(lettre_couleur.c,VERT)==0){
                Erreur +=1;
            }
            
            //Consigne 2 : il ne contient pas les lettres bleues au même emplacement
            else if (essai[j] == lettre_couleur.l && strcmp(lettre_couleur.c,BLEU)==0){
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
            //printf("%s\n", essai);
            DicoNew[d] = malloc(6*sizeof(char));
            for (int k=0;k<5;++k){
                DicoNew[d][k]=essai[k];
            }
            d+=1;
        }
    }
    /*
    for (int i=0; i<n; ++i) {
        for (int j=0; j<5; ++j){
            free(Jeam.Dico[i]);
        }
    }
    */
    JeamNew.Dico = DicoNew;
    JeamNew.n = d;
    return JeamNew;
}