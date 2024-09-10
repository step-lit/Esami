#ifndef _LISTE_S
#define _LISTE_S

typedef struct i {
    int info;
    // non posso ancora scrivere item* perché non lo conosce ancora!!!! devo scrivere struct i* perché è un puntatore al tipo struct i!!!!
    struct i* next;
} item;

//Da questo momento in poi usare "item*" o "lista_s" e' lo stesso
typedef item* lista_s; 

void insert_lista_s_riferimento(item** item, int n);

item* insert_lista_s_valore(item* item, int n);

//utilizzo il typedef lista_s per il puntatore item* (risparmio qualche carattere)
void insert_lista_s(lista_s* l, int n);

int somma_uno_lista_s(lista_s l);

int somma_due_lista_s(lista_s l);

void stampa_lista_s(lista_s l);

void stampa_lista_locazioni_s(lista_s l);

void cancella_lista_s(lista_s* l, item* i);

void cancella_lista_s_elem(lista_s* l, int n);

int massimo_lista_s(lista_s l);

item* search_lista_s(lista_s l, int n);

int conta_nodi_lista_s(lista_s l);

int comuni_liste_s(lista_s l1, lista_s l2);

void dealloca_lista_s(lista_s* l);

lista_s inversa_lista_s(lista_s l);

/* ESERCITAZIONI LISTE S*/
int calcola_minimo_lista_s(lista_s l);
int verifica_max_min_lista_s(lista_s l);
void insert_end_lista_s(lista_s* l, int val);



#endif

//file per le dichiarazioni di metodi e strutture/variabili