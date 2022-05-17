#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<time.h>
#define MAX 10140

char * robot(char * mot,int* COULEUR2){
    // Le programme récupère en entrée le mot testé à l'itération précédente et son code couleur associée, on va chercher à trouver tous les mots du dico qui ont le même fonctionnement puis tester un des mots de ce dictionnaire mis à jour
    char * Dico[10140];     //Je fais une copie de mon dico sous forme de liste pour que la comparaison soit plus simple
    char * buffer=(char *) malloc(6);
    int i=0;
    while (i<MAX-1){
        D[i] = fgets(buffer,6,f);
        //fgets(buffer,6,f);
       //printf("%s\n", D[i]);
        i=i+1;
    }
    int j=1;      
    int k=0;
    char * DicoNew[10140]; //Le dico qui va être mis à jour avec seulement les mots correspondants au bon truc

    while (k<MAX-1){
       int* COULEUR = decriptage(Dico[k],mot)   //On recuperer le code couleur de tous les mots du dico et on garde ceux qui ont celui qui correspond à notre mot
        if (COULEUR==COULEUR2){
            DICONew[j]=DICO[k]; //maj du dico
            j=j+1;
        }
    }
    if DICONew[1]==mot{
        return DICONew[2];  //On fait en sorte de ne pas retester notre mot
    }
    else{
        return DICONew[1];
    }
    
}