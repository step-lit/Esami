#include <stdio.h>
#include <stdlib.h>
#include "Grafi_liste/grafi_liste.h"

//file principale

/* PER COMPILARE UTILIZZARE IL SEGUENTE COMANDO: 

  gcc principale.c .\strutture_esempi\strutture.c -o principale

  perché per il linking corretto vanno inclusi tutti i .c

*/

int main () {
    grafo_l* grafo_liste = new_graph_l(10);

    new_edge_graph_l(grafo_liste, 0, 1);
    new_edge_graph_l(grafo_liste, 0, 2);
    new_edge_graph_l(grafo_liste, 3, 3);

    print_graph_l(grafo_liste);
    
    grafo_m* grafo_matrice = grafo_l_into_m(grafo_liste);

    print_graph_m(grafo_matrice);

}