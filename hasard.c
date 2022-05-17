#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<time.h>
//fonction qui renvoie un mot choisi au hasard dans le dictionnaire 

#define MAX 10140
#define MIN 0
char* hasard(){
    //on va créer un tableau contenant les mots du dico
    char* erreur = "erreur";
    char* D[10140];
    FILE *f;
    f=fopen("dico.txt","rt");

    //verification le dico est ouvert
     if (f==NULL){
        printf("Fichier corrompu\n");
        fclose(f);
        return erreur;
    }
    
    char * buffer=(char *) malloc(6);
    int i=0;
    while (i<MAX-1){
        D[i] = fgets(buffer,6,f);
        //fgets(buffer,6,f);
        printf("%s\n", D[i]);
        i=i+1;
    }
    
    srand(time(NULL));
    int r = (rand() % (MAX + 1 - MIN)) + MIN;
    printf("%d\n", r);
    printf("%s\n", D[r]);

    fclose(f);
    return D[r];
    
}
