#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Prova_alberi_francy.h"

int main() {

    albero_b root_b = NULL;
    crea_albero_binario_random(&(root_b), 10, 50);
    print2D(root_b);
    
    albero_b root_a = NULL;


    return 0;
}