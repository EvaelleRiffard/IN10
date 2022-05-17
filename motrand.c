#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<time.h>

#define TAILLE_MAX 1000
 
int main()
{
    srand(time(NULL));
    int k=0;
    const int MIN = 0, MAX = 2509;
    int r = (rand() % (MAX + 1 - MIN)) + MIN;
    

    FILE* fichier2 = NULL;
    char chaine[TAILLE_MAX] = "";
 
    fichier2 = fopen("Dico5.txt","r");
 
    if (fichier2 != NULL)
    {
        while (fgets(chaine, TAILLE_MAX, fichier2) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
            if (k==r){
                printf("%s \n", chaine);
            }
            k++;

        }
fclose(fichier2);
        }
        printf("%d\n",r); 
    return 0;
        
    }
    
