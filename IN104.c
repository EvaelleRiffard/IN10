#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Saisie.h"
#include "decriptage.h"

int main(){

    #define VERT "\x1B[32m"
    #define JAUNE "\x1B[33m"
     #define ROUGE "\x1B[31m"
    #define RESET "\x1B[0m"

    char* j = "jaune";
    printf("%s", JAUNE, j, RESET);
    struct lettre * L = decriptage(saisie(), "lilas");
    for (int i = 0; i<5; i++){
        printf("%s%c%s\n", L[i].c, L[i].l, RESET );
    } 
    free(L);
}