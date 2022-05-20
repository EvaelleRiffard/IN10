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
  //  char* D[10140];
    FILE *f;
    f=fopen("dico.txt","rt");

    //verification le dico est ouvert
     if (f==NULL){
        printf("Fichier corrompu\n");
        fclose(f);
        return erreur;
    }
    
    char * buffer=(char *) malloc(6);
    srand(time(NULL));
    int r = (rand() % (MAX + 1 - MIN)) + MIN;
    int i=0;
    while (i<r-2){  //r-2 pour eviter le segmentation fault si r vaut 10140 qui est pair et qui va redécaler après
       // D[i] = fgets(buffer,6,f);
        fgets(buffer,6,f);
       // printf("%s\n", D[i]);
        i=i+1;
    }

    if ((i-1)%2==0){    //On remarque qu'une ligne sur 2 (les lignes pairs) présente seulement un espace, donc on reapplique un buffer pour avoir un mot
        fgets(buffer,6,f);
    }
    char * mot=fgets(buffer,6,f);
    //printf("%d\n", r);
    //printf("%s\n", mot);

    fclose(f);
    return mot;
    
}
