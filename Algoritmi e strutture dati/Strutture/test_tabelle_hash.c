#include <stdio.h>
#include <stdlib.h>
#include "Tabelle_hash/tabelle_hash.h"

#include <math.h>

//file principale

/* PER COMPILARE UTILIZZARE IL SEGUENTE COMANDO: 

  gcc principale.c .\strutture_esempi\strutture.c -o principale

  perché per il linking corretto vanno inclusi tutti i .c

*/

int main () {

    tabella* thash = new_tabella();

    for(int i = 0; i < 30; i++) {
        add_tabella(thash,i,2*i);
        stampa_tabella(thash);
        printf("---------------------------------\n");
    }
    
    
}