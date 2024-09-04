#include <stdio.h>
#include <stdlib.h>
#include "Code/code.h"

//file principale

/* PER COMPILARE UTILIZZARE IL SEGUENTE COMANDO: 

  gcc principale.c .\strutture_esempi\strutture.c -o principale

  perché per il linking corretto vanno inclusi tutti i .c

*/

int main() {

    coda* nuova_coda = new_queue(10);
    printf("La coda e' vuota? %d\n", is_empty(nuova_coda));
    stampa_coda(nuova_coda);
    printf("Ora ci sono %d interi in coda!\n", size(nuova_coda));
    enqueue(nuova_coda, 2);
    enqueue(nuova_coda, 3);
    enqueue(nuova_coda, 5);
    enqueue(nuova_coda, 7);
    stampa_coda(nuova_coda);
    printf("Ora ci sono %d interi in coda!\n", size(nuova_coda));
    enqueue(nuova_coda, 3);
    enqueue(nuova_coda, 3);
    enqueue(nuova_coda, 5);
    enqueue(nuova_coda, 7);
    enqueue(nuova_coda, 6);
    stampa_coda(nuova_coda);
    printf("Ora ci sono %d interi in coda!\n", size(nuova_coda));
    enqueue(nuova_coda, 8);
}



