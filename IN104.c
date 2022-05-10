#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Saisie.h"
#include "decriptage.h"
#include "reglejeu.h"
#include "wordle.h"


int main(){
    
    #define VERT "\x1B[32m"
    #define BLEU "\x1B[36m"
    #define ROUGE "\x1B[31m"
    #define RESET "\x1B[0m"

    /*TEST COULEURS
    char* j = "bleu";
    printf("%s%s%s\n", BLEU, j, RESET);
    char* r = "rouge";
    printf("%s%s%s\n", ROUGE, r, RESET);
    char* v = "vert";
    printf("%s%s%s\n", VERT, v, RESET);
    */

    wordle("votif");
    
}