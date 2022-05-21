#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* maj_essai(char* essai, char**Dico){
    if (Dico[0]==essai){
        return Dico[1];  //On fait en sorte de ne pas retester notre mot
    }
    else{
        return Dico[0];
    }
}