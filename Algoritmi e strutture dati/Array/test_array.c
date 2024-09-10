#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "array.h"


int main() {

    /*        TEST ARRAY TUTTI_PARI      */
    int array_test[5];  
    for( int i=0; i < 5; i++) {
        array_test[i] = i;
    }
    //adesso l'array ha i numeri 0,1,2,3,4
    stampa_array(array_test, 5);
    printf("L'array ha solo numeri pari? %d\n", tutti_pary_array(array_test, 5));
    printf("\n");

    array_test[0] = 2;
    array_test[1] = 0;
    array_test[2] = 4;
    array_test[3] = 6;
    array_test[4] = 8;
    
    stampa_array(array_test, 5);
    printf("L'array ha solo numeri pari? %d\n", tutti_pary_array(array_test, 5));
    printf("\n");

    /*     TEST DUE ARRAY UGUALI       */
    int array_test2[5];
    array_test2[0] = 2;
    array_test2[1] = 0;
    array_test2[2] = 4;
    array_test2[3] = 6;
    array_test2[4] = 8;
    
    printf("I due array sono uguali? %d\n", verifica_array_uguali(array_test, array_test2, 5, 5));

    for( int i=0; i < 5; i++) {
        array_test2[i] = i;
    }
    printf("Ora i due array sono uguali? %d\n", verifica_array_uguali(array_test2, array_test, 5, 5));


    int array_test3[7];
    array_test3[0] = 2;
    array_test3[1] = 0;
    array_test3[2] = 4;
    array_test3[3] = 6;
    array_test3[4] = 8;
    array_test3[4] = 0;
    array_test3[4] = 0;

    printf("Questi altri due array di lunghezza diversa sono uguali? %d\n", verifica_array_uguali(array_test2, array_test3, 5, 7));

    /*     TEST ARRAY CRESCENTE     */
    printf("L'array e' crescente? %d\n", verifica_array_crescente(array_test2, 5)); 
    array_test2[0] = 2;
    array_test2[1] = 0;
    array_test2[2] = 4;
    array_test2[3] = 6;
    array_test2[4] = 8;
    printf("L'array ora e' crescente? %d\n", verifica_array_crescente(array_test2, 5)); 

    printf("\n");
    printf("\n");


    printf("La somma dei numeri pari all'interno dell'array e' %d!\n", somma_pari(array_test2, 5));

    int min_array_test2, max_array_test2;
    trova_min_max( array_test2, 5, &min_array_test2, &max_array_test2);
    printf("Il minimo nell'array_test2 e' %d ed il massimo e' %d!\n", min_array_test2, max_array_test2);

    int* inverso_array_test2 = inverti_array(array_test2, 5);
    stampa_array(inverso_array_test2, 5);
    
    printf("La media degli elementi nell'array array_test2 e' uguale a: %d\n", media_elementi_array(array_test2, 5));

    return 0;
}