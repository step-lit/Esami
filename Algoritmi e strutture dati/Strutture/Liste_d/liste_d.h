#ifndef _LISTE_D
#define _LISTE_D

typedef struct n {
    int info;
    struct n* prev;
    struct n* next;
} nodo;

//utilizzando questo typedef, usare nodo* oppure lista_d è la stessa cosa!
typedef nodo* lista_d;

void insert_lista_d(lista_d* l, int n);

void insert_before_d(lista_d* l, int n, nodo* i);

void stampa_lista_d(lista_d l);

void insert_after_d(lista_d* l, int n, nodo* i);

void cancella_lista_d(lista_d* l, int n);

int doppioni_lista_d(lista_d l);

int doppioni_sorted_lista_d(lista_d l);

nodo* search_lista_d_elem(lista_d l, int n);

int search_lista_d_(lista_d l, nodo* i);

#endif

//file per le dichiarazioni di metodi e strutture/variabili