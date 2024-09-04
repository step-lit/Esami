#include <stdio.h>
#include <stdlib.h>
#include "Pile/pile.h"

//file principale

/* PER COMPILARE UTILIZZARE IL SEGUENTE COMANDO: 

  gcc principale.c .\strutture_esempi\strutture.c -o principale

  perché per il linking corretto vanno inclusi tutti i .c

*/

int main() {

  /* -------------------------------------------------------*/
  /* --------------------- TEST PILE -----------------------*/
  /* -------------------------------------------------------*/

   pila* nuova_pila = new_pila(10);
   printf("La pila e' vuota? %d\n", is_empty(nuova_pila));
   stampa_pila(nuova_pila);
   push(nuova_pila,2);
   push(nuova_pila,5);
   push(nuova_pila,3);
   push(nuova_pila,7);
   printf("La pila e' vuota? %d\n", is_empty(nuova_pila));
   stampa_pila(nuova_pila);
   int a = pop(nuova_pila);
   printf("L'elemento tolto e' %d\n", a);
   stampa_pila(nuova_pila);
   printf("La grandezza massima della pila e': %d", size(nuova_pila));
   empty(nuova_pila);
   stampa_pila(nuova_pila);

}