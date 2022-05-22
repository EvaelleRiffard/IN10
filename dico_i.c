#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10140

char** dico_i(){
     //Je fais une copie de mon dico sous forme de liste pour que la comparaison soit plus simple
    FILE *f;
    f=fopen("dico.txt","rt");
    char ** Dico=malloc(sizeof(char*)*10140);
    char * buffer=(char *) malloc(6);
    int i=0;
    while (i<MAX-1){
        Dico[i] = fgets(buffer,6,f);
        //fgets(buffer,6,f);
       //printf("%s\n", D[i]);
        i=i+1;
    }
    fclose(f);
    return Dico;
 }