//On demande à l'utilisateur d'entrée le mot et on vérifie qu'il appartient au dictionnaire
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* saisie(){
    char* mot = malloc(sizeof(char)*10);
    char* erreur = "erreur";

    printf("Ecrivez un mot : ");
    scanf("%s",mot);
    printf("\n");
    if (strlen(mot)!=5){
        printf ("La taille du mot doit faire 5 lettres");
        return erreur;
    }
    FILE *f;
    f=fopen("dico.txt","rt");
    if (f==NULL){
        printf("Fichier corrompu");
        fclose(f);
        return erreur;
    }
    int n=1140;
    char * buffer=(char *) malloc(6);
    int i=1;
    while ((strcmp(fgets(buffer,6,f),mot)!=0)&&i<=n){
        i=i+1;
        //printf("%s", buffer);
    }
    if (i==5071){
        printf("Le mot n'existe pas");
        fclose(f);
        return erreur;
    }
    else{
        fclose(f);
        return mot;
    }
}