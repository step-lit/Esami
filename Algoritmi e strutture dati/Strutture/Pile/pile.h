#ifndef _PILE
#define _PILE

//la pila di interi è una struttura formata da un array di interi, un valore size e top (elemento in testa alla pila)
typedef struct pi {
     int* A; //utilizziamo int* perché l'array non può essere preallocato
     int top;
     int size;
} pila;

pila* new_pila(int max_size); //passiamo max_size per la grandezza dell'array

int is_empty(pila* pila);

void push(pila* pila,int x);

int pop(pila* pila);

int top(pila* pila);

void empty(pila* pila);

int size(pila* pila);

void stampa_pila(pila* pila);

#endif

//file per le dichiarazioni (di strutture ma anche funzioni/metodi)