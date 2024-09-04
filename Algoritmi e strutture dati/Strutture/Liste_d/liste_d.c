#include <stdio.h>
#include <stdlib.h>
#include "liste_d.h"

/****************************************************/
/******************* INSERIMENTI ********************/
/****************************************************/

//inserimento in testa di un nuovo nodo con campo info = n
void insert_lista_d(lista_d* l, int n) {
    nodo* nuovo_nodo = (nodo*)malloc(sizeof(nodo));
    nuovo_nodo->info = n;
    nuovo_nodo->prev = NULL;
    nuovo_nodo->next = (*l);
    // la lista inizialmente potrebbe essere vuota, in quel caso non devo modificare il prev del primo nodo perché non c'è!
    if ( (*l) != NULL ) {
       (*l)->prev = nuovo_nodo;
    }
    (*l) = nuovo_nodo;
}



//inserimento prima del nodo i di un nuovo nodo con campo info = n
void insert_before_d(lista_d* l, int n, nodo* i) {
    if ( (*l) == NULL ) {
        printf("La lista e' vuota quindi il nodo cercato non esiste!\n");
        exit(1);
    }
    nodo* nuovo_nodo = (nodo*)malloc(sizeof(nodo));
    nuovo_nodo->info = n;
    nuovo_nodo->next = i;
    i->prev = nuovo_nodo;
    //inserimento in testa alla lista (i è proprio il primo elemento della lista)
    if ( i == (*l) ) {
        nuovo_nodo->prev = NULL;
        (*l) = nuovo_nodo;
    }
    else {
        i->prev->next = nuovo_nodo;
        nuovo_nodo->prev = i->prev;
    }
}

//inserimento dopo il nodo i di un nuovo nodo con campo info = n
void insert_after_d(lista_d* l, int n, nodo* i) {
    if ( (*l) == NULL ) {
        printf("La lista e' vuota quindi il nodo cercato non esiste!\n");
        exit(1);
    }
    nodo* nuovo_nodo = (nodo*)malloc(sizeof(nodo));
    nuovo_nodo->info = n;
    nuovo_nodo->prev = i;
    if ( i->next == NULL) {
        i->next = nuovo_nodo;
        nuovo_nodo->next = NULL;
    }
    else {
    //i -> c
    //i -> nuovo_nodo -> c
        nuovo_nodo->next = i->next;
        i->next->prev = nuovo_nodo;
        i->next = nuovo_nodo;
    }                                                            
}


/****************************************************/
/******************* STAMPA LISTA *******************/
/****************************************************/

void stampa_lista_d(lista_d l) {
    while( l != NULL) {
        if ( l->next != NULL)
            printf("[%d] [%p] -> ", l->info, l);
        else
            printf("[%d] [%p]", l->info, l);
        l = l->next;
    }
    printf("\n");
}

/****************************************************/
/******************* CANCELLA ELEM ******************/
/****************************************************/

//cancella il nodo con il campo info = n
void cancella_lista_d(lista_d* l, int n) {
    if ( (*l) == NULL ) {
        printf("Errore di cancellazione: La lista e' vuota!\n");
        exit(1);
    }
    nodo* corrente = (*l);
    while( corrente->info != n ) {
        corrente = corrente->next;
    }
    //questo è il caso in cui cancelliamo all'inizio della lista
    // head -> nodo trovato -> c
    if ( corrente->prev == NULL ) {
        (*l) = corrente->next;
        corrente->next->prev = NULL;
    }
    else if ( corrente->next == NULL) {
        corrente->prev->next = NULL;
    }
    else {
        // a -> nodo trovato -> c
        // a -> c
        corrente->prev->next = corrente->next;
        corrente->next->prev = corrente->prev;
    } 
    free(corrente);
}

/****************************************************/
/***************** VERIFICA DOPPIONI ****************/
/****************************************************/

//verifica che ci sono doppioni in una lista non ordinata
int doppioni_lista_d(lista_d l) {
    nodo* x = l;
    while( x != NULL) {
        nodo* y = x->next;
        while( y != NULL) {
            if( x->info == y->info )
                return 1;
            y = y->next;
        }
        x = x->next;
    }
    return 0;
}

//verifica che ci sono doppioni in una lista ordinata
int doppioni_sorted_lista_d(lista_d l) {
    int verificato = 0;
    while( l != NULL && !verificato) {
        if ( l == l->next )
           verificato = 1;
        l = l->next;
    }
    return verificato;
}

/****************************************************/
/********************* RICERCA  *********************/
/****************************************************/

//ricerca di un nodo nella lista con un valore specifico, la funzione ritorna l'indirizzo del nodo
nodo* search_lista_d_elem(lista_d l, int n) {
    if( l == NULL ) {
        printf("Errore: La lista e' vuota!\n");
        exit(1);
    }
    nodo* x = l;
    while( x != NULL ) {
        if( x->info == n )
            return x;
        x = x->next;
    }
    return NULL;
}

//verifica dell'esistenza di un nodo con indirizzo pari ad i nella lista
int search_lista_d_(lista_d l, nodo* i) {
    if( l == NULL ) return 0;
    if( i == l ) return 1;
    nodo* x = l->next;
    while( x != NULL ) {
        if( x == i ) 
            return 1;
        x = x->next;
    }
    return 0;
}