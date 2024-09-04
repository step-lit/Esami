#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

//file per le definizioni di metodi

pila* new_pila(int max_size) {
      pila* nuova_pila = (pila*)malloc(sizeof(pila));
      nuova_pila->A = (int*)calloc(max_size, sizeof(int));
      nuova_pila->size = max_size; 
      nuova_pila->top = -1; 

      return nuova_pila;
}

int is_empty(pila* pila) {
    return pila->top == -1;
}

void push(pila* pila,int x) {
    //controlliamo che la pila non sia piena
    if (pila->top == pila->size - 1) {
       printf("La pila e' piena \n");
       //codice d'uscita errore
       exit(1); 
       //altrimenti raddoppi la size (non l'abbiamo implementato)
    }
    //incrementiamo il top
    pila->top += 1;
    //inseriamo l'elemento nella pila
    pila->A[pila->top] = x;
}

int pop(pila* pila) {
    if (pila->top == -1) {
       printf("La pila e' gia' vuota \n");
       //codice d'uscita errore
       exit(1); 
    }
    int valore = pila->A[pila->top];
    pila->A[pila->top] = 0;
    pila->top -= 1;

    return valore;
}

int top(pila* pila) {
    return pila->top;
}

void empty(pila* pila) {
     for (int i=0; i < pila->size; i++) {
         pila->A[i] = 0;
     }
     pila->top = -1; //riassegno top a -1
}

int size(pila* pila) {
    return pila->size;
}

void stampa_pila(pila* pila) {
    printf("\n[");
    for (int i=0; i <= pila->top; i++) {
         printf(" %d ", pila->A[i]);
    }
    printf("]\n");
}