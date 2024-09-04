#include <stdio.h>
#include <stdlib.h>
#include "code.h"

coda* new_queue(int max_size) {
      coda* nuova_coda = (coda*)malloc(sizeof(coda));
      nuova_coda->A = (int*)calloc(max_size,sizeof(int));
      nuova_coda->size = max_size;
      nuova_coda->head = 0;
      nuova_coda->tail = 0;

      return nuova_coda;
}

int is_empty(coda* coda) {
    return coda->head == coda->tail;
}

void enqueue(coda* coda, int x) {
    if( (coda->tail == coda->head - 1) ||
        (coda->head == 0 && coda->tail == coda->size - 1) ) {
        printf("Errore: la lista e' piena!\n");
        exit(1);
        /* CASO FUNZIONE TELESCOPICA 
        coda->size = coda->size*2;                                 //adesso size vale il doppio del size precedente
        coda->A = (int*)realloc(coda->A,sizeof(int)*coda->size);   //primo valore array da riallocare, secondo valore il size totale da allocare

        *** Se coda->head > coda->tail raddoppiando l'array mi trovo nella situazione di una coda spezzata (la fine sta all'inizio e la testa al centro) : devo riportarla in una condizione normale ***
        *** Posso decidere di spostare la parte di coda->tail e attaccarla a quella di coda->head oppure spostare quella di coda->head alla fine ***
        if ( coda->head > coda->tail ) {
           for (int i=0; i < coda->tail; i++)
               coda->A[coda->size/2 + i]= coda->A[i];
        }
        
        */
    }
    coda->A[coda->tail] = x;
    //posso fare un if per il caso in cui esco fuori dall'array oppure uso l'operazione di modulo con coda->size (ogni divisione darà come resto l'indice esatto incrementato di uno tranne quando arriverà a coda->size, perché ritornerà resto 0)
    coda->tail = (coda->tail + 1) % coda->size; //il modulo serve solo nel caso in cui head sta in mezzo e quindi tail deve tornare indietro

}

int dequeue(coda* coda) {
    int valore;
    if(coda->tail == coda->head){
        printf("La coda e' vuota!\n");
        exit(1);
    }
    valore = coda->A[coda->head];
    if(coda->head == coda->size - 1)
       //se sta a fine corsa lo riporto a 0;
       coda->head == 0;
    else
       //questo se coda->head non sta a fine corsa
       coda->head++;
    return valore;
}

int front(coda* coda) {
    if(coda->tail == coda->head){
        printf("La coda e' vuota, percio' non trovo l'elemento piu' vecchio!\n");
        exit(1);
    }
    return coda->A[coda->tail - 1];
}

void empty(coda* coda) {
    for (int i=0; i < coda->size; i++) {
         coda->A[i] = 0;
    }
    coda->head = 0;
    coda->tail = 0;
}

int size(coda* coda) {
    int contatore = 0;
    if ( coda->head == coda->tail )  return contatore;
    if ( coda->head < coda->tail ){
       for(int i=coda->head; i < coda->tail; i++)
          contatore++;
       return contatore;
    }
    for(int i=0; i < coda->tail; i++)
          contatore++;
    for(int i=coda->head; i < coda->size; i++)
          contatore++;
    return contatore;
}

void stampa_coda(coda* coda) {
    printf("\n[");
    for (int i=0; i < coda->size; i++) {
         printf(" %d ", coda->A[i]);
    }
    printf("]\n");
}