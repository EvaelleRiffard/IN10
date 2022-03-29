#include <stdio.h>

int len(char* mot){
    int i=0;
    while (strcmp(mot[i],"\0")!=0){
        i=i+1;
    }
    return i;
}