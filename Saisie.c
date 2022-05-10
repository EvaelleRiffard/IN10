//On demande à l'utilisateur d'entrée le mot et on vérifie qu'il appartient au dictionnaire
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* saisie(){
    char* mot = malloc(sizeof(char)*10);
    char* erreur = "erreur";

    //Saisie du mot
    printf("Ecrivez un mot : ");
    scanf("%s",mot);
    printf("\n");

    //problème taille du mot
    if (strlen(mot)!=5){
        printf ("La taille du mot doit faire 5 lettres");
        return erreur;
    }

    //vérification le mot existe
    FILE *f;
    f=fopen("dico.txt","rt");

    //vérification le dico est ouvert
    if (f==NULL){
        printf("Fichier corrompu\n");
        fclose(f);
        return erreur;
    }
    
    int n=10140;
    char * buffer=(char *) malloc(6);
    int i=1;
    while ((i<n && strcmp(fgets(buffer,6,f),mot)!=0) ){
        i=i+1;
       // printf("%d\n", i);
    }
    
    if (i==10140){
        printf("Le mot n'existe pas");
        fclose(f);
        return erreur;
    }
    else{
        fclose(f);
        return mot;
    }
}