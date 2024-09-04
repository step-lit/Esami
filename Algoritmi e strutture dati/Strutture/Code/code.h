#ifndef _CODE
#define _CODE

typedef struct c {
    int* A;
    int size;
    int head;
    int tail;
} coda;

coda* new_queue(int max_size);

int is_empty(coda* coda);

void enqueue(coda* coda, int x);

int dequeue(coda* coda);

//ritorna l'elemento più vecchio
int front(coda* coda); 

void empty(coda* coda);

int size(coda* coda);

void stampa_coda(coda* coda);

#endif

//file per le dichiarazioni di metodi e strutture/variabili