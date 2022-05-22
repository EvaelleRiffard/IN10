#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(int* A, int a, int* B, int b){
    int S = 0;
    if (a != b){
        S = 1;
    }
    else{

        for (int i = 0; i<a; i++){
            if (A[i] != B[i]){
                S += 1;
            }
        }
    }
    return S;
}