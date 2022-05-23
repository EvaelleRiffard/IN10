#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5070

char** dico_i(){
     //Je fais une copie de mon dico sous forme de liste pour que la comparaison soit plus simple
    
    /*char* erreur[2];
    erreur[0] = "erreur";
    erreur[1] = "erreur";
   
    if (f==NULL){
        printf("Fichier corrompu\n");
        fclose(f);
        return erreur;
    */
    FILE *f;
    f=fopen("dico.txt","rt");
    char ** Dico = malloc(sizeof(char**)*5070);
    //char * buffer= malloc(6*sizeof(char*));
    int i=0;
    while (i < MAX){
        Dico[i] = malloc(sizeof(char)*6);
        fgets(Dico[i],6,f);
        fgetc(f);
        i=i+1;
    }

    fclose(f);
    return Dico;
 }  