#ifndef _ARRAY_H
#define _ARRAY_H


void stampa_array(int* A, int length);
int tutti_pary_array(int* A, int length);
int verifica_array_uguali(int* A1, int* A2, int l1, int l2);
int verifica_array_crescente(int* A, int length);

int somma_pari(int* A, int length);
void trova_min_max( int* A, int length, int* min, int* max);
int* inverti_array(int* A, int length);
int somma_elementi_array(int* A, int length);
int media_elementi_array(int* A, int length);


#endif