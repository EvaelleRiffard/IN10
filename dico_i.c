#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** dico_i(){
     //Je fais une copie de mon dico sous forme de liste pour que la comparaison soit plus simple
    char * Dico[10140];
    char * buffer=(char *) malloc(6);
    int i=0;
    while (i<MAX-1){
        D[i] = fgets(buffer,6,f);
        //fgets(buffer,6,f);
       //printf("%s\n", D[i]);
        i=i+1;
    }
    return D;
 }