#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "array.h"


//funzione che stampa un array di interi
void stampa_array(int* A, int length) {
    for( int i = 0; i < length; i++ ) {
        printf("A[%d]: %d\n", i, A[i]);
    }
    printf("\n");
}

//funzione che riceve come parametro una sequenza di interi 
//(e la sua lunghezza) e verifica se gli interi sono tutti pari
int tutti_pary_array(int* A, int length) {
    int verificato = 1; //verifica universale, inizialmente sono tutti pari
    for( int i = 0; i < length; i++ ) {
        if( A[i]%2 != 0 )
            verificato = 0; //non sono tutti pari
    }
    return verificato;
}

//funzione che riceve come parametro due sequenze di interi 
//(e le loro lunghezze) e verifica se le sequenze sono uguali
int verifica_array_uguali(int* A1, int* A2, int l1, int l2) {
    if( l1 != l2 ) {
        return 0;
    }
    int i = 0;
    while( i < l1 ) {
        if( A1[i] != A2[i])
            return 0;
        else
            i++;
    }
    return 1;;
}

/* funzione che riceve come parametro una sequenza di interi 
 * (e la sua lunghezza) e verifica se la sequenza è crescente */
int verifica_array_crescente(int* A, int length) {
    for( int i=0; i < length; i++ ) {
        if( A[i] > A[i+1] )
            return 0;
    }
    return 1;
}

//funzione che ritorna la somma dei numeri pari in un array
int somma_pari(int* A, int length) {
    int somma_pari = 0;
    for( int i=0; i < length; i++ ) {
        if( A[i]%2 == 0 )
            somma_pari += A[i];
    }
    return somma_pari;
}

//funzione che trova il minimo ed il massimo in un array e li inserisce nelle variabili del main!
void trova_min_max( int* A, int length, int* min, int* max) {
    //min e max sono due puntatori ad int con all'interno l'indirizzo della variabile, per gestire il loro contenuto devo usare l'operatore *!
    *min = *max = A[0];
    for( int i=1; i < length; i++ ) {
        if( A[i] > *max )
            *max = A[i];
        if( A[i] < *min )
            *min = A[i];
    }
    //non ritorno nulla perché vado a modificare min e max direttamente nel main!
}

//funzione che inverte l'ordine dell'array
int* inverti_array(int* A, int length) {
    int* A_new = (int*)calloc(length, sizeof(int));

    int j = 0; //indice dell'array nuovo
    while( j < length) {
        for(int i=length-1; i >= 0; i-- ) {
            A_new[j] = A[i];
            j++;
        }
    }
    return A_new;
}

//somma elementi array
int somma_elementi_array(int* A, int length) {
    int somma = 0;
    for( int i=0; i < length; i++ ) {
        somma += A[i];
    }
    return somma;
}


//media elementi array
int media_elementi_array(int* A, int length) {
    return (float)(somma_elementi_array(A, length)/length);
}